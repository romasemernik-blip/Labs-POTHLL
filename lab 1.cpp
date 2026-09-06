#include<iostream>
#include<string>

using namespace std;
class Halls 
{
    Halls (int num, int num_seat, string name)
    {
        In(num, num_seat, name);
    }
    private:
    int num;
    int num_seat;
    string name;
    public:
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
    Session(string film, string date, int time_start)
    {
        In(film, date, time_start);
    }
    private:
    string film;
    class Halls;
    string date;
    int time_start;
    public:
    void Out ( )
    {
      Out_film ();
      Out_date ();
      Out_time_start ();
    }  
     void In (string film, string date, int time_start)
    {
        In_film (film);
        In_date (date);
        In_time_start (time_start);
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


};
int main ()
{
    return 0;
}