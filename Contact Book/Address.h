#pragma once
#include <iostream>
#include <string>

class Address {
private:
    
    std::string house;
    std::string street;
    std::string city;
    std::string country;
    
public:
    friend std::istream & operator >>(std :: istream & in , Address & addr);
    friend std::ostream & operator <<(std :: ostream & in , const Address & addr);

    void  House(std :: string house);
    void  Street(std :: string street);
    
    void  City(std :: string city);
    
    void  Country(std :: string country);
    
    std ::  string  House();
    
    std :: string  Street();
    
    std :: string  City();
    
    std :: string  Country();
    
    bool Equals(const Address & address);

    void PrintAddress();
    
    Address  * CopyAddress();

    Address(std::string house, std::string street, std::string city, std::string country);
    
    Address();
    
    ~Address();
};
