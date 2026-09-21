#pragma once
#include <memory>
#include <vector>

class Ticket;
class Session;

void menu_ticket(std::vector<std::shared_ptr<Ticket>>& tickets,
                 std::vector<std::shared_ptr<Session>>& sessions);