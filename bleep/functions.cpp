#include <iostream>
#include <string>
#include <vector>
#include "functions.hpp" // Include the header for declarations

// Function to replace characters with asterisks
void asterisk(const std::string& word, std::string& text, int start_index) {
    for (int k = 0; k < word.size(); ++k) {
        text[start_index + k] = '*';
    }
}

// Function to search for words and apply asterisks
void bleep(const std::vector<std::string>& words, std::string& text) {
    for (int i = 0; i < text.size(); ++i) {
        for (const auto& word : words) {
            int match = 0;
            for (int j = 0; j < word.size(); ++j) {
                if (i + j < text.size() && text[i + j] == word[j]) {
                    ++match;
                }
            }
            if (match == word.size()) {
                asterisk(word, text, i);
                break; // Stop further checks if the word is found
            }
        }
    }
}
