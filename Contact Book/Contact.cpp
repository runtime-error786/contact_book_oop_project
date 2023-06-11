#include "Contact.h"
#include <fstream>
Contact :: Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address *address)
{
    FirstName(first_name);
    LastName(last_name);
    EmailAddress(email_address);
    MobileNumber(mobile_number);
    this->address=address;
   
}
 Contact :: Contact()
{
     this->first_name="";
     this->last_name="";
     this->email_address="";
     this->mobile_number="";
}

std::ostream & operator <<(std :: ostream & in ,  Contact & cont)
{
    in<<cont.first_name<<" , ";
    in<<cont.last_name<<" , ";
    in<<cont.mobile_number<<" , ";
    in<<cont.email_address<<" , ";
    in<<*cont.address;
    return in;
}
void Contact :: operator = ( const Contact  & contact)
{
    this->first_name=contact.first_name;
    this->last_name=contact.last_name;
    this->email_address=contact.email_address;
    this->mobile_number=contact.mobile_number;
    this->address=contact.address;
}
void Contact :: SetAddress(Address &address)
{
    this->address=&address;
}
Address * Contact  :: GetAddres()
{
    return address;
}
void Contact:: Print()
{
    std :: cout<<first_name<<" "<<last_name<<" "<<email_address<<" "<<mobile_number<<std::endl;
    address->PrintAddress();
}
void Contact :: FirstName(std :: string first_name)
{
    if(first_name.empty()==true)
    {
        
    }
    else{
        this->first_name=first_name;
    }
}


void Contact :: LastName(std :: string last_name)
{
    if(last_name.empty()==true)
    {
        
    }
    else{
        this->last_name=last_name;
    }
}

void Contact :: MobileNumber(std :: string mobile_number)
{
    if(mobile_number.length()==11)
    {
        this->mobile_number = mobile_number;
    }
    else
    {
        mobile_number="00000000000";
    }
}

void Contact :: EmailAddress(std :: string email_address)
{
    if(email_address.empty()==true)
    {
        
    }
    else{
        this->email_address=email_address;
    }
}

std ::  string  Contact :: FirstName()
{
    return  first_name;
}

std :: string Contact :: LastName()
{
    return last_name;
}

std :: string Contact  :: MobileNumber()
{
    return mobile_number;
}

std :: string Contact :: EmailAddress()
{
    return email_address;
}



bool Contact :: Equals(Contact contact)
{
    if(     this->first_name==contact.first_name && this->last_name==contact.last_name && this->email_address==contact.email_address && this->mobile_number==contact.mobile_number && this->address->Equals(*(contact.address))        )
    {
        return true;
    }
    return false;
}

Contact* Contact::CopyContact()
{
    Contact *c1 = new Contact;
    c1->FirstName(this->FirstName());
    c1->LastName(this->LastName());
    c1->EmailAddress(this->EmailAddress());
    c1->MobileNumber(this->MobileNumber());
    c1->address=address->CopyAddress();
    return c1;
}

Contact :: Contact (const Contact & p1)
{
    
    first_name = p1.first_name;
    last_name = p1.last_name;
    email_address = p1.email_address;
    mobile_number = p1.mobile_number;
    address = new Address;
    address->City(p1.address->City());
    address->Street(p1.address->Street());
    address->Country(p1.address->Country());
    address->House(p1.address->House());
    
}
void Contact:: operator == (const Contact & p1)
{
    std::cout<<"== constructor call"<<std::endl;
    first_name = p1.first_name;
    last_name = p1.last_name;
    email_address = p1.email_address;
    mobile_number = p1.mobile_number;
    address = new Address;
    address->City(p1.address->City());
    address->Street(p1.address->Street());
    address->Country(p1.address->Country());
    address->House(p1.address->House());
}
 std::istream & operator >>(std :: istream & in , Contact   &  cont)
 {
    
     in>>cont.first_name;
     in>>cont.last_name;
     in>>cont.email_address;
     in>>cont.mobile_number;
     if (cont.mobile_number.length() != 11)
     {
         cont.mobile_number = "00000000000";
     }
     cont.address = new Address;
     in>>*cont.address;
     return in;
 }

Contact :: ~ Contact()
{
    
}
