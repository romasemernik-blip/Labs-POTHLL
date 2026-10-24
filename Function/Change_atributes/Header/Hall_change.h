#pragma once
#include <memory>
#include "Template/Collection.h"

class Hall;

void change_hall_field(Collection<std::shared_ptr<Hall>>& halls, int idx);