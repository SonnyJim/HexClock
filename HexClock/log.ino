void log_write (String message)
{
  Serial.println("LOG: " + message);
  logfile = LittleFS.open (LOGFILE, "a");
 logfile.print(message);
 logfile.print("\n");
 logfile.close();
}

void log_setup ()
{/*
  logfile = LittleFS.open (LOGFILE, "w");

  if (!logfile)
  {
    Serial.println ("log_setup: couldn't open logfile");
  }
  */
  log_write ("Opening log file");
}