#pragma once
#include <memory>
#include "Template/Collection.h"

class Ticket;
class Session;

void menu_fifth_lab( Collection<std::shared_ptr<Ticket>>& tickets,
                    const Collection<std::shared_ptr<Session>>& sessions);