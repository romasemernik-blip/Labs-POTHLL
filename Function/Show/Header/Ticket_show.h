#pragma once
#include <memory>
#include <vector>

using namespace std;

class Ticket;

void Show_all_tickets(const vector<shared_ptr<Ticket>>& tickets);
void Show_ticket_short(const vector<shared_ptr<Ticket>>& tickets);
void Show_ticket_short_no_price(const vector<shared_ptr<Ticket>>& tickets);