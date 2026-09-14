#pragma once

#include <vector>
#include <memory>
#include <cstdint>
#include <unordered_set>
#include <random>
#include "user.h"
#include "userRepo.h"

class Atm {
private:
    std::vector<std::unique_ptr<User>> users;
    userRepo repo;

    std::unordered_set<uint64_t> generatedAccNums;

    uint64_t generateAccNum();

public:
    Atm();
    ~Atm();

    uint64_t createAccount();

    User* login(uint64_t accNum, const char* pin);

    void save();

    bool deleteAccount(uint64_t accNum, const char* pin);
};