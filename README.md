# 🧠 DAY-01 :-  Sharp Creativity Puzzle: The Guessing Game 🎮

Welcome to a classic game Feeling bored? Need a quick mental reset? Welcome to the Guessing Game, a simple yet powerful puzzle designed to sharpen your creativity and bring a moment of calm focus to your day. This isn't just code; it's a challenge to your intuition.

---

## 🌟 About The Game

This project is a simple yet engaging number guessing game written in C. The computer thinks of a random number between 1 and 100, and your challenge is to guess it in the fewest attempts possible. With each guess, the program will guide you, telling you whether your guess is too high or too low.
It's a perfect little puzzle to take a break, reset your focus, and enjoy a moment of simple, creative problem-solving.

---

## 🚀 How to Play

1.  **Run the program.**
2.  You'll be prompted to enter a guess between 1 and 100.
3.  The program will give you a hint:
    - `Guess a larger number.`
    - `Guess a smaller number.`
4.  Use the hints to narrow down your next guess.
5.  Keep guessing until you find the correct number! The game will celebrate your victory and tell you how many attempts it took.

---

## 🔧 How to Compile and Run

This project is written in C and can be compiled with any standard C compiler like GCC.

1.  **Save the code** into a file named `guessing_game.c`.
2.  **Open your terminal** or command prompt.
3.  **Navigate to the directory** where you saved the file.
4.  **Compile the code** using the following command:
    ```bash
    g++ guessing_game.c -o guessing_game
    ```
5.  **Run the executable**:
    -   On Windows: `.\guessing_game.exe`
    -   On Linux/macOS: `./guessing_game`

Enjoy the puzzle!


---

# 🧠 DAY-02 :- Simple Console Calculator
A classic, straightforward console calculator built to demonstrate fundamental programming principles in different languages. This project provides a clean, easy-to-understand implementation of basic arithmetic operations.

---

## 🌟 About This Project
This repository contains the source code for a simple command-line calculator. The goal is to perform basic math functions like addition, subtraction, multiplication, and division. It's an excellent project for beginners to understand core programming concepts like user input, control flow, and functions.

---

## ✨ Features
- User-Friendly Interface: A simple menu-driven system for easy operation.
- Core Arithmetic Operations: Supports addition, subtraction, multiplication, and division.
- Error Handling: Includes basic checks, such as for division by zero.
- Cross-Platform: Designed to be compiled and run on any system with a standard compiler.

---

## 🚀 Versions
This project is available in three different programming languages:

**C++ Version** : The C++ version introduces object-oriented principles. The logic is encapsulated within a Calculator class, and it uses C++ streams (iostream) for input and output, showcasing a more modern approach to the same problem.

---

## 🔧 How to Run
Please refer to the source code file for your language of choice for specific compilation and execution instructions.
For C: g++ 02_Simple_Calculator.cpp -o clock && ./clock

---


# 🧠 DAY-03 :- Digital Clock Console Application
A classic and elegant digital clock implemented in the console. This project demonstrates the fundamentals of time handling and continuous updates in three different programming languages in C. 

---

## 🌟 About This Project
This repository contains a simple yet functional digital clock that displays the current time and date directly in your terminal. The clock updates every second, providing a live feed of the current time. It's an excellent project for understanding time libraries, loops, and cross-platform console manipulation.

---

## ✨ Features
- Real-Time Display: Shows the current time, updating every second.
- Date Display: Shows the current date, including the day of the week.
- Customizable Time Format: Users can choose between 12-hour (AM/PM) and 24-hour formats at the start.
- Cross-Platform: Designed to run on both Windows and UNIX-like systems (Linux, macOS).

---

## 🚀 Versions
This project is available in three different programming languages, each showcasing a unique approach:

**C++ Version** : A lightweight and efficient implementation using a procedural approach. It relies on the standard <time.h> library for all time-related functions and uses conditional compilation for cross-platform compatibility.

---

## 🔧 How to Run
For each version, you will need the appropriate compiler (GCC for C/C++, JDK for Java). You can compile and run the source file from your terminal.
For C++: g++ 03_DigitalClock.cpp -o clock && ./clock


---


# 🧠 DAY-04: Terminal Progress Bar

