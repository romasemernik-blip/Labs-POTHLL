#include "Function/Menu/Header/Second_lab_menu.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Show/Header/Session_show.h"
#include "Function/Show/Header/Ticket_show.h"
#include <iostream>

using namespace std;

void Menu_second_lab(vector<shared_ptr<Hall>>& halls,
                     vector<shared_ptr<Session>>& sessions,
                     vector<shared_ptr<Ticket>>& tickets,
                     Ticket_system& system) {
  while (true) {
    cout << "\nFOR SECOND LAB MENU\n";
    cout << "1.  cout << hall              (operator<< for Hall)\n";
    cout << "2.  cin  >> hall              (operator>> for Hall)\n";
    cout << "3.  cout << session           (operator<< for Session)\n";
    cout << "4.  cout << ticket            (operator<< for Ticket)\n";
    cout << "5.  cout << ticket_system     (operator<< for Ticket_system)\n";
    cout << "6.  Compare sessions by seats (operator<, >, ==)\n";
    cout << "7.  Show halls bigger than session (operator< with Hall)\n";
    cout << "8.  system += shared ticket   (operator+= shared)\n";
    cout << "9. system += unique ticket   (operator+= unique)\n";
    cout << "10. system -= ticket by value (operator-= by value)\n";
    cout << "11. system -= shared ticket   (operator-= shared)\n";
    cout << "0.  Back\n";

    int choice = Read_int("Choice: ");

    if (choice == 0) return;

    switch (choice) {
      case 1: {
        Show_all_halls(halls);
        break;
      }
      case 2: {
        Show_all_halls(halls);
        int idx = Read_int("Hall index to edit: ");
        if (idx < 0 || idx >= (int)halls.size()) {
          cout << "Invalid index.\n";
          break;
        }
        cin >> *halls[idx];               
        cout << "Updated:\n" << *halls[idx];
        break;
      }
      case 3: {
        Show_all_sessions(sessions);
        int idx = Read_int("Session index: ");
        if (idx < 0 || idx >= (int)sessions.size()) {
          cout << "Invalid index.\n";
          break;
        }
        cout << *sessions[idx];
        break;
      }
      case 4: {
        Show_all_tickets(tickets);
        int idx = Read_int("Ticket index: ");
        if (idx < 0 || idx >= (int)tickets.size()) {
          cout << "Invalid index.\n";
          break;
        }
        cout << *tickets[idx];
        break;
      }

      case 5: {
        cout << system;
        break;
      }
      case 6: {
        if (sessions.size() < 2) {
          cout << "Need at least 2 sessions.\n";
          break;
        }
        Show_session_films(sessions);
        int a = Read_int("First session index: ");
        int b = Read_int("Second session index: ");
        if (a < 0 || b < 0 ||
            a >= (int)sessions.size() || b >= (int)sessions.size()) {
          cout << "Invalid index.\n";
          break;
        }
        const Session& sa = *sessions[a];
        const Session& sb = *sessions[b];

        cout << "Seats: A=" << sa.Seats_limit()
             << ", B=" << sb.Seats_limit() << "\n";

        if (sa == sb) cout << "Sessions have EQUAL seats.\n";
        if (sa <  sb) cout << "A has FEWER seats than B.\n";
        if (sa >  sb) cout << "A has MORE seats than B.\n";
        break;
      }
      case 7: {
        Show_session_films(sessions);
        int idx = Read_int("Session index: ");
        if (idx < 0 || idx >= (int)sessions.size()) {
          cout << "Invalid index.\n";
          break;
        }
        Show_halls_bigger_than(*sessions[idx], halls);
        break;
      }
      case 8: {
        Show_ticket_short_no_price(tickets);
        int idx = Read_int("Ticket index: ");
        if (idx < 0 || idx >= (int)tickets.size()) {
          cout << "Invalid index.\n";
          break;
        }
        system += tickets[idx];
        break;
      }
      case 9: {
        int row   = Read_int("Row: ");
        int place = Read_int("Place: ");
        float pr  = Read_float("Price: ");
        Show_session_films(sessions);
        int s = Read_int("Session index: ");
        if (s < 0 || s >= (int)sessions.size()) {
          cout << "Invalid index.\n";
          break;
        }
        system += make_unique<Ticket>(row, place, pr, sessions[s]);
        break;
      }
      case 10: {
        Show_ticket_short(tickets);
        int idx = Read_int("Ticket index to remove: ");
        if (idx < 0 || idx >= (int)tickets.size()) {
          cout << "Invalid index.\n";
          break;
        }
        system -= *tickets[idx];
        break;
      }
      case 11: {
        Show_ticket_short(tickets);
        int idx = Read_int("Ticket index to remove: ");
        if (idx < 0 || idx >= (int)tickets.size()) {
          cout << "Invalid index.\n";
          break;
        }
        system -= tickets[idx];
        break;
      }

      default:
        cout << "Invalid choice.\n";
    }
  }
}