#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime> 

#ifdef _WIN32
    #include <windows.h> 
#else
    #include <unistd.h>  
#endif

using namespace std;

const int BAR_LENGTH = 20;
const int MAX_TASKS = 10;

class Task {
public:
    int id;
    int progress;
    int step;

    Task(int taskId) : id(taskId), progress(0) {
        step = rand() % 5 + 1;
    }

    void update() {
        if (progress < 100) {
            progress += step;
            if (progress > 100) {
                progress = 100;
            }
        }
    }

    bool is_complete() const {
        return progress >= 100;
    }
};

class ProgressBarManager {
private:
    vector<Task> tasks;

    void print_bar(const Task& task) {
        int bars_to_show = (task.progress * BAR_LENGTH) / 100;
        cout << "Task " << task.id << ": [";
        for (int i = 0; i < BAR_LENGTH; ++i) {
            cout << (i < bars_to_show ? "=" : " ");
        }
        cout << "] " << task.progress << "%" << endl;
    }

    void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

public:
    ProgressBarManager() {
        srand(time(NULL));
        for (int i = 0; i < MAX_TASKS; ++i) {
            tasks.emplace_back(i + 1);
        }
    }

    void run() {
        bool all_tasks_complete = false;
        while (!all_tasks_complete) {
            all_tasks_complete = true;
            clear_screen();
            
            for (auto& task : tasks) {
                task.update();
                print_bar(task);
                if (!task.is_complete()) {
                    all_tasks_complete = false;
                }
            }
            
            #ifdef _WIN32
                Sleep(1000); // Sleep on Windows takes milliseconds
            #else
                sleep(1);    // sleep on Linux/macOS takes seconds
            #endif
        }
        cout << "\nAll tasks completed!" << endl;
    }
};

int main() {
    ProgressBarManager manager;
    manager.run();
    return 0;
}
