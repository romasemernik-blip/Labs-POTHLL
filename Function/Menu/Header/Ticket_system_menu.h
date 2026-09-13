#pragma once
#include <memory>
#include <vector>

class Ticket_system;
class Ticket;
class Session;

void Menu_ticket_system(Ticket_system& system,
                        std::vector<std::shared_ptr<Ticket>>& tickets,
                        std::vector<std::shared_ptr<Session>>& sessions);