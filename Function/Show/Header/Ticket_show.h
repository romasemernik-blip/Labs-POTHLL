#pragma once
#include <memory>
#include <vector>

class Ticket;

void show_all_tickets(const std::vector<std::shared_ptr<Ticket>>& tickets);
void show_ticket_short(const std::vector<std::shared_ptr<Ticket>>& tickets);
void show_ticket_short_no_price(const std::vector<std::shared_ptr<Ticket>>& tickets);