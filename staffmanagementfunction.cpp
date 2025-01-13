#include"staffmanagementfunction.h"
#include<iostream>
int id;

void addMembers(Staff staff[],int &staffMembers) {//this function adds members of the staff and stores their name,id and role
   
    cout<<"Enter the information about the staff members"<<endl;
    for(int i=0;i<staffMembers;i++) {
        
        cout<<"Enter the information about "<<i+1<<" staff member"<<endl;

        cout<<"Enter the Name of staff member "<<i+1<<" :"<<endl;

        getline(cin>>ws,staff[i].staffName);
        cout<<"Enter the Staff ID of staff member "<<i+1<<" :"<<endl;
        cin>>staff[i].staffID;
        cout<<"Enter the Role  of staff member "<<i+1<<" :"<<endl;

        getline(cin>>ws,staff[i].role);
    }
}
void search(Staff staff[],int Id,int index) {//this reccursive function searches for a specific id and displays his name

//base case
if(index<-1) {//if index becomes less than -1 then it terminates
    cout<<"No person found with this id"<<endl;
    return;
}
if(Id==staff[index].staffID) {//id searched by the user is equal to any id in our struct then displays that member
    cout<<"This person exits in our staff. The person is "<<staff[index].staffName<<endl;
    return;
}

//recursive case
else {
search(staff,Id,index-1);//recursively calls the function
}
}

void update(Staff staff[],int &staffMembers) {//this update function updates the information of a person using the id input by the user and then uses switch case whether he wants to update his name,id or his role or wants to do all
 
    int count=0;// a count varaible is initialized
    cout<<"Enter  the id to update :"<<endl;//asks the user about id to update
    
    cin>>id;

    for(int i=0;i<staffMembers;i++) {//starts a loop to total staff members
if(staff[i].staffID==id) {//if the current staffmember through loop is equal to id entered by the user it updates count and gives the menu
    count++;
int choice;

    do {
        cout<<"1. Update name"<<endl;//menu asks the user whether he wants to update name,id or role
        cout<<"2. Update ID"<<endl;
        cout<<"3. Update role"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;
    switch (choice) {
        case 1:
            cout<<"Enter the updated name:"<<endl;

            getline(cin>>ws,staff[i].staffName);
            break;
        case 2:
            cout<<"Enter the updated id"<<endl;
            cin>>staff[i].staffID;
            break;
        case 3:
            cout<<"Enter the Updated role "<<endl;
        getline(cin>>ws,staff[i].role);
            break;
        case 4:
            break;
        default:
            cout<<"You entered an invalid number"<<endl;
            break;
    }




    }while (choice!=4);


}
    }
    if(count==0) {//we had initalized count to if it does not change then if statemnent displays the no one had this id
        cout<<" none of our staff member has "<<id<<" id. " <<endl;
    }
}
void staffRole(Staff staff[],int &staffMembers) {//dipslays the staff members according to their role

for(int i=0;i<staffMembers-1;i++) {//diplays the role of a person 
    cout<<staff[i].role<< " :"<<endl;
    cout<<staff[i].staffName<<endl;
for(int j=staffMembers-1;j>=0;j--) {//it gives the same role of other persons

    if(i==j) {
        continue;
    }
    else {
        if (staff[i].role==staff[j].role) {

            cout<<staff[j].staffName<<endl;

        }

    }

}
}
}

void displayStaff(Staff staff[],const int staffMembers) {//write the inforamtion of staff to a file and then reads it to display staff
 
        ofstream o("Staff Member.txt");
        if(o) {
            for(int i=0;i<staffMembers;i++) {
                o<<staff[i].staffName<< ' '<<staff[i].staffID<< ' '<<staff[i].role<<endl;

            }
            o.close();
        }
    cout<<"The staff member names ,their IDs and their role are dipslayed as"<<endl;
    ifstream i("Staff Member.txt");
    string st;
    
    if(i) {
        while(!i.eof()) {

            getline(i,st);
            cout<<st<<endl;
        }
    }
    if(i) {
        i.close();
    }
}



