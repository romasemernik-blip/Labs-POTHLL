#pragma once
#include <vector>
#include <memory>

class Ticket;
class Session;

void menu_fifth_lab( const std::vector<std::shared_ptr<Ticket>>& tickets,
                     const std::vector<std::shared_ptr<Session>>& sessions);