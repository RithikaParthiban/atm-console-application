#include "atm.h"
#include <iostream>
#include <cstring>

Atm::Atm() : repo("users.bin"){
    users = repo.load();

    for (const auto& user : users) {
        generatedAccNums.insert(
            user->getAccountNumber()
        );
    }
}

uint64_t Atm::generateAccNum(){
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis(
        1000000000000000ULL,
        9999999999999999ULL
    );

    uint64_t accNum;

    do {
        accNum = dis(gen);
    }
    while (generatedAccNums.find(accNum) != generatedAccNums.end());
    generatedAccNums.insert(accNum);
    return accNum;
}

uint64_t Atm::createAccount(){
    char name[100];
    char pin[20];

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your PIN: ";
    std::cin >> pin;

    uint64_t accNum = generateAccNum();

    users.push_back(
        std::make_unique<User>(accNum,name,pin,0)
    );

    repo.save(users);
    return accNum;
}

User* Atm::login(uint64_t accNum, const char* pin)
{
    for (auto& user : users) {
        if (user->getAccountNumber() == accNum &&
            std::strcmp(user->getPin(), pin) == 0) {
            return user.get();
        }
    }
    return nullptr;
}

void Atm::save() { repo.save(users); }

bool Atm::deleteAccount(uint64_t accNum, const char* pin) {
    for (auto i = users.begin(); i != users.end(); ++i) {
        if ((*i)->getAccountNumber() == accNum &&
            std::strcmp((*i)->getPin(), pin) == 0) {
            users.erase(i);
            generatedAccNums.erase(accNum);
            repo.save(users);
            return true;
        }
    }
    return false;
}

Atm::~Atm() { repo.save(users); }