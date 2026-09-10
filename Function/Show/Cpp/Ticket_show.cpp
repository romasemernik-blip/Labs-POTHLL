#include "Function/Show/Header/Ticket_show.h"
#include "Class/Header/Ticket.h"
#include <iostream>

using namespace std;

void Show_all_tickets(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n";
    tickets[i]->Out_t();
  }
}

void Show_ticket_short(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] Row " << tickets[i]->Get_row()
         << ", place " << tickets[i]->Get_place()
         << ", price " << tickets[i]->Get_price() << endl;
  }
}

void Show_ticket_short_no_price(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] Row " << tickets[i]->Get_row()
         << ", place " << tickets[i]->Get_place() << endl;
  }
}