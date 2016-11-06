
#ifndef  __TIMER_H
#define  __TIMER_H

#include <ctime>

class Timer  {
  private:
    tm*  tidspunkt;
  public: 
    void hent(int& time, int& min, int& sek);
};

void Timer::hent(int& ti, int& mi, int& se)  {
   long tid;
   tid = time(NULL);
   tidspunkt = localtime(&tid);
   ti = tidspunkt->tm_hour;
   mi = tidspunkt->tm_min;
   se = tidspunkt->tm_sec;
}

#endif
