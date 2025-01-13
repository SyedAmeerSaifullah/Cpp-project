#include<iostream>
#include "supplies.h"
using namespace std;
struct cargo {
    string itemName;
    int quantity;
    string category;
    string pickupLocation;
    string dropOffLocation;
};
const int maxItems = 100; // Maximum capacity of the inventory
cargo cargoinventory;
int itemCount=0;
void addItem() { //This function adds the items in cargo Inventory
    if (itemCount >= 100) {
        cout << "Inventory is full Cannot add more items " << endl;
        return;
    }
    cout<< "Enter item name: ";
    cin>> cargoinventory.itemName;
    cout<< "Enter quantity: ";
    cin>> cargoinventory.quantity;
    cout<< "Enter category: ";
    cin>> cargoinventory.category;
    cout<< "Enter pickup location: ";
    cin>> cargoinventory.pickupLocation;
    cout<< "Enter dropoff location: ";
    cin>> cargoinventory.dropOffLocation;
    itemCount++;
}
void trackCargo() { //This function tracks the cargo Inventory item at which place it is picked up and where it is dropped
    string name;
    cout << "Enter item name to track destination: ";
    cin>> name;
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (cargoinventory.itemName == name) {
            cout<< "Item found:";
            cout<< "Name: " << cargoinventory.itemName<<endl;
            cout<< "Pickup Location: " << cargoinventory.pickupLocation<<endl;
            cout<< "Dropoff Location: " << cargoinventory.dropOffLocation << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found.";
    }
}
void removeItems() { //This function remove the item when the cargo reached its destination
    string name;
    cout << "Enter item name to remove: ";
    cin>>name;
    int index = -1;
    for (int i = 0; i < itemCount; i++) {
        if (cargoinventory.itemName == name) {
            index = i;
            itemCount--;
            cout << "Item removed successfully";
        } else {
            cout << "Item not found";
        }
        cout << endl;
    }
}
void viewItems() {
    if (itemCount == 0) {
        cout<< "No items in inventory.";
        cout << endl;
        return;
    }
    for (int i = 0; i < itemCount; ++i) {
        cout<< "Name: " << cargoinventory.itemName<<endl;
        cout<< "Quantity: " <<cargoinventory.quantity<<endl;
        cout<< "Category: " <<cargoinventory.category<<endl;
        cout<< "pickup Location: " <<cargoinventory.pickupLocation <<endl;
    }
}
