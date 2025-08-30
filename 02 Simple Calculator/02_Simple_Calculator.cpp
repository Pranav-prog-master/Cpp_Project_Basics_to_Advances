#include <iostream>
#include <cmath>
#include <limits> 
using namespace std;

class Calculator {
public:
    void run() {
        int choice;
        do {
            print_menu();
            choice = get_menu_choice();

            if (choice == 7) {
                break;
            }

            if (choice < 1 || choice > 7) {
                cerr << "Invalid Menu Choice." << endl;
                continue;
            }

            double first = get_number("Please enter the first number: ");
            double second = get_number("Now, enter the second number: ");
            double result = 0.0;
            bool calculation_valid = true;

            switch (choice) {
                case 1: // Add
                    result = first + second;
                    break;
                case 2: // Subtract
                    result = first - second;
                    break;
                case 3: // Multiply
                    result = first * second;
                    break;
                case 4: // Divide
                    if (second == 0) {
                        cerr << "Error: Cannot divide by zero." << endl;
                        calculation_valid = false;
                    } else {
                        result = first / second;
                    }
                    break;
                case 5: // Modulus
                    if (static_cast<int>(second) == 0) {
                        cerr << "Error: Cannot perform modulus by zero." << endl;
                        calculation_valid = false;
                    } else {
                        result = fmod(first, second);
                    }
                    break;
                case 6: // Power
                    result = pow(first, second);
                    break;
            }

            if (calculation_valid) {
                cout << "\nResult of operation is: " << result << endl;
            }

        } while (choice != 7);
         cout << "\nCalculator is exiting. Goodbye!" << endl;
    }

private:
    void print_menu() {
        cout << "\n\n---------------------------------" << endl;
        cout << "Welcome to Simple Calculator" << endl;
        cout << "\nChoose one of the following options:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Power" << endl;
        cout << "7. Exit" << endl;
        cout << "Now, enter your choice: ";
    }

    double get_number(const string& prompt) {
        double num;
        cout << prompt;
        while (!(cin >> num)) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        return num;
    }

    int get_menu_choice() {
        int choice;
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number for your choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return choice;
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}
