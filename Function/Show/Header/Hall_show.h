#pragma once
#include <memory>
#include "Template/Collection.h"

class Hall;

void show_all_halls(const Collection<std::shared_ptr<Hall>>& halls);
void show_hall_names(const Collection<std::shared_ptr<Hall>>& halls);