#include "tickets.h"
#include <iostream>

using namespace std;

void bookTicket(TrainTicket tickets[], int& ticketCount) {
    if (ticketCount >= MAX_TICKETS) {  //show error message if ticket count exceeds maximum
        cout << "Sorry, no more tickets can be booked.\n";
        return;  //exit
    }

    TrainTicket newTicket;   //new ticket object
    newTicket.ticketID = ticketCount + 1;    //new ticket id

    cout << "Enter Train ID : ";    //ask user to enter info
    getline(cin, newTicket.trainID);

    cout << "Enter Passenger ID : ";
    getline(cin, newTicket.passengerID);

    cout << "Enter Departure Time (HH:MM): ";
    getline(cin, newTicket.departureTime);

    cout << "Enter Seat Number : ";
    getline(cin, newTicket.seatNumber);

    tickets[ticketCount] = newTicket;   //store new ticket in tickets array
    ticketCount++;                      //increase tickets count
    cout << "Ticket booked successfully!\n";
}

void viewTickets(const TrainTicket tickets[], int ticketCount) {
    if (ticketCount == 0) {
        cout << "No tickets have been booked yet.\n";    //if no tickets booked display message
        return;
    }

    for (int i = 0; i < ticketCount; ++i) {   //loop through all tickets and display info
        cout << "Ticket ID: " << tickets[i].ticketID << "\n";
        cout << "Train ID: " << tickets[i].trainID << "\n";
        cout << "Passenger ID: " << tickets[i].passengerID << "\n";
        cout << "Departure Time: " << tickets[i].departureTime << "\n";
        cout << "Seat Number: " << tickets[i].seatNumber << "\n";
        cout << "----------------------\n";
    }
}

void listTickets(const TrainTicket tickets[], int ticketCount) {
    if (ticketCount == 0) {
        cout << "No tickets have been booked yet.\n";
        return;
    }

    cout << "List of Booked Tickets:\n";
    for (int i = 0; i < ticketCount; ++i) {
        cout << "Ticket ID: " << tickets[i].ticketID << " - ";
        cout << "Train ID: " << tickets[i].trainID << ", ";
        cout << "Passenger ID: " << tickets[i].passengerID << "\n";
    }
}

void cancelTicket(TrainTicket tickets[], int& ticketCount, int ticketID) {
    bool found = false;
    // look for the ticket ID
    for (int i = 0; i < ticketCount; ++i) {
        if (tickets[i].ticketID == ticketID) {
            found = true;
            // shift all tickets after the canceled ticket to the left
            for (int j = i; j < ticketCount - 1; ++j) {
                tickets[j] = tickets[j + 1];
            }
            ticketCount--;  // reduce ticket count
            cout << "Ticket with ID " << ticketID << " has been canceled.\n";
            break;  // exit the loop once ticket is found
        }
    }

    // if no ticket found
    if (!found) {
        cout << "Ticket with ID " << ticketID << " not found.\n";
    }
}
