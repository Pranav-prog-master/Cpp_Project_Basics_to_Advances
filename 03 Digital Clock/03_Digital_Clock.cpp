#include <iostream>
#include <string>
#include <chrono>   
#include <iomanip>  
#include <limits>   

#ifdef _WIN32
    #include <windows.h> 
#else
    #include <unistd.h>  
#endif

using namespace std;

class DigitalClock {
public:
    void run() {
        int format = input_format();
        
        while (true) {
            auto now = chrono::system_clock::now();
            time_t current_time_t = chrono::system_clock::to_time_t(now);

            tm timeinfo = *localtime(&current_time_t);

            clear_screen();
            
            cout << "Current Time: ";
            if (format == 1) {
                cout << put_time(&timeinfo, "%H:%M:%S") << endl;
            } else {
                cout << put_time(&timeinfo, "%I:%M:%S %p") << endl;
            }

            cout << "Date: " << put_time(&timeinfo, "%A, %B %d, %Y") << endl;

            #ifdef _WIN32
                Sleep(1000); // Windows takes milliseconds
            #else
                sleep(1);    // Linux/macOS takes seconds
            #endif
        }
    }

private:
    void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

        int input_format() {
        int format;
        cout << "\nChoose the time format:" << endl;
        cout << "1. 24 Hour format" << endl;
        cout << "2. 12 Hour format (default)" << endl;
        cout << "Make a choice (1/2): ";
        
        while (!(cin >> format) || (format != 1 && format != 2)) {
            cout << "Invalid input. Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return format;
    }
};

int main() {
    DigitalClock clock;
    clock.run();
    return 0;
}