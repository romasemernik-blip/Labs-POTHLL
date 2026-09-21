#pragma once
#include <memory>
#include <vector>

class Ticket;
class Session;

void change_ticket_field(std::vector<std::shared_ptr<Ticket>>& tickets,
                         std::vector<std::shared_ptr<Session>>& sessions,
                         int idx);