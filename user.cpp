#include <iostream>
#include <cstring>
#include "user.h"

User::User(uint64_t accNum, const char* userName, const char* userPin, size_t userBalance) : accountNumber(accNum), balance(userBalance){
    setName(userName);
    setPin(userPin);
}

void User::setName(const char* userName){
    std::strncpy(name, userName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void User::setPin(const char* userPin){ 
    std::strncpy(pin, userPin, sizeof(pin) - 1);
    pin[sizeof(pin) - 1] = '\0';
}

void User::deposit(size_t amount){
    if (amount == 0) {
        std::cout << "Invalid amount!" << std::endl;
        return;
    }

    balance += amount;
    std::cout << "Deposit successful! Your new balance is: " << balance << std::endl;
    std::cout << "=========================================" << std::endl;
}

void User::withdraw(size_t amount){
    if (amount == 0) {
        std::cout << "Invalid amount!" << std::endl;
        return;
    }

    if (amount > balance) {
        std::cout << "Insufficient balance!" << std::endl;
        return;
    }

    balance -= amount;
    std::cout << "Withdrawal successful! Your new balance is: " << balance << std::endl;
}

uint64_t User::getAccountNumber() const { return accountNumber; }

const char* User::getName() const { return name; }

const char* User::getPin() const { return pin; }

size_t User::getBalance() const { return balance; }