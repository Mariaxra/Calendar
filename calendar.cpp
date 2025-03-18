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
void Calendar ::Add_Event(std ::string Eventstart, std ::string EventEnd, std ::string Eventname)
{
    time_t now = std :: time(0);
    Event e(Eventname , Eventstart , EventEnd );
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
        std :: cout << "Task added";
        v.push_back(e);
    }
}

void Calendar ::Refresh()
{
    time_t now = std ::time(0);

    for (auto it = v.begin(); it != v.end(); )
    {
        if(it->GetEventDateEnd() < now)
        {
            it = v.erase(it);
        }
        else 
        ++it;
        
    }
}