// Define a bicycle

#include <iostream> // general header
#include <string> // header for strings

// using namespace std; // This makes it so you don't have to do std::cout all the time.

class Bicycle{
private: // initalize parameters of the bike
  int cadence;
  int speed;
  int gear;

public: // can be called or used anywhere in the code.
  // Constructor - a function that is called when an object of a class is created.  The purpose is to initialize the data.
  Bicycle(int initalCadence, int initalSpeed, int initialGear) :
    cadence(initalCadence), speed(initalSpeed), gear(initialGear) {}

  // Methods or functions:
    void changeCadence(int newValue){
      cadence = newValue;
    }

    void changeGear(int newValue){
      gear = newValue;
    }

    void speedUp(int increment){
      speed += increment; // increment the speed.
    }

    void applyBrakes(int decrement){
      speed -= decrement;  // decrease the speed.
    }

// Print the current state of the bicycle:
  void printStates(){
        std::cout << "Cadence: " << cadence << ", Speed: " << speed << ", Gear: " << gear << std::endl; // std::endl inserts a new line after gear.
  }

};

int main(){
  // Create a bicycle object
  Bicycle myBike(0,0,1); // this means the cadence = 0, speed = 0, and gear = first gear.


  // Use methods to modify the object's states
  myBike.changeCadence(50);
  myBike.speedUp(10);
  myBike.changeGear(2);
  myBike.printStates(); // show new states of bike.

  myBike.applyBrakes(5);  // what happens if you break?
  myBike.printStates();

  return 0; // end program with 0.

}
