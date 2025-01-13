#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include<fstream>
using namespace std;
struct Staff {
    string staffName;
    int staffID;
    string role;
};
void addMembers(Staff staff[],int &staffMembers) ;
void search(Staff staff[],int id,int index);
void update(Staff staff[],int &staffMembers) ;
void staffRole(Staff staff[],int &staffMembers,int index);

void displayStaff(Staff staff[],int &staffMembers) ;

#endif //FUNCTIONS_H



