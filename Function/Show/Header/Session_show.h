#pragma once
#include <memory>
#include <vector>
#include "Class/Header/Hall.h" 
#include "Class/Header/Session.h"
class Session;

void show_all_sessions(const std::vector<std::shared_ptr<Session>>& sessions);
void show_session_films(const std::vector<std::shared_ptr<Session>>& sessions);
void show_halls_bigger_than(const Session& s,
                            const std::vector<std::shared_ptr<Hall>>& halls);