// ************************************************************************** //
//                                                                            //
//                account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Martijn Weverling <f**kbankers@gov.co.uk          //
//                                                                            //
// ************************************************************************** //

#include <Account.hpp>
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;;
	return ;
}

Account::~Account()
{}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << &getNbAccounts << ";";
	std::cout << "total:" << &getTotalAmount << ";";
	std::cout << "deposits:" << &getNbDeposits << ";";
	std::cout << "withdrawls:" << &getNbWithdrawals << std::endl;
}

void	_displayTimestamp(void)
{
	time_t		timer;
	struct tm	*local; 

	timer = time(NULL);
	local = localtime(&timer);
	std::cout << "[" << local->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << local->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << local->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << local->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local->tm_sec;
	std::cout << "] " << std::endl;

}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
