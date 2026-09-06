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
};
struct Time {
int hour;
int minute;
Time (int h, int m)
{
     hour = h;
     minute = m;
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
    Date* date;
    Time* time_start;
    public:
    Session(string film, Time* time_start, Date* date, Hall* hall)
    {
        In(film,time_start, date, hall);
    }
    void Out ( )
    {
      Out_film ();
      Out_hall ();
      Out_date ();
      Out_time ();
    }  
     void In (string film, Time* time_start, Date* date, Hall* hall)
    {
        In_film (film);
        In_hall (hall);
        In_date (date);
        In_time_start (time_start);
    }
    void In_film (string film)
    {
         this->film = film;
    }
    void In_hall (Hall* hall)
    {
         this->hall = hall;
    }
    void In_time_start (Time* time_start)
    {
         this->time_start = time_start;
    }
    void In_date (Date* date)
    {
         this->date = date;
    }
    void Out_date ()
{
     cout <<"Date of session:"<< date->day << "." << date->month << "." << date->year << endl;
}
void Out_time ()
{
     cout << "Time of session start:"<< time_start->hour << ":" << time_start->minute << endl;
}
    void Out_film ()
    {
         cout << "Name of session film: " << film << endl;
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
    Time time1(13,30);
    Date date1(2026,02,12);
    Time time2(18,20);
    Date date2(2025,12,12);
    Session Nut("Breaking bad",&time1,&date1, &Fifth );
    Session Not("Stranger things", &time2,&date2, &Second);
    Nut.Out();
    Not.Out();

    return 0;
}