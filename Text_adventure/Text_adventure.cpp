#include <iostream>
#include <string>

using namespace std;  // makes it so you do not have to type std:: so many times

// Character class to define each character
class Character {
public:
    string name;
    string description;

    Character(string name, string description) : name(name), description(description) {}

    void introduce() {
        cout << "You are " << name << ". " << description << endl;
    }
};

// Forest path with loops for retry
void exploreForest() {
    cout << "\nYou enter the dark forest. Shadows twist and turn in the corners of your vision.\n";
    bool loop = true;
    while (loop) {
        cout << "You come across a fork in the path. Do you:\n1. Take the left path (deeper into the forest)\n2. Take the right path (toward faint light)\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "The left path leads deeper into the forest, where you are surrounded by eerie noises.\n";
            cout << "You hear a growl behind you! Do you:\n1. Turn and fight\n2. Run deeper into the woods\n";
            cin >> choice;

            if (choice == 1) {
                cout << "You fight bravely but are overpowered by a beast lurking in the dark. The adventure ends here.\n";
                loop = false;
            } else {
                cout << "You manage to escape the beast but find yourself hopelessly lost.\n";
                cout << "Do you:\n1. Climb a tree to look for a way out\n2. Keep walking and hope for the best\n";
                cin >> choice;

                if (choice == 1) {
                    cout << "From the treetop, you spot a clearing. You make your way there and escape the forest. Success!\n";
                    loop = false; // Good outcome, end loop
                } else {
                    cout << "You wander aimlessly until exhaustion takes you. The adventure ends here.\n";
                    loop = false;
                }
            }
        } else {
            cout << "The right path leads to an abandoned hut. Inside, you find supplies and a map to escape the forest. Success!\n";
            loop = false; // Good outcome, end loop
        }
    }
}

// Mountain path with loops
void climbMountain() {
    cout << "\nYou begin your climb up the mountain, the air getting colder with each step.\n";
    bool loop = true;
    while (loop) {
        cout << "As you climb, you find a narrow ledge with a precarious bridge ahead. Do you:\n1. Cross the bridge\n2. Find another way around\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "The bridge sways dangerously. Halfway across, a plank snaps!\n";
            cout << "Do you:\n1. Try to jump to safety\n2. Hold on and climb back\n";
            cin >> choice;

            if (choice == 1) {
                cout << "You leap to safety just in time and find a hidden path leading upward. Success!\n";
                loop = false; // Good outcome, end loop
            } else {
                cout << "You lose your grip and fall into the ravine. The adventure ends here.\n";
                loop = false;
            }
        } else {
            cout << "You take another path but encounter a fierce snowstorm. Do you:\n1. Press forward\n2. Seek shelter\n";
            cin >> choice;

            if (choice == 1) {
                cout << "You brave the storm and find an old climber’s hut with supplies. You use them to continue your journey. Success!\n";
                loop = false; // Good outcome, end loop
            } else {
                cout << "The storm overwhelms you, and you perish in the cold. The adventure ends here.\n";
                loop = false;
            }
        }
    }
}

// Castle path with loops
void exploreCastle() {
    cout << "\nYou approach the ominous castle, its spires piercing the clouds.\n";
    bool loop = true;
    while (loop) {
        cout << "Inside the grand hall, you see two staircases. Do you:\n1. Go up the left staircase\n2. Go up the right staircase\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "The left staircase leads to a locked door. A riddle is inscribed on it:\n";
            cout << "\"I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?\"\n";
            cout << "1. An Echo\n2. A Shadow\n";
            cin >> choice;

            if (choice == 1) {
                cout << "The door creaks open, revealing a treasure room. You find an enchanted artifact that boosts your power. Success!\n";
                loop = false; // Good outcome, end loop
            } else {
                cout << "The door remains locked, and a trap is triggered! You are caught and thrown into the dungeon. The adventure ends here.\n";
                loop = false;
            }
        } else {
            cout << "The right staircase leads to a library filled with ancient tomes.\n";
            cout << "Do you:\n1. Read the books\n2. Search the shelves for hidden mechanisms\n";
            cin >> choice;

            if (choice == 1) {
                cout << "The books grant you forbidden knowledge, but the castle's magic overwhelms you. The adventure ends here.\n";
                loop = false;
            } else {
                cout << "You discover a hidden passage leading to the castle’s inner sanctum. Success!\n";
                loop = false; // Good outcome, end loop
            }
        }
    }
}

int main() {
    cout << "Welcome to the Text Adventure Game!\n";
    cout << "Choose your character:\n";
    cout << "1. Thor: A brave warrior\n2. Ivan: A cunning rogue\n3. Clara: A wise mage\n";
    
    int charChoice;
    cin >> charChoice;

    Character player("", "");
    switch (charChoice) {
    case 1:
        player = Character("Alice", "A brave warrior with unmatched courage."); // Character class follows name and description.  Set Character to name, description accordingly.
        break;
    case 2:
        player = Character("Bob", "A cunning rogue who thrives in the shadows.");
        break;
    case 3:
        player = Character("Clara", "A wise mage with knowledge of arcane spells.");
        break;
    default: // if you choose a variable/case outside the choices you will be an unknown figure/character.
        cout << "Invalid choice. Starting as a default character.\n";
        player = Character("Unknown", "A mysterious figure.");
        break;
    }

    player.introduce();

    cout << "\nWhere would you like to go?\n";
    cout << "1. Explore the Forest\n2. Climb the Mountain\n3. Explore the Castle\n";

    int destination; // Initialize destination
    cin >> destination; // Set destination based on input

    switch (destination) {
    case 1:
        exploreForest();  // explore this function.
        break;
    case 2:
        climbMountain();
        break;
    case 3:
        exploreCastle();
        break;
    default: // if choose a variable/choice outside these choices your advendure will end.
        cout << "Invalid choice. The adventure ends before it begins.\n";
    }

    cout << "\nThank you for playing the Text Adventure Game!\n";
    return 0;
}
