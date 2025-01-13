#include <iostream>
#include <fstream>
#include "trains.h"
#include <string>

const int Maxseats=40;
int seatingArray[10][4];

using namespace std;

void addtrain() {
    ofstream fout("train.txt", ios::app);           // opening file in append mode to prevent overwriting

    Train* trainPtr = new Train;                           // dynamically allocates memory for train
    Train train;  //object of Train

    cout << "Enter train ID : ";
    cin >> trainPtr->ID;
    fout << trainPtr->ID << " ";

    int total=0;
    do {                                                  // loop to make sure total seats dont exceed 40

        cout << "Enter No. of seats available :";
        cin >> trainPtr->availableSeats;
        fout << trainPtr->availableSeats << " ";

        cout << "Enter No. of seats occupied : ";
        cin >> trainPtr->occupiedSeats;
        fout << trainPtr->occupiedSeats << " ";

        total = trainPtr->occupiedSeats + trainPtr->availableSeats;
        if (total > Maxseats ) {
            cout << "the number of available seats and occupied seats must be less than equal to 40" << endl;
            cout << "Enter again:"<<endl;
        }

    } while (total > Maxseats);

    cout << "Enter train Name : ";
    cin >> trainPtr->Name;
    fout << trainPtr->Name << " ";

    cout << "Enter train Starting Point : " ;
    cin >> trainPtr->startingPoint;
    fout << trainPtr->startingPoint << " ";

    cout << "Enter train Destination : ";
    cin >> trainPtr->destination;
    fout << trainPtr->destination << " " << endl;
    cout << "      " << endl;
    cout << "Train added successfully"<< endl;

    fout.close();
    delete trainPtr;        // deletes memory
}

void displayTrain() {
    ifstream fin("train.txt");
    Train train;

    while (fin>>train.ID>>train.availableSeats                 // reads data using fin
        >>train.occupiedSeats>>train.Name
        >>train.startingPoint>>train.destination) {

        cout << "Train ID : " << train.ID << endl;                    // displays all the information of train
        cout << "Train Name : " << train.Name << endl;
        cout << "Seat Available : " << train.availableSeats << endl;
        cout << "Seat Occupied : " << train.occupiedSeats << endl;
        cout << "Start Point : " << train.startingPoint << endl;
        cout << "Destination : " << train.destination << endl;
        cout << "     " << endl;
    }
    fin.close();
}

bool recursiveSearch(ifstream& fin, int SearchID, Train& train) {

    if (!(fin >> train.ID >> train.availableSeats >> train.occupiedSeats >> train.Name
        >> train.startingPoint >> train.destination)) {                                  //base case
        return false;
        }


    if (train.ID == SearchID) {
        cout << "Train found!" << endl;
        return true;
    }


    return recursiveSearch(fin, SearchID, train);  // here comes recursion.function call itself if id not
}                                                        // found and move to next train record to search till the end

bool SearchTrain(int SearchID) {
    ifstream fin("train.txt");
    Train train;                                                   // the function for user. result stores the value of
    bool result = recursiveSearch(fin, SearchID, train);     // recursive search and displays accordingly
    if (!result) {
        cout << "Train ID " << SearchID << " not found!" << endl;
    }
    fin.close();
    return result;
}

void deleteTrain(int deleteID) {
    ifstream fin("train.txt");
    ofstream fouttemp("temp.txt");
    Train train;
    bool found = false;

    while (fin >> train.ID>> train.availableSeats
        >> train.occupiedSeats >> train.Name
        >> train.startingPoint >> train.destination) {              //If the trains ID does not match deleteID
        if (train.ID != deleteID) {                                 //the record is stored to the temp file to rename it later
            fouttemp << train.ID << " " << train.availableSeats << " " << train.occupiedSeats << " "
                 << train.Name << " " << train.startingPoint << " " << train.destination << endl;
        } else {
            found = true;                                       // If the train ID matches deleteID
        }                                                       // the record is not written into file
    }
    fin.close();
    fouttemp.close();

    // Removing the original file and renaming the temporary file as trains.txt
    remove("train.txt");
    rename("temp.txt", "train.txt");     //builtin functions

    if (found) {
        cout << "Train with ID " << deleteID << " has been deleted successfully." << endl;
    } else {
        cout << "Train ID " << deleteID << " not found!" << endl;
    }
}

void updateTrain(int updateID) {
    ifstream fin("train.txt");
    ofstream temp("temp.txt");
    Train train;
    bool found = false;

    int newSeatsAvailable, newSeatsOccupied;
    string newTrainName, newStartingPoint, newDestination;   // new variables for train attributes
                                                             // but id remains same

    cout << "Enter new available seats: ";
    cin >> newSeatsAvailable;
    cout << "Enter new occupied seats: ";
    cin >> newSeatsOccupied;
    cout << "Enter new train name: ";
    cin >> newTrainName;
    cout << "Enter new starting point: ";
    cin >> newStartingPoint;
    cout << "Enter new destination: ";
    cin >> newDestination;

    while (fin >> train.ID>> train.availableSeats            // reads data using fin
        >> train.occupiedSeats>> train.Name
        >> train.startingPoint>> train.destination)
    {
        if (train.ID == updateID) {             // if train id found the new attributes will be stored in file.
            found = true;
            temp << train.ID << " " << newSeatsAvailable << " " << newSeatsOccupied << " "
                 << newTrainName << " " << newStartingPoint << " " << newDestination << endl;
        } else {                               // if train id not found the old attributes will be stored in file.
            temp << train.ID << " " << train.availableSeats << " " << train.occupiedSeats << " "
                 << train.Name << " " << train.startingPoint << " " << train.destination << endl;
        }
    }
    fin.close();
    temp.close();

    // Removing the original file and renaming the temporary file as trains.txt
    remove("train.txt");
    rename("temp.txt", "train.txt");

    if (found) {
        cout << "Train with ID " << updateID << " has been updated successfully." << endl;
    } else {
        cout << "Train ID " << updateID << " not found!" << endl;
    }
}

void removeAllTrains() {
    ofstream fout("train.txt", ios::trunc);            // opening file in truncate mode to remove all the data
    if (fout) {
        cout << "All trains have been removed successfully." << endl;
    } else {
        cout << "Error reading the file" << endl;
    }
    fout.close();
}

void seatsMapping(int SearchiD) {

    ifstream fin("train.txt");
    Train train;
    bool found = false;

    while (fin>>train.ID>>train.availableSeats           //reads data
        >>train.occupiedSeats>>train.Name
        >>train.startingPoint
        >>train.destination){
        if (train.ID == SearchiD) {
            int seatingArray[10][4];
            int value1=train.availableSeats;
            int value2=train.occupiedSeats;

            int seats=Maxseats-value2;              // seats will get value of available seats
            cout<<"____________________"<<endl;
            cout<<" TRAIN SEATING PLAN   X : occupied  O : available"<<endl;
            cout<<"____________________"<<endl;
            for(int i= 0;i< 10;i++) {
                for(int j= 0;j< 4;j++) {
                    if(seats!=0) {
                        cout<<" O |";                //available seats
                        seats--;
                    }
                    else {
                        cout<<" X |";            //occupied seats
                    }
                }
                cout << endl;
            }
            found = true;
        }
        }
    if (!found) {
        cout << "Train ID: " << SearchiD << " not found!" << endl;
    }
    fin.close();
}