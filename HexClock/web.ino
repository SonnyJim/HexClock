#include "timez.h"

AsyncWebServer httpd(80);

const char cfg_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Hexclock configuration</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/get">
    FTP enabled <input type="checkbox" name="ftp_enabled" %FTPENABLED%><br>
    FTP Username: <input type="text" name="ftp_username" value="%FTPUSERNAME%"><br>
    FTP Password: <input type="text" name="ftp_password" value="%FTPPASSWORD%"><br>
    <br>
    Home assistant %HA_STATUS%<br>
    HA enabled <input type="checkbox" name="ha_enabled" %HAENABLED%><br>
    MQTT Address: <input type="text" name="mqtt_addr" value="%MQTTADDR%"><br>
    MQTT Username: <input type="text" name="mqtt_username" value="%MQTTUSERNAME%"><br>
    MQTT Password: <input type="text" name="mqtt_password" value="%MQTTPASSWORD%"><br>
  </form><br>
</body></html>)rawliteral";

void sendTZOptions(AsyncWebServerRequest *request,
                   const char *const table[][2],
                   size_t count) {
  String html;

  for (size_t i = 0; i < count; i++) {

    const char *namePtr = (const char *)pgm_read_ptr(&table[i][0]);

    char name[40];
    strcpy_P(name, namePtr);

    html += "<option value='";
    html += name;
    html += "'>";
    html += name;
    html += "</option>";
  }

  request->send(200, "text/html", html);
}

void handleTZList(AsyncWebServerRequest *request) {
  if (!request->hasParam("region")) {
    request->send(400, "text/plain", "Missing region");
    return;
  }

  String region = request->getParam("region")->value();

  if (region == "Africa")
    sendTZOptions(request, tz_Africa, TZ_COUNT(tz_Africa));

  else if (region == "America")
    sendTZOptions(request, tz_America, TZ_COUNT(tz_America));

  else if (region == "Antarctica")
    sendTZOptions(request, tz_Antarctica, TZ_COUNT(tz_Antarctica));

  else if (region == "Arctic")
    sendTZOptions(request, tz_Arctic, TZ_COUNT(tz_Arctic));

  else if (region == "Asia")
    sendTZOptions(request, tz_Asia, TZ_COUNT(tz_Asia));

  else if (region == "Atlantic")
    sendTZOptions(request, tz_Atlantic, TZ_COUNT(tz_Atlantic));

  else if (region == "Australia")
    sendTZOptions(request, tz_Australia, TZ_COUNT(tz_Australia));

  else if (region == "Etc")
    sendTZOptions(request, tz_Etc, TZ_COUNT(tz_Etc));

  else if (region == "Europe")
    sendTZOptions(request, tz_Europe, TZ_COUNT(tz_Europe));

  else if (region == "Indian")
    sendTZOptions(request, tz_Indian, TZ_COUNT(tz_Indian));

  else if (region == "Pacific")
    sendTZOptions(request, tz_Pacific, TZ_COUNT(tz_Pacific));

  else
    request->send(404, "text/plain", "Region not found");
}

void handleSetTZ(AsyncWebServerRequest *request) {
  if (!request->hasParam("region") || !request->hasParam("city")) {
    request->send(400, "text/plain", "Missing parameters");
    return;
  }

  String region = request->getParam("region")->value();
  String city = request->getParam("city")->value();

  String tz = region + "/" + city;
  tz.toCharArray(cfg.regioncity, sizeof(cfg.regioncity));

  if (setTimezoneFromString(tz.c_str()))
  {
    cfg_save();
    // Send HTML that shows success and redirects after 3 seconds
    String html = "<!DOCTYPE html><html><head>"
                  "<meta http-equiv='refresh' content='3;url=" + 
                  request->header("Referer") + "'>"
                  "<title>Timezone Set</title></head>"
                  "<body>"
                  "<p>Timezone set to " + tz + ".</p>"
                  "<p>Returning to previous page in 3 seconds...</p>"
                  "</body></html>";
    request->send(200, "text/html", html);
  }
  else
    request->send(500, "text/plain", "Failed to set timezone");
}

