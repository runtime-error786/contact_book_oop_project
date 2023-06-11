#include "ContactsBook.h"

void ContactsBook::AddContact(Contact & contact)
{
    if(size_of_contacts == contacts_count)
    {
        ResizeList();
    }
        contacts_list[contacts_count]=contact;
       std:: cout<<"your data is successfully enter"<<std::endl;
        contacts_count++;
    
}
/*
    in update contact the user enter first name and last name and then we check in whole contact_list if match then user enter data to overwrite the previous data after that we set these changes by setter and getter
 */
void ContactsBook :: UpdateContact(std::string str_first, std::string str_last )
{
    int re=0;
    std::string e_mail,mob_num,house_no,city,country,street;
    for(int i=0;i<contacts_count;i++)
    {
        if(contacts_list[i].FirstName() == str_first && contacts_list[i].LastName()==str_last)
        {
            std::cout<<"enter first name:";
            std::cin>>str_first;
            std::cout<<"enter last name:";
            std::cin>>str_last;
            std::cout<<"enter mail:";
            std::cin>>e_mail;
            std::cout<<"enter mobile number:";
            std::cin>>mob_num;
            std::cout<<"enter house:";
            std::cin>>house_no;
            std::cout<<"enter city:";
            std::cin>>city;
            std::cout<<"enter country:";
            std::cin>>country;
            std::cout<<"enter street:";
            std::cin>>street;
            contacts_list[i].FirstName(str_first);
            contacts_list[i].LastName(str_last);
            contacts_list[i].EmailAddress(e_mail);
            contacts_list[i].MobileNumber(mob_num);
            contacts_list[i].GetAddres()->Country(country);
            contacts_list[i].GetAddres()->City(city);
            contacts_list[i].GetAddres()->House(house_no);
            contacts_list[i].GetAddres()->Street(street);
            re++;
        }
    }
    if(re==0)
    {
        std::cout<<"your data is not found in the ContactBook"<<std::endl;
    }
}
/*
 
 
 the user enter the name which you want to delete when user tell which name want to delete we replace the firstname and lastname by -1 and we swap -1 to end of array and count decrease one time i cannot delete this data but i considered as garbage value
 
 
 */

void ContactsBook::PrintFrequentlyTop5()
{
    
    array_shuffle = new Contact[contacts_count];
    for(int i=0;i<contacts_count;i++)
    {
        array_shuffle[i] = contacts_list[i];
    }
    
    view v1;
    v1.PrintTop(Count_array, Size_count_array, array_shuffle, arr,  contacts_count);
    
}
void ContactsBook:: DeleteContact(std::string str_first , std::string str_last)
{
    for(int i=0;i<contacts_count;i++)
    {
        if(contacts_list[i].FirstName() == str_first && contacts_list[i].LastName()==str_last)
        {
            contacts_list[i].FirstName("-1");
            contacts_list[i].LastName("-1");
        }
    }
    
    for(int i=0;i<contacts_count;i++)
    {
        if(contacts_list[i].FirstName()=="-1" && i+1<contacts_count)
        {
            std::swap(contacts_list[i],contacts_list[i+1]);
        }
    }
    
    int count=0;
    for(int i=0;i<contacts_count;i++)
    {
            if(contacts_list[i].FirstName()!="-1")
            {
                count++;
            }
        
    }
    contacts_count=count;
    
}

int ContactsBook::TotalContacts()
{
    return contacts_count;
}


bool ContactsBook::Full()
{
    if(size_of_contacts == contacts_count)
    {
        return true;
    }
    return false;
}


void ContactsBook::ResizeList()
{
    std::cout<<"resizelist:"<<std::endl;
    int num = size_of_contacts;
    size_of_contacts  = size_of_contacts * 2;
    Contact *temp = new Contact[size_of_contacts];
    for(int i=0;i<contacts_count;i++)
    {
        temp[i] = contacts_list[i];
    }
    delete[] contacts_list;
    contacts_list = temp;
    
    
    
    int *tempo = new int[size_of_contacts];
    for(int i=0; i<num ; i++)
    {
        tempo[i] = Count_array[i];
    }
    
    delete[] Count_array;
    Count_array = tempo;
}

void ContactsBook :: ListSort()
{
   
     // search_history_list.ReverseSort(search_history_list.get_arr(), search_history_list.get_count());
}

