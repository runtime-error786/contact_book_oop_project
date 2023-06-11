
#ifndef Date_h
#define Date_h

#include <iostream>
class Date
{
private:
    int day;
    int month;
    int year;
    int hour;
    int minutes;
    int seconds;
public:
    void Day(int);//Setters
    void Month(int);
    void Year(int);
    void Hour(int);
    void Minutes(int);
    void Seconds(int);

    int Hour();
    int Minutes();
    int Seconds();
    int Day();
    int Month();
    int Year();
    friend std::ostream & operator << (std::ostream &, const Date &);
    void SetCurrentDate();
    //void DisplayCurrentDate();
    Date();
};


#endif /* Date_hpp */

