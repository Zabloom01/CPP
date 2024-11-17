// For the Text_adventure script you could add in a list as a utility belt which you could then use to save the character, etc.  
// Makes the game more fun and interesting if incorporaated.

#include <iostream>
#include <list>
#include <string>

using namespace std;

// Function to display the current items in the belt
void displayBelt(const list<string>& belt) {
    cout << "Your storage belt contains:\n";
    if (belt.empty()) {
        cout << "Nothing! It's empty.\n";
    } else {
        int index = 1;
        for (const auto& item : belt) {
            cout << index++ << ". " << item << endl;
        }
    }
    cout << endl;
}

// Function to add an item to the belt
bool addItem(list<string>& belt, const string& item, size_t capacity) {
    if (belt.size() >= capacity) {
        cout << "Your storage belt is full! You need to drop an item first.\n";
        return false;
    } else {
        belt.push_back(item);
        cout << "You collected: " << item << endl;
        return true;
    }
}

// Function to drop an item from the belt
void dropItem(list<string>& belt) {
    displayBelt(belt);
    if (belt.empty()) {
        cout << "You have no items to drop!\n";
        return;
    }

    cout << "Enter the number of the item you want to drop: ";
    size_t dropIndex;
    cin >> dropIndex;

    if (dropIndex >= 1 && dropIndex <= belt.size()) {
        auto it = belt.begin();
        advance(it, dropIndex - 1); // Move iterator to the correct position
        cout << "You dropped: " << *it << endl;
        belt.erase(it);
    } else {
        cout << "Invalid choice. No item dropped.\n";
    }
}

// Function to use an item from the belt
void useItem(list<string>& belt) {
    displayBelt(belt);
    if (belt.empty()) {
        cout << "You have no items to use!\n";
        return;
    }

    cout << "Enter the number of the item you want to use: ";
    size_t useIndex;
    cin >> useIndex;

    if (useIndex >= 1 && useIndex <= belt.size()) {
        auto it = belt.begin();
        advance(it, useIndex - 1); // Move iterator to the correct position
        cout << "You used: " << *it << ". It's no longer in your belt.\n";
        belt.erase(it);
    } else {
        cout << "Invalid choice. No item used.\n";
    }
}

// Adventure example with item collection and usage
void adventure() {
    const size_t beltCapacity = 5; // Maximum number of items the belt can hold
    list<string> belt;             // Storage belt

    cout << "Welcome to the Adventure! Your storage belt can hold up to " << beltCapacity << " items.\n\n";

    bool exploring = true;
    while (exploring) {
        cout << "\nWhat do you want to do?\n";
        cout << "1. Collect an item\n2. Use an item\n3. Drop an item\n4. Check belt\n5. Exit adventure\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Simulating random item collection
            string items[] = { "Potion", "Sword", "Shield", "Map", "Key", "Torch" };
            string newItem = items[rand() % 6];
            if (!addItem(belt, newItem, beltCapacity)) {
                cout << "You couldn't collect " << newItem << " because the belt is full.\n";
            }
            break;
        }
        case 2:
            useItem(belt);
            break;
        case 3:
            dropItem(belt);
            break;
        case 4:
            displayBelt(belt);
            break;
        case 5:
            exploring = false;
            cout << "Exiting adventure. Thanks for playing!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random item generation
    adventure();
    return 0;
}