void ContactsBook ::SaveDataToList()
{
    search_history_list.SaveToFile();
}

void ContactsBook ::LoadDataFromList()
{
    search_history_list.ReadFromFile();
}

void ContactsBook::DisplayDataList()
{
    search_history_list.PrintList();
}

/*
 
 
 in search the   i replace the 3 search contact function with one the user enter anything firstname,lastname,address,mobile no,email i check if anything of contact is same with the user value enter the i display the data of that contact
 
 
 */

Contact*ContactsBook::SearchContact(std::string str)
{
    SearchHistory s1;
    s1.SetData(str);
    search_history_list.AddToList(s1);
        for(int i=0;i<contacts_count;i++)
        {
            if(str == contacts_list[i].MobileNumber() || str == contacts_list[i].FirstName() || str == contacts_list[i].LastName() || str == contacts_list[i].EmailAddress()|| str == contacts_list[i].GetAddres()->City() || str == contacts_list[i].GetAddres()->Country() || str == contacts_list[i].GetAddres()->House() || str == contacts_list[i].GetAddres()->Street())
            {
                Count_array[i] = Count_array[i] + 1;
                return contacts_list[i].CopyContact();
            }
        }
        std::cout<<"your data is not found in diary"<<std::endl;
        return NULL;
}


ContactsBook::ContactsBook(int size_of_list)
{
    size_of_contacts=size_of_list;
    contacts_list = new Contact[size_of_contacts];
    contacts_count=0;
    Count_array = new int[size_of_contacts];
    for(int i=0 ; i<size_of_contacts ; i++)
    {
        Count_array[i] = 0;
    }
}

ContactsBook::ContactsBook()
{
    //default contructor 
}

void ContactsBook::PrintContactsSorted(std::string choice)
{
    Contact * temp3=new Contact[contacts_count];
    for(int i=0;i<contacts_count;i++)
    {
        Address *a3= new Address;
        temp3[i].SetAddress(*a3);
        temp3[i].FirstName(contacts_list[i].FirstName());
        temp3[i].LastName(contacts_list[i].LastName());
        temp3[i].EmailAddress(contacts_list[i].EmailAddress());
        temp3[i].MobileNumber(contacts_list[i].MobileNumber());
        temp3[i].SetAddress(*contacts_list[i].GetAddres());
      
    }
   
    SortContactsList(temp3, choice);
    std::cout<<"Your list sorted : "<<std::endl;
       for(int i=0;i<contacts_count;i++)
       {
          std::cout<< temp3[i].FirstName()<<","<<temp3[i].LastName()<<","<<temp3[i].EmailAddress()<<","<<temp3[i].MobileNumber()<<","<<std::endl;
           temp3[i].GetAddres()->PrintAddress();
           std::cout<<std::endl;
       }
}


void ContactsBook::PrintLoad()
{
    std::cout<<"your data without sort:"<<std::endl;
       for(int i=0;i<contacts_count;i++)
       {
          std::cout<< contacts_list[i].FirstName()<<contacts_list[i].LastName()<<contacts_list[i].EmailAddress()<<contacts_list[i].MobileNumber()<<std::endl;
           contacts_list[i].GetAddres()->PrintAddress();
           std::cout<<std::endl;
       }
}


void  ContactsBook :: LoadFromFile(std::string file_name)
{
    std :: ifstream read;
    read.open(file_name);
    if(!read)
    {
        std::cout<<"Error";
    }
    else{
        std::cout<<"yes";
    }
    read>> size_of_contacts;
    Contact *contact1 = new Contact[size_of_contacts];
    read>> contacts_count;
    std :: string var;
    for(int i=0;i< contacts_count;i++)
    {
        Address *a1= new Address;
        contact1[i].SetAddress(*a1);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].FirstName(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].LastName(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].MobileNumber(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].EmailAddress(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].GetAddres()->Street(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].GetAddres()->House(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].GetAddres()->Country(var);
        read>>var;
        if(var==","){
            read>>var;
        }
        contact1[i].GetAddres()->City(var);
    }
    read.close();
    delete[] contacts_list;
    contacts_list=contact1;
}


