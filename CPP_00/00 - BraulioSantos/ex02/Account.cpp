#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:";
    std::cout << getNbAccounts() ;
    std::cout << ";total:";
    std::cout << getTotalAmount();
    std::cout << ";deposits:";
    std::cout << getNbDeposits();
    std::cout << ";withdrawals:";
    std::cout << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:";
    this->_amount += deposit;
    std::cout << this->_amount;
    std::cout << ";nb_deposits:";
    this->_nbDeposits++;
    std::cout << this->_nbDeposits << std::endl;;
    _totalNbDeposits++;
    _totalAmount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount >= withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex ;
        std::cout << ";p_amount:" << this->_amount;
        std::cout << ";withdrawal:" << withdrawal;
        std::cout << ";amount:";
        this->_amount -= withdrawal;
        std::cout << this->_amount;
        std::cout << ";nb_withdrawals:";
        this->_nbWithdrawals++;
        std::cout << this->_nbWithdrawals << std::endl;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        return true;
    }
    else if (withdrawal < 0 || withdrawal > this->_amount)
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex ;
        std::cout << ";p_amount:" << this->_amount;
        std::cout << ";withdrawal:"<< "refused" << std::endl;
        return false;
    }
    return false;
}
int		Account::checkAmount( void ) const
{
    return this->_amount;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:"  << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:"  << this->_nbWithdrawals << std::endl;
}
void	Account::_displayTimestamp( void )
{
	std::time_t	now = std::time(0);
	std::tm	*ltm = std::localtime(&now);
	char	timestamp[16];
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", ltm );
	std::cout << "[" << timestamp << "] ";
}

Account::Account(int initial_deposit)
{
    this->_nbAccounts++;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex ;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}