#include<iostream>
#include<string>

class Halls 
{
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
};
class Session
{
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

};
int main ()
{
    return 0;
}