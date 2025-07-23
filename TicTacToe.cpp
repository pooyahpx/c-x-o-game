/*--------
Advanced Tic-Tac-Toe Game
Features:
- Object-oriented design with proper encapsulation
- Minimax AI algorithm with alpha-beta pruning
- Multiple difficulty levels (Easy, Medium, Hard, Expert)
- Game statistics tracking with win percentages
- Modern C++ features (smart pointers, STL containers)
- Cross-platform compatibility
- Enhanced user interface
- Memory-safe implementation
- Error handling and input validation
--------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <memory>
#include <string>
#include <iomanip>
#include <random>
#include <chrono>
#include <cstdlib>
#include <thread>

// Cross-platform compatibility
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

// Game Statistics Class
class GameStats {
private:
    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;
    int totalGames = 0;
    std::chrono::steady_clock::time_point startTime;

public:
    void startGame() {
        startTime = std::chrono::steady_clock::now();
    }
    
    void recordResult(int winner) {
        totalGames++;
        switch(winner) {
            case 1: playerWins++; break;
            case 2: computerWins++; break;
            case 0: draws++; break;
        }
    }
    
    void displayStats() const {
        auto endTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
        
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "              GAME STATISTICS" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        std::cout << "Total Games Played: " << totalGames << std::endl;
        std::cout << "Player Wins: " << playerWins << " (" 
                  << std::fixed << std::setprecision(1)
                  << (totalGames > 0 ? (playerWins * 100.0 / totalGames) : 0) << "%)" << std::endl;
        std::cout << "Computer Wins: " << computerWins << " (" 
                  << (totalGames > 0 ? (computerWins * 100.0 / totalGames) : 0) << "%)" << std::endl;
        std::cout << "Draws: " << draws << " (" 
                  << (totalGames > 0 ? (draws * 100.0 / totalGames) : 0) << "%)" << std::endl;
        std::cout << "Session Duration: " << duration.count() << " seconds" << std::endl;
        
        if (totalGames > 0) {
            double winRate = (playerWins * 100.0 / totalGames);
            std::cout << "\nPerformance Rating: ";
            if (winRate >= 70) std::cout << "EXCELLENT!";
            else if (winRate >= 50) std::cout << "GOOD!";
            else if (winRate >= 30) std::cout << "FAIR";
            else std::cout << "NEEDS IMPROVEMENT";
            std::cout << std::endl;
        }
        std::cout << std::string(50, '=') << std::endl;
    }
    
    void reset() {
        playerWins = computerWins = draws = totalGames = 0;
    }
};

// Game Board Class
class TicTacToeBoard {
private:
    std::vector<std::vector<char>> board;
    static const int SIZE = 3;
    
public:
    TicTacToeBoard() : board(SIZE, std::vector<char>(SIZE, ' ')) {}
    
    void reset() {
        for (auto& row : board) {
            std::fill(row.begin(), row.end(), ' ');
        }
    }
    
    bool makeMove(int row, int col, char player) {
        if (isValidPosition(row, col) && board[row][col] == ' ') {
            board[row][col] = player;
            return true;
        }
        return false;
    }
    
    void undoMove(int row, int col) {
        if (isValidPosition(row, col)) {
            board[row][col] = ' ';
        }
    }
    
    char getCell(int row, int col) const {
        if (isValidPosition(row, col)) {
            return board[row][col];
        }
        return ' ';
    }
    
    bool isValidPosition(int row, int col) const {
        return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
    }
    
    bool isFull() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }
    
    std::vector<std::pair<int, int>> getEmptyCells() const {
        std::vector<std::pair<int, int>> emptyCells;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == ' ') {
                    emptyCells.emplace_back(i, j);
                }
            }
        }
        return emptyCells;
    }
    
    int checkWinner() const {
        // Check rows
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return (board[i][0] == 'X') ? 1 : 2;
            }
        }
        
        // Check columns
        for (int j = 0; j < SIZE; ++j) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return (board[0][j] == 'X') ? 1 : 2;
            }
        }
        
        // Check main diagonal
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return (board[0][0] == 'X') ? 1 : 2;
        }
        
        // Check anti-diagonal
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return (board[0][2] == 'X') ? 1 : 2;
        }
        
        // Check for draw
        if (isFull()) return 0;
        
        // Game continues
        return -1;
    }
    
    void display() const {
        std::cout << "\n     1   2   3" << std::endl;
        std::cout << "   +---+---+---+" << std::endl;
        
        for (int i = 0; i < SIZE; ++i) {
            std::cout << " " << (i + 1) << " |";
            for (int j = 0; j < SIZE; ++j) {
                char cell = board[i][j];
                std::cout << " " << cell << " |";
            }
            std::cout << std::endl;
            std::cout << "   +---+---+---+" << std::endl;
        }
        std::cout << std::endl;
    }
    
    void displayWithHighlight(int lastRow = -1, int lastCol = -1) const {
        std::cout << "\n     1   2   3" << std::endl;
        std::cout << "   +---+---+---+" << std::endl;
        
        for (int i = 0; i < SIZE; ++i) {
            std::cout << " " << (i + 1) << " |";
            for (int j = 0; j < SIZE; ++j) {
                char cell = board[i][j];
                if (i == lastRow && j == lastCol) {
                    std::cout << "[" << cell << "]";
                } else {
                    std::cout << " " << cell << " ";
                }
                std::cout << "|";
            }
            std::cout << std::endl;
            std::cout << "   +---+---+---+" << std::endl;
        }
        std::cout << std::endl;
    }
};

// AI Player Class with Minimax Algorithm
class AIPlayer {
private:
    enum Difficulty { EASY, MEDIUM, HARD, EXPERT };
    Difficulty difficulty;
    std::mt19937 rng;
    mutable int nodesEvaluated; // For performance tracking
    
    int minimax(TicTacToeBoard& board, int depth, bool isMaximizing, 
                int alpha = std::numeric_limits<int>::min(), 
                int beta = std::numeric_limits<int>::max()) const {
        nodesEvaluated++;
        int result = board.checkWinner();
        
        // Base cases with depth consideration for better play
        if (result == 2) return 10 - depth;  // AI wins (prefer quicker wins)
        if (result == 1) return depth - 10;  // Player wins (delay losses)
        if (result == 0 || depth >= 9) return 0;  // Draw or max depth
        
        if (isMaximizing) {
            int maxEval = std::numeric_limits<int>::min();
            auto emptyCells = board.getEmptyCells();
            
            for (const auto& cell : emptyCells) {
                board.makeMove(cell.first, cell.second, 'O');
                int eval = minimax(board, depth + 1, false, alpha, beta);
                board.undoMove(cell.first, cell.second);
                
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (beta <= alpha) break; // Alpha-beta pruning
            }
            return maxEval;
        } else {
            int minEval = std::numeric_limits<int>::max();
            auto emptyCells = board.getEmptyCells();
            
            for (const auto& cell : emptyCells) {
                board.makeMove(cell.first, cell.second, 'X');
                int eval = minimax(board, depth + 1, true, alpha, beta);
                board.undoMove(cell.first, cell.second);
                
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (beta <= alpha) break; // Alpha-beta pruning
            }
            return minEval;
        }
    }
    
    std::pair<int, int> getBestMove(TicTacToeBoard& board) const {
        auto emptyCells = board.getEmptyCells();
        if (emptyCells.empty()) return {-1, -1};
        
        nodesEvaluated = 0;
        int bestScore = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = emptyCells[0];
        
        for (const auto& cell : emptyCells) {
            board.makeMove(cell.first, cell.second, 'O');
            int score = minimax(board, 0, false);
            board.undoMove(cell.first, cell.second);
            
            if (score > bestScore) {
                bestScore = score;
                bestMove = cell;
            }
        }
        
        return bestMove;
    }
    
    std::pair<int, int> getRandomMove(TicTacToeBoard& board) const {
        auto emptyCells = board.getEmptyCells();
        if (emptyCells.empty()) return {-1, -1};
        
        std::uniform_int_distribution<> dis(0, emptyCells.size() - 1);
        return emptyCells[dis(const_cast<std::mt19937&>(rng))];
    }
    
    std::pair<int, int> getMediumMove(TicTacToeBoard& board) const {
        // 70% chance for best move, 30% for random
        std::uniform_int_distribution<> dis(1, 100);
        if (dis(const_cast<std::mt19937&>(rng)) <= 70) {
            return getBestMove(board);
        } else {
            return getRandomMove(board);
        }
    }
    
    std::pair<int, int> getHardMove(TicTacToeBoard& board) const {
        // 90% chance for best move, 10% for random
        std::uniform_int_distribution<> dis(1, 100);
        if (dis(const_cast<std::mt19937&>(rng)) <= 90) {
            return getBestMove(board);
        } else {
            return getRandomMove(board);
        }
    }
    
public:
    AIPlayer(int difficultyLevel) : rng(std::chrono::steady_clock::now().time_since_epoch().count()),
        nodesEvaluated(0) {
        switch (difficultyLevel) {
            case 1: difficulty = EASY; break;
            case 2: difficulty = MEDIUM; break;
            case 3: difficulty = HARD; break;
            case 4: difficulty = EXPERT; break;
            default: difficulty = MEDIUM; break;
        }
    }
    
    std::pair<int, int> makeMove(TicTacToeBoard& board) const {
        switch (difficulty) {
            case EASY: return getRandomMove(board);
            case MEDIUM: return getMediumMove(board);
            case HARD: return getHardMove(board);
            case EXPERT: return getBestMove(board);
            default: return getBestMove(board);
        }
    }
    
    std::string getDifficultyName() const {
        switch (difficulty) {
            case EASY: return "Easy (Random)";
            case MEDIUM: return "Medium (70% Optimal)";
            case HARD: return "Hard (90% Optimal)";
            case EXPERT: return "Expert (Perfect Play)";
            default: return "Unknown";
        }
    }
    
    int getNodesEvaluated() const { return nodesEvaluated; }
};

// Main Game Class
class TicTacToeGame {
private:
    TicTacToeBoard board;
    std::unique_ptr<AIPlayer> ai;
    GameStats stats;
    bool isPlayerVsPlayer;
    std::pair<int, int> lastMove;
    
    void clearScreen() const {
        system(CLEAR_SCREEN);
    }
    
    void displayTitle() const {
        std::cout << std::string(60, '=') << std::endl;
        std::cout << "              ADVANCED TIC-TAC-TOE GAME" << std::endl;
        std::cout << "           Featuring Minimax AI Algorithm" << std::endl;
        std::cout << std::string(60, '=') << std::endl;
    }
    
    void displayMenu() const {
        std::cout << "\nGAME MENU:" << std::endl;
        std::cout << "1. Player vs Computer" << std::endl;
        std::cout << "2. Player vs Player" << std::endl;
        std::cout << "3. View Statistics" << std::endl;
        std::cout << "4. Reset Statistics" << std::endl;
        std::cout << "5. How to Play" << std::endl;
        std::cout << "6. Exit Game" << std::endl;
    }
    
    void displayInstructions() const {
        clearScreen();
        displayTitle();
        std::cout << "\nHOW TO PLAY:" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        std::cout << "* Enter row and column numbers (1-3) to make your move" << std::endl;
        std::cout << "* Player 1 uses 'X', Player 2/Computer uses 'O'" << std::endl;
        std::cout << "* Get three in a row (horizontal, vertical, or diagonal) to win!" << std::endl;
        std::cout << "* If all spaces are filled with no winner, it's a draw" << std::endl;
        std::cout << "\nAI DIFFICULTY LEVELS:" << std::endl;
        std::cout << "* Easy: Random moves (good for beginners)" << std::endl;
        std::cout << "* Medium: 70% optimal moves (balanced challenge)" << std::endl;
        std::cout << "* Hard: 90% optimal moves (challenging)" << std::endl;
        std::cout << "* Expert: Perfect play using Minimax algorithm (unbeatable)" << std::endl;
        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }
    
    int getPlayerChoice(const std::string& prompt, int min, int max) {
        int choice;
        while (true) {
            std::cout << prompt;
            if (std::cin >> choice && choice >= min && choice <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            } else {
                std::cout << "Invalid input! Please enter a number between " 
                          << min << " and " << max << "." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
    std::pair<int, int> getPlayerMove(const std::string& playerName) {
        int row, col;
        while (true) {
            std::cout << playerName << ", enter your move (row column): ";
            if (std::cin >> row >> col) {
                row--; col--; // Convert to 0-based indexing
                if (board.isValidPosition(row, col)) {
                    if (board.getCell(row, col) == ' ') {
                        return {row, col};
                    } else {
                        std::cout << "That position is already taken! Try again." << std::endl;
                    }
                } else {
                    std::cout << "Invalid position! Use numbers 1-3 for both row and column." << std::endl;
                }
            } else {
                std::cout << "Invalid input! Please enter two numbers separated by space." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
    void displayGameResult(int winner) {
        clearScreen();
        displayTitle();
        board.displayWithHighlight(lastMove.first, lastMove.second);
        
        std::cout << std::string(60, '-') << std::endl;
        switch (winner) {
            case 1:
                std::cout << "CONGRATULATIONS! Player 1 (X) wins!" << std::endl;
                break;
            case 2:
                if (isPlayerVsPlayer) {
                    std::cout << "CONGRATULATIONS! Player 2 (O) wins!" << std::endl;
                } else {
                    std::cout << "Computer wins! The AI was too strong this time!" << std::endl;
                    if (ai) {
                        std::cout << "Nodes evaluated by AI: " << ai->getNodesEvaluated() << std::endl;
                    }
                }
                break;
            case 0:
                std::cout << "It's a draw! Great game, well played by both sides!" << std::endl;
                break;
        }
        std::cout << std::string(60, '-') << std::endl;
        
        stats.recordResult(winner);
    }
    
    void setupComputerGame() {
        isPlayerVsPlayer = false;
        clearScreen();
        displayTitle();
        
        std::cout << "\nSELECT AI DIFFICULTY LEVEL:" << std::endl;
        std::cout << "1. Easy (Random moves - Good for beginners)" << std::endl;
        std::cout << "2. Medium (70% optimal - Balanced challenge)" << std::endl;
        std::cout << "3. Hard (90% optimal - Challenging)" << std::endl;
        std::cout << "4. Expert (Perfect play - Unbeatable)" << std::endl;
        
        int difficulty = getPlayerChoice("\nEnter difficulty level (1-4): ", 1, 4);
        ai = std::make_unique<AIPlayer>(difficulty);
        
        std::cout << "\nDifficulty set to: " << ai->getDifficultyName() << std::endl;
        std::cout << "You are 'X', Computer is 'O'" << std::endl;
        std::cout << "Try to get three in a row to win!" << std::endl;
        std::cout << "\nPress Enter to start the game...";
        std::cin.get();
    }
    
    void playGame() {
        board.reset();
        lastMove = {-1, -1};
        bool isPlayerTurn = true;
        int currentPlayer = 1; // 1 for X, 2 for O
        
        while (true) {
            clearScreen();
            displayTitle();
            
            if (!isPlayerVsPlayer && ai) {
                std::cout << "AI Difficulty: " << ai->getDifficultyName() << std::endl;
            }
            
            if (lastMove.first != -1) {
                board.displayWithHighlight(lastMove.first, lastMove.second);
            } else {
                board.display();
            }
            
            int winner = board.checkWinner();
            if (winner != -1) {
                displayGameResult(winner);
                std::cout << "\nPress Enter to return to menu...";
                std::cin.get();
                return;
            }
            
            if (isPlayerVsPlayer) {
                std::string playerName = "Player " + std::to_string(currentPlayer) + 
                                       " (" + (currentPlayer == 1 ? "X" : "O") + ")";
                auto move = getPlayerMove(playerName);
                board.makeMove(move.first, move.second, currentPlayer == 1 ? 'X' : 'O');
                lastMove = move;
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            } else {
                if (isPlayerTurn) {
                    auto move = getPlayerMove("Your turn (X)");
                    board.makeMove(move.first, move.second, 'X');
                    lastMove = move;
                } else {
                    std::cout << "Computer is thinking";
                    // Add thinking animation
                    for (int i = 0; i < 3; ++i) {
                        std::cout << ".";
                        std::cout.flush();
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    }
                    
                    auto move = ai->makeMove(board);
                    if (move.first != -1 && move.second != -1) {
                        board.makeMove(move.first, move.second, 'O');
                        lastMove = move;
                        std::cout << "\nComputer chose position (" << (move.first + 1) 
                                  << ", " << (move.second + 1) << ")" << std::endl;
                        std::cout << "Press Enter to continue...";
                        std::cin.get();
                    }
                }
                isPlayerTurn = !isPlayerTurn;
            }
        }
    }
    
public:
    TicTacToeGame() : isPlayerVsPlayer(false), lastMove{-1, -1} {}
    
    void run() {
        stats.startGame();
        
        while (true) {
            clearScreen();
            displayTitle();
            displayMenu();
            
            int choice = getPlayerChoice("\nEnter your choice (1-6): ", 1, 6);
            
            switch (choice) {
                case 1:
                    setupComputerGame();
                    playGame();
                    break;
                case 2:
                    isPlayerVsPlayer = true;
                    ai.reset();
                    std::cout << "\nTwo-player mode selected!" << std::endl;
                    std::cout << "Player 1 is 'X', Player 2 is 'O'" << std::endl;
                    std::cout << "Press Enter to start...";
                    std::cin.get();
                    playGame();
                    break;
                case 3:
                    clearScreen();
                    displayTitle();
                    stats.displayStats();
                    std::cout << "\nPress Enter to continue...";
                    std::cin.get();
                    break;
                case 4:
                    stats.reset();
                    std::cout << "\nStatistics have been reset successfully!" << std::endl;
                    std::cout << "Press Enter to continue...";
                    std::cin.get();
                    break;
                case 5:
                    displayInstructions();
                    break;
                case 6:
                    clearScreen();
                    displayTitle();
                    stats.displayStats();
                    std::cout << "\nThank you for playing Advanced Tic-Tac-Toe!" << std::endl;
                    std::cout << "Powered by C++ with Minimax AI Algorithm" << std::endl;
                    std::cout << "Created with modern programming practices" << std::endl;
                    std::cout << "\nGoodbye!" << std::endl;
                    return;
            }
        }
    }
};

// Main Function
int main() {
    try {
        TicTacToeGame game;
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
        std::cerr << "Please restart the application." << std::endl;
        return 1;
    }
    
    return 0;
}
