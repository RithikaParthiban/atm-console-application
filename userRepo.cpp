#include "userRepo.h"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <memory>

userRepo::userRepo(const std::string& filename) : filename(filename) {}

void userRepo::save(const std::vector<std::unique_ptr<User>>& users){
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    size_t size = users.size();

    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& user : users) {
        uint64_t accNum = user->getAccountNumber();
        size_t balance = user->getBalance();
        file.write( reinterpret_cast<const char*>(&accNum), sizeof(accNum) );

        file.write( user->getName(), 100 );

        file.write( user->getPin(), 5 );

        file.write( reinterpret_cast<const char*>(&balance), sizeof(balance) );
    }

    file.close();
}

std::vector<std::unique_ptr<User>> userRepo::load(){
    std::vector<std::unique_ptr<User>> users;

    std::ifstream file(filename, std::ios::binary | std::ios::in);

    if (!file.is_open()) {
        return users;
    }

    size_t size = 0;

    file.read( reinterpret_cast<char*>(&size), sizeof(size) );

    if (!file) {
        return users;
    }

    if (size > 10000) {
        std::cerr << "Invalid user data in users.bin!" << std::endl;
        return users;
    }

    for (size_t i = 0; i < size; ++i) {
        uint64_t accNum;
        char name[100];
        char pin[5];
        size_t balance;

        file.read( reinterpret_cast<char*>(&accNum), sizeof(accNum) );

        file.read(name, sizeof(name));

        file.read(pin, sizeof(pin));

        file.read( reinterpret_cast<char*>(&balance), sizeof(balance) );

        if (!file) {
            std::cerr << "Corrupted user data!" << std::endl;
            users.clear();
            return users;
        }

        name[99] = '\0';
        pin[4] = '\0';

        users.push_back(
            std::make_unique<User>( accNum, name, pin, balance )
        );
    }
    file.close();

    return users;
}