#include "Address.h"

Address :: Address( std::string house, std::string street, std::string city, std::string country)
{
    this->house=house;
    this->street=street;
    this->city=city;
    this->country=country;
}

Address :: Address()
{
    this->house="";
    this->street="";
    this->city="";
    this->country="";
}

std::ostream & operator <<(std :: ostream & in , const Address & addr)
{
    in<<addr.city<<" , ";
    in<<addr.country<<" , ";
    in<<addr.house<<" , ";
    in<<addr.street<<" , ";
    in<<std::endl;
    return in;
}
Address :: ~Address()
{
    
}
void Address :: House(std :: string house)
{
    this->house=house;
}

void Address :: Street(std :: string street)
{
    this->street=street;
}

void Address :: City(std :: string city)
{
    this->city=city;
}

void Address :: Country(std :: string country)
{
    this->country=country;
}

std :: string Address :: House()
{
    return house;
}

std :: string Address :: Street()
{
    return street;
}

std :: string Address :: City()
{
    return city;
}

std :: string Address :: Country()
{
    return country;
}

bool Address::Equals(const Address & address)
{
    if((this->house==address .house && this->street==address.street && this->city==address.city && this->country==address.country))
    {
        return true;
    }
    return false;
}

void Address::PrintAddress()
{
    std::cout<< house<< ","<< street<<","<<city<<","<<country<<std :: endl;
}

Address * Address::CopyAddress()
{
    Address *a1 = new Address;
    a1->House(House());
    a1->City(City());
    a1->Street(Street());
    a1->Country(Country());
    return a1;
}

std::istream & operator >>(std :: istream & in , Address & addr)
{
    in>>addr.house;
    in>>addr.street;
    in>>addr.city;
    in>>addr.country;
    return in;
}
