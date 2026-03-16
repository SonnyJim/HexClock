#define CFG_FILE "/cfg.bin"

void cfg_print ()
{
  Serial.println (String("FTP Username: ") + cfg.ftp_username);
  Serial.println (String("FTP Password: ") + cfg.ftp_password);
  Serial.println (String("MQTT: ") + cfg.mqtt_addr + " " + cfg.mqtt_username +" " + cfg.mqtt_password);
}

uint8_t cfg_get_checksum (void)
{
  uint8_t sum;
  unsigned char *p = (unsigned char *)&cfg;
  for (int i = 0; i < (sizeof(cfg) - sizeof(cfg.checksum)); i++)
  {
      sum += p[i];
  }
  return sum;
}

void cfg_load ()
{
  if (!fs_mounted)
  {
    Serial.println ("cfg_load: Filesystem not mounted");
    return;
  }

  File f = LittleFS.open(CFG_FILE, "r");
  if (!LittleFS.exists (CFG_FILE))
  {
    Serial.println ("cfg_load: Could not find config file, loading defaults");
    cfg_load_default();
    cfg_save ();
    return;
  }
  else if (!f)
  {
    Serial.println (String("cfg_load: Error loading ") + CFG_FILE);
    return;
  }
  f.read((byte*) &cfg,sizeof(cfg));
  f.close();
  if (cfg.checksum != cfg_get_checksum())
  {
    Serial.println ("cfg_load: Checksum error, loading defaults");
    cfg_load_default ();
  }
  return;
}

void cfg_save ()
{
  Serial.println ("Saving config.....");
  if (!fs_mounted)
  {
    Serial.println ("cfg_save: Filesystem not mounted, aborting..");
    return;
  }

  File f = LittleFS.open(CFG_FILE, "w");
  if (!f)
  {
    Serial.println (String("cfg_save: Error opening file for saving ") + CFG_FILE);
    return;
  }
  cfg.checksum = cfg_get_checksum ();
  if (f.write((byte*) &cfg,sizeof(cfg)))
    Serial.println ("cfg_save: Saved successfully");
  else
    Serial.println ("cfg_save: Error writing cfg file");
}

void cfg_load_default ()
{
  memset (&cfg, '\0', sizeof(cfg));

  cfg.ftp_enabled = false;
  
  strcpy (cfg.ftp_username, DEFAULT_FTP_USERNAME);
  strcpy (cfg.ftp_password, DEFAULT_FTP_PASSWORD);
  cfg.ha_enabled = true;
  strcpy (cfg.mqtt_addr, DEFAULT_MQTT_ADDR);
  strcpy (cfg.mqtt_username, DEFAULT_MQTT_USERNAME);
  strcpy (cfg.mqtt_password, DEFAULT_MQTT_PASSWORD);
  
  cfg_loaded = true;
  cfg_save ();
}

void cfg_setup ()
{
  cfg_loaded = false;
  fs_mounted = false;
  Serial.println ("Mounting filesystem....");
  if (!LittleFS.begin())
  {
    Serial.println ("Error mounting Filesystem, loading default config");
    cfg_load_default ();
  }
  else
  {
    fs_mounted = true;
    cfg_load_default ();
    cfg_load ();
  }

  cfg_print ();
}