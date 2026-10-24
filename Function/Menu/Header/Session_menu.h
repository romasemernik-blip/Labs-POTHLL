#pragma once
#include <memory>
#include <vector>
#include "Template/Collection.h"

class Session;
class Hall;

void menu_session(Collection<std::shared_ptr<Session>>& sessions,
                  Collection<std::shared_ptr<Hall>>& halls);