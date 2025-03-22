#include <iostream>
#include "event.hpp"
#include "calendar.hpp"
using namespace std;
int main(){
    
        Calendar c1(Event("freedom day" , "20/10/2020" ,"24/10/2020" ));
        c1.Add_Event(Event("Anni Day" , "21/11/2027" ,"24/11/2027"));
        c1.Add_Event(Event("New year" , "12/12/2024" , "13/12/2024"));
        //c1.Add_Event(Event("" , "-40" , "12/12" )); // Error for invalid Event
        c1.PrintCalendar();
        c1.Refresh();
        c1.PrintCalendar();

    return 0;
}