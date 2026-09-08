
#include<iostream>
#include<string>
#include<memory>

using namespace std;

class Session;
class Hall;
class Ticket;
class Cinema_system;

struct Date {
int year;
int month;
int day;
Date (int y, int m, int d) : year(y), month(m), day(d) {}
void print() {
     cout << day <<"." << month << "." << year;
}
};
struct Time {
int hour;
int minute;
Time (int h, int m): hour(h), minute(m) {}
void print () const {
     cout << hour << ":";
     if (minute < 10) cout << "0";
     cout << minute;
}
};
class Hall
{
    private:
    int num;
    int num_seat;
    string name;
    public:
     Hall (int num, int num_seat, string name): num(num), num_seat(num_seat), name(name) {}
    
    void In_num (int num)
    {
         this->num = num;
    }
    void In_num_seat (int num_seat)
    {
         this->num_seat = num_seat;
    }
    void In_name (string name)
    {
         this->name = name;
    }
    void OutH ( )
    { 
     cout << "Hall:" << endl;
       Out_num();
       Out_num_seat();
       Out_name();
       cout << endl;
    }
    void Out_num ()
    {
         cout << "Number of Hall: " << num << endl;
    }   
     void Out_num_seat ()
    {
         cout << "Number of seats: " << num_seat << endl;
    }   
     void Out_name ()
    {
         cout << "Name of Hall: " << name << endl;
    }
    int getNum() const { return num; }
    int getNumSeats() const { return num_seat; }
    string getName() const { return name; }    

};

class Session
{
    
    private:
    string film;
    shared_ptr<Hall> hall;
    shared_ptr<Date> date;
    shared_ptr<Time> time_start;
    public:
    Session( string film, shared_ptr<Time> time_start, shared_ptr<Date> date,shared_ptr<Hall> hall ): film(film), hall(hall), date(date), time_start(time_start) {}
      void In_film (string film)
    {
         this->film = film;
    }
    void In_hall (shared_ptr<Hall> hall)
    {
         this->hall = hall;
    }
    void In_time_start (shared_ptr<Time> time_start)
    {
         this->time_start = time_start;
    }
    void In_date (shared_ptr<Date> date )
    {
         this->date = date;
    } 
    void OutS ( )
    {
     cout << "Session info" << endl;
      Out_film ();
      Out_hall ();
      Out_date ();
      Out_time ();
      cout << endl;
    }  
 
    void Out_date ()
{
     if (date) {
          cout << "Date:";
          date->print();
          cout << endl;
     }
}
void Out_time ()
{
   if (time_start) {
          cout << "Time:";
          time_start->print();
          cout << endl;
     }
}
    void Out_film ()
    {
         cout << "Name of session film: " << film << endl;
    }
    void Out_hall ()
    {
     if (hall)
     {
          hall->Out_name();
          hall->Out_num(); 
     }
         
    }
    string getFilm() const { return film; }
    shared_ptr<Hall> getHall() const { return hall; }
    shared_ptr<Date> getDate() const { return date; }
    shared_ptr<Time> getTimeStart() const { return time_start; }   


};
class Ticket
{
     private:
     int place;
     shared_ptr<Session> session;
     float price;
     int row;
     public:
     Ticket( int row,int place,  float price,shared_ptr<Session> session ): place(place), price(price), session(session), row(row) {}
     void OutT ()
     {
          cout<< "Ticket:"<<endl;
          Out_place_and_row();
          Out_session();
          Out_price();
          cout << endl;

     }
     void  In_place(int place)
     {
         this->place = place;
     }
     void   In_session(shared_ptr<Session> session)
     {
         this->session = session;
     }
     void  In_price(float price)
     {
         this->price = price;
     }
     void  In_row(int row)
     {
         this->row = row;
     }
     void Out_place_and_row()
     {
         cout << "Row and place of person: " << row << " " << place <<  endl;
     }
     void Out_session()
     {
          if (session)
          {
               session->OutS();
          }
          

     }
     void Out_price()
     {
          cout << "Price of ticket: " << price << "$" << endl;
     }
     int getRow() const { return row; }
     int getPlace() const { return place; }
     float getPrice() const { return price; }
     shared_ptr<Session> getSession() const { return session; }

};
int main ()
{
    auto hall1 = make_shared<Hall>(1, 120, "Moon");
    auto hall2 = make_shared<Hall>(2, 240, "Spartac");
    auto hall3 = make_shared<Hall>(3, 200, "October");
    auto hall4 = make_shared<Hall>(4, 420, "Queen");
    auto hall5 = make_shared<Hall>(5, 90, "Moon");
    hall1->OutH();
    hall2->OutH();
    hall3->OutH();
    hall4->OutH();
    hall5->OutH();
    auto date1 = make_shared<Date>(2026, 2, 12);
    auto date2 = make_shared<Date>(2025, 12, 12);
    auto time1 = make_shared<Time>(13, 30);
    auto time2 = make_shared<Time>(18, 20);
    auto session1 = make_shared<Session>("Breaking Bad", time1, date1, hall5);
    auto session2 = make_shared<Session>("Stranger Things", time2, date2, hall2);
    session1->OutS();
    session2->OutS();
    session1->In_hall(hall3);
    session1->OutS();
    auto ticket1 = make_shared<Ticket>(2, 7, 12.3f, session1);
    auto ticket2 = make_shared<Ticket>(3, 14, 10.3f, session2);
    ticket1->OutT();
    ticket2->OutT();
    return 0;
}