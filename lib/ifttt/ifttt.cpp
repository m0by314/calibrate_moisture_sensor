#include "ifttt.h"
#include <config.h>
#include <http_request.h>

String Ifttt::_ifttt_url() {
      return "http://maker.ifttt.com/trigger/" + this->_trigger + "/with/key/" + IFTTT_KEY;
}

void Ifttt::post_request(String value1, String value2, String value3) {
    String content = "{\"value1\":\"" + value1 + "\",\"value2\":\"" + value2 + "\",\"value3\":\"" + value3 +"\"}";
    post_http_request(this->_ifttt_url(), content);
}