
#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Passenger {
    string pID;
    string gender;
    string pname;
    string pContactNumber;
    string pCnic;
};

void addPassenger();

void searchPassenger();

void displayPassengers();

void removePassenger();

//void passengerMain();

#endif
