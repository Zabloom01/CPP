#include <iostream>
#include <string>
#include <vector>
#include "functions.hpp"  // include this file for the functions.


int main() {
    // Using std::vector for the list of words
    std::vector<std::string> words = {"broccoli", "spinach"}; // adjust this vector as needed to include more words

    std::string sentence = "I sometimes eat broccoli.  I think broccoli tastes really good if you cook it right and have a good dipping sauce.  If you like broccoli, you should try spinach too!  They are both great for you! #broccoli #spinach";

    // Call the bleep function
    bleep(words, sentence);

    // Print the modified sentence
    std::cout << sentence << "\n";

    return 0;
}
