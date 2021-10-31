#include "ifttt.h"

/* 
*   Constructor
*/
Ifttt::Ifttt (String trigger, String ifttt_key)
    : _trigger(trigger), _ifttt_key(ifttt_key) {}


/* 
*   Build ifttt url
*/
String Ifttt::get_url() {
      return "http://maker.ifttt.com/trigger/" + _trigger + "/with/key/" + _ifttt_key;
}

String Ifttt::build_content(String value1, String value2, String value3) {
    return "{\"value1\":\"" + value1 + "\",\"value2\":\"" + value2 + "\",\"value3\":\"" + value3 +"\"}";
   
}