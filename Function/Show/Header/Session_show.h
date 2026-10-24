#pragma once
#include <memory>
#include "Class/Header/Hall.h" 
#include "Class/Header/Session.h"
#include "Template/Collection.h"

class Session;

void show_all_sessions(const Collection<std::shared_ptr<Session>>& sessions);
void show_session_films(const Collection<std::shared_ptr<Session>>& sessions);
void show_halls_bigger_than(const Session& s,
                            const Collection<std::shared_ptr<Hall>>& halls);