

#ifndef view_h
#define view_h
#include <iostream>
#include "ContactsBook.h"
class view
{
    int *Count_array;
    int Size_count_array;
    Contact *array_shuffle;
    int arr[5];
    
public:
    void PrintTop(int *Count_array , int size_count_array , Contact * array_shuffle , int arr[5], int contacts_count);
    view();
};

#endif /* view_h */
