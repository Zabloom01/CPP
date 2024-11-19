#include <vector>

// This section is used to create classes, declare variables, declare functions, etc.

class Profile{ // create a class called profile
// initialize all variables
// by default these are private variables
private:  // we can call private to be clearer
  std::string name;
  int age;
  std::string city;
  std::string country;
  std::string pronouns;
  std::vector<std::string> hobbies;

public: // these variables are accessible outside the class
// Initalize constructor
  Profile(std::string new_name, int new_age, std::string new_city, std::string new_country, std::string new_pronouns);

  std::string view_profile(); // returns a string
  
  void add_hobby(std::string new_hobby);  // void does not return any values, but can return types like strings


}; // need semicolon here for all classes
