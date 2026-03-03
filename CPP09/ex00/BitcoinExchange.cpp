#include "BitciionExchange.hpp"
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdexcept>

BitcoinExchange :: BitcoinExchange(){}
BitcoinExchange :: BitcoinExchange (const BitcoinExchange &other ):_rates(other._rates){}
BitcoinExchange& BitcoinExchange :: operator= (const BitcoinExchange& other){
    if (this != &other){
        _rates = other._rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}


void BitcoinExchange :: loadDatabase(const std::string &filename) {
    std::ifstream file (filename.c_str()); // Opening the file
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
    
    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"
    while(std::getline(file, line)){
        if (line.empty())
            continue;

        //Prepare to split the line
        std::stringstream ss(line); //Wrap the line in a stringstream so we can extract parts easily.
        std::string date, rateStr;

        // xtract everything before the comma into date.
        //Extract everything after the comma into rateStr.

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            throw std::runtime_error("Error: bad database line => " + line);
        
        // Validate date format
        if (!isValidDate(date))
            throw std::runtime_error("Error: invalid date in database => " + date);
        
        // Convert the rate string to a double
        char *end; //end will point to the first invalid character.
        double rate = std::strtod(rateStr.c_str(), &end); //converts a C‑string to a double.
        if(*end != '\0')
            throw std::runtime_error("Error: invalid rate in database => " + rateStr);
        _rates[date] = rate;
    }


}
