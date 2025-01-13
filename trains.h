#ifndef TRAINS_H
#define TRAINS_H
#include <iostream>
#include <fstream>

using namespace std;


struct Train {
    int ID;                     // train ID
    string Name;                // name of train
    int availableSeats;         // number of seats available
    int occupiedSeats;          // number of seats occupied
    string startingPoint;       // the starting point of train
    string destination;         // the ending point of train
};


void addtrain();                    // adds a new train dynamically into file
void displayTrain();                // displays all the trains from file
bool SearchTrain(int SearchID);     // searches for a train by its id , uses recursion
void deleteTrain(int deleteID);     // deletes a specific train from file by its id
void updateTrain(int updateID);     // updates a specific attribute of train without changing its id
void removeAllTrains();             // a function that removes all the trains from file
void seatsMapping(int SearchiD);    // displays the seating map of specific train
//void trainsMenu();

#endif //TRAINS_H
