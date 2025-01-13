/*#include <iostream>
#include <string>
#include <fstream>
#include "passengers.h"

using namespace std;
void passengerMain() {
int choose ;
do{
       cout <<"\n---- PASSENGER  MANAGEMENT SYSTEM -----\n"
            <<endl
            <<"1. Add passenger information into the system\n"
            <<"2. Search passenger information from the system\n"
            <<"3. Remove passenger information from the system\n"
            <<"4. Display passengers from the system\n"
            <<"5. Exit\n"
            <<endl
            <<"Enter your choice: ";
       cin>>choose;
        switch(choose) {
            case 1:
                addPassenger();
                    break;
            case 2:
              searchPassenger();
                break;
            case 3:
              removePassenger();
                break;
            case 4:
              displayPassengers();
                break;

              case 5:
                cout<<"Exiting\n";
            break;
            default:
                cout<<"Invalid choice. Please enter again";
            break;
        }
    }while(choose!=5);



    return 0;
}
*/