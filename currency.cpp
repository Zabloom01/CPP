#include <iostream>
#include <iomanip> // helps clip output to decimal points

int main() {

// declare three variables to represent currency
  double pesos;
  double reais;
  double soles;

  double dollars;

// ask user the first question
  std::cout << "Enter number of Columbian Pesos: ";
  std::cin >> pesos; // assigns value from user input 

  std::cout << "Enter number of Brazillian Reais: ";
  std::cin >> reais; // assigns value from user input 

  std::cout << "Enter number of Peruvian Soles: ";
  std::cin >> soles; // assigns value from user input 

// Conversion rates for currency to USD:
  double pesos_conversion_rate = 0.0032; // Pesos conversion rate: 0.00032
  double reais_conversion_rate = 0.27; // Reais conversion rate: 0.27
  double soles_conversion_rate = 0.3; // Soles conversion rate: 0.3

// Convert to USD formula:
dollars = (pesos_conversion_rate * pesos) + (reais_conversion_rate * reais) + (soles_conversion_rate * soles); // takes all currencies from database, converts them and then adds to calculate total USD.

// Display the total USD amount:
std::cout << "Total USD available: $"   << std::fixed << std::setprecision(2)  << dollars << std::endl;  // std::fixed ensures number is displayed in fixed-point notation and not scientific notation and std::setprecision sets the decimals to two places.

return 0; // end program

}

