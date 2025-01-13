#include <iostream>
#include "tickets.h"
#include "passengers.h"
#include "staffmanagementfunction.h"
#include "supplies.h"
#include "trains.h" 

using namespace std;

int main() {
    static int count=0;
    int staffMembers;
        cout<<"Enter the number of staff members"<<endl;
        cin>>staffMembers;
        while(staffMembers<=0){//checks if total number of staff member is a positive integer
                cout << "Please enter a valid positive number for staff members: ";
                cin>>staffMembers;

        }
    Staff *staff = new Staff[staffMembers];//dynamically creates an array of size having total number of staff members
    TrainTicket tickets[MAX_TICKETS];  // Array to store tickets
    int ticketCount = 0;              // Counter for the number of booked tickets
    

    static int choice;                       // Variable to store user choice
    do {
        // Display menu
        cout << "\n=== Railway Management System ===\n";
        cout << "\n ===Ticket Management=== \n";
        cout << "1. Book a Ticket\n";
        cout << "2. View All Tickets\n";
        cout << "3. List Tickets \n";
        cout << "4. Cancel a Ticket\n";
        cout<< "===Cargo Management System===\n";
        cout<<"5. addItems:"<<endl;
        cout<<"6. track cargo:"<<endl;
        cout<<"7. remove items:"<<endl;
        cout<<"8. view items"<<endl;
        cout <<"\n===Passenger Management System==="<<endl
           <<"9. Add passenger information into the system\n"
           <<"10.Search passenger information from the system\n"
           <<"11.Remove passenger information from the system\n"
           <<"12.Display passengers from the system\n";
cout <<"\n===Staff Management System==="<<endl;
cout<<"13.Add members\n"<<endl;
        cout<<"14.Search staff members\n"<<endl;
        cout<<"15.Update staff members\n"<<endl;
        cout<<"16.Display staff members by their roles\n"<<endl;
        cout<<"17.Display staff members\n"<<endl;
        cout << "===Train Management System===" << endl;
        cout << "18. Add Train"<< endl;
        cout << "19. Display All Trains"<< endl;
        cout << "20. Search Train"<< endl;
        cout << "21. Delete Train"<< endl;
        cout << "22. Update Train"<< endl;
        cout << "23. Remove all trains"<< endl;
        cout << "24. Display seating map"<< endl;
        cout << "25.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        // Process user choice
        switch (choice) {
            case 1:
                bookTicket(tickets, ticketCount); // Call book ticket function
            break;

            case 2:
                viewTickets(tickets, ticketCount); // Call view tickets function
            break;

            case 3:
                listTickets(tickets, ticketCount); // Call list tickets function
            break;

            case 4: {
                int ticketID;
                cout << "Enter Ticket ID to cancel: ";
                cin >> ticketID;
                cancelTicket(tickets, ticketCount, ticketID); // Call cancel ticket function
                break;
            }
            case 5:
                addItem();
            break;
            case 6:
                trackCargo();
            break;
            case 7:
                removeItems();
            break;
            case 8:
                viewItems();
            break;
            case 9:
                addPassenger();
            break;
            case 10:
                searchPassenger();
            break;
            case 11:
                removePassenger();
            break;
            case 12:
                displayPassengers();
            break;
            case 13:
                count++;
                addMembers(staff,staffMembers);//calls the function to add members in our staff
                cout<<"Function call for staff management:"<<count<<endl;
            break;
            case 14:
            count++;
                int id;
            cout<<"Enter the ID of the staff member to search"<<endl;
            cin>>id;
            search(staff,id,staffMembers-1);// calls the function to search for a specific id
            cout<<"Function call for staff management:"<<count<<endl;
            break;
            case 15:
            count++;
            update(staff,staffMembers);//calls the function to update the information of a specific person using his id
            cout<<"Function call for staff management:"<<count<<endl;
            break;
            case 16:
            count++;
                staffRole(staff,staffMembers);//displays staff members according to their roles
                cout<<"Function call for staff management:"<<count<<endl;
            break;
            case 17:
            count++;
                displayStaff(staff,staffMembers);//generates a file Staff Member.txt and then writes the data of staff in it then and then reads line by line to display the staff member inforamtion
                cout<<"Function call for staff management:"<<count<<endl;
            break;
            case 18:
                addtrain();

            break;
            case 19:
                displayTrain();
            break;
            case 20:
                int SearchID;
            cout << "Enter the train ID to search: ";
            cin >> SearchID;
            SearchTrain(SearchID);
            break;
            case 21:
                int deleteID;
            cout << "Enter ID of the train to delete: ";
            cin >> deleteID;
            deleteTrain(deleteID);
            break;
            case 22:
                int updateID;
            cout << "Enter ID of the train to update: ";
            cin >> updateID;
            updateTrain(updateID);
            break;
            case 23:
                removeAllTrains();
            break;
            case 24:
                int SearchiD;
            cout << "Enter ID to search Train : ";
            cin >> SearchiD;
            seatsMapping(SearchiD);
            break;
            case 25:
                cout << "EXIT" << endl;
            break;

            default:
                cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 25); // Continue until user selects option 5
return 0;
}
/*

void suppliesMenu()
{
    char option;
    do {
        cout<<"1. addItems:"<<endl;
        cout<<"2. trac cargo:"<<endl;
        cout<<"3. remove items:"<<endl;
        cout<<"4. view items"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"Enter option :";
        cin>>option;
        switch(option) {
            case '1':
                addItem();
            break;
            case '2':
                trackCargo();
            break;
            case '3':
                removeItems();
            break;
            case '4':
                viewItems();
            break;
            case '5':
                cout<<"Exist the program:"<<endl;
            default:
                cout<<"Invalid option"<<endl;
        }
    }while(option!='5');
    return 0;
}

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
void satffMainMenu(){

        static int count=0;
        int choice;
        int staffMembers;
        cout<<"Enter the number of staff members"<<endl;
        cin>>staffMembers;//takes total number of staff member as input
        while(staffMembers<=0){//checks if total number of staff member is a positive integer
                cout << "Please enter a valid positive number for staff members: ";
                cin>>staffMembers;

        }
        Staff *staff = new Staff[staffMembers];//dynamically creates an array of size having total number of staff members

        do {
            cout<<"1. Add members"<<endl;
            cout<<"2. Search staff members"<<endl;
            cout<<"3. Update staff members"<<endl;
            cout<<"4. Display staff members by their role"<<endl;
            cout<<"5. Display staff members"<<endl;

            cout<<"6. Exit the program"<<endl;
            cout<<"Enter your choice:"<<endl;
                                                //a menu is created here
            cin>>choice;
            switch (choice) {//use switch case to perform operations
                case 1:
                    count++;
                    addMembers(staff,staffMembers);//calls the function to add members in our staff


                    break;

                case 2:
                count++;
                int id;
                cout<<"Enter the ID of the staff member to search"<<endl;
                cin>>id;

                search(staff,id,staffMembers-1);// calls the function to search for a specific id

                    break;
                case 3:
                    count++;
                    update(staff,staffMembers);//calls the function to update the information of a specific person using his id
                break;
                case 4:
                count++;
                    staffRole(staff,staffMembers);//displays staff members according to their roles
                break;
                case 5:
                count++;
                    displayStaff(staff,staffMembers);//generates a file Staff Member.txt and then writes the data of staff in it then and then reads line by line to display the staff member inforamtion
                break;


                case 6://when user enter 6 it exits program and also deallocates memory for the array
                    count++;
                    cout<<"the functions have been called "<<count<<" times."<<endl;
                    delete[] staff;
                staff=nullptr;
                cout<<"Exiting our program..."<<endl;
                break;

                default:
                    cout<<"Invlid value enterd .Please enter a valid value"<<endl;
                    break;
            }
        }while (choice!=6);



}

 */
