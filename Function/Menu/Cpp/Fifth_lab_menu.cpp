#include "Function/Menu/Header/Fifth_lab_menu.h"
#include "Template/Collection.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include <iostream>
#include <string>

using namespace std;

void menu_fifth_lab(vector<shared_ptr<Ticket>>& tickets,
                    vector<shared_ptr<Session>>& sessions) {

    Collection<shared_ptr<Ticket>> ticket_coll;
    for (auto& t : tickets) ticket_coll.add(t);

    Collection<shared_ptr<Session>> session_coll;
    for (auto& s : sessions) session_coll.add(s);

    Collection<string> string_coll;
    string_coll.add("Apple");
    string_coll.add("Banana");
    string_coll.add("Watermelon");
    string_coll.add("Blueberry");

    while (true) {
        cout << "\nLAB 5: TEMPLATES (COLLECTION<T>)\n";
        cout << "Base Container Methods\n";
        cout << "1.  [print]     Show Ticket Collection\n";
        cout << "2.  [print]     Show Session Collection\n";
        cout << "3.  [print]     Show String Collection\n";
        cout << "4.  [size]      Get size of Ticket Collection\n";
        cout << "5.  [size]      Get size of Session Collection\n";
        cout << "6.  [size]      Get size of String Collection\n";
        cout << "7.  [get]       Get Ticket by index\n";
        cout << "8.  [get]       Get String by index\n";
        cout << "9.  [findIf]    Find Ticket by row and place\n";
        cout << "10. [removeAt]  Remove Ticket by index\n";
        cout << "11. [clear]     Clear String Collection\n";
        
        cout << "\nTemplate Functions (Algorithms)\n";
        cout << "12. [findBest]  Find most expensive ticket\n";
        cout << "13. [findBest]  Find longest string\n";
        cout << "14. [countIf]   Count VIP tickets\n";
        cout << "15. [filter]    Filter strings starting with 'B'\n";
    
        cout << "\n";
        cout << "0.  Back\n";

        int choice = read_int("Choice: ");
        if (choice == 0) break;

        switch (choice) {
            case 1:
                ticket_coll.print(cout, [](const shared_ptr<Ticket>& t, ostream& os) {
                    t->print_ticket(os);
                });
                break;
            case 2:
                session_coll.print(cout, [](const shared_ptr<Session>& s, ostream& os) {
                    os << s->get_film() << " | seats: " << s->seats_limit() << "\n";
                });
                break;
            case 3:
                string_coll.print(cout, [](const string& str, ostream& os) {
                    os << str << "\n";
                });
                break;

            case 4:
                cout << "Ticket Collection size: " << ticket_coll.size() << "\n";
                break;
            case 5:
                cout << "Session Collection size: " << session_coll.size() << "\n";
                break;
            case 6:
                cout << "String Collection size: " << string_coll.size() << "\n";
                break;

            case 7: {
                int idx = read_int("Enter ticket index: ");
                if (idx >= 0 && idx < (int)ticket_coll.size()) {
                    cout << "Ticket at index " << idx << ":\n";
                    ticket_coll.get(idx)->print_ticket(cout);
                } else {
                    cout << "Index out of bounds.\n";
                }
                break;
            }
            case 8: {
                int idx = read_int("Enter string index: ");
                if (idx >= 0 && idx < (int)string_coll.size()) {
                    cout << "String at index " << idx << ": " << string_coll.get(idx) << "\n";
                } else {
                    cout << "Index out of bounds.\n";
                }
                break;
            }

            case 9: {
                int r = read_int("Row: ");
                int p = read_int("Place: ");
                int idx = ticket_coll.find_if([r, p](const shared_ptr<Ticket>& t) {
                    return t->get_row() == r && t->get_place() == p;
                });
                if (idx != -1) cout << "Found at index " << idx << "\n";
                else cout << "Not found.\n";
                break;
            }
            case 10: {
                int idx = read_int("Index to remove: ");
                if (ticket_coll.remove_at(idx)) cout << "Removed. New size: " << ticket_coll.size() << "\n";
                else cout << "Invalid index.\n";
                break;
            }
            case 11:
                string_coll.clear();
                cout << "String collection cleared. New size: " << string_coll.size() << "\n";
                break;

            case 12: {
                auto best = find_best(ticket_coll, [](const shared_ptr<Ticket>& a, const shared_ptr<Ticket>& b) {
                    return a->final_price() > b->final_price();
                });
                cout << "Most expensive ticket:\n";
                best->print_ticket(cout);
                break;
            }
            case 13: {
                auto best = find_best(string_coll, [](const string& a, const string& b) {
                    return a.length() > b.length();
                });
                cout << "Longest string: " << best << "\n";
                break;
            }
            case 14: {
                int count = count_if(ticket_coll, [](const shared_ptr<Ticket>& t) {
                    return t->type_name() == "VIP";
                });
                cout << "Number of VIP tickets: " << count << "\n";
                break;
            }
            case 15: {
                Collection<string> filtered = filter(string_coll, [](const string& s) {
                    return !s.empty() && s[0] == 'B';
                });
                cout << "Filtered strings (starting with 'B'):\n";
                filtered.print(cout, [](const string& s, ostream& os) {
                    os << s << "\n";
                });
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }
    }
}