A simple yet visually satisfying terminal-based progress bar implemented in **Cpp**. This project demonstrates how to update console output dynamically and is perfect for learning about loops, formatting, and time delays across languages.

---

## 🌟 About This Project

This repository contains source code for a basic progress bar that updates in real-time on the terminal. It’s designed to help beginners understand how to manipulate console output and simulate task progress in different programming environments.

---

## ✨ Features

- Dynamic Console Output: Real-time progress updates using loops and formatted strings  
- Adjustable Speed: Delay intervals can be modified to simulate different task durations  
- Cross-Language Comparison: See how similar logic is implemented in C, C++, and Java  
- Minimal Dependencies: Uses only standard libraries for portability and simplicity  

---

## 🚀 Versions

**C++ Version** : Leverages `iostream`, `thread`, and `chrono` for clean, modern C++ implementation with string manipulation.

---

## 🔧 How to Run

Refer to the source code files for each language. Below are sample compilation and execution commands:
For Cpp: g++ 04_Progress.c -o progress && ./progress


---


# 🧠 DAY-05 :- Console-Based User Management System
A robust, cross-platform User Management System designed to demonstrate core principles of data handling, security, and user interaction in different programming languages.

---

## 🌟 About This Project
This repository contains the source code for a console-based application that allows users to register and log in. It features a secure, in-memory database and a clean, interactive interface. A key feature is the cross-platform password masking, which hides user input for enhanced security on any operating system.

---

## ✨ Features
- User Registration: Allows new users to create an account.
- User Login: Authenticates existing users with their credentials.
- Password Masking: Hides password input for security (e.g., shows * instead of characters).
- Cross-Platform: The C and C++ versions are designed with conditional compilation to run seamlessly on Windows, macOS, and Linux.

---

## 🚀 Versions
This project is available in three different programming languages, each showcasing a unique approach to solving the same problem.

**C++ Version** - This version introduces object-oriented programming by encapsulating logic within User and UserManager classes. It leverages C++ features like the string and vector classes for safer and more modern code, while maintaining cross-platform compatibility.

---

## 🔧 How to Run

Refer to the source code files for each language. Below are sample compilation and execution commands:
For Cpp : g++ 05_user_management.c -o user_management && ./user_management


---


# 🧠 DAY-06 :- Console Bank Management System
A comprehensive, console-based banking application built to demonstrate fundamental and advanced programming concepts across Cpp. This project simulates the core functionalities of a bank account management system, focusing on data persistence, user interaction, and robust error handling.

---

## 🌟 About This Project
This repository contains the source code for a fully functional Bank Management System. The application allows users to create new bank accounts, deposit money, withdraw funds, and check their account balance. All user data is persistently stored, ensuring that information is saved between sessions. It's an excellent project for showcasing skills in file handling, data structures, and object-oriented programming.

---

## ✨ Features
- Account Creation: Users can create a new bank account with their name and a unique account number.
- Deposit & Withdrawal: Perform deposits and withdrawals, with the system updating the account balance accordingly.
- Balance Inquiry: Check the current balance of any existing account.
- Persistent Data: All account information is saved to a local file, so data is never lost.
- Robust Error Handling: The system includes checks for invalid input, insufficient funds, and non-existent accounts.

---

## 🚀 Versions
This project is available in three powerful languages, each showcasing a different programming paradigm:

**C++ Version** - The C++ version refactors the C code into a modern, object-oriented structure. The logic is encapsulated within Account and Bank classes, and it uses C++ file streams (fstream) for more robust and type-safe file handling.

---

## 🔧 How to Run

Please refer to the source code file for your language of choice for specific compilation and execution instructions.
For Cpp : g++ 06_Bank_Management_System.c -o Bank_Management_System && ./Bank_Management_System


---


# 🧠 DAY-07 :- Sudoku Solver
A classic Sudoku puzzle solver built to demonstrate the power of the backtracking algorithm. This project, available in C++, takes a hardcoded 9x9 Sudoku puzzle with empty cells (represented by 0) and efficiently finds the solution.

---

## 🌟 About This Project
This repository contains the source code for a console-based Sudoku solver. The goal is to showcase a practical implementation of a recursive, depth-first search algorithm to solve a complex logic puzzle. It's an excellent project for demonstrating an understanding of algorithms, recursion, and multi-dimensional arrays.

