#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <limits>  
using namespace std;
int main() {
    srand(time(NULL));

    cout << "Welcome to the world of Guessing Numbers" << endl;
    int random = rand() % 100 + 1;
    int guess;
    int no_of_guess = 0;

    do {
        cout << "\nPlease enter your Guess between (1 to 100): ";
        
        while (!(std::cin >> guess)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        no_of_guess++;

        if (guess < random) {
            cout << "Guess a larger number." << endl;
        } else if (guess > random) {
            cout << "Guess a smaller number." << endl;
        } else {
            cout << "\nCongratulations!!! You have successfully guessed the Number in "
                      << no_of_guess << " attempts" << endl;
        }

    } while (guess != random);

    cout << "\nBye Bye, Thanks for Playing." << endl;
    cout << "Developed by: KGCoding" << endl;
    return 0;
}
