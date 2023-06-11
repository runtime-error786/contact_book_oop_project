#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"


class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string mobile_number;
    std::string email_address;
    Address* address;

public:
    friend std::istream& operator >>(std::istream&, Contact&);
    friend std::ostream& operator <<(std::ostream&, Contact&);
    bool Equals(Contact);
    Contact();
    Contact (const Contact &);
    void Print();

    Contact* CopyContact();

    void operator = (const Contact&);

    void FirstName(std::string);//Setters
    void LastName(std::string);
    void MobileNumber(std::string);
    void EmailAddress(std::string);
    void SetAddress(Address&);

    std::string  FirstName();//Getters
    std::string  LastName();
    std::string  MobileNumber();
    std::string  EmailAddress();
    Address* GetAddres();
   

   
    void  operator == (const Contact & p1);
    Contact(std::string, std::string, std::string, std::string, Address*);

    ~Contact();
};
