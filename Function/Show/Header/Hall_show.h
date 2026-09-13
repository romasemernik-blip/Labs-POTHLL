#pragma once
#include <memory>
#include <vector>

class Hall;

void Show_all_halls(const std::vector<std::shared_ptr<Hall>>& halls);
void Show_hall_names(const std::vector<std::shared_ptr<Hall>>& halls);