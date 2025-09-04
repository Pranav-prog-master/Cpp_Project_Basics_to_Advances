#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

class registration {
protected:
    int who;
    int l_no = 0;
    char name[100];
    int registration_no;
    int hostel_no;
    int room_no;
    char block;
    long int mobile_no;
    int password;

public:
    // A function to get the laundry number
    int get_l_no() const {
        return l_no;
    }

    // A function to check credentials
    bool check_credentials(int num, int pin) const {
        return (l_no == num && password == pin);
    }

    void input() {
        cout << "enter the following details for registration\n";
        cout << "Press 1 If you are Student\n";
        cout << "Press 2 If you are Laundry Man\n";
        cin >> who;

        if (who == 1) {
            cout << "Registration No.: ";
            cin >> registration_no;
            cout << "\nStudent Name: ";
            cin.ignore(); 
            cin.getline(name, 99);
            cout << "\nHostel_no.: ";
            cin >> hostel_no;
            cout << "\nBlock Code: ";
            cin >> block;
            cout << "\nRoom No.: ";
            cin >> room_no;
            cout << "\nMobile No.: ";
            cin >> mobile_no;
        }
    }

    void get_register() {
        registration r1;
        int last_r = 0; 
        fstream book;

        // Open file to read the last record
        book.open("laundary_book", ios::in | ios::binary);
        if (book) { 
            book.seekg(-sizeof(registration), ios::end); 
            book.read((char*)&r1, sizeof(r1));
            last_r = r1.l_no;
            book.close();
        }

        l_no = last_r + 1; 

        // Open file in append mode to write the new record
        book.open("laundary_book", ios::app | ios::binary);
        book.write((char*)this, sizeof(*this));
        book.close();

        cout << "Congratulations!! You are successfully registered.\n";
        cout << "Your laundry number is " << l_no << ". Please do not forget it.\n";
    }

    void set_pass() {
        int repin;
        cout << "\nPlease set a strong password to protect your Laundry Account.\n";
        cout << "Your laundry number will be your user name.\n";
        
        do {
            cout << "Password: ";
            cin >> password;
            cout << "\nConfirm Password: ";
            cin >> repin;
            if (password != repin) {
                cout << "\nPasswords do not match. Please try again.\n";
            }
        } while (password != repin);

        cout << "\nYour Password was saved successfully.\n";
    }
};

class login {
private:
    int pin;
    int lnumber;

public:
    login() {
        cout << "Welcome Back\nPlease Enter the required credentials";
        cout << "\nLaundry Number: ";
        cin >> lnumber;
        cout << "\nPassword: ";
        cin >> pin;
    }

    // This function now returns true on success and false on failure
    bool check() {
        registration r;
        fstream check_book;
        check_book.open("laundary_book", ios::in | ios::binary);

        if (!check_book) {
            cout << "Error: Cannot open registration file. No users registered yet.\n";
            return false;
        }

        // Read each registration object from the file
        while (check_book.read((char*)&r, sizeof(r))) {
            if (r.check_credentials(lnumber, pin)) {
                cout << "\nLogin Successful!\n";
                check_book.close();
                return true;
            }
        }

        // If the loop finishes, the user was not found
        cout << "\nLogin Failed: Invalid Laundry Number or Password.\n";
        check_book.close();
        return false;
    }
};

int main() {
    int x;
    cout << "Welcome To Laundry Management System\n";
    cout << "Press 1 for Login\n";
    cout << "Press 2 for Registration\n";
    cin >> x;

    if (x == 1) { // Login
        login user_login;
        user_login.check();
    } else if (x == 2) { // Registration
        registration s1;
        s1.input();
        s1.set_pass(); 
        s1.get_register();
    } else {
        cout << "Invalid option selected.\n";
    }

    return 0;
}