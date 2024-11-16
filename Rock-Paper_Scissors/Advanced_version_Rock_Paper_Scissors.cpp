#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>  // Include string library for std::string

int main() {
    std::string playAgain; // String to store response to play again or not

    do {
        int user; // Setup user choice
        int computer;  // Setup CPU choice
        int userScore = 0; // Initialize user score to 0
        int computerScore = 0; // Initialize CPU score to 0

        std::cout << "====================\n";
        std::cout << "Welcome to Rock Paper Scissors!\n";
        std::cout << "If you wish to end the program, enter \"0\".\n";
        std::cout << "====================\n";

        // Seed the random number generator for computer choice
        std::srand(std::time(0));

        // Main game loop for best out of 3
        while (userScore < 2 && computerScore < 2) {

            // Prompt the user for input
            std::cout << "Enter your choice: \n";
            std::cout << "1 for Rock ✊\n";
            std::cout << "2 for Paper ✋\n";
            std::cout << "3 for Scissors ✌️\n";
            std::cout << "\n Type your choice and press enter: \n";

            // Check if the user entered something
            if (!(std::cin >> user)) {  // Check if input is valid
                std::cout << "====================\n";
                std::cout << "Invalid input! Please enter a number (0, 1, 2, or 3).\n";
                std::cout << "====================\n";
                std::cin.clear(); // Clear the error state
                std::cin.ignore(10000, '\n'); // clears invalid inputs up to 10000 characters up to the new line ensuring all characters are ignored 
                continue; // Skip this loop iteration
            }

            // Check if user enters invalid choice
            if (user != 0 && user != 1 && user != 2 && user != 3) {
                std::cout << "====================\n";
                std::cout << "Invalid choice. Please try again.\n";
                std::cout << "====================\n";
                continue; // Skip this loop iteration
            }

            // End program if 0 is entered
            if (user == 0) {
                std::cout << "You chose to exit the game. Goodbye!\n";
                return 0;  // Completely exit the program
            }

            // Generate random choice for computer
            computer = std::rand() % 3 + 1;

            // Display user choice
            if (user == 1) {
                std::cout << "You chose ✊\n";
            } else if (user == 2) {
                std::cout << "You chose ✋\n";
            } else if (user == 3) {
                std::cout << "You chose ✌️\n";
            }

            // Display computer choice
            if (computer == 1) {
                std::cout << "CPU chose ✊\n\n";
            } else if (computer == 2) {
                std::cout << "CPU chose ✋\n\n";
            } else if (computer == 3) {
                std::cout << "CPU chose ✌️\n\n";
            }

            // Determine the winner of the round
            if (user == computer) {
                std::cout << "====================\n";
                std::cout << "It's a tie!\n";
                std::cout << "====================\n";
            }
            // User chooses rock
            else if (user == 1 && computer == 2) {
                std::cout << "====================\n";
                std::cout << "CPU wins this round!\n";
                std::cout << "====================\n";
                computerScore++;
            } else if (user == 1 && computer == 3) {
                std::cout << "====================\n";
                std::cout << "You win this round!\n";
                std::cout << "====================\n";
                userScore++;
            }
            // User chooses paper
            else if (user == 2 && computer == 1) {
                std::cout << "====================\n";
                std::cout << "You win this round!\n";
                std::cout << "====================\n";
                userScore++;
            } else if (user == 2 && computer == 3) {
                std::cout << "====================\n";
                std::cout << "CPU wins this round!\n";
                std::cout << "====================\n";
                computerScore++;
            }
            // User chooses scissors
            else if (user == 3 && computer == 1) {
                std::cout << "====================\n";
                std::cout << "CPU wins this round!\n";
                std::cout << "====================\n";
                computerScore++;
            } else if (user == 3 && computer == 2) {
                std::cout << "====================\n";
                std::cout << "You win this round!\n";
                std::cout << "====================\n";
                userScore++;
            }

            // Display scores after each round
            std::cout << "Score: You " << userScore << " - " << computerScore << " CPU\n";
        }

        // Determine the overall winner
        if (userScore == 2) {
            std::cout << "Congratulations! You won the best out of 3!\n";
        } else if (computerScore == 2) {
            std::cout << "CPU wins the best out of 3! Better luck next time!\n";
        } else {
            std::cout << "Program has ended!\n";
        }

        // Ask the user if they want to play again (only if they didn't enter 0 to exit)
        if (user != 0) {
            std::cout << "\nDo you want to play again? (Yes/No): ";
            std::cin >> playAgain;

            // Handle invalid inputs for the play again prompt
            if (playAgain != "Yes" && playAgain != "yes" && playAgain != "Y" && playAgain != "y" && playAgain != "No" && playAgain != "no" && playAgain != "N" && playAgain != "n") {
                std::cout << "Invalid input! Please enter \"Yes\" for yes or \"No\" for no.\n";
                continue; // Restart the game loop if the input is invalid
            }

            // If the user chooses 'No' or 'no', exit the loop and end the program
            if (playAgain == "No" || playAgain == "no" || playAgain == "n" || playAgain == "N") {
                std::cout << "You chose to not play again. Goodbye!\n";
                return 0;  // Break out of the outer loop and end the program
            }
        }

    } while (true);  // Continue playing if user chooses to play again

    return 0;
}