---

## ✨ Features
- Backtracking Algorithm: Implements the highly efficient backtracking algorithm to explore all possible solutions without brute-forcing every combination.
- Clear Console Output: The program prints both the initial unsolved puzzle and the final solved version in a clean, easy-to-read grid format.
- Validation Logic: Includes robust logic to check if a move is valid according to the rules of Sudoku (no repeated numbers in any row, column, or 3x3 subgrid).
- Solvability Check: Determines whether a given puzzle is solvable and reports back if no solution exists.

---

## 🚀 Versions
This project is available in three languages, each highlighting a different approach to solving the same problem:

**C++ Version** - The C++ version refactors the logic into a modern, object-oriented structure. The puzzle board and solving algorithm are encapsulated within a SudokuSolver class, demonstrating strong OOP principles.

---

## 🔧 How to Run
Please refer to the source code file for your language of choice for specific compilation and execution instructions. The puzzle is hardcoded into the source for simplicity.
For Cpp : g++ 07_Sudoku_Solver.c -o 07_Sudoku_Solver && ./07_Sudoku_Solver


---


# 🧠 DAY-08 :- Console Tic-Tac-Toe Game
A classic Tic-Tac-Toe game where you can challenge an AI opponent. This project, available in C++, is a perfect demonstration of game loop mechanics, 2D array manipulation, and fundamental AI logic.

---

## 🌟 About This Project
This repository contains the source code for a console-based Tic-Tac-Toe game. The goal is to create a fully playable game against a computer opponent with varying difficulty levels. It's an excellent project for showcasing skills in procedural and object-oriented programming, logical thinking, and basic algorithm design.

---

## ✨ Features
- Interactive Gameplay: Play a full game of Tic-Tac-Toe directly in your console.
- Intelligent AI Opponent: The computer player uses a strategic algorithm to block wins and secure its own, making it a challenging opponent.
- Selectable Difficulty: Choose between a standard mode and a "God Mode" where the AI is unbeatable.
- Clear Console Display: The game board is printed in a clean, easy-to-read format after every turn.
- Score Tracking: The game keeps track of wins, losses, and draws across multiple rounds.

---

## 🚀 Versions
This project is available in three languages, each offering a unique perspective on building the same game:

**C++ Version** - The C++ version refactors the logic into a modern, object-oriented structure. The game board, player logic, and AI are encapsulated within a TicTacToe class, demonstrating strong OOP principles and the use of the C++ Standard Library.

## 🔧 How to Run
Please refer to the source code file for your language of choice for specific compilation and execution instructions. 
For Cpp : g++ tic-tac-toe.cpp -o tic-tac-toe && ./tic-tac-toe


---


# 🧠 DAY-09 :- Laundry Management System
A straightforward and efficient console-based application designed to manage laundry service registrations and logins. This project, available in C, C++, and Java, showcases how to handle user data, perform file operations, and structure a practical application.

---

## 🌟 About This Project
This repository contains the source code for a console-based laundry management system. The primary goal is to provide a simple interface for users (students or laundry staff) to register for the service and log in to their accounts. It's an excellent project for demonstrating skills in data persistence, user input handling, and both procedural and object-oriented programming.

---

## ✨ Features
- User Registration: Allows new users to create an account by providing their details, which are then saved to a file.
- User Login: Authenticates existing users by checking their credentials against the saved records.
- Data Persistence: All user registration data is saved to a binary file (laundry_book.dat), ensuring that information is retained between sessions.
- Clear Console Interface: A simple and intuitive menu-driven interface for easy navigation and use.

---

## 🚀 Versions
This project is available in three languages, each offering a unique perspective on building the same application:

**C++ Version** - The C++ version refactors the logic into a modern, object-oriented structure. The user data and operations are encapsulated within Registration and Login classes, and it uses C++ file streams (fstream) for more robust data handling.

---

## 🔧 How to Run
Please refer to the source code file for your language of choice for specific compilation and execution instructions.
For Cpp : g++ Laundry-Management-System.cpp -o Laundry-Management-System && ./Laundry-Management-System


---