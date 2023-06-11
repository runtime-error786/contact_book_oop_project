#pragma once
#ifndef BASIC_LIB

#define BASIC_LIB
#include "List.h"
#include "Contact.h"
#include "SearchHistory.h"
#include <fstream>
#include "view.h"
#endif // !BASIC_LIB

class ContactsBook {
private:
    Contact *contacts_list;
    int size_of_contacts;
    int contacts_count;
    List <SearchHistory> search_history_list;
    
    int *Count_array;//  also for top 5 contact
    int Size_count_array;
    Contact *array_shuffle;
    int arr[5];
    
public:
    void DisplayPhoneName();
    void AddContact(Contact& contact);
    int TotalContacts();
    void ListSort();//help
    void SaveDataToList();
    void LoadDataFromList();
    void PrintFrequentlyTop5();
    void UpdateContact(std::string str_first , std:: string str_last);
    void DeleteContact(std::string str_first , std::string str_last);
    void DisplayDataList();
    Contact* SearchContact(std::string);
   
    ContactsBook(int size_of_list);
    ContactsBook();
    void PrintContactsSorted(std::string choice);
    void MergeDuplicates();
    void SaveToFile(std::string file_name);
    void  LoadFromFile(std::string file_name);
    void PrintLoad();
    ~ContactsBook();
    
    void AdvanceSearch(std::string);

private:

    bool Full();
    void ResizeList();
    void SortContactsList(Contact *contacts_list, std::string choice);
 
};
