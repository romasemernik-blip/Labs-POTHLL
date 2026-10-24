#pragma once
#include <memory>
#include "Template/Collection.h"

class Session;
class Hall;

void change_session_field(Collection<std::shared_ptr<Session>>& sessions,
                          Collection<std::shared_ptr<Hall>>& halls,
                          int idx);