#include <iostream>
#include <vector> // we will use vectors
#include <string> // we will use strings

int main (){
std::string input = "turpentine and turtles"; // initialize string to this phrase.
std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // whales can only speak in vowels

std::vector<char> results = {}; // this is a place to store vectors as result, starts as nothing since no values.  You can also just do std::vector<char> results;

// take size of input string
for (int i = 0; i < input.size(); i++){

// take size of vowels vector
  for (int j = 0; j < vowels.size(); j++){

    // compare string input [i] to vector vowels
      if (input[i] == vowels[j]){
        results.push_back(input[i]);

      // for 'e' or 'u' push them into input[i], this doubles up on the e's and u's
        if (input[i] == 'e' || input[i] == 'u'){
          results.push_back(input[i]);
        }

      }
  }
}

for (int k = 0; k < results.size(); k++){
  std::cout << results[k];
}

std::cout << "\n";

}
