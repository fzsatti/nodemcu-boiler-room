
#ifndef SUPABASE_FUNCTIONS_H
#define SUPABASE_FUNCTIONS_H
#include <ESPSupabase.h>

class SupabaseFunctions {
  private:
    Supabase supabase;
  public:
    SupabaseFunctions();
    void init();
    void sendData(float waterTemp, float airTemp, float humididty);
};

#endif
