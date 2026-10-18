#include "Function/Menu/Header/Fifth_lab_menu.h"
#include "Template/Collection.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include <iostream>
#include <string>
#include <string_view>
#include <memory>

using namespace std;

static void handle_print(const Collection<shared_ptr<Ticket>>& tc,
                         const Collection<shared_ptr<Session>>& sc,
                         const Collection<string>& strc, int choice) {
    if (choice == 1) {
        tc.print(cout, [](const shared_ptr<Ticket>& t, ostream& os) { t->print_ticket(os); });
    } else if (choice == 2) {
        sc.print(cout, [](const shared_ptr<Session>& s, ostream& os) { 
            os << s->get_film() << " | seats: " << s->seats_limit() << "\n"; 
        });
    } else if (choice == 3) {
        strc.print(cout, [](string_view str, ostream& os) { os << str << "\n"; }); 
    }
}

static void handle_size(const Collection<shared_ptr<Ticket>>& tc,
                        const Collection<shared_ptr<Session>>& sc,
                        const Collection<string>& strc, int choice) {
    if (choice == 4) cout << "Ticket Collection size: " << tc.size() << "\n";
    else if (choice == 5) cout << "Session Collection size: " << sc.size() << "\n";
    else if (choice == 6) cout << "String Collection size: " << strc.size() << "\n";
}

static void handle_get(Collection<shared_ptr<Ticket>>& tc, Collection<string>& strc, int choice) {
    if (choice == 7) {
        if (int idx = read_int("Enter ticket index: "); idx >= 0 && idx < static_cast<int>(tc.size())) {
            cout << "Ticket at index " << idx << ":\n";
            tc.get(idx)->print_ticket(cout);
        } else cout << "Index out of bounds.\n";
    } else if (choice == 8) {
        if (int idx = read_int("Enter string index: "); idx >= 0 && idx < static_cast<int>(strc.size())) {
            cout << "String at index " << idx << ": " << strc.get(idx) << "\n";
        } else cout << "Index out of bounds.\n";
    }
}

static void handle_modify(Collection<shared_ptr<Ticket>>& tc, Collection<string>& strc, 
                          const vector<shared_ptr<Session>>& sessions, int choice) {
    if (choice == 9) {
        int r = read_int("Row: ");
        int p = read_int("Place: ");
        int idx = tc.find_if([r, p](const shared_ptr<Ticket>& t) { return t->get_row() == r && t->get_place() == p; });
        if (idx != -1) cout << "Found at index " << idx << "\n";
        else cout << "Not found.\n";
    } else if (choice == 10) {
        if (int idx = read_int("Index to remove ticket: "); idx >= 0 && tc.remove_at(idx)) {
            cout << "Ticket removed. New size: " << tc.size() << "\n";
        } else cout << "Invalid index.\n";
    } else if (choice == 11) {
        strc.clear();
        cout << "String collection cleared. New size: " << strc.size() << "\n";
    } else if (choice == 16) { 
        string s = read_string("Enter new string to add: ");
        strc.add(s);
        cout << "String added. New size: " << strc.size() << "\n";
    } else if (choice == 17) { 
        if (int idx = read_int("Index to remove string: "); idx >= 0 && strc.remove_at(idx)) {
            cout << "String removed. New size: " << strc.size() << "\n";
        } else cout << "Invalid index.\n";
    } else if (choice == 18) { 
        if (sessions.empty()) {
            cout << "Cannot add ticket: no sessions available.\n";
            return;
        }
        int r = read_int("New ticket row: ");
        int p = read_int("New ticket place: ");
        float pr = read_float("New ticket price: ");
        auto new_ticket = make_shared<Standard_ticket>(r, p, pr, sessions[0], "Standard");
        tc.add(new_ticket);
        cout << "New Standard_ticket added to collection. New size: " << tc.size() << "\n";
    } else if (choice == 19) { 
        tc.clear();
        cout << "Ticket collection cleared. New size: " << tc.size() << "\n";
    }
}

