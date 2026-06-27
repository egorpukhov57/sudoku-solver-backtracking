# Multi-Language Sudoku Solver (Backtracking Algorithm)

A robust and efficient application designed to solve any valid 9x9 Sudoku puzzle using the **Recursive Backtracking** approach. This repository features implementations in both **Python** and **C++** to demonstrate algorithm cross-compatibility and performance optimization.

## 🚀 Features
* **Guaranteed Solutions:** Solves standard 9x9 puzzles, from simple to expert+ difficulty levels.
* **Backtracking Paradigm:** Utilizes a depth-first search approach to systematically find solutions and backtrack upon hitting constraints.
* **Multi-Language Support:** Includes a clean Python script for readability and a high-performance C++ implementation.

## 🧠 How It Works
1. **Find Empty Cell:** The algorithm scans the grid for an unassigned cell (represented by `0`).
2. **Generate Candidates:** It identifies valid numbers (1-9) based on row, column, and 3x3 sub-grid rules.
3. **Recursive Trial:** It tentatively places a valid number and recursively attempts to solve the rest of the grid.
4. **Backtrack:** If a conflict arises down the line, the algorithm erases the choice and tries the next candidate.

## 💻 Tech Stack & Concepts
* **Languages:** Python 3.x, C++11 (or higher)
* **Concepts:** Recursion, Backtracking, Constraint Satisfaction, Matrices

## 🔧 Installation & Usage

### Python Version
```bash
python solver.py
```

### C++ Version
Compile and run using any standard C++ compiler (e.g., g++):
```bash
g++ -O3 solver.cpp -o solver
./solver
```

### Input Format
Enter 9 rows of numbers separated by spaces. Use `0` for empty cells.
