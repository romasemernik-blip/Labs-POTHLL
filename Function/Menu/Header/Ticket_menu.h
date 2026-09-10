#pragma once
#include <memory>
#include <vector>

using namespace std;

class Ticket;
class Session;

void Menu_ticket(vector<shared_ptr<Ticket>>& tickets,
                 vector<shared_ptr<Session>>& sessions);