#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>

using namespace std;

const string ACCOUNT_FILE = "accounts.txt";

class Account {
public:
    string name;
    int acc_no;
    double balance;

    Account() : acc_no(0), balance(0.0) {}

    Account(string n, int an, double b) : name(n), acc_no(an), balance(b) {}

    string serialize() const {
        ostringstream oss;
        oss << acc_no << '|' << name << '|' << balance;
        return oss.str();
    }

    static Account deserialize(const string& line) {
        istringstream iss(line);
        string token;
        getline(iss, token, '|');
        int an = stoi(token);
        getline(iss, token, '|');
        string n = token;
        getline(iss, token, '|');
        double b = stod(token);
        return Account(n, an, b);
    }
};

class Bank {
private:
    int get_int_input() {
        int value;
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }

    double get_double_input() {
        double value;
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }

public:
    void run() {
        while (true) {
            cout << "\n\n*** Bank Management System ***" << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Check Balance" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            int choice = get_int_input();
            switch (choice) {
                case 1: create_account(); break;
                case 2: deposit_money(); break;
                case 3: withdraw_money(); break;
                case 4: check_balance(); break;
                case 5:
                    cout << "\nClosing the Bank, Thanks for your visit." << endl;
                    return;
                default:
                    cout << "\nInvalid choice!" << endl;
            }
        }
    }

    void create_account() {
        Account acc;
        cout << "\nEnter your name: ";
        getline(cin, acc.name);
        cout << "Enter your account number: ";
        acc.acc_no = get_int_input();
        acc.balance = 0;

        ofstream file(ACCOUNT_FILE, ios::app);
        if (!file) {
            cerr << "\nUnable to open file!!" << endl;
            return;
        }
        file << acc.serialize() << endl;
        file.close();
        cout << "\nAccount created successfully!" << endl;
    }

    void deposit_money() {
        cout << "Enter your account number: ";
        int acc_no = get_int_input();
        cout << "Enter amount to deposit: ";
        double money = get_double_input();

        vector<Account> accounts = load_accounts();
        bool found = false;
        for (auto& acc : accounts) {
            if (acc.acc_no == acc_no) {
                acc.balance += money;
                cout << fixed << setprecision(2);
                cout << "Successfully deposited Rs." << money << ". New balance is Rs." << acc.balance << endl;
                found = true;
                break;
            }
        }
        if (found) save_accounts(accounts);
        else cout << "Account not found." << endl;
    }

    void withdraw_money() {
        cout << "Enter your account number: ";
        int acc_no = get_int_input();
        cout << "Enter amount to withdraw: ";
        double money = get_double_input();

        vector<Account> accounts = load_accounts();
        bool found = false;
        for (auto& acc : accounts) {
            if (acc.acc_no == acc_no) {
                if (acc.balance >= money) {
                    acc.balance -= money;
                    cout << fixed << setprecision(2);
                    cout << "Successfully withdrawn Rs." << money << ". Remaining balance is Rs." << acc.balance << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
                found = true;
                break;
            }
        }
        if (found) save_accounts(accounts);
        else cout << "Account not found." << endl;
    }

    void check_balance() {
        cout << "Enter your account number: ";
        int acc_no = get_int_input();

        vector<Account> accounts = load_accounts();
        bool found = false;
        for (const auto& acc : accounts) {
            if (acc.acc_no == acc_no) {
                cout << fixed << setprecision(2);
                cout << "\nYour current balance is Rs." << acc.balance << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Account not found." << endl;
    }

    vector<Account> load_accounts() {
        vector<Account> accounts;
        ifstream file(ACCOUNT_FILE);
        string line;
        while (getline(file, line)) {
            if (!line.empty())
                accounts.push_back(Account::deserialize(line));
        }
        return accounts;
    }

    void save_accounts(const vector<Account>& accounts) {
        ofstream file(ACCOUNT_FILE, ios::trunc);
        for (const auto& acc : accounts)
            file << acc.serialize() << endl;
    }
};

int main() {
    Bank bank;
    bank.run();
    return 0;
}
