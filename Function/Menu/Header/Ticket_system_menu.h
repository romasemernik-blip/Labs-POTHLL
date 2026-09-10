#pragma once
#include <memory>
#include <vector>

using namespace std;

class Ticket_system;
class Ticket;
class Session;

void Menu_ticket_system(Ticket_system& system,
                        vector<shared_ptr<Ticket>>& tickets,
                        vector<shared_ptr<Session>>& sessions);