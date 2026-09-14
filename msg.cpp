#include <iostream>
#include "msg.h"

void welcomeMsg()
{
    std::cout << "===================" << std::endl;
    std::cout << "Welcome to the ATM!" << std::endl;
    std::cout << "===================" << std::endl;
}

void mainMsg()
{
    std::cout << "1.Login" << std::endl;
    std::cout << "2.Create Account" << std::endl;
    std::cout << "3.Exit" << std::endl;
    std::cout << "Please enter your choice: ";
}

void invalidChoiceMsg()
{
    std::cout << "Invalid account number or PIN!" << std::endl;
}

void invalidMsg()
{
    std::cout << "Invalid choice!" << std::endl;
}

void loginMsg()
{
    std::cout << "Login successful!" << std::endl;
}

void accMsg()
{
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Delete Account" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Please enter your choice: ";
}

void confirmationMsg()
{
    std::cout << "Are you sure you want to delete your account? (1 for Yes, 0 for No): ";
}

void deleteSuccessMsg()
{
    std::cout << "Account deleted successfully!" << std::endl;
}

void deleteErrorMsg()
{
    std::cout << "Error deleting the account!" << std::endl;
}

void thankYouMsg()
{
    std::cout << "=============================" << std::endl;
    std::cout << "Thank you for using the ATM!" << std::endl;
    std::cout << "=============================" << std::endl;
}

void accountCreationMsg(uint64_t newAccNum)
{
    std::cout << "=============================" << std::endl;
    std::cout << "Account created successfully!" << std::endl;
    std::cout << "Your account number is: " << newAccNum << std::endl;
    std::cout << "=============================" << std::endl;
}