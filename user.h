#pragma once

#include <string>
#include <cstdint>

class User{
    private:
        uint64_t accountNumber;
        char name[100];
        char pin[5];
        size_t balance;

    public:
        User(uint64_t accNum, const char *name, const char *pin, size_t balance);

        void setName(const char *name);
        void setPin(const char *pin);
        void deposit(size_t amount);
        void withdraw(size_t amount);

        uint64_t getAccountNumber() const;
        const char *getName() const;
        const char *getPin() const;
        size_t getBalance() const;
};