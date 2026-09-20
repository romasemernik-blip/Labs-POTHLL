#pragma once
#include <memory>
#include <vector>

class Session;

void Show_all_sessions(const std::vector<std::shared_ptr<Session>>& sessions);
void Show_session_films(const std::vector<std::shared_ptr<Session>>& sessions);
void Show_halls_bigger_than(const Session& s,
                            const std::vector<std::shared_ptr<Hall>>& halls);