//
//  view.cpp
//  existing project
//
//  Created by Mustafa Rizwan on 27/06/2022.
//

#include "view.h"
void view ::PrintTop(int *Count_array , int size_count_array , Contact * array_shuffle , int arr[5] , int contacts_count)
{
    Contact tempo2;
    int tempo1;
    for (int i = 0; i < contacts_count; i++)
    {
        for (int j = i+1; j < contacts_count; j++)
        {
            if (Count_array[i] < Count_array[j])
            {
                tempo1 = Count_array[i];
                Count_array[i] = Count_array[j];
                Count_array[j] = tempo1;

                tempo2 = array_shuffle[i];
                array_shuffle[i] = array_shuffle[j];
                array_shuffle[j] = tempo2;
            }
        }
    }
    if(contacts_count>=5)
    {
        for(int i=0;i<5;i++)
        {
            std::cout<<array_shuffle[i];
        }
    }
    else{
        for(int i=0;i<contacts_count;i++)
        {
            std::cout<<array_shuffle[i];
        }
    }
    std::ofstream s1;
    std::string str;
    s1.open("frequentlyTop");
    for(int i=0;i<contacts_count;i++)
    {
        s1<<array_shuffle[i].FirstName()<<" "<<array_shuffle[i].LastName();
        s1<<std::endl;
    }
    s1.close();
}


view :: view()
{
    
}
