#include <iostream>
#include <iomanip>
#include <string>

class Account {
public:
    //properties
    std::string accountNumber;
    std::string accountHolder;
    double balance;

    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    //can be overriden by derived classes
    virtual void displayDetails() const {
        std::cout << "Account Details for Account (ID: " << accountNumber << "):\n";
        std::cout << "   Holder: " << accountHolder << "\n";
        std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    //adds deposit
    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: $" << amount << "\n";
    }

    //can be overriden by derived classes
    virtual void withdraw(double amount) {
        //will only work if balance is sufficient
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        } else {
            std::cout << "Insufficient balance for withdrawal\n";
        }
    }

    //operator overloading for later
    Account& operator+=(double amount) {
        this->deposit(amount);
        return *this;
    }

    Account& operator-=(double amount) {
        this->withdraw(amount);
        return *this;
    }
    
};

class SavingsAccount : public Account {
public:
    double interestRate = 0.02;

    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    void withdraw(double amount) override {
        double minBalance = 1000;
        //will only work if balance - amt is more or equal to minbalance
        if (balance - amount >= minBalance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        } else {
            std::cout << "Insufficient balance for withdrawal\n";
        }
    }
    //prints interest rate
    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "   Interest Rate: " << std::fixed << std::setprecision(2) << (interestRate * 100) << "%\n";
        std::cout << std::endl;
    }
};

class CurrentAccount : public Account {
public:
    double overdraftLimit = 500;

    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        //will only work is balance + limit is more than or equal to amt
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        } else {
            std::cout << "Withdrawal exceeds overdraft limit\n";
        }
    }
    //prints overdraft limit
    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "   Overdraft Limit: $" << std::fixed << std::setprecision(2) << overdraftLimit << "\n";
    }
    //allows operator overloading func to access current account info
    friend CurrentAccount operator+(CurrentAccount currentAcc, SavingsAccount& savingsAcc);
};

CurrentAccount operator+(CurrentAccount currentAcc, SavingsAccount& savingsAcc) {
    double amount = 300; 
    //if savings has enough money
    if (savingsAcc.balance >= amount) {
        //transfer between accs
        currentAcc.balance += amount;
        savingsAcc.balance -= amount;
        std::cout << "Transfer completed\n";
        std::cout << std::endl;
    } else {
        std::cout << "Insufficient balance in savings for transfer\n";
    }
    return currentAcc;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();
    std::cout << std::endl;

    savings.deposit(500);
    current.withdraw(1000);
    std::cout << std::endl;

    savings.displayDetails();
    current.displayDetails();
    std::cout << std::endl;

    //Transfer specified amount from savings to current
    current = current + savings;
    savings.displayDetails();
    current.displayDetails();

    return 0;
}
