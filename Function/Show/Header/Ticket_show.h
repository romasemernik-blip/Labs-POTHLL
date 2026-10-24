#pragma once
#include <memory>
#include "Template/Collection.h"

class Ticket;

void show_all_tickets(const Collection<std::shared_ptr<Ticket>>& tickets);
void show_ticket_short(const Collection<std::shared_ptr<Ticket>>& tickets);
void show_ticket_short_no_price(const Collection<std::shared_ptr<Ticket>>& tickets);

bool is_duplicate_ticket(const Collection<std::shared_ptr<Ticket>>& tickets,
                         const Ticket& candidate);