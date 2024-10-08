#include <iostream>
/*
  Sriram S
  Period 7
  Most logic from me, some logic like the drawing of the board and initalizing it I got help since I was struggling with that part
 */
using namespace std;


//Makes the tictactoe board, we can control lines and how it looks here, as well as set up the values on the sides
void drawBoard(char board[3][3]) {
    cout << "   1   2   3\n";
    cout << "A | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n";
    cout << "  -------------\n";
    cout << "B | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n";
    cout << "  -------------\n";
    cout << "C | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n";
}

//Checks for a win, for a row, column, and diagonal win
bool checkWin(char board[3][3], char player) {
    // row win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // column win
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // diagonal win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Checks for a tie, if there are no more moves left
bool checkTie(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Stuff left, not a tie
            }
        }
    }
    return true; // All spots are filled, it's a tie
}

// Function to get a valid player move
bool getMove(char board[3][3], char player, int& row, int& col) {
    char rowInput, colInput;
    while (true) {
        cout << "Player " << player << ", enter your move (e.g., A1): ";
        cin >> rowInput >> colInput;

        // Check if the input is valid
        if (rowInput >= 'A' && rowInput <= 'C' && colInput >= '1' && colInput <= '3') {
            row = rowInput - 'A'; // Convert A to 0, B to 1, C to 2
            col = colInput - '1'; // Convert 1 to 0, 2 to 1, 3 to 2
            if (board[row][col] == ' ') {
                return true; // Valid move
            } else {
                cout << "There's already something here. Try again.\n";
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
       
    }
}

int main() {
    int xWins = 0;
    int oWins = 0;

    while (true) {
        // Start the board
        char board[3][3] = {
            { ' ', ' ', ' ' },
            { ' ', ' ', ' ' },
            { ' ', ' ', ' ' }
        };
     
        char player = 'X'; // Always start with X, can be changed to O if someone wanted
        int turn = 0;

        cout << "\nNew Game!\n"; //Starts at the top of each board, since its a nice little visualiser

        // Game loop
        while (turn < 9) {
            drawBoard(board);

            int row, col;
            if (getMove(board, player, row, col)) {
                board[row][col] = player;
                turn++;

                // Check for win after each move
                if (checkWin(board, player)) {
                    drawBoard(board);
                    cout << "Player " << player << " wins!\n";
                    if (player == 'X') {
                        xWins++;
                    } else {
                        oWins++;
                    }
                    break;
                }

                // Check for tie after each move
                if (checkTie(board)) {
                    drawBoard(board);
                    cout << "It's a tie!\n";
                    break;
                }

                // Switch to the other player
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        // Print win stats
        cout << "X Wins: " << xWins << " | O Wins: " << oWins << endl;

        // Play again loop
        char playAgain;
        cout << "Play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y') { //if its not yes, exit the game loop, which will then go to the return
            cout << "X Wins: " << xWins << " | O Wins: " << oWins << endl;  //Print win stats before exiting, so you can see the final score
            break; // Exit the game loop
        }
    }

    return 0;
}
