#define CFG_FILE "/cfg.bin"

void cfg_print ()
{
  Serial.println (String("Username: ") + cfg.username);
  Serial.println (String("Password: ") + cfg.password);
  Serial.println (String("ESSID: ") + cfg.wifi_essid);
  Serial.println (String("Wifi Password: ") + cfg.wifi_password);
  Serial.println (String("MQTT: ") + cfg.mqtt_addr + " " + cfg.mqtt_username +" " + cfg.mqtt_password);
  log_write(String("Home assistant enabled: ") + (cfg.ha_enabled ? "true" : "false"));
  log_write (String("Timezone: ") + cfg.regioncity);
}

uint8_t cfg_get_checksum (void)
{
  uint8_t sum = 0;
  unsigned char *p = (unsigned char *)&cfg;
  for (int i = 0; i < (sizeof(cfg) - sizeof(cfg.checksum)); i++)
  {
      sum += p[i];
  }
  return sum;
}

void cfg_load ()
{
  log_write("cfg_load()");
  if (!fs_mounted)
  {
    Serial.println ("cfg_load: Filesystem not mounted");
    return;
  }

  File f = LittleFS.open(CFG_FILE, "r");
  if (!LittleFS.exists (CFG_FILE))
  {
    log_write ("cfg_load: Could not find config file, loading defaults");
    cfg_load_default();
    cfg_save ();
    return;
  }
  else if (!f)
  {
    log_write (String("cfg_load: Error loading ") + CFG_FILE);
    return;
  }
  f.read((byte*) &cfg,sizeof(cfg));
  f.close();
  if (cfg.checksum != cfg_get_checksum())
  {
    log_write ("cfg_load: Checksum error, loading defaults");
    cfg_load_default ();
  }
  return;
}

void cfg_save ()
{
  log_write ("Saving config.....");
  if (!fs_mounted)
  {
    log_write ("cfg_save: Filesystem not mounted, aborting..");
    return;
  }

  File f = LittleFS.open(CFG_FILE, "w");
  if (!f)
  {
    log_write (String("cfg_save: Error opening file for saving ") + CFG_FILE);
    return;
  }
  cfg.checksum = cfg_get_checksum ();
  if (f.write((byte*) &cfg,sizeof(cfg)))
    log_write ("cfg_save: Saved successfully");
  else
    log_write ("cfg_save: Error writing cfg file");
  cfg_print();
}

void cfg_load_default ()
{
  log_write("cfg_load_default()");
  memset (&cfg, '\0', sizeof(cfg));

  cfg.ftp_enabled = false;
  
  strcpy (cfg.username, DEFAULT_USERNAME);
  strcpy (cfg.password, DEFAULT_PASSWORD);
  cfg.ha_enabled = true;
  strcpy (cfg.mqtt_addr, DEFAULT_MQTT_ADDR);
  strcpy (cfg.mqtt_username, DEFAULT_MQTT_USERNAME);
  strcpy (cfg.mqtt_password, DEFAULT_MQTT_PASSWORD);
  strcpy (cfg.regioncity, DEFAULT_REGIONCITY);
  strcpy (cfg.wifi_essid, "");
  strcpy (cfg.wifi_password, "");
  cfg_loaded = true;
  cfg_save ();
}

void cfg_setup ()
{
  cfg_loaded = false;
  fs_mounted = false;
  log_write ("Mounting filesystem....");
  if (!LittleFS.begin())
  {
    Serial.println ("Error mounting Filesystem, loading default config");
    cfg_load_default ();
  }
  else
  {
    fs_mounted = true;
    cfg_load ();
  }

  cfg_print ();
}