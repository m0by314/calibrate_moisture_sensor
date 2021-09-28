#ifndef _HTTP_REQUEST_H_
#define _HTTP_REQUEST_H_

#include <Arduino.h>
#include <HTTPClient.h>

void post_http_request(String url, String content);

#endif