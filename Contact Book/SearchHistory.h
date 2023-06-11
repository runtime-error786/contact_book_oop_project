
#ifndef SearchHistory_h
#define SearchHistory_h

#include <iostream>
#include "Date.h"
class SearchHistory
{
private:
    Date date;
    std::string str_search;
    
public:
    SearchHistory();
    Date  GetObj1();
    std::string GetString();
    void Reverse(SearchHistory* s1 , int count);//oldest
    void SetData(std::string str_search);
    void SaveData(std::ofstream & out);
    void InputData(std::ifstream & in);

    friend std::ostream& operator <<(std::ostream& in, const SearchHistory& s1);
};

#endif /* SearchHitory_hpp */

