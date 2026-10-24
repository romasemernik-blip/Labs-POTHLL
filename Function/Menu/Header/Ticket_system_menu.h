#pragma once
#include <memory>
#include <vector>
#include "Template/Collection.h"

class Ticket_system;
class Ticket;
class Session;

void menu_ticket_system(Ticket_system& system,
                        Collection<std::shared_ptr<Ticket>>& tickets,
                        Collection<std::shared_ptr<Session>>& sessions);