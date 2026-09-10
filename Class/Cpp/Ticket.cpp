#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"   
#include <iostream>

using namespace std;

Ticket::Ticket(int row, int place, float price, shared_ptr<Session> session)
    : place(place), session(session), price(price), row(row) {}

void Ticket::In_place(int place) { this->place = place; }
void Ticket::In_session(shared_ptr<Session> session_) { session = session_; }
void Ticket::In_price(float price) { this->price = price; }
void Ticket::In_row(int row) { this->row = row; }

void Ticket::Out_t() const {
  cout << "Ticket:" << endl;
  Out_place_and_row();
  Out_session();
  Out_price();
  cout << endl;
}

void Ticket::Out_place_and_row() const {
  cout << "Row and place of person: " << row << " " << place << endl;
}

void Ticket::Out_session() const {
  if (session) session->Out_s();
}

void Ticket::Out_price() const {
  cout << "Price of ticket: " << price << "$" << endl;
}

int Ticket::Get_row() const { return row; }
int Ticket::Get_place() const { return place; }
float Ticket::Get_price() const { return price; }
shared_ptr<Session> Ticket::Get_session() const { return session; }