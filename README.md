# Advanced C++ Tic-Tac-Toe Game

An advanced, feature-rich Tic-Tac-Toe game written in modern C++ with sophisticated AI and enhanced user experience.

## 🚀 Advanced Features

### 🤖 Intelligent AI System
- **Minimax Algorithm**: Implements the classic minimax algorithm with alpha-beta pruning for optimal play
- **Multiple Difficulty Levels**:
  - **Easy**: Random moves (perfect for beginners)
  - **Medium**: 70% optimal moves (balanced challenge)
  - **Hard**: 90% optimal moves (challenging gameplay)
  - **Expert**: Perfect play using full minimax (unbeatable)

### 🎮 Enhanced Gameplay
- **Player vs Computer**: Challenge the AI at different difficulty levels
- **Player vs Player**: Classic two-player mode
- **Move Highlighting**: Visual feedback showing the last move made
- **Input Validation**: Robust error handling for all user inputs
- **Cross-platform Compatibility**: Works on Windows, Linux, and macOS

### 📊 Game Statistics & Analytics
- **Win/Loss Tracking**: Comprehensive statistics for all games played
- **Win Percentage Calculation**: Real-time performance metrics
- **Session Duration**: Track how long you've been playing
- **Performance Rating**: Get rated based on your win percentage
- **AI Performance Metrics**: See how many nodes the AI evaluated

### 💻 Modern C++ Implementation
- **Object-Oriented Design**: Clean separation of concerns with proper encapsulation
- **Smart Pointers**: Memory-safe implementation using `std::unique_ptr`
- **STL Containers**: Efficient use of `std::vector` and other STL components
- **Modern C++14 Features**: Utilizes auto keyword, range-based loops, and more
- **Exception Safety**: Proper error handling throughout the application

### 🎨 Enhanced User Interface
- **Clean ASCII Art Board**: Beautiful game board representation
- **Colored Output**: Different colors for X and O (platform-dependent)
- **Intuitive Menu System**: Easy navigation through all game options
- **Thinking Animation**: Visual feedback when AI is calculating moves
- **Clear Instructions**: Built-in help system explaining all features

## 🛠️ Technical Improvements Over Original

### Code Quality
- **Memory Management**: No memory leaks with proper RAII principles
- **Const Correctness**: Proper use of const methods and parameters
- **Error Handling**: Comprehensive input validation and exception safety
- **Code Organization**: Modular design with separate classes for different responsibilities

### Algorithm Efficiency
- **Alpha-Beta Pruning**: Reduces search space by up to 50% in minimax algorithm
- **Depth-Limited Search**: Prevents infinite recursion with proper depth limits
- **Move Ordering**: Optimized move evaluation for better performance

### User Experience
- **Responsive Interface**: Immediate feedback for all user actions
- **Progress Indicators**: Visual cues during AI thinking process
- **Persistent Statistics**: Game data maintained throughout session
- **Flexible Gameplay**: Multiple game modes and difficulty options

## 🎯 How to Play

1. **Compile**: `g++ -std=c++14 -O2 -Wall TicTacToe.cpp -o TicTacToe`
2. **Run**: `./TicTacToe`
3. **Choose Mode**: Select Player vs Computer or Player vs Player
4. **Select Difficulty**: Choose AI difficulty level (Computer mode only)
5. **Make Moves**: Enter row and column numbers (1-3) to place your mark
6. **Win Condition**: Get three in a row horizontally, vertically, or diagonally

This advanced implementation transforms a simple Tic-Tac-Toe game into a showcase of modern C++ programming practices and game development techniques!
