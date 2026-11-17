#pragma once
#include <string>
#include <memory>
#include "Template/Collection.h"

class Hall;
class Session;
class Ticket;
class Ticket_system;

class File_Manager {
public:
    static void save_system(const std::string& filename,
                            const Collection<std::shared_ptr<Hall>>& halls,
                            const Collection<std::shared_ptr<Session>>& sessions,
                            const Ticket_system& system);

    static void load_system(const std::string& filename,
                            Collection<std::shared_ptr<Hall>>& halls,
                            Collection<std::shared_ptr<Session>>& sessions,
                            Ticket_system& system);

    static void log_action(const std::string& message);

    static void generate_report(const std::string& filename,
                                const Collection<std::shared_ptr<Hall>>& halls,
                                const Collection<std::shared_ptr<Session>>& sessions,
                                const Ticket_system& system);
};