static void handle_algorithms(const Collection<shared_ptr<Ticket>>& tc, const Collection<string>& strc, int choice) {
    if (choice == 12) {
        auto best = find_best(tc, [](const shared_ptr<Ticket>& a, const shared_ptr<Ticket>& b) { return a->final_price() > b->final_price(); });
        cout << "Most expensive ticket:\n";
        best->print_ticket(cout);
    } else if (choice == 13) {
        auto best = find_best(strc, [](string_view a, string_view b) { return a.length() > b.length(); }); 
        cout << "Longest string: " << best << "\n";
    } else if (choice == 14) {
        int count = count_if(tc, [](const shared_ptr<Ticket>& t) { return t->type_name() == "VIP"; });
        cout << "Number of VIP tickets: " << count << "\n";
    } else if (choice == 15) {
        Collection<string> filtered = filter(strc, [](string_view s) { return !s.empty() && s[0] == 'B'; });
        cout << "Filtered strings (starting with 'B'):\n";
        filtered.print(cout, [](string_view s, ostream& os) { os << s << "\n"; });
    }
}

void menu_fifth_lab(const vector<shared_ptr<Ticket>>& tickets,
                    const vector<shared_ptr<Session>>& sessions) {

    Collection<shared_ptr<Ticket>> ticket_coll;
    for (const auto& t : tickets) ticket_coll.add(t);

    Collection<shared_ptr<Session>> session_coll;
    for (const auto& s : sessions) session_coll.add(s);

    Collection<string> string_coll;
    string_coll.add("Apple");
    string_coll.add("Banana");
    string_coll.add("Watermelon");
    string_coll.add("Blueberry");

    while (true) {
        cout << "\nLAB 5: TEMPLATES (COLLECTION<T>)\n";
        cout << "--- User-defined types (Ticket) ---\n";
        cout << "1. [print] Show Ticket Collection\n";
        cout << "10.[removeAt] Remove Ticket by index\n";
        cout << "18.[add]     Add new Ticket to Collection\n";
        cout << "19.[clear]   Clear Ticket Collection\n";  
        
        cout << "--- User-defined types (Session) ---\n";
        cout << "2. [print] Show Session Collection\n";
        cout << "5. [size]  Get size of Session Collection\n";
        
        cout << "--- Base types (string) ---\n";
        cout << "3. [print] Show String Collection\n";
        cout << "6. [size]  Get size of String Collection\n";
        cout << "8. [get]   Get String by index\n";
        cout << "11.[clear] Clear String Collection\n";
        cout << "16.[add]   Add new string to Collection\n"; 
        cout << "17.[removeAt] Remove string by index\n"; 
        
        cout << "--- Other methods ---\n";
        cout << "4. [size]  Get size of Ticket Collection\n";
        cout << "7. [get]   Get Ticket by index\n";
        cout << "9. [findIf] Find Ticket by row and place\n";
        
        cout << "--- Template Functions ---\n";
        cout << "12.[findBest] Find most expensive ticket\n";
        cout << "13.[findBest] Find longest string\n";
        cout << "14.[countIf] Count VIP tickets\n";
        cout << "15.[filter]  Filter strings starting with 'B'\n";
        
        cout << "0. Back\n";

        int choice = read_int("Choice: ");
        if (choice == 0) break;

        if (choice >= 1 && choice <= 3) handle_print(ticket_coll, session_coll, string_coll, choice);
        else if (choice >= 4 && choice <= 6) handle_size(ticket_coll, session_coll, string_coll, choice);
        else if (choice == 7 || choice == 8) handle_get(ticket_coll, string_coll, choice);
        else if ((choice >= 9 && choice <= 11) || (choice >= 16 && choice <= 19)) 
            handle_modify(ticket_coll, string_coll, sessions, choice);
        else if (choice >= 12 && choice <= 15) handle_algorithms(ticket_coll, string_coll, choice);
        else cout << "Invalid choice.\n";
    }
}