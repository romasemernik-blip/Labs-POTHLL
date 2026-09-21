#pragma once
#include <memory>
#include <vector>

class Hall;

void change_hall_field(std::vector<std::shared_ptr<Hall>>& halls, int idx);