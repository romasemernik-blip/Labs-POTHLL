#include<iostream>
#include<string>
#include<memory>

using namespace std;
class Session;
class Hall;
class Ticket;
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
       Out_num();
       Out_num_seat();
       Out_name();
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
};
class Ticket
{
     private:
     int place;
     Session* session;
     float price;
     int row;
     public:
     Ticket(int place, Session* session, float price, int row)
     {
          In(place,session, price, row );
     }
     void OutT ()
     {
          Out_place_and_row();
          Out_session();
          Out_price();

     }
     void In (int place, Session* session, float price, int row)
     {
          In_place(place);
          In_session(session);
          In_price(price);
          In_row(row);

     }
     void  In_place(int place)
     {
         this->place = place;
     }
     void   In_session(Session* session)
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
          session->OutS();

     }
     void Out_price()
     {
          cout << "Price of ticket: " << price << "$" << endl;
     }

};
class Session
{
    
    private:
    string film;
    shared_ptr<Hall> hall;
    shared_ptr<Date> date;
    shared_ptr<Time> time_start;
    public:
    Session(string film, shared_ptr<Hall> hall, shared_ptr<Date> date, shared_ptr<Time> time_start): film(film), hall(hall), date(date), time_start(time_start) {}
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


};
int main ()
{
    Hall First(1 ,120 ,"mooon" );
    Hall Second(2 ,240 ,"spartac" );
    Hall Third(3 ,200 ,"october" );
    Hall Fourth(4 ,420 ,"qeen" );
    Hall Fifth(5 ,90 ,"mooon" );
    First.OutH();
    Second.OutH();
    Third.OutH();
    Fourth.OutH();
    Fifth.OutH();
    Time time1(13,30);
    Date date1(2026,02,12);
    Time time2(18,20);
    Date date2(2025,12,12);
    Session Nut("Breaking bad",&time1,&date1, &Fifth );
    Session Not("Stranger things", &time2,&date2, &Second);
    Nut.OutS();
    Not.OutS();
    Ticket t1( 7,&Nut,12.3,2);
    Ticket t2( 14,&Not,10.3,3);
    t1.OutT();
    t2.OutT();


    return 0;
}