#pragma once
#include <memory>
#include "Template/Collection.h"

class Hall;
class Session;
class Ticket;
class Ticket_system;

void menu_seventh_lab(Ticket_system& system,
                      Collection<std::shared_ptr<Hall>>& halls,
                      Collection<std::shared_ptr<Session>>& sessions);