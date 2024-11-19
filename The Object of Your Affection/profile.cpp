#include <iostream>
#include "profile.hpp"

// This section is used to define functions/methods, constructors, etc.

// define constructor - constructor name must match constructor class e.g., Profile::Profile
Profile::Profile(std::string new_name, int new_age, std::string new_city, std::string new_country, std::string new_pronouns)
 : name(new_name), age(new_age), city(new_city), country(new_country), pronouns(new_pronouns) {  // profile constructor takes five arguments and then takes those arguments and uses those to initialize variables.

}

// define function to view profiles

std::string Profile::view_profile() { // return a string for the function belonging to the Profile class meaning it also has access to that class too.

// we want a bio that includes your name, age, pronouns, and hobbies
  std::string bio = "Name: " + name;  // add name to bio
  bio += "\nAge: " + std::to_string(age); // add age to bio
  bio += "\nPronouns: " + pronouns; // add pronouns to bio
  
  std::string hobby_string = "Hobbies:\n";

  for(std::string hobby : hobbies) { // for each hobby in list of hobbies
    hobby_string += " - " + hobby + "\n"; // add hobby to hobby string
    // will print something like "- listening to audiobooks and podcasts"
    // just adding strings togethers
  }

  return bio + "\n" + hobby_string; // create a new line and then add 

}
  void Profile::add_hobby(std::string new_hobby) {

  hobbies.push_back(new_hobby);





}
