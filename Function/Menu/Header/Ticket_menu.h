#pragma once
#include <memory>
#include <vector>
#include "Template/Collection.h"

class Ticket;
class Session;

void menu_ticket(Collection<std::shared_ptr<Ticket>>& tickets,
                 Collection<std::shared_ptr<Session>>& sessions);