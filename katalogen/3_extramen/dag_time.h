
#if !defined(__DAG_TIME_H)
#define  __DAG_TIME_H

#include <ctime>

class Dag_Time  {
  private:
    tm*  tidspunkt;
  public: 
    int hent_dag();
    int hent_time();
};

int Dag_Time::hent_dag()  {
   time_t  tid;        //  Tidligere:   long tid; 
   tid = time(NULL);
   tidspunkt = localtime(&tid);
   return (int(tidspunkt->tm_wday));
}

int Dag_Time::hent_time()  {
   time_t  tid;        //  Tidligere:   long tid; 
   tid = time(NULL);
   tidspunkt = localtime(&tid);
   return (int(tidspunkt->tm_hour));
}

#endif
