#pragma once
#include <vector>
#include <memory>

class Ticket;
class Session;

void menu_fifth_lab(std::vector<std::shared_ptr<Ticket>>& tickets,
                    std::vector<std::shared_ptr<Session>>& sessions);