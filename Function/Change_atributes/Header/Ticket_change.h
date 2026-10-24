#pragma once
#include <memory>
#include "Template/Collection.h"

class Ticket;
class Session;

void change_ticket_field(Collection<std::shared_ptr<Ticket>>& tickets,
                         Collection<std::shared_ptr<Session>>& sessions,
                         int idx);