#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>  // for numeric_limits

using namespace std; // helps make it so you do not have to type std every time

// define the array for the 3x3 board
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player;  // initialize the player. Player will eventually choose X or O
char computer; // initialize the computer

// define function to draw the board
void drawBoard() {
    cout << "  1 2 3\n";  
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";  // print the row number on the left (1, 2, 3)
        for (int j = 0; j < 3; j++) {
            cout << board[i][j]; 
            if (j < 2) cout << "|"; // vertical divider between columns
        }
        cout << "\n";
        if (i < 2) cout << "  -----\n"; // horizontal divider between rows
    }
}

// define winner function - char c is the parameter that is replaced with either the argument player or CPU whichever is true
bool isWinner(char c) { 
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
            return true;  // returns winner
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c) {
            return true; // returns winner
        }
    }
    // check diagonals
    if ((board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
        (board[0][2] == c && board[1][1] == c && board[2][0] == c)) {
        return true; // returns winner
    }
    return false;  // if no winner, then condition is false
}

// if there are blanks on the board, then the function is false and exits, otherwise if not, then the function is true and exits.
bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // if there are blanks on the board then this condition is false
            }
        }
    }
    return true;  // if no blanks or empty spaces then the condition is returned true
}

// define function for player move
void playerMove() {
    int row, col;
    while (true) {
        cout << "Enter row and column (e.g., 1 3): ";
        
        if (!(cin >> row >> col)) {
            // Clear the error flag and ignore invalid input
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // numeric_limits is a template in C++ that provides info of fundamental types like int, double, char.  ::max() says to ignore everything up to the new line.
            cout << "Invalid input. Please enter two numbers between 1 and 3.\n";
            continue;
        }

        // Check if the move is within the valid range (1 to 3) and the chosen cell is empty
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

// define function for CPU move
void computerMove() {
    int row, col;
    do {
        row = rand() % 3;  // Random number between 0 and 2
        col = rand() % 3;  // Random number between 0 and 2
    } while (board[row][col] != ' ');  // keep trying until an empty spot is found
    board[row][col] = computer;
}

// initialize the game
void initializeGame() {
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Choose your symbol (X or O): ";
    cin >> player;
    player = toupper(player); // converts lowercase entry to uppercase, this ensures the input is uppercase

    while (player != 'X' && player != 'O') {
        cout << "Invalid choice. Please choose X or O: ";
        cin >> player;
        player = toupper(player);
    }

    computer = (player == 'X') ? 'O' : 'X';
    cout << "You are " << player << " and the computer is " << computer << ".\n\n";
}

// main game loop
int main() {
    srand(time(0)); // seed random number generator
    initializeGame();

    while (true) { // loop will run until game ends - every move, this while loop is checked.
        drawBoard();  // displays the current board
        playerMove(); // gets the player's move

        if (isWinner(player)) { // checks if player won
            drawBoard();
            cout << "You win!\n";
            break;
        }

        if (isBoardFull()) { // checks if board is full
            drawBoard();
            cout << "It's a draw!\n";  // if true, then it is a draw and loop breaks
            break;
        }

        computerMove(); // gets the computer move
        if (isWinner(computer)) { // checks if computer won
            drawBoard();
            cout << "Computer wins!\n";
            break;
        }

        if (isBoardFull()) {  // checks if the board is full
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
