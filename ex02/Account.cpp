#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){}

Account::Account(int initial_deposit){
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->checkAmount() << ";created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

Account::~Account(){
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" \
	<< checkAmount()<< ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() \
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" \
	<< checkAmount()<< ";deposit:" << this->_nbDeposits << ";withdrawls:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" \
	<< this->_amount - deposit << ";deposit:" << deposit << ";amount:" << checkAmount()<< \
	"nb_deposits" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawl) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" \
	<< checkAmount()<< ";withdrawal:";
	if (this->_amount < withdrawl) {
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawl;
	this->_totalAmount -= withdrawl;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << withdrawl << ";amount:" << checkAmount() << ";nb_withdrawals" \
	<< this->_nbWithdrawals << std::endl;
	return true;
}

void Account::_displayTimestamp() {
	std::time_t time = std::time(nullptr);
	std::tm *localTime = std::localtime(&time);
	char buf[20];
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localTime);
	 std::cout << "[" <<  buf << "]" << " ";
}

int Account::checkAmount() const {
	return this->_amount;
}

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits(){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
	return _totalNbWithdrawals;
}

