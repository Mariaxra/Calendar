#include "calendar.hpp"
#include "event.hpp"
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

Calendar ::Calendar(const Event & a)
{
    v.push_back(a);
}
void Calendar ::Add_Event(const Event & e)
{
    time_t now = std :: time(0);
    bool find_conflict = false;
    
    for(int i = 0 ; i  < v.size() ; ++i)
    {
       if((e.GetEventDateStart() >= v[i].GetEventDateStart()) && (e.GetEventDateStart() <= v[i].GetEventDateEnd()) )
       {
         std :: cout << "the event has conflict with other events \n";
         v[i].SetPass();
         find_conflict = true;
         break;
       }
       else if((e.GetEventDateEnd() >= v[i].GetEventDateStart()) && (e.GetEventDateEnd() <= v[i].GetEventDateEnd()))
       {
        //  std :: cout << "the time now is " << time(0)  << '\n';
        // std  :: cout <<  v[i].GetEventDateStart () <<" s" << v[i].GetEventDateEnd() << "e\n";
         v[i].SetPass();
         find_conflict = true;
        std :: cout << "the event has conflict with other events \n";
        find_conflict = true;
        break;

       }

    }
    if(!find_conflict)
    {
        std :: cout << "Task added.\n";
        v.push_back(e);
    }
}
void Calendar ::Refresh()
{
    time_t now = std ::time(0);
    int len = v.size();
    int i = 0;
    while (i < len)
    {
        if((v[i].GetEventDateEnd()) < now)
        {
            std :: swap(v[i] , v.back());
            v.back().SetPass();
            v.pop_back();
            len--;   
        }   
        else
        {
            i++;
        } 
    }
}
void Calendar :: PrintCalendar()
{
    std :: cout << std :: left << std :: fixed <<std :: setw(30) << "Event name"<<"|"<< std :: setw(10) << "Start" <<'|'<<std :: setw(10) << 
    "End" <<"|" <<'\n';
    std :: cout << std :: string(53 , '_')<<'\n';
    for(auto & c : v)
    {
         std :: cout << std :: left << std :: fixed <<std :: setw(30) << c.GetEventName()<<"|"
         << std :: setw(10) << c.GetEventStart() <<'|'<<std :: setw(10) << 
    c.GetEventEnd() <<"|" <<'\n';

    }
}