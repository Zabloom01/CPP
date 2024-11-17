#include <iostream>
#include <vector>
#include <string>

int main (){

// input string for the program to translate
std::string input ("turpentine and turtles"); // initialize string for input variable to this phrase.

// create a char vector names vowels
std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
std::vector<char> result; // create results vector to store vowels from the input string (e.g., translated whale talk).

for(int i = 0; i < input.size(); i++){ // input.size() measures the characters of the input string.

  for(int j = 0; j < vowels.size(); j++){ // this is a nested for loop that iterates through the vowel vector.  Helps make easier to iterate through input string and vector

    if (input[i] == vowels[j]){
      result.push_back(input[i]);

      if (input[i] == 'e' || input[i] == 'u'){
        result.push_back(input[i]);
      }

    }
  }
}

for (int k = 0; k < result.size(); k++){
  std::cout << result[k];
}

std::cout << "\n";

}
