#include <time.h>


static String getOldLogFileName() {
    return String(LOGFILE) + ".old";
}

static void log_rotate_if_needed() {
    if (LittleFS.exists(LOGFILE)) {
        File f = LittleFS.open(LOGFILE, "r");
        if (f) {
            size_t size = f.size();
            f.close();
            if (size >= LOGFILE_SIZE) {
                String oldFile = getOldLogFileName();

                // Delete old rotated file if it exists
                if (LittleFS.exists(oldFile)) {
                    LittleFS.remove(oldFile);
                }

                // Rename current log to old
                LittleFS.rename(LOGFILE, oldFile);
            }
        }
    }
}


void log_write(String message)
{
    // Get current time from NTP
    time_t now = time(nullptr);           // current epoch time
    struct tm* tm_info = localtime(&now); // convert to local time

    char timestamp[25];
    // Format: YYYY-MM-DD HH:MM:SS
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    String log_entry = String(timestamp) + " LOG: " + message;

    // Print to Serial
    Serial.println(log_entry);
    log_rotate_if_needed();
    // Append to logfile
    File logfile = LittleFS.open(LOGFILE, "a");
    if (logfile) {
        logfile.println(log_entry);
        logfile.close();
    }
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