void  ContactsBook::SortContactsList(Contact *contacts_list,std::string choice)
{
    std::string s1,s2;
    for(int i=0;i<contacts_count;i++)
    {
        for(int j=i+1;j<contacts_count;j++)
        {
            s2 = choice == "f" ? contacts_list[j].FirstName() :contacts_list[j].LastName();
            s1 = choice == "f" ? contacts_list[i].FirstName() :contacts_list[i].LastName();
            if(s1[0] > s2[0])
            {
                 std::swap(contacts_list[i],contacts_list[j]);
            }

        }
    }
    
}


void ContactsBook::MergeDuplicates()
{
    for(int i=0;i<contacts_count;i++)
      {
          for(int j=0;j<contacts_count;j++)
          {
              if( contacts_list[i].Equals(contacts_list[j])==true  && j!=i)
              {
                  contacts_list[j].FirstName("-1");
              }
          }
      }
    for(int i=0;i<contacts_count;i++)
    {
        for(int j=0;j<contacts_count;j++)
        {
            if(contacts_list[j].FirstName()=="-1" && j+1<contacts_count)
            {
                std::swap(contacts_list[j],contacts_list[j+1]);
            }
        }
    }
    int count=0;
    for(int i=0;i<contacts_count;i++)
    {
            if(contacts_list[i].FirstName()!="-1")
            {
                count++;
            }
        
    }
    contacts_count=count;
}
void ContactsBook::SaveToFile(std::string file_name)
{
    std::cout<<"file:"<<std::endl;
    std::ofstream out;
    out.open(file_name);
    if(!out)
    {
        std::cout<<"error"<<std::endl;
    }
    else{
        std::cout<<"yes:"<<std::endl;
    }
    out<<size_of_contacts;
    out<<std::endl;
    out<<contacts_count;
    out<<std::endl;
    for(int i=0;i<contacts_count;i++)
    {
        out << contacts_list[i].FirstName()<<" , "<<contacts_list[i].LastName()<<" , "<<contacts_list[i].MobileNumber()<<" , "<<contacts_list[i].EmailAddress()<<std::endl;
        out<<contacts_list[i].GetAddres()->Street()<<" , "<<contacts_list[i].GetAddres()->House()<<" , "<<contacts_list [i].GetAddres()->Country()<<" , "<<contacts_list[i].GetAddres()->City()<<std::endl;
    }
    out.close();
}

ContactsBook :: ~ContactsBook()
{
    delete[] contacts_list;
    contacts_list=NULL;
}

void ContactsBook::DisplayPhoneName()
{
    for(int i=0;i<contacts_count;i++)
    {
        std::cout<<contacts_list[i].FirstName() <<" : "<<contacts_list[i].LastName()<<" : "<<contacts_list[i].MobileNumber()<<std::endl;
    }
}

void ContactsBook::AdvanceSearch(std::string str)
{
    std::cout << "Advance Search" << std::endl;
    int length = str.length();
    int count = 0;
    for (int i = 0;i < contacts_count;i++)
    {
        for (int j = 0;j < length;j++)
        {
            std::string str1 = contacts_list[i].FirstName();
            std::string str2 = contacts_list[i].LastName(), str3 = contacts_list[i].MobileNumber(), str4 = contacts_list[i].EmailAddress(), str5 = contacts_list[i].GetAddres()->Street(), str6 = contacts_list[i].GetAddres()->City(), str7 = contacts_list[i].GetAddres()->Country(), str8 = contacts_list[i].GetAddres()->House();
            for (int k = 0;k < str1.length();k++)
            {
                if (str1[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str2.length();k++)
            {
                if (str2[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str3.length();k++)
            {
                if (str3[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str4.length();k++)
            {
                if (str4[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str5.length();k++)
            {
                if (str5[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str6.length();k++)
            {
                if (str6[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str7.length();k++)
            {
                if (str7[k] == str[i])
                {
                    count++;
                }
            }


            for (int k = 0;k < str8.length();k++)
            {
                if (str8[k] == str[i])
                {
                    count++;
                }
            }


        }


        if (count >= length)
        {
            std::cout << contacts_list[i].FirstName() << " , " << contacts_list[i].LastName() << " , " << contacts_list[i].MobileNumber() << " , " << contacts_list[i].EmailAddress() << std::endl;
            std::cout << contacts_list[i].GetAddres()->House() << " , " << contacts_list[i].GetAddres()->Street() << " , " << contacts_list[i].GetAddres()->City() << " , " << contacts_list[i].GetAddres()->Country() << std::endl;
        }
        count = 0;
    }


}
