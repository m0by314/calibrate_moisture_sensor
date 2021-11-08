#ifndef _IFTTT_H_
#define _IFTTT_H_

#include <Arduino.h>


class Ifttt {
    public:
        Ifttt(String trigger_name, String ifttt_key, const char* ssid,  const char* pwd);
        void post_request(String value1, String value2, String value3);
        void connect();
        bool is_connected();
        
    private:
        const char* _ssid;
        const char* _pwd;
        String _trigger_name;
        String _ifttt_key;

        String _build_url();
        String _build_content(String value1, String value2, String value3);
};

#endif