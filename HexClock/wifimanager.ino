// DNS server
#include <DNSServer.h>
const byte DNS_PORT = 53;
DNSServer dnsServer;
String wifiOptions;


bool tryWiFiConnect() {
  if (strlen(cfg.wifi_essid) != 0) {
    WiFi.mode(WIFI_STA);
    WiFi.setHostname(HOSTNAME);
    WiFi.begin(cfg.wifi_essid, cfg.wifi_password);
    Serial.printf("Trying WiFi: %s\n", cfg.wifi_essid);

    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 20000) {
      delay(500);
      Serial.print(".");
    }
    Serial.println();
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi!");
    Serial.println(WiFi.localIP());
    return true;
  } else {
    String msg = "Failed to connect to: ";
    msg += cfg.wifi_essid;
    log_write(msg);
    Serial.println("Failed to connect.");
    delay(5000);
    return false;
  }
}

void scanWiFi() {
  wifiOptions = "";

  int n = WiFi.scanNetworks();

  for (int i = 0; i < n; i++) {
    wifiOptions += "<option value=\"";
    wifiOptions += WiFi.SSID(i);
    wifiOptions += "\">";
    wifiOptions += WiFi.SSID(i);
    wifiOptions += "</option>";
  }

  WiFi.scanDelete();  // free memory
}

void startConfigPortal() {
  Serial.println("Starting config portal...");
  scanWiFi();
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(IPAddress(192, 168, 4, 1), IPAddress(192, 168, 4, 1), IPAddress(255, 255, 255, 0));
  WiFi.softAP(String(HOSTNAME) + String(ESP.getChipId()));
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(DNS_PORT, "*", IPAddress(192, 168, 4, 1));
  Serial.println("AP started: ESP_ConfigPortal");

  httpd.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String options = wifiOptions;

    String html = "<!DOCTYPE html><html><head><title>WiFi Setup</title>";
    html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";

    html += "<style>";
    html += "body{font-family:sans-serif;font-size:20px;margin:20px;}";
    html += "select,input{font-size:20px;width:100%;padding:10px;margin-top:5px;margin-bottom:15px;}";
    html += "input[type=submit]{background:#2c7be5;color:white;border:none;padding:12px;}";
    html += "</style>";

    html += "<script>";
    html += "function pickSSID(){";
    html += "var s=document.getElementById('essid').value;";
    html += "document.getElementById('custom_essid').value=s;";
    html += "}";
    html += "</script>";

    html += "</head>";
    html += "<body onload=\"pickSSID()\">";

    html += "<h2>Configure WiFi</h2>";
    html += "<form action=\"/save\" method=\"get\">";

    html += "SSID:<br>";
    html += "<select id=\"essid\" name=\"essid\" onchange=\"pickSSID()\">";
    html += options;
    html += "</select>";

    html += "Or enter custom SSID:";
    html += "<input type=\"text\" id=\"custom_essid\" name=\"custom_essid\" maxlength=\"32\">";

    html += "Password:";
    html += "<input type=\"password\" name=\"pass\" maxlength=\"64\" required>";

    html += "<input type=\"submit\" value=\"Save\">";

    html += "</form></body></html>";

    request->send(200, "text/html", html);
  });

  httpd.on("/save", [](AsyncWebServerRequest *request) {
    String essid;
    if (request->hasParam("custom_essid") && request->getParam("custom_essid")->value() != "") {
      essid = request->getParam("custom_essid")->value();
    } else if (request->hasParam("essid")) {
      essid = request->getParam("essid")->value();
    }

    if (request->hasParam("pass") && essid.length() > 0) {
      String pass = request->getParam("pass")->value();

      if (essid.length() > 32) essid = essid.substring(0, 32);
      if (pass.length() > 64) pass = pass.substring(0, 64);

      essid.toCharArray(cfg.wifi_essid, sizeof(cfg.wifi_essid));
      pass.toCharArray(cfg.wifi_password, sizeof(cfg.wifi_password));

      cfg_save();

      request->send(200, "text/html", "<h2>Saved wifi details, rebooting...</h2>");
      delay(500);
      ESP.restart();
    } else {
      request->send(400, "text/plain", "Missing SSID or password");
    }
  });

  httpd.begin();

  // **Loop until Wi-Fi connects**

  while (true) {
    dnsServer.processNextRequest();
    //delay(1); // Let AsyncWebServer handle requests
    //if(tryWiFiConnect()) break; // Exit loop if connection successful
  }

  Serial.println("Wi-Fi connected! Stopping AP...");
  WiFi.softAPdisconnect(true);
}

void wifi_setup() {
  //Serial.begin(115200);

  if (!tryWiFiConnect()) {
    startConfigPortal();
  }
}
