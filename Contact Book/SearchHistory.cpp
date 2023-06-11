
#include "SearchHistory.h"
#include "ContactsBook.h"
#include "Contact.h"
#include <fstream>
#include<iostream>
#include "Date.h"


std::ostream & operator <<(std::ostream & in ,const SearchHistory & s1)
{
    /*
     operator overloaded to print string search, date ,time
    */
    in<<s1.str_search;
    in<<s1.date;
    return in;
}

Date  SearchHistory:: GetObj1()
{
    /*
    *returns the object of the date time
    */
    return  date;
}
SearchHistory :: SearchHistory()
{
    //default constructor
}


std::string SearchHistory::GetString()
{
    return str_search;
}

void SearchHistory::SetData(std::string str)
{
    /*
    * set the data such that the user enter the searched string and date time
    */
    str_search=str;
    date.SetCurrentDate();
}


void SearchHistory:: SaveData(std::ofstream & out)
{
    /*
    * Saves the data to file
    */
    out<<str_search <<" "<<date.Day()<<" "<<date.Month()<<" "<<date.Year()<<" "<<date.Hour()<<" "<<date.Minutes()<<" "<<date.Seconds()<<std::endl;
}

void SearchHistory:: InputData(std::ifstream & read)
{
    /*
    * reads the data from file
    */
    std::string str;
    int a;
    read>>str;
    if(str==","){
        read>>str;
    }
    str_search=str;
    
    read>>a;
    
    if(a==44){
       
        read>>a;
    }
    date.Day(a);
    read>>a;
    
    if(a==44){
        read>>a;
    }
    date.Month(a);
    read>>a;
    
    if(a==44){
        read>>a;
    }
    date.Year(a);
    read>>a;
    
    if(a==44){
        read>>a;
    }
    date.Hour(a);
    read>>a;
    
    if(a==44){
        read>>a;
    }
    date.Minutes(a);
    read>>a;
    if(a==44){
        read>>a;
    }
    date.Seconds(a);
}
void SearchHistory::Reverse(SearchHistory* s1, int count_search)
{
    std::cout << "Search History :" << std::endl;
    SearchHistory object;
    std::cout << "enter in sort:" << std::endl;
    std::string str;
    for (int i = 0; i < count_search; i++)
    {
        for (int j = 0; j < count_search; j++)
        {
            if (s1[i].GetObj1().Year() > s1[j].GetObj1().Year() && j != i)
            {
                object = s1[i];
                s1[i] = s1[j];
                s1[j] = object;
            }
            else if (s1[i].GetObj1().Year() == s1[j].GetObj1().Year() && j != i)
            {
                if (s1[i].GetObj1().Month() > s1[j].GetObj1().Month() && j != i)
                {
                    object = s1[i];
                    s1[i] = s1[j];
                    s1[j] = object;
                }
                else if (s1[i].GetObj1().Month() == s1[j].GetObj1().Month() && j != i)
                {
                    if (s1[i].GetObj1().Day() > s1[j].GetObj1().Day() && j != i)
                    {
                        object = s1[i];
                        s1[i] = s1[j];
                        s1[j] = object;
                    }
                    else if (s1[i].GetObj1().Day() == s1[j].GetObj1().Day() && j != i)
                    {
                        if (s1[i].GetObj1().Hour() > s1[j].GetObj1().Hour() && j != i)
                        {
                            object = s1[i];
                            s1[i] = s1[j];
                            s1[j] = object;
                        }
                        else if (s1[i].GetObj1().Hour() == s1[j].GetObj1().Hour() && j != i)
                        {
                            if (s1[i].GetObj1().Minutes() > s1[j].GetObj1().Minutes() && j != i)
                            {
                                object = s1[i];
                                s1[i] = s1[j];
                                s1[j] = object;
                            }
                            else if (s1[i].GetObj1().Minutes() == s1[j].GetObj1().Minutes() && j != i)
                            {
                                if (s1[i].GetObj1().Seconds() > s1[j].GetObj1().Seconds() && j != i)
                                {
                                    object = s1[i];
                                    s1[i] = s1[j];
                                    s1[j] = object;
                                }
                                else if (s1[i].GetObj1().Seconds() == s1[j].GetObj1().Seconds() && j != i)
                                {
                                    object = s1[i];
                                    s1[i] = s1[j];
                                    s1[j] = object;
                                }
                            }
                        }



                    }
                }
            }

        }
    }
}