// Replaces vars in webpage output
String processor(const String &var) {
  if (var == "FTPENABLED") {
    return cfg.ftp_enabled ? "checked" : "";
  } 
  else if (var == "HAENABLED") {
    return cfg.ha_enabled ? "checked" : "";
  } 
  else if (var == "HA_STATUS") {
    return ha_connected ? "Connected" : "Not connected";
  } 
  else if (var == "ANIM") {
    return anim_names[anim_state];
  } 
  else if (var == "FTPUSERNAME") {
    return cfg.ftp_username;
  } 
  else if (var == "FTPPASSWORD") {
    return cfg.ftp_password;
  } 
  else if (var == "MQTTADDR") {
    return cfg.mqtt_addr;
  } 
  else if (var == "MQTTUSERNAME") {
    return cfg.mqtt_username;
  } 
  else if (var == "MQTTPASSWORD") {
    return cfg.mqtt_password;
  } 
  else if (var == "DEFAULT_REGION") {
    // Split cfg.regioncity at '/'
    String tz = String(cfg.regioncity);
    int slashIndex = tz.indexOf('/');
    if (slashIndex > 0)
      return tz.substring(0, slashIndex);
    else
      return "Europe"; // fallback default
  } 
  else if (var == "DEFAULT_CITY") {
    String tz = String(cfg.regioncity);
    int slashIndex = tz.indexOf('/');
    if (slashIndex > 0)
      return tz.substring(slashIndex + 1);
    else
      return "London"; // fallback default
  } 
  else
    return String();
}

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void web_setup() {
  if (fs_mounted) {
    log_write("Starting web services......");
    //if (cfg.ftp_enabled)
    //  ftpSrv.begin(cfg.ftp_username,cfg.ftp_password);

    httpd.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(LittleFS, "/index.html", String(), false, processor);
    });
    httpd.on("/current_time", HTTP_GET, [](AsyncWebServerRequest *request) {
      time_t now = time(nullptr);  // get current epoch time
      struct tm timeinfo;
      localtime_r(&now, &timeinfo);  // convert to local time using TZ

      char buf[32];
      strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);  // format time

      request->send(200, "text/plain", String(buf));
    });
    httpd.on("/tzlist", HTTP_GET, handleTZList);
    httpd.on("/set_tz", HTTP_GET, handleSetTZ);

    httpd.on("/log", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(LittleFS, LOGFILE, String(), false, processor);
    });
    //Serve the config page
    httpd.on("/cfg", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send_P(200, "text/html", cfg_html, processor);
    });
    //Handle the GET requestions
    httpd.on("/get", HTTP_GET, [](AsyncWebServerRequest *request) {
      String inputMessage;
      String inputParam;
      bool cfg_changed = false;
      if (request->hasParam("ftp_enabled")) {
        //strncpy (cfg._password, request->getParam("mqtt_password")->value().c_str(), sizeof(cfg.mqtt_password));
        inputParam = request->getParam("ftp_enabled")->value();
        Serial.println(String("Checkbox: ") + inputParam);
        cfg.ftp_enabled = true;
        cfg_changed = true;
      } else {
        //  ftpSrv.end();
        cfg.ftp_enabled = false;
      }

      if (request->hasParam("ha_enabled")) {

        cfg.ha_enabled = true;
        cfg_changed = true;
      } else {
        mqtt.disconnect();
        cfg.ha_enabled = false;
      }

      if (request->hasParam("ftp_username")) {
        strncpy(cfg.ftp_username, request->getParam("ftp_username")->value().c_str(), sizeof(cfg.ftp_username));
        cfg_changed = true;
      }
      if (request->hasParam("ftp_password")) {
        strncpy(cfg.ftp_password, request->getParam("ftp_password")->value().c_str(), sizeof(cfg.ftp_password));
        cfg_changed = true;
      }
      if (request->hasParam("mqtt_addr")) {
        strncpy(cfg.mqtt_addr, request->getParam("mqtt_addr")->value().c_str(), sizeof(cfg.mqtt_addr));
        cfg_changed = true;
      }
      if (request->hasParam("mqtt_username")) {
        strncpy(cfg.mqtt_username, request->getParam("mqtt_username")->value().c_str(), sizeof(cfg.mqtt_username));
        cfg_changed = true;
      }
      if (request->hasParam("mqtt_password")) {
        strncpy(cfg.mqtt_password, request->getParam("mqtt_password")->value().c_str(), sizeof(cfg.mqtt_password));
        cfg_changed = true;
      } else {
        inputMessage = "No message sent";
        inputParam = "none";
      }
      if (cfg_changed) {
        cfg_save();
        //ftpSrv.end(); //Restart FTP server to update password
        //if (cfg.ftp_enabled)
        //  ftpSrv.begin(cfg.ftp_username,cfg.ftp_password);
        mqtt.disconnect();
        ha_start();
        //mqtt.begin(cfg.mqtt_addr,cfg.mqtt_username, cfg.mqtt_password);
      }
      request->send(200, "text/html", "Settings saved<br><a href=\"/cfg\">Return to configuration</a>");
    });

    httpd.onNotFound(notFound);
    httpd.begin();
  } else {
    httpd.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
      request->send(200, "text/plain", "Unable to start filesystem :(");
    });
    httpd.onNotFound(notFound);
    httpd.begin();
  }
}
