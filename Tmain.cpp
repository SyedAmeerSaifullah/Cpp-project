#include <iostream>
#include <fstream>
#include "trains.h"
/*
using namespace std;

void trainsMenu() {
    static int choice;

    do {
        cout << "      " << endl;
        cout << "||----Train Management System----||" << endl;
        cout << "      " << endl;
        cout << "1. Add Train"<< endl;
        cout << "2. Display All Trains"<< endl;
        cout << "3. Search Train"<< endl;
        cout << "4. Delete Train"<< endl;
        cout << "5. Update Train"<< endl;
        cout << "6. Remove all trains"<< endl;
        cout << "7. Display seating map"<< endl;
        cout << "8. Exit"<< endl;

        cout << "Enter choice: "<< endl;
        cin >> choice;

        switch (choice) {
            case 1:
                addtrain();
            break;
            case 2:
                displayTrain();
            break;
            case 3:
                int SearchID;
            cout << "Enter the train ID to search: ";
            cin >> SearchID;
            SearchTrain(SearchID);
            break;
            case 4:
                int deleteID;
            cout << "Enter ID of the train to delete: ";
            cin >> deleteID;
            deleteTrain(deleteID);
            break;
            case 5:
                int updateID;
            cout << "Enter ID of the train to update: ";
            cin >> updateID;
            updateTrain(updateID);
            break;
            case 6:
                removeAllTrains();
            break;
            case 7:
                int SearchiD;
            cout << "Enter ID to search Train : ";
            cin >> SearchiD;
            seatsMapping(SearchiD);
            break;
            case 8:
                cout << "EXIT" << endl;
            break;
            default:
                cout << "Invalid choice!" <<endl;
        }
    } while (choice != 8);


    return 0;
}  */