#include "event.hpp"
#include <iostream>
#include <exception>
bool isNumber(const std::string &str)
{
    try
    {
        size_t pos;
        std::stod(str, &pos);
        if (pos != str.length())
        {
            throw std::invalid_argument("invalid Date");
        }
        return true;
    }
    catch (const std::invalid_argument &e)
    {
        return false;
    }
    catch (const std::out_of_range &e)
    {
        return false;
    }
}

time_t ConvertDateToTimestamps(std ::string day, std ::string month, std ::string year)
{
    std ::tm tm = {};
    tm.tm_mday = stoi(day);
    tm.tm_mon = stoi(month) - 1;
    tm.tm_year = stoi(year) - 1900;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    time_t Date = mktime(&tm);
    return Date;
}
//check implemention
bool Event :: CheckName(std :: string x)
{
    if ((x.empty()))
    {
        throw std :: invalid_argument( "Empty input is invaild.");
    }
    return true;
}
bool Event :: CheckDate(std :: string date)
{
     if(date.length() != 10 ||  date[2] != '/' ||  date[5] != '/') {
        throw std :: invalid_argument( "invalid date");
        }
        std::string day = date.substr(0, 2);
        std::string month = date.substr(3, 2);
        std::string year = date.substr(6, 4);

               if( isNumber(day) && isNumber(month) && isNumber(year) &&
               (std::stoi(day) >= 1 && std::stoi(day) <= 31) &&
               (std::stoi(month) >= 1 && std::stoi(month)) <= 12)
               {
                return true;
               }
               else 
               {
                throw std :: invalid_argument( "invalid date");
               }
    }
//Set implemention
void Event ::SetEventName(std ::string name)
{
    if(CheckName(name))
    this->EventName = name;
}
void Event ::SetEventDateStart(std ::string start)
{
    if(CheckDate(start) && CheckName(start)){
   
    std ::string day = start.substr(0, 2), month = start.substr(3, 2), year = start.substr(6, 4);
    
        this->StartDate = ConvertDateToTimestamps(day, month, year);
        this->Start = start;
    }
    else{
     std :: cout << "invalid Date";
     return;}
}
void Event ::SetEventDateEnd(std ::string end)
{
        if(CheckDate(end) && CheckName(end)){
   
    std ::string day = end.substr(0, 2), month = end.substr(3, 2), year = end.substr(6, 4);
        this->EndDate = ConvertDateToTimestamps(day, month, year);
        this->End = end;
    }
    else {
    std :: cout << "invalid Date";
    return ;}
}
void Event ::SetPass() { this->Passed = true; }
//Get implemntion
std ::string Event ::GetEventName() const { return EventName; }
std ::string Event ::GetEventStart() const { return Start; }
std ::string Event ::GetEventEnd() const { return End; }
time_t Event ::GetEventDateStart() const { return StartDate; }
time_t Event ::GetEventDateEnd() const { return EndDate; }
//constructor
Event ::Event(std ::string Eventname, std ::string start, std ::string end)
{
    SetEventName(Eventname);
    SetEventDateStart(start);
    SetEventDateEnd(end);
}
//destructor
Event ::~Event()
{
    if (Passed)
    {
        time_t now;
        time(&now);
        std ::cout << "The event has already passed ! \n";
        std ::cout << "We deleted : " << EventName << " " << Start << " " << End << '\n';
        std ::cout << "the Date now is : " << ctime(&now);
    }
}
