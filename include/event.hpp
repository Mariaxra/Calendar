#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <ctime>
class Event
{
private:
    std ::string EventName;
    time_t StartDate;
    time_t EndDate;
    std :: string Start;
    std :: string End;
    bool Passed = false;

public:
    //check function
    bool CheckName(std :: string );
    bool CheckDate(std :: string);

    //set functions
    Event(std :: string Eventname , std :: string start , std :: string end);
    void SetEventName(std ::string name);
    void SetEventDateStart(std ::string start);
    void SetEventDateEnd(std ::string end);
    void SetPass();
    // get function
    std ::string GetEventName() const;
    time_t GetEventDateStart() const;
    time_t GetEventDateEnd() const;
    std :: string GetEventEnd() const ;
    std :: string GetEventStart() const;
  
    ~Event();
};

#endif