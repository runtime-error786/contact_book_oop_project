#include<iostream>
class runtime_error : public std::exception
{
public:
    void what();
};
