# ATM Simulation in C++

A console-based ATM simulation built with C++. This project demonstrates **OOP, encapsulation, abstraction, smart pointers, STL vectors, and file persistence**.

## Features

* Create a bank account
* Generate randomized 16-digit account numbers
* Login using account number and PIN
* Check balance
* Deposit and withdraw money
* Delete an account
* Validate transactions
* Support multiple users
* Persistent storage using binary files
* Menu-driven console interface

## Technologies

* C++
* OOP
* STL `vector` and `unordered_set`
* Smart Pointers (`unique_ptr`)
* Fixed-width data types (`uint64_t`)
* Binary file I/O
* `fstream`

## Project Structure

```text
ATM-Simulation/
│
├── main.cpp
├── user.h
├── user.cpp
├── atm.h
├── atm.cpp
├── userRepo.h
├── userRepo.cpp
├── msg.h
├── msg.cpp
├── .gitignore
└── README.md
```

### File Responsibilities

* **`user.h / user.cpp`** — User data and account operations
* **`atm.h / atm.cpp`** — Account creation, login, deletion, and ATM operations
* **`userRepo.h / userRepo.cpp`** — Binary file storage
* **`msg.h / msg.cpp`** — Console messages and menus
* **`main.cpp`** — Program flow and user interaction

## Persistence

User data is stored in `users.bin` using binary file I/O.

```text
Program
   ↓
  Atm
   ↓
userRepo
   ↓
users.bin
```

`users.bin` is excluded from Git using `.gitignore`.

## How to Run

### Compile

```bash
g++ main.cpp user.cpp atm.cpp userRepo.cpp msg.cpp -o atm
```

### Run

**Windows:**

```bash
.\atm.exe
```

**Linux/macOS:**

```bash
./atm
```

## Future Improvements

* Transaction history
* Money transfers
* Change PIN
* Login attempt limits
* Secure PIN hashing
* Database integration

## Author

**Rithika P**
