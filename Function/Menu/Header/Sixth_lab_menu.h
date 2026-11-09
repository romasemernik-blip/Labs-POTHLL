#pragma once
#include <memory>
#include "Template/Collection.h"

class Ticket_System;
class Ticket;
class Session;
class Hall;

void menu_sixth_lab(Ticket_system& system,
                    Collection<std::shared_ptr<Session>>& sessions,
                    Collection<std::shared_ptr<Ticket>>& tickets,
                    Collection<std::shared_ptr<Hall>>& halls);