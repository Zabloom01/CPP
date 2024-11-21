#include <string>
#include <vector>

// Function declarations
// pass-by-reference - function operates directly on the original object in memory rather than copying it allowing the function to modify the original object if reference is not marked as constant and avoids creating copy which improves the performance, especially as the vector gets larger.
void bleep(const std::vector<std::string>& words, std::string& sentence); // Words as vector and sentence by reference
void asterisk(const std::string& word, std::string& sentence, int i); // Single word, sentence by reference, and index

// const passes the object but does not allow modifcations to the reference object.  This is common for vectors when not using pop_back() or push_back()
