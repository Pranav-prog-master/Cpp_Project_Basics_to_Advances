#include <iostream>
#include <string>
#include <vector>
#include <limits>

#ifdef _WIN32
    #include <conio.h> 
#else
    #include <unistd.h>
    #include <termios.h>
#endif

using namespace std;

const int MAX_USERS = 10;
const int CREDENTIAL_LENGTH = 30;

class User {
public:
    string username;
    string password;
};

class UserManager {
private:
    vector<User> users;

    string get_masked_password() {
        string pass = "";
        char ch;

#ifdef _WIN32
        while ((ch = _getch()) != '\r') { 
            if (ch == '\b') { 
                if (!pass.empty()) {
                    pass.pop_back();
                    cout << "\b \b"; 
                }
            } else {
                pass += ch;
                cout << "*";
            }
        }
#else
        // Change terminal properties for UNIX/Linux
        struct termios old_props, new_props;
        tcgetattr(STDIN_FILENO, &old_props);
        new_props = old_props;
        new_props.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_props);

        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch == '\b' || ch == 127) { 
                if (!pass.empty()) {
                    pass.pop_back();
                    cout << "\b \b";
                }
            } else {
                pass += ch;
                cout << "*";
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
#endif
        cout << endl;
        return pass;
    }

public:
    void run() {
        int option;
        while (true) {
            cout << "\nWelcome to User Management" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Select an option: ";

            while (!(cin >> option)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            switch (option) {
                case 1:
                    register_user();
                    break;
                case 2:
                    login_user();
                    break;
                case 3:
                    cout << "\nExiting Program." << endl;
                    return;
                default:
                    cout << "\nInvalid option. Please try again." << endl;
                    break;
            }
        }
    }

    void register_user() {
        if (users.size() >= MAX_USERS) {
            cout << "\nMaximum " << MAX_USERS << " users are supported! No more registrations allowed!" << endl;
            return;
        }

        User new_user;
        cout << "\nRegister a new user" << endl;
        cout << "Enter username: ";
        getline(cin, new_user.username);
        
        cout << "Enter password (masking enabled): ";
        new_user.password = get_masked_password();
        
        users.push_back(new_user);
        cout << "Registration successful!" << endl;
    }

    void login_user() {
        string username, password;
        cout << "\nEnter username: ";
        getline(cin, username);
        
        cout << "Enter password (masking enabled): ";
        password = get_masked_password();

        for (const auto& user : users) {
            if (user.username == username && user.password == password) {
                cout << "\nLogin successful! Welcome, " << user.username << "!" << endl;
                return;
            }
        }
        cout << "\nLogin failed! Incorrect username or password." << endl;
    }
};

int main() {
    UserManager manager;
    manager.run();
    return 0;
}
