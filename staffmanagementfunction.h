#ifndef STAFFMANAGEMENTFUNCTION_H
#define STAFFMANAGEMENTFUNCTION_H
#include<iostream>
#include<fstream>
using namespace std;
struct Staff {
    string staffName;
    int staffID;
    string role;
};
void addMembers(Staff staff[],int &staffMembers) ;
void search(Staff staff[],int Id,int index);
void update(Staff staff[],int &staffMembers) ;
void staffRole(Staff staff[],int &staffMembers);
//void staffMainMenu();
void displayStaff(Staff staff[],const int staffMembers) ;

void numberoftimesfunctioncalled();
#endif



