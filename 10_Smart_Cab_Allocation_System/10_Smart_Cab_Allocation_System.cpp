#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Hash function must be declared before its use in classes
unsigned long hash_password(const string& str) {
    unsigned long hash = 5381;
    for (char c : str)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

struct Location {
    double x = 0, y = 0;
    Location(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Cab {
    int cabId;
    Location location;
    bool available;
    Cab(int id = 0, double x = 0, double y = 0)
        : cabId(id), location(x, y), available(true) {}
};

struct UserCredential {
    string username;
    unsigned long hashedPassword;
    UserCredential(const string& u, unsigned long h) : username(u), hashedPassword(h) {}
};

class UserManager {
public:
    vector<UserCredential> users;

    void registerUser(const string& username, const string& password) {
        users.push_back(UserCredential(username, hash_password(password)));
        cout << "\nUser registered successfully!" << endl;
    }

    bool authenticate(const string& username, const string& password) {
        unsigned long hashedPassword = hash_password(password);
        for (const auto& user : users)
            if (user.username == username && user.hashedPassword == hashedPassword)
                return true;
        return false;
    }
};

struct User {
    string name;
    string password;
};

class Admin {
public:
    string username, password;
    vector<Cab> cabs;

    Admin() : username("admin"), password("admin123") {}

    bool isAuthorized(const string& enteredName, const string& enteredPassword) {
        return username == enteredName && password == enteredPassword;
    }

    void addCab(const Cab& cab) {
        cabs.push_back(cab);
        cout << "Cab added successfully!" << endl;
    }
};

struct SmartCabAllocSystem {
    UserManager user_manager;
    Admin admin;
    User current_user;
    bool is_admin_logged_in = false;

    void clean_input_buffer() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void system_init() {
        user_manager = UserManager();
        admin = Admin();
        current_user = User();
        is_admin_logged_in = false;
    }

    void system_home() {
        int main_option;
        cout << "Welcome to Smart Cab Allocation System\n";
        cout << "Enter one from below:\n\t1. Admin login\n\t2. User login/register\n\t-1. Exit from the system\n:";
        cin >> main_option;
        clean_input_buffer();
        switch (main_option) {
            case 1:
                system_admin_route();
                break;
            case 2:
                system_user_route();
                break;
            case -1:
                cout << "Exiting system. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    void system_get_started() {
        system_init();
        while (true) {
            system_home();
            if (is_admin_logged_in) {
                system_admin_functionality();
            } else if (!current_user.name.empty()) {
                system_user_functionality();
            }
        }
    }

    void system_admin_route() {
        string username, password;
        cout << "Admin please authenticate yourself first\n";
        cout << "\nEnter your username:\t";
        getline(cin, username);
        cout << "Enter your password:\t";
        getline(cin, password);

        if (admin.isAuthorized(username, password)) {
            cout << "\nWelcome Admin!\n";
            is_admin_logged_in = true;
        } else {
            cout << "\nAdmin login failed. Please retry.\n";
            is_admin_logged_in = false;
        }
    }

    void system_user_route() {
        int option = 0;
        while (option != -1) {
            cout << "\nPlease choose an option:\n\t1. Register\n\t2. Login\n\t-1. Back to main menu\n:";
            cin >> option;
            clean_input_buffer();
            if (option == 1) {
                system_register_util();
            } else if (option == 2) {
                system_login_util();
                if (!current_user.name.empty())
                    break;
            } else if (option == -1) {
                cout << "\nReturning to the main menu...\n";
            } else {
                cout << "Invalid option. Please try again.\n";
            }
        }
    }

    void system_login_util() {
        string username, password;
        cout << "\nEnter your username:\t";
        getline(cin, username);
        cout << "Enter your password:\t";
        getline(cin, password);

        if (user_manager.authenticate(username, password)) {
            cout << "\nAuthentication successful!\n";
            current_user.name = username;
        } else {
            cout << "\nAuthentication failed. Please register first or check your credentials.\n";
            current_user.name.clear();
        }
    }

    void system_register_util() {
        string username, password;
        cout << "\nEnter a username:\t";
        getline(cin, username);
        cout << "Enter a password:\t";
        getline(cin, password);
        user_manager.registerUser(username, password);
        cout << "Now login to access our features.\n";
    }

    void system_admin_functionality() {
        int option = 0;
        while (option != -1) {
            cout << "\nAdmin Menu:\n\t1. Add Cab\n\t2. Get all cabs details\n\t-1. Logout\n:";
            cin >> option;
            clean_input_buffer();
            if (option == 1) {
                int id;
                double x, y;
                cout << "Enter the cab id:\t";
                cin >> id;
                cout << "Enter the cab location (x y):\t";
                cin >> x >> y;
                clean_input_buffer();
                admin.addCab(Cab(id, x, y));
            } else if (option == 2) {
                if (admin.cabs.empty()) {
                    cout << "No cabs in the system yet.\n";
                } else {
                    cout << "List of all cabs:\n";
                    for (const auto& cab : admin.cabs) {
                        cout << "Cab ID: " << cab.cabId
                             << ", Location: (" << cab.location.x << ", " << cab.location.y << ")"
                             << ", Available: " << (cab.available ? "Yes" : "No") << endl;
                    }
                }
            } else if (option == -1) {
                is_admin_logged_in = false;
                cout << "Admin logged out.\n";
            } else {
                cout << "Invalid option.\n";
            }
        }
    }

    void system_user_functionality() {
        cout << "\nWelcome " << current_user.name << "! Hope you like our services.\n";
        cout << "(User functionality is not yet implemented.)\n";
        cout << "Logging out...\n\n";
        current_user.name.clear();
    }
};

int main() {
    SmartCabAllocSystem system;
    system.system_get_started();
    return 0;
}
