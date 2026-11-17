#include "Function/Menu/Header/Seventh_lab_menu.h"
#include "Class/File/Header/File_manager.h"
#include "Class/Header/Ticket_system.h"
#include "Function/Read/Header/Read.h"
#include <iostream>
#include "Exception/Header/All_exceptions.h"

using namespace std;

void menu_seventh_lab(Ticket_system& system,
                      Collection<shared_ptr<Hall>>& halls,
                      Collection<shared_ptr<Session>>& sessions) {
    while (true) {
        try {
            cout << "\nLAB 7: FILE I/O\n";
            cout << "1. Save system to data.txt\n";
            cout << "2. Load system from data.txt\n";
            cout << "3. Generate text report (report.txt)\n";
            cout << "4. Write test message to log\n";
            cout << "0. Back to Main Menu\n";

            int choice = read_int("Choice: ");
            if (choice == 0) return;

            switch (choice) {
                case 1:
                    File_Manager::save_system("data.txt", halls, sessions, system);
                    File_Manager::log_action("System saved to data.txt");
                    cout << "[OK] System saved successfully.\n";
                    break;
                case 2:
                    File_Manager::load_system("data.txt", halls, sessions, system);
                    File_Manager::log_action("System loaded from data.txt");
                    cout << "[OK] System loaded successfully.\n";
                    break;
                case 3:
                    File_Manager::generate_report("report.txt", halls, sessions, system);
                    File_Manager::log_action("Report generated to report.txt");
                    cout << "[OK] Report generated.\n";
                    break;
                case 4:
                    File_Manager::log_action("Test log message from menu");
                    cout << "[OK] Log updated.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        }
        catch (const Cinema_Exception& e) {
            cout << "[FILE ERROR] " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            cout << "[STD ERROR] " << e.what() << "\n";
        }
    }
}