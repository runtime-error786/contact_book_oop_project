#include "Date.h"
#include <ctime>
void Date::Day(int dat)
{
    this->day = dat;
}

void Date::Month(int month)
{
    this->month=month;
}

void Date::Year(int year)
{
    this->year=year;
}

int Date::Day()
{
    return day;
}

int Date::Month()
{
    return month;
}

int Date::Year()
{
    return year;
}

std::ostream & operator << (std::ostream & in , const Date & date )
{
    std::cout<<"Date:";
    in<<date.day;
    std::cout<<"Month:";
    in<<date.month;
    std::cout<<"Year:";
    in<<date.year;
    std::cout<<"Seconds:";
    in<<date.seconds;
    std::cout<<"Minutes:";
    in<<date.minutes;
    std::cout<<"Hour:";
    in<<date.hour;
    in<<std::endl;
    return in;
}
Date::Date()
{
    day=0;
    month=0;
    year=0;
    hour=0;
    minutes=0;
    seconds=0;
}


void Date::SetCurrentDate()
{
    /*
    * Sets the current date time of system;
    */
    time_t tt;
  
    // Declaring variable to store return value of
    // localtime()
    struct tm * ti;
  
    // Applying time()
    time (&tt);
    
    
    ti = localtime(&tt);//Problem
    day = ti->tm_mday;
    month = ti->tm_mon+1;
    year = ti->tm_year+1900;
    minutes = ti->tm_min;
    hour = ti->tm_hour;
    seconds = ti->tm_sec;
    
}

void Date::Hour(int hour)
{
    this->hour=hour;
}


void Date::Minutes(int minutes)
{
    this->minutes=minutes;
}


void Date::Seconds(int seconds)
{
    this->seconds=seconds;
}


int Date::Hour()
{
    return hour;
}


int Date::Minutes()
{
    return minutes;
}

int Date::Seconds()
{
    return seconds;
}
