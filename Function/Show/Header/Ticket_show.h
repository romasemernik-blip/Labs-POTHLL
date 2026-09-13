#pragma once
#include <memory>
#include <vector>

class Ticket;

void Show_all_tickets(const std::vector<std::shared_ptr<Ticket>>& tickets);
void Show_ticket_short(const std::vector<std::shared_ptr<Ticket>>& tickets);
void Show_ticket_short_no_price(const std::vector<std::shared_ptr<Ticket>>& tickets);