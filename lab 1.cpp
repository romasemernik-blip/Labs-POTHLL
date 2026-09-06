#include<iostream>
#include<string>

using namespace std;
class Session;
class Hall;
struct Date {
int year;
int month;
int day;
Date (int y, int m, int d)
{
    year = y;
    month = m;
    day = d; 
}
void Out ()
{
     cout << day << "." << month << "." << year << endl;
}
};
struct Time {
int hour;
int minute;
Time (int h, int m)
{
     hour = h;
     minute = m;
}
void Out ()
{
     cout << hour << ":" << minute << endl;
}
};
class Hall
{
   
    private:
    int num;
    int num_seat;
    string name;
    public:
     Hall (int num, int num_seat, string name)
    {
        In(num, num_seat, name);
    }
    void Out ( )
    {
       Out_num();
       Out_num_seat();
       Out_name();
    }
    void In (int num, int num_seat, string name)
    {
        In_num (num);
        In_num_seat (num_seat);
        In_name (name);
    }
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
    void Out_num ()
    {
         cout << "Number of Hall: " << num << endl;
    }   
     void Out_num_seat ()
    {
         cout << "Name of Hall: " << name << endl;
    }   
     void Out_name ()
    {
         cout << "Number of seats: " << num_seat << endl;
    }    
};
class Session
{
    
    private:
    string film;
    Hall* hall;
    string date;
    int time_start;
    public:
    Session(string film, string date, int time_start, Hall* hall)
    {
        In(film, date, time_start, hall);
    }
    void Out ( )
    {
      Out_film ();
      Out_date ();
      Out_time_start ();
      Out_hall ();
    }  
     void In (string film, string date, int time_start, Hall* hall)
    {
        In_film (film);
        In_date (date);
        In_time_start (time_start);
        In_hall (hall);
    }
    void In_film (string film)
    {
         this->film = film;
    }
    void In_date (string date)
    {
         this->date = date;
    }
    void In_time_start (int time_start)
    {
         this->time_start = time_start;
    }
    void In_hall (Hall* hall)
    {
         this->hall = hall;
    }
    void Out_film ()
    {
         cout << "Name of session film: " << film << endl;
    }
    void Out_date ()
    {
         cout << "Date of session: " << date << endl;
    }  
    void Out_time_start ()
    {
         cout << "Session start time: " << time_start << endl;
    }  
    void Out_hall ()
    {
         hall->Out();
    }   


};
int main ()
{
    Hall First(1 ,120 ,"mooon" );
    Hall Second(2 ,240 ,"spartac" );
    Hall Third(3 ,200 ,"october" );
    Hall Fourth(4 ,420 ,"qeen" );
    Hall Fifth(5 ,90 ,"mooon" );
    First.Out();
    Second.Out();
    Third.Out();
    Fourth.Out();
    Fifth.Out();
    Session Nut("Breaking bad", "24.12.2026",19, &Fifth );
    Session Not("Stranger things", "20.02.2020",10, &Second);
    Nut.Out();
    Not.Out();

    return 0;
}