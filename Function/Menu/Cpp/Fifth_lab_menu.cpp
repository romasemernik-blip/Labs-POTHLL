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
        cout << "\n--- LAB 5: TEMPLATES (COLLECTION<T>) ---\n";
        cout << "1. Print Ticket Collection\n";
        cout << "2. Print Session Collection\n";
        cout << "3. Print String Collection (Independent of domain)\n";
        cout << "---------------------------------------\n";
        cout << "4. Find max (final_price) in Ticket Collection [findBest]\n";
        cout << "5. Find max (seats_limit) in Session Collection [findBest]\n";
        cout << "6. Find longest string in String Collection [findBest]\n";
        cout << "---------------------------------------\n";
        cout << "7. Count VIP tickets [countIf template function]\n";
        cout << "8. Filter strings starting with 'B' [filter template function]\n";
        cout << "---------------------------------------\n";
        cout << "9. Remove item by index (Ticket)\n";
        cout << "10. Clear String Collection\n";
        cout << "0. Back\n";

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
            case 4: {
                auto best = find_best(ticket_coll, [](const shared_ptr<Ticket>& a, const shared_ptr<Ticket>& b) {
                    return a->final_price() > b->final_price();
                });
                cout << "Most expensive ticket:\n";
                best->print_ticket(cout);
                break;
            }
            case 5: {
                auto best = find_best(session_coll, [](const shared_ptr<Session>& a, const shared_ptr<Session>& b) {
                    return a->seats_limit() > b->seats_limit();
                });
                cout << "Session with max seats: " << best->get_film() << "\n";
                break;
            }
            case 6: {
                auto best = find_best(string_coll, [](const string& a, const string& b) {
                    return a.length() > b.length();
                });
                cout << "Longest string: " << best << "\n";
                break;
            }
            case 7: {
                int count = count_if(ticket_coll, [](const shared_ptr<Ticket>& t) {
                    return t->type_name() == "VIP";
                });
                cout << "Number of VIP tickets: " << count << "\n";
                break;
            }
            case 8: {
                Collection<string> filtered = filter(string_coll, [](const string& s) {
                    return !s.empty() && s[0] == 'B';
                });
                cout << "Filtered strings (starting with 'B'):\n";
                filtered.print(cout, [](const string& s, ostream& os) {
                    os << s << "\n";
                });
                break;
            }
            case 9: {
                int idx = read_int("Index to remove from Ticket Collection: ");
                if (ticket_coll.remove_at(idx)) cout << "Removed.\n";
                else cout << "Invalid index.\n";
                break;
            }
            case 10:
                string_coll.clear();
                cout << "String collection cleared.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}