#ifndef Calendar_H
#define Calendar_H
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "event.hpp"

class Calendar
{
private:
    std ::vector<Event> v;

public:
    
    Calendar(const Event & );
    void PrintCalendar();
    void Add_Event(const Event & ); // 12\02\1403
    void Refresh();
};

#endif