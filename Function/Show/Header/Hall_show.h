#pragma once
#include <memory>
#include <vector>

class Hall;

void show_all_halls(const std::vector<std::shared_ptr<Hall>>& halls);
void show_hall_names(const std::vector<std::shared_ptr<Hall>>& halls);