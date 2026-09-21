#pragma once
#include <memory>
#include <vector>


class Session;
class Hall;

void change_session_field(std::vector<std::shared_ptr<Session>>& sessions,
                          std::vector<std::shared_ptr<Hall>>& halls,
                          int idx);