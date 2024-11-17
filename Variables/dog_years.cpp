#include <iostream>

int main() {
  
  // initialize variables for human and dog
  double human_age;
  double dog_age;

  // prompt user question and set response as variable
  std::cout << "How old is the human? ";
  std::cin >> human_age;

  // convert human years to dog years
  dog_age = human_age * 10.5;

  // print
  std::cout << "The human would be " << dog_age << " years old in dog years \n";


}
