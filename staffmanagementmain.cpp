/*#include <iostream>
using namespace  std;
#include"staffmanagementfunction.h"
    int main() {
        satffMainMenu();

    return 0;
}
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