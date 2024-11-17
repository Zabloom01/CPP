#include <iostream>
#include <stdlib.h>

int main(){

  srand(time(NULL)); // set the "seed" based on current time
  int computer = rand() % 3 + 1; // Sets CPU choice randomly between 1 and 3 (note +1 makes it 1 and 3, otherwise it would be between 0 and 3)
  int user = 0; // initialize the user choice to 0

// Start game!
std::cout << "====================\n";
std::cout << "rock paper scissors!\n";
std::cout << "====================\n";

// User choices
std::cout << "1) ✊\n" ; // Rock
std::cout << "2) ✋\n"; // Paper
std::cout << "3) ✌️\n"; // Scissors

std::cout << "shoot! "; // Tells user it is time for input
std::cin >> user; // Stores input into user variable per user's choice

// General Rules: rock beats scissors, paper beats rock, scissors beats paper


// Set User Choice:
if (user == 1){
  std::cout << "You chose ✊\n";
}
else if (user == 2){
  std::cout << "You chose ✋\n";
}
else {
  std::cout << "You chose ✌️\n";
}

// Set Computer/CPU Choice:
if (computer == 1){
  std::cout << "CPU chose ✊\n";
}
else if (computer == 2){
  std::cout << "CPU chose ✋\n";
}
else {
  std::cout << "CPU chose ✌️\n";
}

// Determine the winner using conditional statements:

// If both choose same number:
if(user == computer){
  std::cout << "it's a tie!";
}

// User chooses rock:
else if(user == 1 && computer == 2){
  std::cout << "CPU wins \n!";
}

else if(user == 1 && computer == 3){
  std::cout << "You win! \n";
}

// User chooses paper:
else if(user == 2 && computer == 1){
  std::cout << "You win! \n";
}
else if(user == 2 && computer == 3){
  std::cout << "CPU wins! \n";
}

// User chooses scissors:
else if (user == 3 && computer == 1){
  std::cout << "You lose! \n";
}
else{
  std::cout << "You win! \n";
}

}
