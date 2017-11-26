#include <ESP8266HTTPClient.h>
#include "ESP8266Ifttt.h"

void ESP8266Ifttt::trigger(String iftttEventName, String iftttKey) {
  HTTPClient http;
  String json = "{}";
  http.begin("http://maker.ifttt.com/trigger/" + iftttEventName  + "/with/key/" + iftttKey);
  http.addHeader("Content-Type", "application/JSON");
  http.addHeader("Content-Length", String(json.length()));
  int httpCode = http.POST(json);
  http.end();
}

ESP8266Ifttt IFTTT;
