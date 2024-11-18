#include <iostream>
#include "ufo_functions.hpp"

int main() {
  
  // display greet function
  greet();
  std::string codeword = "starship"; // codeword that player must guess to win
  std::string answer = "________"; // spaces for guessed letters, similar to the game hangman
  int misses = 0; // initialize, set misses to 0
  std::vector<char> incorrect; // will add to on each iteration of the loop
  bool guess = false; // this will track if player guessed correct letter
  char letter; // this will capture the player's guessed letter

// game continues as long as both conditions are true
  while(answer != codeword && misses < 7){
    // code for each turn will go here.

    display_misses(misses);  // call display misses function
    display_status(incorrect, answer); // call display status function for incorrect and answer
    
    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter; // record response as letter

// loop through each character in codeword to see if the player was right
    for (int i = 0; i < codeword.length(); i++){

      if (letter == codeword[i]){
        answer[i] = letter;
        guess = true; // sets guess to true
      }
    }

// if guess is true, you are correct
    if (guess){
      std::cout << "\nCorrect!\n";  
    }

// if guess is not true then this else statement would add a char letter to the incorrect vector.  Then misses would increment.
    else{
      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter); // add letter to incorrect vector
      misses++; // must go at end of loop to prevent infinite loop due to incrementing.  Only increment if guess was false.
    }

    guess = false; // Outside of the loop to reset guess back to false at end of while loop.  Now guess will only be true again if another correct letter is selected.

  }

  end_game(answer, codeword);


}
