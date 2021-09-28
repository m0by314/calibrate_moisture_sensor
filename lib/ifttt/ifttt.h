#ifndef _IFTTT_H_
#define _IFTTT_H_

#include <Arduino.h>
 
class Ifttt {
    public:
        Ifttt(String trigger)  : _trigger(trigger)  {};
        void post_request(String value1, String value2, String value3);
    
    private:
        String _trigger;
        String _ifttt_url();
};

#endif