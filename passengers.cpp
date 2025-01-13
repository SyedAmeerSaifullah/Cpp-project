#include "passengers.h"
#include <iostream>
#include <string>
#include <fstream>

int initialCapacity = 2;
Passenger *passengers = new Passenger[initialCapacity];
int size = 0;
int capacity = initialCapacity;

void addPassenger() {
    ofstream fout;
    fout.open("passenger.txt", ios::app);
    if (!fout) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    int stop = 0;
    while (stop != 2){
     // ask user the user
        cout << "\n1. Add a passenger\n";
        cout << "2. Stop adding passengers\n";
        cout << "3. Display number of passengers added at the moment \n";
        cout << "Enter choice: ";
        cin >> stop;

      if (stop == 1) {
        if (size == capacity) { // to resize array
            capacity *= 2;
            Passenger *newPassengers = new Passenger[capacity];
            for (int i = 0; i < size; i++) { // copy data into new
                newPassengers[i] = passengers[i];
            }
            delete[] passengers; // free the old array
            passengers = newPassengers;
        }
          // Input for passenger Id
          string tempID;
          cout << "\nPlease enter a passenger" << endl;
          cout << "Enter passenger ID: ";
          cin >> tempID;
          // to check if ID is unique or already exits
          // check in current array first
          bool existenceOfId = false;
          for(int i = 0; i < size; i++){
            if(passengers[i].pID == tempID){
              existenceOfId = true;
              cout << "Error: ID already exists." << endl;
              break;
            }
          }
          // to check existnece of Id in file
          if(!existenceOfId) {
              ifstream fin("passenger.txt");
              string line;

              while(getline(fin, line)) {
                  // Check if line starts with "Passenger ID: "
                  string passengerId = "Passenger ID: ";
                  bool isIDLine = true;
                  string currentID = "";
                  if(line.length() >=  passengerId.length()) {
                      // Check each character of  passengerId
                      for(int i = 0; i < passengerId.length(); i++) {
                          if(line[i] !=  passengerId[i]) {
                              isIDLine = false;
                              break;
                          }
                      }
                      if(isIDLine) {
                          // Extract ID
                          for(int i =  passengerId.length(); i < line.length(); i++) {
                              currentID += line[i];
                          }

                          if(currentID == tempID) {
                              existenceOfId = true;
                              cout << "Error: ID already exists in file." << endl;
                              break;
                          }
                      }
                  }
              }
              fin.close();
          }
          // If ID is unique then add passenger
          if(!existenceOfId) {
            passengers[size].pID = tempID;
            cout << "Passenger Name: ";
            cin.ignore();
            getline(cin, passengers[size].pname);
            cout << "Passenger Gender (male or female): ";
            getline(cin, passengers[size].gender);
            cout << "Contact Information: ";
            getline(cin, passengers[size].pContactNumber);
            cout << "CNIC: ";
            getline(cin, passengers[size].pCnic);

            // to write to passenger file
            fout << "Passenger ID: " << passengers[size].pID << endl;
            fout << "Passenger Name: " << passengers[size].pname << endl;
            fout << "Contact Information: " << passengers[size].pContactNumber << endl;
            fout << "CNIC: " << passengers[size].pCnic << endl;
            fout << "Gender: " << passengers[size].gender << endl;
            fout << endl;
           //increase size of array
            size++;
            cout << "Passenger added successfully!" << endl;
          }
      }
        if(stop == 3){
            cout << "\nNumber of passengers added: " << size << endl;
        }
    }
    fout.close();
}



void searchPassenger() {

    string searchID;
    bool found = false;

    cout << "Enter Passenger ID to search: ";
    cin >> searchID;
    // to open the file
    ifstream fin("passenger.txt");
    if (!fin) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    string line;//to hold each line and read from the file
    while (getline(fin, line)) { // to process each line of the file

   // Check if line starts with "Passenger ID: "
    string passengerId = "Passenger ID: ";

        //to indicate wether current line includes id
    bool isIDLine = true;
    string currentID = "";//to store id extracted from file

        // Check if this line is ID line(if size of line is equal to id line)
    if (line.length() >= passengerId.length()) {
            // Check each character to match with "Passenger ID: "
     for (int i = 0; i < passengerId.length(); i++) {
       if (line[i] != passengerId[i]) {// if character doesnt match then line doesnt contain ID
         isIDLine = false;
         break;
     }
     }

            // if it is ID line then extract the ID
     if (isIDLine) {
      // extracts only the ID from the line
      for (int i = passengerId.length(); i < line.length(); i++) {
         currentID += line[i];
      }

        // checks if this is the ID we're looking for
        if (currentID == searchID) {
          found = true;
           cout << endl;
           cout << line << endl;  // to print the ID line
           cout << endl;
        // to print the next 4 lines including name contact cnic gender
        for (int i = 0; i < 4; i++) {
             getline(fin, line);
             cout << line << endl;
        }
        break;
        }
        }
        }
    }

    if (!found) {
        cout << "Passenger with ID " << searchID <<" not found."<<endl;
        cout << endl;
    }
   fin.close();

}
void displayPassengers() {
  ifstream fin("passenger.txt");
  if (!fin){
    cout << "Error occured while reading from file." << endl;
  }
   string line; //to hold each line and read from the file
   if(!fin.eof()){
     while(getline(fin, line)){
       cout <<line << endl;
     }
   }
}


void removePassenger() {
    string removeID;
    bool found = false;

    cout << "Enter ID of Passenger to remove: ";
    cin >> removeID;

    //to open file for reading
    string line;
    ifstream fin("passenger.txt");
    if (!fin) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }
    // to pen a temporary file to write
    ofstream fout("temp.txt");
    if (!fout) {
        cout << "Error: Unable to create temporary file." << endl;
        fin.close();
        return;
    }
    // to read from the original file
    while (getline(fin, line)) {
        // Check if line starts with "Passenger ID: "
        string passengerId = "Passenger ID: ";
        bool isIDLine = true;
        string currentID = "";
        // to check if this line is the ID line
        if (line.length() >= passengerId.length()) {
            // to check each character of passengerId
            for (int i = 0; i < passengerId.length(); i++) {
                if (line[i] != passengerId[i]) {
                    isIDLine = false;
                    break;
                }
            }

            // to check if it is ID line then to extract the ID
            if (isIDLine) {
                // Extract ID (characters after prefix)
                for (int i = passengerId.length(); i < line.length(); i++) {
                    currentID += line[i];
                }
                // Check if this is the ID we want to remove
                if (currentID == removeID) {
                    found = true;
                    // Skip the next 5 lines (current ID line + 4 info lines)
                    for (int i = 0; i < 5; i++) {
                        if (i < 4) {  // Skip reading the next 4 lines
                            getline(fin, line);
                        }
                    }
                    continue;  // Skip writing this passenger's info
                }
            }
        }

        // Write line to temp file if it's not the passenger to remove
        fout << line << endl;
    }

    fin.close();
    fout.close();

    // to delete the original file and also renaming of the temp file
    if (found) {
        remove("passenger.txt");
        rename("temp.txt", "passenger.txt");
        cout << "\nPassenger with ID " << removeID << " has been removed." << endl;

        // to remove from the array
        for (int i = 0; i < size; i++) {
            if (passengers[i].pID == removeID) {
                // Shift remaining elements left
                for (int j = i; j < size - 1; j++) {
                    passengers[j] = passengers[j + 1];
                }
                size--;
                break;
            }
        }
    } else
    {
        // to delete temp file if no passenger was found
        remove("temp.txt");
        cout << "Passenger with ID: " << removeID << " not found." << endl;
    }

   }

























