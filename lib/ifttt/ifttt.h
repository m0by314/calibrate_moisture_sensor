#ifndef _IFTTT_H_
#define _IFTTT_H_

#include <Arduino.h>
 
class Ifttt {
    public:
        Ifttt(String trigger, String ifttt_key);
        String build_content(String value1, String value2, String value3);
        String get_url();
    
    private:
        String _trigger;
        String _ifttt_key;
};

#endif