#include<iostream>
#include<string>

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
      cout << "Name of Hall: " << name << endl;
      cout << "Number of Hall: " << num << endl;
      cout << "Number of seats: " << num_seat << endl;
    }
    void In (int num, int num_seat, string name)
    {
        this->num = num;
        this->num_seat = num_seat;
        this->name = name;
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
      cout << "Name of session film: " << film << endl;
      cout << "Date of session: " << date << endl;
      cout << "Session start time: " << time_start << endl;
    }  
     void In (string film, string date, int time_start)
    {
        this->film = film;
        this->date = date;
        this->time_start = time_start;
    }

};
int main ()
{
    return 0;
}