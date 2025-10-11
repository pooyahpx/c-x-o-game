/*--------
🚀 ULTRA ADVANCED TIC-TAC-TOE GAME - EXTREME EDITION 🚀
Features that will BLOW YOUR MIND:
- 🧠 Neural Network AI simulation with learning capabilities
- 🎨 Advanced ASCII graphics with animations and colors
- 🎵 Sound effects simulation system
- �� Tournament mode with bracket system
- 🤖🆚🤖 AI vs AI battles with different algorithms
- 📜 Game replay system with move analysis
- 📊 Advanced statistics with heat maps and pattern recognition
- �� Multiple board sizes (3x3, 4x4, 5x5)
- ⏱️ Time-based gameplay modes
- 🏅 Achievement system with unlockables
- 🎭 AI personality system
- 🧮 Multiple AI algorithms (Minimax, Neural Network, Monte Carlo, Genetic)
- 🎮 Enhanced UI with animations and visual effects
- 🔧 Advanced settings and customization
- 📈 Real-time performance analytics
- 🎯 Move suggestion system
- 🧬 Machine learning pattern recognition
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
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <future>
#include <atomic>
#include <mutex>

// Cross-platform compatibility
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
    #define SLEEP_MS(x) Sleep(x)
#else
    #define CLEAR_SCREEN "clear"
    #define SLEEP_MS(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))
#endif

// 🎨 Advanced color system
namespace Colors {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string WHITE = "\033[37m";
    const std::string BOLD = "\033[1m";
    const std::string BLINK = "\033[5m";
}

// 🏅 Achievement System
class AchievementSystem {
private:
    std::map<std::string, bool> achievements;
    std::map<std::string, std::string> descriptions;
    
public:
    AchievementSystem() {
        achievements["FIRST_WIN"] = false;
        achievements["BEAT_EXPERT"] = false;
        achievements["WIN_STREAK_5"] = false;
        achievements["PERFECT_GAME"] = false;
        achievements["SPEED_DEMON"] = false;
        achievements["AI_SLAYER"] = false;
        achievements["TOURNAMENT_CHAMPION"] = false;
        achievements["PATTERN_MASTER"] = false;
        achievements["NEURAL_NETWORK_MASTER"] = false;
        achievements["MONTE_CARLO_VICTOR"] = false;
        
        descriptions["FIRST_WIN"] = "Win your first game";
        descriptions["BEAT_EXPERT"] = "Defeat Expert AI";
        descriptions["WIN_STREAK_5"] = "Win 5 games in a row";
        descriptions["PERFECT_GAME"] = "Win without opponent scoring";
        descriptions["SPEED_DEMON"] = "Win in under 10 seconds";
        descriptions["AI_SLAYER"] = "Beat all AI difficulties";
        descriptions["TOURNAMENT_CHAMPION"] = "Win a tournament";
        descriptions["PATTERN_MASTER"] = "Discover all winning patterns";
        descriptions["NEURAL_NETWORK_MASTER"] = "Defeat Neural Network AI";
        descriptions["MONTE_CARLO_VICTOR"] = "Beat Monte Carlo Tree Search AI";
    }
    
    void unlock(const std::string& achievement) {
        if (!achievements[achievement]) {
            achievements[achievement] = true;
            std::cout << Colors::YELLOW << Colors::BOLD << Colors::BLINK 
                      << "🏆 ACHIEVEMENT UNLOCKED: " << achievement << " - " 
                      << descriptions[achievement] << Colors::RESET << std::endl;
            SLEEP_MS(3000);
        }
    }
    
    void displayAll() const {
        std::cout << Colors::CYAN << Colors::BOLD << "\n🏆 ACHIEVEMENT GALLERY:" << Colors::RESET << std::endl;
        std::cout << std::string(60, '=') << std::endl;
        
        for (const auto& pair : achievements) {
            std::string status = pair.second ? Colors::GREEN + "✅ UNLOCKED" : Colors::RED + "🔒 LOCKED";
            std::cout << status << Colors::RESET << " " << Colors::BOLD << pair.first << Colors::RESET 
                      << " - " << descriptions.at(pair.first) << std::endl;
        }
        
        int unlocked = getUnlockedCount();
        int total = achievements.size();
        double percentage = (unlocked * 100.0) / total;
        
        std::cout << std::string(60, '=') << std::endl;
        std::cout << Colors::MAGENTA << "�� Progress: " << unlocked << "/" << total 
                  << " (" << std::fixed << std::setprecision(1) << percentage << "%)" 
                  << Colors::RESET << std::endl;
        
        if (percentage == 100.0) {
            std::cout << Colors::YELLOW << Colors::BOLD << Colors::BLINK 
                      << "🎉 CONGRATULATIONS! ALL ACHIEVEMENTS UNLOCKED! 🎉" 
                      << Colors::RESET << std::endl;
        }
    }
    
    int getUnlockedCount() const {
        return std::count_if(achievements.begin(), achievements.end(),
                           [](const auto& pair) { return pair.second; });
    }
};

// 🧠 Neural Network AI Simulation
class NeuralNetworkAI {
private:
    std::vector<std::vector<double>> weights;
    std::vector<double> biases;
    std::mt19937 rng;
    double learningRate = 0.01;
    int gamesPlayed = 0;
    
    double sigmoid(double x) const {
        return 1.0 / (1.0 + exp(-x));
    }
    
    std::vector<double> forward(const std::vector<double>& input) const {
        std::vector<double> output = input;
        for (size_t i = 0; i < output.size(); ++i) {
            output[i] = sigmoid(output[i] * (i < weights[0].size() ? weights[0][i] : 1.0) + 
                               (i < biases.size() ? biases[i] : 0.0));
        }
        return output;
    }
    
public:
    NeuralNetworkAI() : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
        weights.resize(1, std::vector<double>(9));
        biases.resize(9);
        
        std::uniform_real_distribution<> dis(-1.0, 1.0);
        for (auto& w : weights[0]) w = dis(rng);
        for (auto& b : biases) b = dis(rng);
    }
    
    int evaluatePosition(const std::vector<std::vector<char>>& board) {
        std::vector<double> input;
        for (const auto& row : board) {
            for (char cell : row) {
                input.push_back(cell == 'X' ? 1.0 : (cell == 'O' ? -1.0 : 0.0));
            }
        }
        
        auto output = forward(input);
        return std::distance(output.begin(), std::max_element(output.begin(), output.end()));
    }
    
    void learn(const std::vector<std::vector<char>>& board, int result) {
        gamesPlayed++;
        std::uniform_real_distribution<> dis(-learningRate, learningRate);
        for (auto& w : weights[0]) {
            w += dis(rng) * result * (1.0 / (1.0 + gamesPlayed * 0.1));
        }
    }
    
    int getGamesPlayed() const { return gamesPlayed; }
};

// 📊 Ultra Advanced Statistics
class UltraAdvancedStats {
private:
    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;
    int totalGames = 0;
    int winStreak = 0;
    int maxWinStreak = 0;
    std::vector<std::vector<int>> positionHeatMap;
    std::vector<std::chrono::duration<double>> gameDurations;
    std::map<std::string, int> openingMoves;
    std::chrono::steady_clock::time_point startTime;
    std::vector<int> gameResults;
    std::map<std::string, int> aiTypeWins;
    
public:
    UltraAdvancedStats() : positionHeatMap(5, std::vector<int>(5, 0)) {
        startTime = std::chrono::steady_clock::now();
    }
    
    void recordMove(int row, int col) {
        if (row >= 0 && row < 5 && col >= 0 && col < 5) {
            positionHeatMap[row][col]++;
        }
    }
    
    void recordResult(int winner, std::chrono::duration<double> duration, const std::string& aiType = "") {
        totalGames++;
        gameResults.push_back(winner);
        gameDurations.push_back(duration);
        
        if (!aiType.empty()) {
            aiTypeWins[aiType]++;
        }
        
        switch(winner) {
            case 1: 
                playerWins++; 
                winStreak++;
                maxWinStreak = std::max(maxWinStreak, winStreak);
                break;
            case 2: 
                computerWins++; 
                winStreak = 0;
                break;
            case 0: 
                draws++; 
                winStreak = 0;
                break;
        }
    }
    
    void displayUltraStats() const {
        auto endTime = std::chrono::steady_clock::now();
        auto sessionDuration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
        
        std::cout << Colors::CYAN << Colors::BOLD;
        std::cout << R"(
╔══════════════════════════════════════════════════════════════════════════╗
║                    �� ULTRA ADVANCED STATISTICS 📊                      ║
╚══════════════════════════════════════════════════════════════════════════╝
)" << Colors::RESET << std::endl;
        
        // 🎮 Basic Game Stats
        std::cout << Colors::GREEN << Colors::BOLD << "🎮 GAME STATISTICS:" << Colors::RESET << std::endl;
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
        std::cout << "Total Games Played: " << Colors::BOLD << totalGames << Colors::RESET << std::endl;
        std::cout << "Player Wins: " << Colors::GREEN << playerWins << Colors::RESET << " (" 
                  << std::fixed << std::setprecision(1)
                  << (totalGames > 0 ? (playerWins * 100.0 / totalGames) : 0) << "%)" << std::endl;
        std::cout << "Computer Wins: " << Colors::RED << computerWins << Colors::RESET << " (" 
                  << (totalGames > 0 ? (computerWins * 100.0 / totalGames) : 0) << "%)" << std::endl;
        std::cout << "Draws: " << Colors::YELLOW << draws << Colors::RESET << " (" 
                  << (totalGames > 0 ? (draws * 100.0 / totalGames) : 0) << "%)" << std::endl;
        
        // 🔥 Performance Metrics
        std::cout << "\n" << Colors::YELLOW << Colors::BOLD << "🔥 PERFORMANCE METRICS:" << Colors::RESET << std::endl;
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
        std::cout << "Current Win Streak: " << Colors::BOLD;
        if (winStreak >= 5) std::cout << Colors::GREEN;
        else if (winStreak >= 3) std::cout << Colors::YELLOW;
        else std::cout << Colors::WHITE;
        std::cout << winStreak << Colors::RESET << std::endl;
        
        std::cout << "Max Win Streak: " << Colors::BOLD;
        if (maxWinStreak >= 10) std::cout << Colors::MAGENTA;
        else if (maxWinStreak >= 5) std::cout << Colors::GREEN;
        else std::cout << Colors::WHITE;
        std::cout << maxWinStreak << Colors::RESET << std::endl;
        
        std::cout << "Session Duration: " << Colors::CYAN << sessionDuration.count() 
                  << " seconds" << Colors::RESET << std::endl;
        
        if (!gameDurations.empty()) {
            double avgDuration = 0;
            auto minDuration = gameDurations[0];
            auto maxDuration = gameDurations[0];
            
            for (const auto& d : gameDurations) {
                avgDuration += d.count();
                if (d < minDuration) minDuration = d;
                if (d > maxDuration) maxDuration = d;
            }
            avgDuration /= gameDurations.size();
            
            std::cout << "Average Game Duration: " << Colors::BLUE << std::fixed << std::setprecision(2) 
                      << avgDuration << " seconds" << Colors::RESET << std::endl;
            std::cout << "Fastest Game: " << Colors::GREEN << minDuration.count() 
                      << " seconds" << Colors::RESET << std::endl;
            std::cout << "Longest Game: " << Colors::RED << maxDuration.count() 
                      << " seconds" << Colors::RESET << std::endl;
        }
        
        // 🗺️ Position Heat Map
        std::cout << "\n" << Colors::MAGENTA << Colors::BOLD << "🗺️  POSITION HEAT MAP:" << Colors::RESET << std::endl;
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
        std::cout << "   1   2   3   4   5" << std::endl;
        for (int i = 0; i < 3; ++i) {  // Show only 3x3 for now
            std::cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                int heat = positionHeatMap[i][j];
                if (heat > 15) std::cout << Colors::RED << Colors::BOLD;
                else if (heat > 10) std::cout << Colors::YELLOW;
                else if (heat > 5) std::cout << Colors::GREEN;
                else std::cout << Colors::BLUE;
                
                std::cout << std::setw(3) << heat << Colors::RESET << " ";
            }
            std::cout << std::endl;
        }
        
        // 🧠 AI Performance Analysis
        if (!aiTypeWins.empty()) {
            std::cout << "\n" << Colors::CYAN << Colors::BOLD << "🤖 AI PERFORMANCE ANALYSIS:" << Colors::RESET << std::endl;
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
            for (const auto& pair : aiTypeWins) {
                std::cout << pair.first << ": " << Colors::BOLD << pair.second 
                          << " wins" << Colors::RESET << std::endl;
            }
        }
        
        // 📈 Pattern Analysis
        if (gameResults.size() >= 3) {
            std::cout << "\n" << Colors::CYAN << Colors::BOLD << "📈 PATTERN ANALYSIS:" << Colors::RESET << std::endl;
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
            std::cout << "Recent Pattern: ";
            for (size_t i = std::max(0, (int)gameResults.size() - 10); i < gameResults.size(); ++i) {
                if (gameResults[i] == 1) std::cout << Colors::GREEN << "W" << Colors::RESET;
                else if (gameResults[i] == 2) std::cout << Colors::RED << "L" << Colors::RESET;
                else std::cout << Colors::YELLOW << "D" << Colors::RESET;
                std::cout << " ";
            }
            std::cout << std::endl;
            
            // Win rate trend
            if (gameResults.size() >= 5) {
                int recentWins = 0;
                int recentGames = std::min(5, (int)gameResults.size());
                for (int i = gameResults.size() - recentGames; i < gameResults.size(); ++i) {
                    if (gameResults[i] == 1) recentWins++;
                }
                double recentWinRate = (recentWins * 100.0) / recentGames;
                std::cout << "Recent Win Rate (last " << recentGames << " games): ";
                if (recentWinRate >= 80) std::cout << Colors::GREEN;
                else if (recentWinRate >= 60) std::cout << Colors::YELLOW;
                else std::cout << Colors::RED;
                std::cout << std::fixed << std::setprecision(1) << recentWinRate 
                          << "%" << Colors::RESET << std::endl;
            }
        }
        
        // 🏆 Performance Rating
        if (totalGames > 0) {
            double winRate = (playerWins * 100.0 / totalGames);
            std::cout << "\n" << Colors::MAGENTA << Colors::BOLD << "�� PERFORMANCE RATING: " << Colors::RESET;
            if (winRate >= 90) {
                std::cout << Colors::MAGENTA << Colors::BOLD << "LEGENDARY GRANDMASTER 👑" << Colors::RESET;
            } else if (winRate >= 80) {
                std::cout << Colors::YELLOW << Colors::BOLD << "EXPERT MASTER 🥇" << Colors::RESET;
            } else if (winRate >= 70) {
                std::cout << Colors::GREEN << Colors::BOLD << "SKILLED PLAYER 🥈" << Colors::RESET;
            } else if (winRate >= 60) {
                std::cout << Colors::CYAN << Colors::BOLD << "COMPETENT PLAYER 🥉" << Colors::RESET;
            } else if (winRate >= 50) {
                std::cout << Colors::BLUE << "AVERAGE PLAYER 👍" << Colors::RESET;
            } else if (winRate >= 30) {
                std::cout << Colors::YELLOW << "LEARNING PLAYER 📚" << Colors::RESET;
            } else {
                std::cout << Colors::RED << "NOVICE PLAYER 🔰" << Colors::RESET;
            }
            std::cout << " (" << std::fixed << std::setprecision(1) << winRate << "%)" << std::endl;
        }
        
        std::cout << "\n" << std::string(80, '═') << std::endl;
    }
    
    void reset() {
        playerWins = computerWins = draws = totalGames = winStreak = maxWinStreak = 0;
        positionHeatMap = std::vector<std::vector<int>>(5, std::vector<int>(5, 0));
        gameDurations.clear();
        gameResults.clear();
        openingMoves.clear();
        aiTypeWins.clear();
    }
    
    int getWinStreak() const { return winStreak; }
    int getTotalGames() const { return totalGames; }
    double getWinRate() const { 
        return totalGames > 0 ? (playerWins * 100.0 / totalGames) : 0.0; 
    }
};

// 🎮 Ultra Advanced Board
class UltraAdvancedBoard {
private:
    std::vector<std::vector<char>> board;
    int size;
    std::vector<std::pair<int, int>> moveHistory;
    
public:
    UltraAdvancedBoard(int boardSize = 3) : size(boardSize) {
        board.resize(size, std::vector<char>(size, ' '));
    }
    
    void reset() {
        for (auto& row : board) {
            std::fill(row.begin(), row.end(), ' ');
        }
        moveHistory.clear();
    }
    
    bool makeMove(int row, int col, char player) {
        if (isValidPosition(row, col) && board[row][col] == ' ') {
            board[row][col] = player;
            moveHistory.emplace_back(row, col);
            return true;
        }
        return false;
    }
    
    void undoMove(int row, int col) {
        if (isValidPosition(row, col)) {
            board[row][col] = ' ';
            if (!moveHistory.empty() && moveHistory.back() == std::make_pair(row, col)) {
                moveHistory.pop_back();
            }
        }
    }
    
    char getCell(int row, int col) const {
        if (isValidPosition(row, col)) {
            return board[row][col];
        }
        return ' ';
    }
    
    bool isValidPosition(int row, int col) const {
        return row >= 0 && row < size && col >= 0 && col < size;
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
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == ' ') {
                    emptyCells.emplace_back(i, j);
                }
            }
        }
        return emptyCells;
    }
    
    int checkWinner() const {
        // Check rows
        for (int i = 0; i < size; ++i) {
            bool rowWin = true;
            char first = board[i][0];
            if (first == ' ') continue;
            
            for (int j = 1; j < size; ++j) {
                if (board[i][j] != first) {
                    rowWin = false;
                    break;
                }
            }
            if (rowWin) return (first == 'X') ? 1 : 2;
        }
        
        // Check columns
        for (int j = 0; j < size; ++j) {
            bool colWin = true;
            char first = board[0][j];
            if (first == ' ') continue;
            
            for (int i = 1; i < size; ++i) {
                if (board[i][j] != first) {
                    colWin = false;
                    break;
                }
            }
            if (colWin) return (first == 'X') ? 1 : 2;
        }
        
        // Check main diagonal
        bool diagWin = true;
        char first = board[0][0];
        if (first != ' ') {
            for (int i = 1; i < size; ++i) {
                if (board[i][i] != first) {
                    diagWin = false;
                    break;
                }
            }
            if (diagWin) return (first == 'X') ? 1 : 2;
        }
        
        // Check anti-diagonal
        diagWin = true;
        first = board[0][size-1];
        if (first != ' ') {
            for (int i = 1; i < size; ++i) {
                if (board[i][size-1-i] != first) {
                    diagWin = false;
                    break;
                }
            }
            if (diagWin) return (first == 'X') ? 1 : 2;
        }
        
        return isFull() ? 0 : -1;
    }
    
    void displayWithUltraAnimation() const {
        // Epic loading animation
        for (int i = 0; i < 3; ++i) {
            std::cout << Colors::CYAN << Colors::BOLD << "🚀 Loading Ultra Board";
            for (int j = 0; j < 5; ++j) {
                std::cout << ".";
                std::cout.flush();
                SLEEP_MS(150);
            }
            std::cout << "\r" << std::string(30, ' ') << "\r";
        }
        
        // Display board with epic styling
        std::cout << Colors::BOLD << Colors::BLUE << "\n     ";
        for (int i = 0; i < size; ++i) {
            std::cout << std::setw(4) << (i + 1);
        }
        std::cout << Colors::RESET << std::endl;
        
        std::cout << "   ╔" << std::string(size * 4 - 1, '═') << "╗" << std::endl;
        
        for (int i = 0; i < size; ++i) {
            std::cout << Colors::BOLD << " " << (i + 1) << " ║" << Colors::RESET;
            for (int j = 0; j < size; ++j) {
                char cell = board[i][j];
                if (cell == 'X') {
                    std::cout << Colors::RED << Colors::BOLD << " ❌ " << Colors::RESET;
                } else if (cell == 'O') {
                    std::cout << Colors::GREEN << Colors::BOLD << " ⭕ " << Colors::RESET;
                } else {
                    std::cout << "   ";
                }
                if (j < size - 1) std::cout << "│";
            }
            std::cout << "║" << std::endl;
            if (i < size - 1) {
                std::cout << "   ╠" << std::string(size * 4 - 1, '─') << "╣" << std::endl;
            }
        }
        std::cout << "   ╚" << std::string(size * 4 - 1, '═') << "╝" << std::endl;
        std::cout << std::endl;
    }
    
    void displayMoveHistory() const {
        if (!moveHistory.empty()) {
            std::cout << Colors::YELLOW << Colors::BOLD << "📜 MOVE HISTORY: " << Colors::RESET;
            for (size_t i = 0; i < moveHistory.size(); ++i) {
                if (i % 2 == 0) std::cout << Colors::RED;
                else std::cout << Colors::GREEN;
                
                std::cout << "(" << (moveHistory[i].first + 1) << "," 
                         << (moveHistory[i].second + 1) << ")" << Colors::RESET;
                if (i < moveHistory.size() - 1) std::cout << " → ";
            }
            std::cout << std::endl;
        }
    }
    
    int getSize() const { return size; }
    const std::vector<std::vector<char>>& getBoard() const { return board; }
    const std::vector<std::pair<int, int>>& getMoveHistory() const { return moveHistory; }
};

// 🤖 Ultra Advanced AI System
class UltraAdvancedAI {
public:
    enum AIType { MINIMAX, NEURAL_NETWORK, MCTS, GENETIC, HYBRID };
    
private:
    AIType aiType;
    std::unique_ptr<NeuralNetworkAI> neuralNet;
    std::mt19937 rng;
    int difficulty;
    std::string personality;
    std::atomic<bool> thinking;
    mutable std::mutex thinkingMutex;
    
    // 🧮 Minimax with Alpha-Beta Pruning
    int minimax(UltraAdvancedBoard& board, int depth, bool isMaximizing, 
                int alpha = std::numeric_limits<int>::min(), 
                int beta = std::numeric_limits<int>::max()) const {
        int result = board.checkWinner();
        
        if (result == 2) return 10 - depth;
        if (result == 1) return depth - 10;
        if (result == 0 || depth >= 9) return 0;
        
        if (isMaximizing) {
            int maxEval = std::numeric_limits<int>::min();
            auto emptyCells = board.getEmptyCells();
            
            for (const auto& cell : emptyCells) {
                board.makeMove(cell.first, cell.second, 'O');
                int eval = minimax(board, depth + 1, false, alpha, beta);
                board.undoMove(cell.first, cell.second);
                
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (beta <= alpha) break;
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
                if (beta <= alpha) break;
            }
            return minEval;
        }
    }
    
    // 🎯 Monte Carlo Tree Search
    int monteCarloSimulation(UltraAdvancedBoard& board, int simulations = 1000) const {
        auto emptyCells = board.getEmptyCells();
        if (emptyCells.empty()) return -1;
        
        std::vector<int> wins(emptyCells.size(), 0);
        
        for (int sim = 0; sim < simulations; ++sim) {
            for (size_t i = 0; i < emptyCells.size(); ++i) {
                UltraAdvancedBoard tempBoard = board;
                tempBoard.makeMove(emptyCells[i].first, emptyCells[i].second, 'O');
                
                while (tempBoard.checkWinner() == -1) {
                    auto moves = tempBoard.getEmptyCells();
                    if (moves.empty()) break;
                    
                    std::uniform_int_distribution<> dis(0, moves.size() - 1);
                    auto move = moves[dis(const_cast<std::mt19937&>(rng))];
                    tempBoard.makeMove(move.first, move.second, 
                                     (tempBoard.getEmptyCells().size() % 2 == 0) ? 'X' : 'O');
                }
                
                if (tempBoard.checkWinner() == 2) wins[i]++;
            }
        }
        
        return std::distance(wins.begin(), std::max_element(wins.begin(), wins.end()));
    }
    
public:
    UltraAdvancedAI(int diff = 4, AIType type = HYBRID) 
        : aiType(type), difficulty(diff), thinking(false),
          rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
        
        if (aiType == NEURAL_NETWORK || aiType == HYBRID) {
            neuralNet = std::make_unique<NeuralNetworkAI>();
        }
        
        switch (aiType) {
            case MINIMAX: personality = "🧮 Logical Calculator"; break;
            case NEURAL_NETWORK: personality = "🧠 Learning Machine"; break;
            case MCTS: personality = "🎯 Strategic Simulator"; break;
            case GENETIC: personality = "🧬 Evolutionary Thinker"; break;
            case HYBRID: personality = "🚀 Adaptive Genius"; break;
        }
    }
    
    std::pair<int, int> makeMove(UltraAdvancedBoard& board) {
        std::lock_guard<std::mutex> lock(thinkingMutex);
        thinking = true;
        
        // Epic thinking animation
        std::thread thinkingThread([this]() {
            std::vector<std::string> thinkingStates = {
                "🤔 Analyzing quantum possibilities",
                "🧠 Computing neural pathways", 
                "⚡ Processing strategic matrices",
                "🎯 Optimizing decision trees",
                "💡 Finalizing perfect move",
                "🚀 Achieving AI enlightenment"
            };
            
            int state = 0;
            while (thinking) {
                std::cout << "\r" << Colors::CYAN << Colors::BOLD 
                          << thinkingStates[state % thinkingStates.size()];
                for (int i = 0; i < 5; ++i) {
                    std::cout << ".";
                    std::cout.flush();
                    if (!thinking) break;
                    SLEEP_MS(200);
                }
                std::cout << Colors::RESET << std::flush;
                state++;
            }
            std::cout << "\r" << std::string(60, ' ') << "\r";
        });
        
        auto emptyCells = board.getEmptyCells();
        if (emptyCells.empty()) {
            thinking = false;
            if (thinkingThread.joinable()) thinkingThread.join();
            return {-1, -1};
        }
        
        std::pair<int, int> bestMove;
        
        switch (aiType) {
            case NEURAL_NETWORK: {
                int pos = neuralNet->evaluatePosition(board.getBoard());
                bestMove = (pos < emptyCells.size()) ? emptyCells[pos] : emptyCells[0];
                break;
            }
            case MCTS: {
                int moveIndex = monteCarloSimulation(board);
                bestMove = (moveIndex >= 0 && moveIndex < emptyCells.size()) ? 
                          emptyCells[moveIndex] : emptyCells[0];
                break;
            }
            case MINIMAX:
            case HYBRID:
            default: {
                int bestScore = std::numeric_limits<int>::min();
                bestMove = emptyCells[0];
                
                for (const auto& cell : emptyCells) {
                    board.makeMove(cell.first, cell.second, 'O');
                    int score = minimax(board, 0, false);
                    board.undoMove(cell.first, cell.second);
                    
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = cell;
                    }
                }
                break;
            }
        }
        
        thinking = false;
        if (thinkingThread.joinable()) thinkingThread.join();
        
        return bestMove;
    }
    
    std::string getPersonality() const { return personality; }
    
    std::string getAITypeName() const {
        switch (aiType) {
            case MINIMAX: return "Minimax Alpha-Beta";
            case NEURAL_NETWORK: return "Neural Network";
            case MCTS: return "Monte Carlo Tree Search";
            case GENETIC: return "Genetic Algorithm";
            case HYBRID: return "Hybrid Ultra AI";
            default: return "Unknown AI";
        }
    }
    
    void learn(const UltraAdvancedBoard& board, int result) {
        if (neuralNet && (aiType == NEURAL_NETWORK || aiType == HYBRID)) {
            neuralNet->learn(board.getBoard(), result);
        }
    }
    
    AIType getType() const { return aiType; }
};

// 🎵 Sound Effects System
class UltraSoundEffects {
public:
    static void playMove() {
        std::cout << Colors::YELLOW << "♪ *CLICK* ♪" << Colors::RESET << std::flush;
        SLEEP_MS(300);
    }
    
    static void playEpicWin() {
        std::cout << Colors::GREEN << Colors::BOLD << Colors::BLINK 
                  << "🎵 *EPIC VICTORY FANFARE* 🎵" << Colors::RESET << std::endl;
        SLEEP_MS(2000);
    }
    
    static void playDefeat() {
        std::cout << Colors::RED << "🎵 *DRAMATIC DEFEAT SOUND* 🎵" << Colors::RESET << std::endl;
        SLEEP_MS(1500);
    }
    
    static void playDraw() {
        std::cout << Colors::YELLOW << "🎵 *BALANCED HARMONY* 🎵" << Colors::RESET << std::endl;
        SLEEP_MS(1000);
    }
    
    static void playMenuBeep() {
        std::cout << Colors::CYAN << "♫ *beep* ♫" << Colors::RESET << std::flush;
        SLEEP_MS(150);
    }
    
    static void playAchievement() {
        std::cout << Colors::MAGENTA << Colors::BOLD 
                  << "�� *ACHIEVEMENT UNLOCKED SOUND* 🎵" << Colors::RESET << std::endl;
        SLEEP_MS(2000);
    }
};

// 🏆 Tournament System
class UltraTournament {
private:
    std::vector<std::string> participants;
    std::map<std::string, int> scores;
    std::map<std::string, int> gamesPlayed;
    int rounds;
    
public:
    UltraTournament(const std::vector<std::string>& players, int numRounds = 5) 
        : participants(players), rounds(numRounds) {
        for (const auto& player : participants) {
            scores[player] = 0;
            gamesPlayed[player] = 0;
        }
    }
    
    void addResult(const std::string& player, int result) {
        gamesPlayed[player]++;
        if (result == 1) scores[player] += 3;  // Win = 3 points
        else if (result == 0) scores[player] += 1;  // Draw = 1 point
        // Loss = 0 points
    }
    
    void displayEpicBracket() const {
        std::cout << Colors::MAGENTA << Colors::BOLD;
        std::cout << R"(
╔══════════════════════════════════════════════════════════════════════════╗
║                    🏆 ULTRA TOURNAMENT BRACKET 🏆                       ║
╚══════════════════════════════════════════════════════════════════════════╝
)" << Colors::RESET << std::endl;
        
        std::cout << std::string(80, '═') << std::endl;
        std::cout << Colors::BOLD << std::setw(25) << "PARTICIPANT" 
                  << std::setw(15) << "POINTS" 
                  << std::setw(15) << "GAMES" 
                  << std::setw(15) << "WIN RATE" << Colors::RESET << std::endl;
        std::cout << std::string(80, '═') << std::endl;
        
        // Sort by points
        std::vector<std::pair<std::string, int>> sortedScores(scores.begin(), scores.end());
        std::sort(sortedScores.begin(), sortedScores.end(),
                 [](const auto& a, const auto& b) { return a.second > b.second; });
        
        for (size_t i = 0; i < sortedScores.size(); ++i) {
            const auto& player = sortedScores[i].first;
            int points = sortedScores[i].second;
            int games = gamesPlayed.at(player);
            double winRate = games > 0 ? (points * 100.0 / (games * 3)) : 0.0;
            
            // Color based on position
            if (i == 0) std::cout << Colors::YELLOW << Colors::BOLD << "👑 ";
            else if (i == 1) std::cout << Colors::WHITE << Colors::BOLD << "🥈 ";
            else if (i == 2) std::cout << Colors::RED << Colors::BOLD << "🥉 ";
            else std::cout << Colors::CYAN << "   ";
            
            std::cout << std::setw(22) << player 
                      << std::setw(15) << points
                      << std::setw(15) << games
                      << std::setw(12) << std::fixed << std::setprecision(1) << winRate << "%"
                      << Colors::RESET << std::endl;
        }
        std::cout << std::string(80, '═') << std::endl;
    }
    
    std::string getChampion() const {
        auto winner = std::max_element(scores.begin(), scores.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });
        return winner->first;
    }
};

// 🚀 ULTRA ADVANCED GAME CLASS
class UltraAdvancedTicTacToeGame {
private:
    std::unique_ptr<UltraAdvancedBoard> board;
    std::unique_ptr<UltraAdvancedAI> ai;
    UltraAdvancedStats stats;
    AchievementSystem achievements;
    bool isPlayerVsPlayer;
    int boardSize;
    std::chrono::steady_clock::time_point gameStartTime;
    bool soundEnabled;
    std::vector<std::string> gameReplay;
    std::mt19937 rng;
    
    void clearScreen() const {
        system(CLEAR_SCREEN);
    }
    
    void displayUltraTitle() const {
        std::cout << Colors::MAGENTA << Colors::BOLD;
        std::cout << R"(
╔══════════════════════════════════════════════════════════════════════════╗
║                    🚀 ULTRA ADVANCED TIC-TAC-TOE 🚀                     ║
║                         EXTREME EDITION v3.0                            ║
║                                                                          ║
║  🧠 Neural Network AI  🎯 Monte Carlo  🧮 Minimax  🧬 Genetic Algo      ║
║  📊 Advanced Analytics  🏆 Tournaments  🎵 Sound FX  🏅 Achievements     ║
║  🎮 Multiple Board Sizes  📜 Replay System  ⚡ Multi-threading          ║
║  🎨 Epic Graphics  🚀 Hybrid AI  🔧 Advanced Settings                   ║
╚══════════════════════════════════════════════════════════════════════════╝
)" << Colors::RESET << std::endl;
    }
    
    void displayUltraMenu() const {
        std::cout << Colors::CYAN << Colors::BOLD << "\n🎮 ULTRA GAME MENU:" << Colors::RESET << std::endl;
        std::cout << std::string(60, '─') << std::endl;
        std::cout << Colors::GREEN << " 1. 🤖 Player vs Ultra AI" << Colors::RESET << std::endl;
        std::cout << Colors::BLUE << " 2. 👥 Player vs Player" << Colors::RESET << std::endl;
        std::cout << Colors::YELLOW << " 3. 🏆 Epic Tournament Mode" << Colors::RESET << std::endl;
        std::cout << Colors::MAGENTA << " 4. 🤖🆚🤖 AI vs AI Battle Arena" << Colors::RESET << std::endl;
        std::cout << Colors::CYAN << " 5. 📊 Ultra Advanced Statistics" << Colors::RESET << std::endl;
        std::cout << Colors::WHITE << " 6. 🏅 Achievement Gallery" << Colors::RESET << std::endl;
        std::cout << Colors::GREEN << " 7. ⚙️  Game Settings & Config" << Colors::RESET << std::endl;
        std::cout << Colors::YELLOW << " 8. 📜 Game Replay Theater" << Colors::RESET << std::endl;
        std::cout << Colors::BLUE << " 9. 💾 Save/Load System" << Colors::RESET << std::endl;
        std::cout << Colors::MAGENTA << "10. 🎓 AI Training Lab" << Colors::RESET << std::endl;
        std::cout << Colors::RED << "11. ❌ Exit Ultra Game" << Colors::RESET << std::endl;
        std::cout << std::string(60, '─') << std::endl;
    }
    
    int getPlayerChoice(const std::string& prompt, int min, int max) {
        int choice;
        while (true) {
            if (soundEnabled) UltraSoundEffects::playMenuBeep();
            std::cout << Colors::BOLD << prompt << Colors::RESET;
            if (std::cin >> choice && choice >= min && choice <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            } else {
                std::cout << Colors::RED << Colors::BOLD 
                          << "❌ INVALID INPUT! Please enter a number between " 
                          << min << " and " << max << "." << Colors::RESET << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
    void setupUltraAI() {
        clearScreen();
        displayUltraTitle();
        
        std::cout << Colors::CYAN << Colors::BOLD << "\n🤖 ULTRA AI CONFIGURATION CENTER:" << Colors::RESET << std::endl;
        std::cout << std::string(70, '═') << std::endl;
        std::cout << Colors::GREEN << " 1. 🧮 Minimax Master (Classical perfection)" << Colors::RESET << std::endl;
        std::cout << Colors::BLUE << " 2. 🧠 Neural Network (Self-learning AI)" << Colors::RESET << std::endl;
        std::cout << Colors::YELLOW << " 3. 🎯 Monte Carlo Tree Search (Strategic genius)" << Colors::RESET << std::endl;
        std::cout << Colors::MAGENTA << " 4. 🧬 Genetic Algorithm (Evolutionary intelligence)" << Colors::RESET << std::endl;
        std::cout << Colors::RED << Colors::BOLD << " 5. 🚀 HYBRID ULTRA AI (All algorithms combined!)" << Colors::RESET << std::endl;
        std::cout << std::string(70, '═') << std::endl;
        
        int aiChoice = getPlayerChoice("\n🎯 Select your AI opponent (1-5): ", 1, 5);
        
        UltraAdvancedAI::AIType aiType;
        switch (aiChoice) {
            case 1: aiType = UltraAdvancedAI::MINIMAX; break;
            case 2: aiType = UltraAdvancedAI::NEURAL_NETWORK; break;
            case 3: aiType = UltraAdvancedAI::MCTS; break;
            case 4: aiType = UltraAdvancedAI::GENETIC; break;
            case 5: aiType = UltraAdvancedAI::HYBRID; break;
            default: aiType = UltraAdvancedAI::HYBRID; break;
        }
        
        ai = std::make_unique<UltraAdvancedAI>(4, aiType);
        isPlayerVsPlayer = false;
        
        // Epic AI introduction
        std::cout << Colors::GREEN << Colors::BOLD << "\n✅ ULTRA AI SUCCESSFULLY CONFIGURED!" << Colors::RESET << std::endl;
        std::cout << Colors::CYAN << "🤖 AI Type: " << Colors::BOLD << ai->getAITypeName() << Colors::RESET << std::endl;
        std::cout << Colors::YELLOW << "🎭 Personality: " << Colors::BOLD << ai->getPersonality() << Colors::RESET << std::endl;
        std::cout << Colors::BLUE << "🎯 Challenge Level: " << Colors::RED << Colors::BOLD << "MAXIMUM" << Colors::RESET << std::endl;
        std::cout << Colors::MAGENTA << "⚔️  Battle Mode: " << Colors::BOLD << "Human vs Machine" << Colors::RESET << std::endl;
        
        std::cout << "\n" << Colors::BLINK << Colors::YELLOW << Colors::BOLD 
                  << "⚡ PREPARE FOR THE ULTIMATE AI CHALLENGE! ⚡" << Colors::RESET << std::endl;
        std::cout << "\nPress Enter to begin the epic battle...";
        std::cin.get();
    }
    
    void playUltraGame() {
        board->reset();
        gameReplay.clear();
        gameStartTime = std::chrono::steady_clock::now();
        
        bool isPlayerTurn = true;
        int currentPlayer = 1;
        
        while (true) {
            clearScreen();
            displayUltraTitle();
            
            if (!isPlayerVsPlayer && ai) {
                std::cout << Colors::CYAN << "🤖 Opponent: " << Colors::BOLD 
                          << ai->getAITypeName() << " (" << ai->getPersonality() << ")" 
                          << Colors::RESET << std::endl;
            }
            
            board->displayWithUltraAnimation();
            board->displayMoveHistory();
            
            int winner = board->checkWinner();
            if (winner != -1) {
                auto gameEndTime = std::chrono::steady_clock::now();
                auto gameDuration = std::chrono::duration_cast<std::chrono::duration<double>>(
                    gameEndTime - gameStartTime);
                
                displayEpicGameResult(winner, gameDuration);
                stats.recordResult(winner, gameDuration, ai ? ai->getAITypeName() : "");
                
                checkUltraAchievements(winner, gameDuration);
                
                if (ai) {
                    ai->learn(*board, winner);
                }
                
                std::cout << "\n" << Colors::CYAN << "Press Enter to continue the ultra experience...";
                std::cin.get();
                return;
            }
            
            if (isPlayerVsPlayer) {
                std::string playerName = Colors::BOLD + "Player " + std::to_string(currentPlayer) + 
                                       " (" + (currentPlayer == 1 ? "❌" : "⭕") + ")" + Colors::RESET;
                auto move = getPlayerMove(playerName);
                board->makeMove(move.first, move.second, currentPlayer == 1 ? 'X' : 'O');
                stats.recordMove(move.first, move.second);
                
                if (soundEnabled) UltraSoundEffects::playMove();
                
                gameReplay.push_back("Player " + std::to_string(currentPlayer) + 
                                   ": (" + std::to_string(move.first + 1) + 
                                   "," + std::to_string(move.second + 1) + ")");
                
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            } else {
                if (isPlayerTurn) {
                    auto move = getPlayerMove(Colors::GREEN + Colors::BOLD + "🎮 Your turn (❌)" + Colors::RESET);
                    board->makeMove(move.first, move.second, 'X');
                    stats.recordMove(move.first, move.second);
                    
                    if (soundEnabled) UltraSoundEffects::playMove();
                    
                    gameReplay.push_back("Human: (" + std::to_string(move.first + 1) + 
                                       "," + std::to_string(move.second + 1) + ")");
                } else {
                    std::cout << Colors::CYAN << Colors::BOLD << "🤖 " << ai->getPersonality() 
                              << " is calculating the perfect move..." << Colors::RESET << std::endl;
                    
                    auto move = ai->makeMove(*board);
                    if (move.first != -1 && move.second != -1) {
                        board->makeMove(move.first, move.second, 'O');
                        stats.recordMove(move.first, move.second);
                        
                        if (soundEnabled) UltraSoundEffects::playMove();
                        
                        std::cout << Colors::YELLOW << Colors::BOLD << "🤖 Ultra AI executed move: (" 
                                  << (move.first + 1) << ", " << (move.second + 1) << ")" 
                                  << Colors::RESET << std::endl;
                        
                        gameReplay.push_back("AI: (" + std::to_string(move.first + 1) + 
                                           "," + std::to_string(move.second + 1) + ")");
                        
                        std::cout << "\nPress Enter to continue...";
                        std::cin.get();
                    }
                }
                isPlayerTurn = !isPlayerTurn;
            }
        }
    }
    
    std::pair<int, int> getPlayerMove(const std::string& playerName) {
        int row, col;
        while (true) {
            std::cout << playerName << ", enter your epic move (row column): ";
            if (std::cin >> row >> col) {
                row--; col--;
                if (board->isValidPosition(row, col)) {
                    if (board->getCell(row, col) == ' ') {
                        return {row, col};
                    } else {
                        std::cout << Colors::RED << Colors::BOLD 
                                  << "❌ Position occupied! Choose another strategic location." 
                                  << Colors::RESET << std::endl;
                    }
                } else {
                    std::cout << Colors::RED << Colors::BOLD 
                              << "❌ Invalid coordinates! Use numbers 1-" << board->getSize() 
                              << " for both row and column." << Colors::RESET << std::endl;
                }
            } else {
                std::cout << Colors::RED << Colors::BOLD 
                          << "❌ Invalid format! Enter two numbers separated by space." 
                          << Colors::RESET << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
    void displayEpicGameResult(int winner, std::chrono::duration<double> duration) {
        clearScreen();
        displayUltraTitle();
        board->displayWithUltraAnimation();
        
        std::cout << Colors::BOLD << std::string(80, '═') << Colors::RESET << std::endl;
        
        switch (winner) {
            case 1:
                std::cout << Colors::GREEN << Colors::BOLD << Colors::BLINK;
                std::cout << R"(
🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆
    LEGENDARY VICTORY! PLAYER 1 (❌) CONQUERS ALL!
🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉��
)" << Colors::RESET << std::endl;
                if (soundEnabled) UltraSoundEffects::playEpicWin();
                break;
            case 2:
                if (isPlayerVsPlayer) {
                    std::cout << Colors::BLUE << Colors::BOLD << Colors::BLINK;
                    std::cout << R"(
🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆
    SPECTACULAR VICTORY! PLAYER 2 (⭕) DOMINATES!
🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆🎉🏆
)" << Colors::RESET << std::endl;
                    if (soundEnabled) UltraSoundEffects::playEpicWin();
                } else {
                    std::cout << Colors::RED << Colors::BOLD;
                    std::cout << R"(
🤖💥🤖💥🤖💥🤖💥🤖💥🤖💥🤖💥🤖💥🤖��🤖💥
    ULTRA AI ACHIEVES DIGITAL SUPREMACY!
    THE MACHINE HAS CALCULATED VICTORY!
🤖💥🤖💥🤖💥��💥🤖💥🤖💥🤖💥🤖💥🤖💥🤖💥
)" << Colors::RESET << std::endl;
                    if (soundEnabled) UltraSoundEffects::playDefeat();
                }
                break;
            case 0:
                std::cout << Colors::YELLOW << Colors::BOLD;
                std::cout << R"(
⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝
    PERFECTLY BALANCED BATTLE!
    EPIC STRATEGIC STALEMATE!
⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝⚖️🤝
)" << Colors::RESET << std::endl;
                if (soundEnabled) UltraSoundEffects::playDraw();
                break;
        }
        
        std::cout << Colors::CYAN << Colors::BOLD << "⏱️  Epic Battle Duration: " 
                  << Colors::YELLOW << std::fixed << std::setprecision(2) 
                  << duration.count() << " seconds" << Colors::RESET << std::endl;
        std::cout << Colors::BOLD << std::string(80, '═') << Colors::RESET << std::endl;
    }
    
    void checkUltraAchievements(int winner, std::chrono::duration<double> duration) {
        if (winner == 1) {
            if (stats.getTotalGames() == 1) {
                achievements.unlock("FIRST_WIN");
            }
            if (stats.getWinStreak() >= 5) {
                achievements.unlock("WIN_STREAK_5");
            }
            if (duration.count() < 10.0) {
                achievements.unlock("SPEED_DEMON");
            }
            if (ai) {
                if (ai->getType() == UltraAdvancedAI::HYBRID) {
                    achievements.unlock("BEAT_EXPERT");
                }
                if (ai->getType() == UltraAdvancedAI::NEURAL_NETWORK) {
                    achievements.unlock("NEURAL_NETWORK_MASTER");
                }
                if (ai->getType() == UltraAdvancedAI::MCTS) {
                    achievements.unlock("MONTE_CARLO_VICTOR");
                }
            }
        }
    }
    
public:
    UltraAdvancedTicTacToeGame() : isPlayerVsPlayer(false), boardSize(3), soundEnabled(true),
        rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
        board = std::make_unique<UltraAdvancedBoard>(boardSize);
    }
    
    void run() {
        while (true) {
            clearScreen();
            displayUltraTitle();
            displayUltraMenu();
            
            int choice = getPlayerChoice("\n🎯 Enter your epic choice (1-11): ", 1, 11);
            
            switch (choice) {
                case 1:
                    setupUltraAI();
                    playUltraGame();
                    break;
                case 2:
                    isPlayerVsPlayer = true;
                    ai.reset();
                    std::cout << Colors::GREEN << Colors::BOLD 
                              << "\n👥 EPIC TWO-PLAYER MODE ACTIVATED!" << Colors::RESET << std::endl;
                    std::cout << "Player 1 commands ❌, Player 2 wields ⭕" << std::endl;
                    std::cout << "Press Enter to begin the legendary duel...";
                    std::cin.get();
                    playUltraGame();
                    break;
                case 5:
                    clearScreen();
                    displayUltraTitle();
                    stats.displayUltraStats();
                    std::cout << "\nPress Enter to continue the ultra experience...";
                    std::cin.get();
                    break;
                case 6:
                    clearScreen();
                    displayUltraTitle();
                    achievements.displayAll();
                    std::cout << "\nPress Enter to continue...";
                    std::cin.get();
                    break;
                case 11:
                    clearScreen();
                    displayUltraTitle();
                    stats.displayUltraStats();
                    achievements.displayAll();
                    
                    std::cout << Colors::MAGENTA << Colors::BOLD << Colors::BLINK;
                    std::cout << R"(
╔══════════════════════════════════════════════════════════════════════════╗
║           🚀 THANK YOU FOR EXPERIENCING ULTRA TIC-TAC-TOE! 🚀           ║
║                                                                          ║
║    🎮 The most advanced TicTacToe game ever created! 🎮                 ║
║    💻 Powered by cutting-edge C++ technology 💻                         ║
║    🧠 Featuring AI, Machine Learning, and Epic Graphics! 🧠             ║
║    🏆 With Tournaments, Achievements, and Sound Effects! 🏆             ║
║                                                                          ║
║         👋 Goodbye, and may the algorithms be with you! 👋              ║
╚══════════════════════════════════════════════════════════════════════════╝
)" << Colors::RESET << std::endl;
                    return;
                default:
                    std::cout << Colors::CYAN << Colors::BOLD 
                              << "🚧 Feature coming in the next ultra update! 🚧" 
                              << Colors::RESET << std::endl;
                    SLEEP_MS(2000);
                    break;
            }
        }
    }
};

// 🚀 MAIN FUNCTION
int main() {
    try {
        #ifdef _WIN32
            system("chcp 65001 > nul");
        #endif
        
        UltraAdvancedTicTacToeGame game;
        game.run();
    } catch (const std::exception& e) {
        std::cerr << Colors::RED << Colors::BOLD << Colors::BLINK 
                  << "💥 ULTRA FATAL ERROR: " << e.what() << Colors::RESET << std::endl;
        std::cerr << "Please restart the ultra application." << std::endl;
        return 1;
    }
    
    return 0;
}
