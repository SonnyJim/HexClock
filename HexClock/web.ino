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
    <br>
    <label for="timezone">Choose a timezone:</label>

    <select name="timezone" id="timezone">
    %TZSELECT%
    </select>
    <br>
    <input type="submit" value="Submit">
  </form><br>
</body></html>)rawliteral";

// Replaces vars in webpage output
String processor(const String& var){
  if (var == "FTPENABLED")
  {
    if (cfg.ftp_enabled)
      return "checked";
    else
      return "";
  }
  else if (var == "TZSELECT")
  {
    String output;
    for (int i = 0; i < NUM_TZS; i++)
    {
      //output +=
    }
      return output;
  }
  else if (var == "HAENABLED")
  {
    if (cfg.ha_enabled)
      return "checked";
    else
      return "";
  }
  else if (var == "HA_STATUS")
  {
    if (ha_connected)
      return "Connected";
    else
      return "Not connected";
  }
  else if (var == "ANIM")
  {
    return anim_names[anim_state];
  }
  else if (var == "FTPUSERNAME")
  {
    return cfg.ftp_username;
  }
  else if (var == "FTPPASSWORD")
  {
    return cfg.ftp_password;
  }
  else if (var == "MQTTADDR")
  {
    return cfg.mqtt_addr;
  }
  else if (var == "MQTTUSERNAME")
  {
    return cfg.mqtt_username;
  }
  else if (var == "MQTTPASSWORD")
  {
    return cfg.mqtt_password;
  }
  else
    return String();
}

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void web_setup ()
{
  if (fs_mounted) 
  {
    Serial.println("Starting web services......");
    //if (cfg.ftp_enabled)
    //  ftpSrv.begin(cfg.ftp_username,cfg.ftp_password);
    httpd.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(LittleFS, "/index.html", String(), false, processor);
      });
    httpd.on("/log", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(LittleFS, LOGFILE, String(), false, processor);
      });
    //Serve the config page
    httpd.on("/cfg", HTTP_GET, [](AsyncWebServerRequest *request)
    {
      request->send_P(200, "text/html", cfg_html, processor);
    });
    //Handle the GET requestions
    httpd.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    String inputParam;
    bool cfg_changed = false;
    if (request->hasParam("ftp_enabled")) {
      //strncpy (cfg._password, request->getParam("mqtt_password")->value().c_str(), sizeof(cfg.mqtt_password));
      inputParam = request->getParam("ftp_enabled")->value();
      Serial.println (String ("Checkbox: ") + inputParam);
      cfg.ftp_enabled = true;
      cfg_changed = true;
    }
    else
    {
    //  ftpSrv.end();
      cfg.ftp_enabled = false;
    }
    
    if (request->hasParam("ha_enabled")) {

      cfg.ha_enabled = true;
      cfg_changed = true;
    }
    else
    {
      mqtt.disconnect();
      cfg.ha_enabled = false;
    }

    if (request->hasParam("ftp_username")) {
      strncpy (cfg.ftp_username, request->getParam("ftp_username")->value().c_str(), sizeof(cfg.ftp_username));
      cfg_changed = true;
    }
    if (request->hasParam("ftp_password")) {
      strncpy (cfg.ftp_password, request->getParam("ftp_password")->value().c_str(), sizeof(cfg.ftp_password));
      cfg_changed = true;
    }
    if (request->hasParam("mqtt_addr")) {
      strncpy (cfg.mqtt_addr, request->getParam("mqtt_addr")->value().c_str(), sizeof(cfg.mqtt_addr));
      cfg_changed = true;
    }
    if (request->hasParam("mqtt_username")) {
      strncpy (cfg.mqtt_username, request->getParam("mqtt_username")->value().c_str(), sizeof(cfg.mqtt_username));
      cfg_changed = true;
    }
    if (request->hasParam("mqtt_password")) {
      strncpy (cfg.mqtt_password, request->getParam("mqtt_password")->value().c_str(), sizeof(cfg.mqtt_password));
      cfg_changed = true;
    }
    else {
      inputMessage = "No message sent";
      inputParam = "none";
    }
    if (cfg_changed)
    {
      cfg_save ();
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
  }
  else
  {
    httpd.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(200, "text/plain", "Unable to start filesystem :("); });
    httpd.onNotFound(notFound);
    httpd.begin();
  }
}
