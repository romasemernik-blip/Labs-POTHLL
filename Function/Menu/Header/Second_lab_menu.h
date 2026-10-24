#pragma once
#include <memory>
#include <vector>
#include "Class/Header/Session.h"
#include "Class/Header/Hall.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Ticket_system.h"
#include "Template/Collection.h"

void menu_second_lab(Collection<std::shared_ptr<Hall>>& halls,
                     const Collection<std::shared_ptr<Session>>& sessions,
                     const Collection<std::shared_ptr<Ticket>>& tickets,
                     Ticket_system& system);