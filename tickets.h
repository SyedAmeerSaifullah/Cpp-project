#ifndef TICKETS_H
#define TICKETS_H
#include <string>
using namespace std;


const int MAX_TICKETS = 100;  // Maximum number of tickets
//struct that represents train ticket
struct TrainTicket {
    int ticketID;
    string trainID;
    string passengerID;
    string departureTime;
    string seatNumber;
};

// function declarations
void bookTicket(TrainTicket tickets[], int& ticketCount);   // book a ticket
void viewTickets(const TrainTicket tickets[], int ticketCount); // view all booked tickets
void listTickets(const TrainTicket tickets[], int ticketCount); // list all tickets with basic info
void cancelTicket(TrainTicket tickets[], int& ticketCount, int ticketID); // cancel a ticket

#endif
