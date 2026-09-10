#pragma once
#include <memory>
#include <vector>

using namespace std;

class Ticket;
class Session;

void Change_ticket_field(vector<shared_ptr<Ticket>>& tickets,
                         vector<shared_ptr<Session>>& sessions,
                         int idx);