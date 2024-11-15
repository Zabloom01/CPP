// Procedural Script: Create quadratic formula equation in the form 
// a*(x*x) + b*x + c = 0.

#include <iostream>
#include <cmath>

int main() {
  
// declare three variables
 double a; // use double type for decimals
 double b;
 double c;

// Create prompt for "a" variable:
std::cout << "Enter a: "; // prompt
std::cin >> a; // user enters variable as input

// Create prompt for "b" variable:
std::cout << "Enter b: "; 
std::cin >> b; 

// Create prompt for "c" variable:
std::cout << "Enter c: "; 
std::cin >> c; 

// declare two variables to store roots
double root1;
double root2;

// Quadratic formula starting with plus(+):
root1 = (-b + std::sqrt(b*b - 4*a*c)) / (2*a);

// Quadratic formula with minus(-):
root2 = (-b - std::sqrt(b*b - 4*a*c)) / (2*a);

std::cout << "Root 1 is " << root1 << "\n"; // print root1
std::cout << "Root 2 is " << root2 << "\n"; // print root2

return 0;

}
