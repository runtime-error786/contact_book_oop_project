//#ifndef HistoryObject_h
//#define HistoryObject_h
#include "ContactsBook.h"
#include "SearchHistory.h"
#include "Group.h"
template<class T>
class List
{
private:
    T* arr;
    int size;
    int count;
public:
    List()
    {
        /*constructor initialize the default size of array*/
        size = 5;
        arr = new T[size];
        count = 0;
    }

    T* Array()//Getters
    {
        return arr;
    }

    int Size()
    {
        return size;
    }

    int Count()
    {
        return count;
    }

    void Count(int count)//Setter only for count
    {
        this->count = count;
    }

    void AddToList(T obj) {
        /*
        *Adds to list,
        *resizes list if object array exceeds intialized count
        */
        if (size == count)
        {
            Resize();
        }
        arr[count] = obj;
        count++;
    }
    void Resize()
    {
        /*
        *same as resize function of contactbook
        */
        T* obj = new T[2 * size];
        for (int i = 0; i < count; i++)
        {
            obj[i] = arr[i];
        }
        size *= 2;
        delete[]arr;
        arr = obj;
    }

    void PrintList()
    {
        for (int i = 0; i < count; i++)
        {
            std::cout << arr[i];
        }
    }

    void ReadFromFile()
    {
        /*
        * Reads data from file
        */
        std::ifstream read;
        std::string str;
        std::cout << "File name : ";
        std::cin >> str;
        read.open(str);
        if (!read)
        {
            std::cout << "Error"<<std::endl;
        }
        else {
            std::cout << "Yes" << std::endl;
        }
        delete[]arr;
        read >> size;
        arr = new T[size];
        read >> count;
        std::string var;
        for (int i = 0; i < count; i++)
        {
            arr[i].InputData(read);

        }
        read.close();
    }

    void SaveToFile()
    {
        /*
        function we put tha data into file
        */
        std::ofstream out;
        std::string str;
        std::cout << "File name : ";
        std::cin >> str;
        out.open(str);
        std::cout << "for safety data is saved to file" << std::endl;
        out << size;
        out << std::endl;
        out << count;
        out << std::endl;
        for (int i = 0; i < count; i++)
        {
            arr[i].SaveData(out);
        }
        out.close();
    }


    //    void ReverseSort(T *s1 , int cout_search)
    //    {
    //        /*std::cout << "list function call" << std::endl;*/
    //        obj1.Reverse(s1 , count_search);
    //    }
};




//#endif /* HistoryObject_h */
