#pragma once
#include <memory>
#include <vector>

class Session;
class Hall;

void Menu_session(std::vector<std::shared_ptr<Session>>& sessions,
                  std::vector<std::shared_ptr<Hall>>& halls);