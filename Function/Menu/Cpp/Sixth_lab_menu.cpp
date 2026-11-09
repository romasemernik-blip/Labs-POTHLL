#include "Function/Menu/Header/Sixth_lab_menu.h"
#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Session.h"
#include "Class/Header/Hall.h"
#include "Structure/Header/Date.h"
#include "Function/Read/Header/Read.h"
#include <iostream>
#include "Exception/Header/All_exceptions.h"

using namespace std;

static void demo_invalid_data() {
    try {
        cout << "Trying to create Date(2026, 13, 1) (invalid month)...\n";
        Date d(2026, 13, 1); 
    }
    catch (const Invalid_Data_Exception& e) {
        cout << "[CAUGHT] Invalid_Data_Exception:\n  -> " << e.what() << "\n";
    }
}

static void demo_object_not_found(Ticket_system& system) {
    try {
        cout << "Trying to remove a ticket that does not exist in system...\n";
        auto fake_session = make_shared<Session>("Fake", nullptr, nullptr, nullptr);
        Standard_ticket fake_ticket(99, 99, 10.0f, fake_session);
        system -= fake_ticket; 
    }
    catch (const Object_Not_Found_Exception& e) {
        cout << "[CAUGHT] Object_Not_Found_Exception:\n  -> " << e.what() << "\n";
    }
}

static void demo_duplicate_id(Ticket_system& system, Collection<shared_ptr<Ticket>>& tickets) {
    try {
        if (tickets.empty()) {
            cout << "[WARNING] Need at least 1 ticket in collection to demo this.\n";
            return;
        }
        cout << "Trying to add the same ticket to system twice...\n";
        
        system.in_shared_ticket(tickets.at(0)); 
        system.in_shared_ticket(tickets.at(0)); 
        
    }
    catch (const Duplicate_Id_Exception& e) {
        cout << "[CAUGHT] Duplicate_Id_Exception:\n  -> " << e.what() << "\n";
    }
}

static void demo_limit_exceeded(Collection<shared_ptr<Session>>& sessions, Collection<shared_ptr<Hall>>& halls) {
    try {
        if (sessions.empty() || halls.empty()) throw runtime_error("Need sessions and halls.");
        cout << "Trying to change a session's hall to a smaller one...\n";

        sessions.at(0)->can_change_hall(halls.at(1)); 
    }
    catch (const Limit_Exceeded_Exception& e) {
        cout << "[CAUGHT] Limit_Exceeded_Exception:\n  -> " << e.what() << "\n";
    }
}

static void demo_out_of_range(Collection<shared_ptr<Ticket>>& tickets) {
    try {
        cout << "Trying to access ticket at index 9999...\n";
        tickets.at(9999); 
    }
    catch (const Out_Of_Range_Exception& e) {
        cout << "[CAUGHT] Out_Of_Range_Exception:\n  -> " << e.what() << "\n";
    }
}

static void demo_invalid_operation(Collection<shared_ptr<Session>>& sessions) {
    try {
        if (sessions.empty()) throw runtime_error("Need at least 1 session.");
        cout << "Trying to return a seat when 0 seats were sold...\n";
        while(sessions.at(0)->sold_seats() > 0) sessions.at(0)->return_seat();
        sessions.at(0)->return_seat(); 
    }
    catch (const Invalid_Operation_Exception& e) {
        cout << "[CAUGHT] Invalid_Operation_Exception:\n  -> " << e.what() << "\n";
    }
}

static void demo_relation(Collection<shared_ptr<Session>>& sessions) {
    try {
        if (sessions.empty()) throw runtime_error("Need at least 1 session.");
        cout << "Trying to link a session to a null hall...\n";
        sessions.at(0)->in_hall(nullptr); 
    }
    catch (const Relation_Exception& e) {
        cout << "[CAUGHT] Relation_Exception:\n  -> " << e.what() << "\n";
    }
}

void menu_sixth_lab(Ticket_system& system,
                    Collection<shared_ptr<Session>>& sessions,
                    Collection<shared_ptr<Ticket>>& tickets,
                    Collection<shared_ptr<Hall>>& halls) {
    while (true) {
        cout << "\n--- LAB 6: EXCEPTION HANDLING DEMO ---\n";
        cout << "1. Trigger Invalid_Data_Exception (Bad Date)\n";
        cout << "2. Trigger Object_Not_Found_Exception (Remove fake ticket)\n";
        cout << "3. Trigger Duplicate_Id_Exception (Sell same seat twice)\n";
        cout << "4. Trigger Limit_Exceeded_Exception (Change to smaller hall)\n";
        cout << "5. Trigger Out_Of_Range_Exception (Bad collection index)\n";
        cout << "6. Trigger Invalid_Operation_Exception (Return non-existent seat)\n";
        cout << "7. Trigger Relation_Exception (Link to null hall)\n";
        cout << "0. Back to Main Menu\n";

        int choice = read_int("Choice: ");

        if (choice == 0) return;

        try {
            switch (choice) {
                case 1: demo_invalid_data(); break;
                case 2: demo_object_not_found(system); break;
                case 3: demo_duplicate_id(system, tickets); break;
                case 4: demo_limit_exceeded(sessions, halls); break;
                case 5: demo_out_of_range(tickets); break;
                case 6: demo_invalid_operation(sessions); break;
                case 7: demo_relation(sessions); break;
                default: cout << "Invalid choice.\n";
            }
            cout << "=> Program continues to work normally.\n";
        }
        catch (const std::exception& e) {
            cout << "[DEMO WARNING] " << e.what() << "\n";
        }
    }
}