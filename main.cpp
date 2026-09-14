#include <iostream>
#include <cstdint>
#include "user.h"
#include "atm.h"
#include "userRepo.h"
#include "msg.h"

int main() {
    Atm atm;

    uint64_t accountNumber;
    char pin[20];
    int choice;
    size_t amount;

    welcomeMsg();

    do {
        mainMsg();
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            std::cout << "Enter your account number: " << std::endl;
            std::cin >> accountNumber;

            std::cout << "Enter your PIN: " << std::endl;
            std::cin >> pin;

            User* currUser = atm.login(accountNumber, pin);

            if (currUser == nullptr) {
                invalidChoiceMsg();
                break;
            }

            loginMsg();
            do {
                accMsg();
                std::cin >> choice;

                switch (choice) {
                case 1:
                    std::cout << "Your balance is: " << currUser->getBalance() << std::endl;
                    break;

                case 2:
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;

                    currUser->deposit(amount);
                    atm.save();
                    break;

                case 3:
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;

                    currUser->withdraw(amount);
                    atm.save();
                    break;

                case 4:
                {
                    confirmationMsg();
                    int confirm;
                    std::cin >> confirm; 

                    if (confirm == 1) {
                        if (atm.deleteAccount(accountNumber, pin)) {
                            deleteSuccessMsg();
                            choice = 5;
                        }
                        else {
                            deleteErrorMsg();
                        }
                    }
                    break;
                }

                case 5:
                    thankYouMsg();
                    break;

                default:
                    invalidMsg();
                }

            } while (choice != 5);
            break;
        }

        case 2:
        {
            uint64_t newAccNum = atm.createAccount();
            accountCreationMsg(newAccNum);
            break;
        }

        case 3:
            thankYouMsg();
            return 0;

        default:
            invalidMsg();
        }

    } while (choice != 3);

    return 0;
}