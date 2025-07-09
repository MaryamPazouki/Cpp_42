#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
:     _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout<<"index"<<_accountIndex
             <<";amount" << _amount
             <<";created" <<std::endl;
}




void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* t = std::localtime(&now); // 	Converts time to local calendar date/time
    // tm* Structure with date/time components
    std::cout << "[" << (t->tm_year + 1900) //  is the number of years since 1900.
			  << (t->tm_mon + 1) //  is months from 0 to 11.
			  << (t->tm_mday)
			  << "_"
			  << (t->tm_hour < 10 ? "0" : "") << t->tm_hour
			  << (t->tm_min < 10 ? "0" : "") << t->tm_min
			  << (t->tm_sec < 10 ? "0" : "") << t->tm_sec
			  << "] ";
}

Account::~Account(void) {
	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit){

    
    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
			  << ";p_amount:" << (_amount - deposit) // previous balance before the deposit
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;


    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;

        std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
        return true;
    }
    else
    {
        std::cout<<";withdrawal:refused"  << std::endl;
        return false;
    }
}


void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

int Account::checkAmount(void) const
{
    _displayTimestamp();
    return _amount;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}