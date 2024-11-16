#include <iostream>

int main(){

// for loop iterating from 1 to 100
for(int i = 1; i <= 100; i++){

// If number is multiples of both 3 and 5
  if(i % 3 == 0 && i % 5 == 0){
    std::cout << "FizzBuzz\n";
  }

// if number is multiples of 3
  else if (i % 3 == 0){
    std::cout << "Fizz\n";
  }

// if number is multiples of 5
  else if (i % 5 == 0){
    std::cout << "Buzz\n";
  }

// all other numbers not mentioned previously
  else{
    std::cout << i << "\n";
  }



}

}
