#pragma once

#include <string>
#include <vector>
#include <memory>
#include "user.h"

class userRepo {
private:
    std::string filename;

public:
    userRepo(const std::string& filename);

    void save(const std::vector<std::unique_ptr<User>>& users);
    std::vector<std::unique_ptr<User>> load();
};