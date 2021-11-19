/** 
 * Library to manage wifi connections for EPS32
*/
#ifndef _WIFI_C_H_
#define _WIFI_C_H_


bool wifi_connect(const char* ssid, const char* pwd, int timeout=10, bool debug=false);

bool wifi_is_connected(bool debug=false);


#endif