#include "Function/Show/Header/Ticket_show.h"
#include "Class/Header/Ticket.h"
#include <iostream>

using namespace std;

void show_all_tickets(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n";
    tickets[i]->out_t();
  }
}

void show_ticket_short(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] Row " << tickets[i]->get_row()
         << ", place " << tickets[i]->get_place()
         << ", price " << tickets[i]->get_price() << endl;
  }
}

void show_ticket_short_no_price(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] Row " << tickets[i]->get_row()
         << ", place " << tickets[i]->get_place() << endl;
  }
}