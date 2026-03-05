#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

BitcoinExchange ::BitcoinExchange() {}
BitcoinExchange ::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}
BitcoinExchange &BitcoinExchange ::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _rates = other._rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// -------------------------------------------------------------
// loadDatabase
// -------------------------------------------------------------
void BitcoinExchange ::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str()); // Opening the file
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Prepare to split the line
        std::stringstream ss(line); // Wrap the line in a stringstream so we can extract parts easily.
        std::string date, rateStr;

        // xtract everything before the comma into date.
        // Extract everything after the comma into rateStr.

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            throw std::runtime_error("Error: bad database line => " + line);

        // Validate date format
        if (!isValidDate(date))
            throw std::runtime_error("Error: invalid date in database => " + date);

        // Convert the rate string to a double
        char *end;                                        // end will point to the first invalid character.
        double rate = std::strtod(rateStr.c_str(), &end); // converts a C‑string to a double.
        if (*end != '\0')
            throw std::runtime_error("Error: invalid rate in database => " + rateStr);
        _rates[date] = rate;
    }
}
// -------------------------------------------------------------
// isValidDate
// -------------------------------------------------------------
bool BitcoinExchange ::isValidDate(const std::string &date) const
{
    // Format must be exactly YYYY-MM-DD (10 chars)
    if (date.size() != 10)
        return false;
    // Check fixed positions for '-'
    if (date[4] != '-' || date[7] != '-')
        return false;
    // Extract substrings
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    // Check digits
    for (size_t i = 0; i < yearStr.size(); i++)
        if (!isdigit(yearStr[i]))
            return false;
    for (size_t i = 0; i < monthStr.size(); i++)
        if (!isdigit(monthStr[i]))
            return false;
    for (size_t i = 0; i < dayStr.size(); i++)
        if (!isdigit(dayStr[i]))
            return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    // Month range
    if (month < 1 || month > 12)
        return false;

    // Days per month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leap year adjustment
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (leap && month == 2)
        return (day >= 1 && day <= 29);
    // normal month
    return (day >= 1 && day <= daysInMonth[month - 1]);
}
// -------------------------------------------------------------
// isValidValue
// -------------------------------------------------------------
bool BitcoinExchange ::isValidValue(const std::string &valueStr) const
{
    if (valueStr.empty())
        return false;

    // Check characters: digits, optional one dot, optional leading +/-
    bool dotSeen = false;
    size_t i = 0;
    if (valueStr[i] == '+' || valueStr[i] == '-')
    {
        i++;
        if (i == valueStr.size())
            return false;
    }

    for (; i < valueStr.size(); i++)
    {
        if (valueStr[i] == '.')
        {
            if (dotSeen)
                return false;
            dotSeen = true;
        }
        else if (!isdigit(valueStr[i]))
            return false;
    }

    // Convert to double
    double value = std::atof(valueStr.c_str());

    // Must be non-negative
    if (value < 0)
        return false;
    // Must not exceed 1000
    if (value > 1000)
        return false;

    return true;
}
// -------------------------------------------------------------
// getRateForDate
// -------------------------------------------------------------
double BitcoinExchange ::getRateForDate(const std::string &date) const
{
    // Find the first element with key >= date
    // keys are strings is lexicographically sortable
    // std::map keeps them in chronological order automatically. always sorted!
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

    // Case 1: exact match
    if (it != _rates.end() && it->first == date)
        return it->second;

    // Case 2: no exact match → need previous date
    if (it == _rates.begin())
        throw std::runtime_error("Error: no earlier date available in database.");
    // Step back to previous date
    --it;
    return it->second;
}

// -------------------------------------------------------------
// processInput
// -------------------------------------------------------------
void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        // format: "date | value"
        size_t pipePos = line.find(',');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        // Validate Date
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input=> " << line << std::endl;
            continue;
        }
        // Validate value
        if (!isValidValue(valueStr))
        {
            double v = std::atof(valueStr.c_str());
            if (v < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (v > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value = std::atof(valueStr.c_str());
        double rate;

        try
        {
            rate = getRateForDate(date);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}