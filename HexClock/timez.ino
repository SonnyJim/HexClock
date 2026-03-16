#include <Arduino.h>
#include <avr/pgmspace.h>
#include "timez.h"

bool findTZInTable(const char* const table[][2], size_t count,
                   const char* city,
                   char* posixOut, size_t posixLen)
{
    for (size_t i = 0; i < count; i++) {

        const char* namePtr  = (const char*)pgm_read_ptr(&table[i][0]);
        const char* posixPtr = (const char*)pgm_read_ptr(&table[i][1]);

        char name[40];
        strcpy_P(name, namePtr);

        if (strcmp(name, city) == 0) {
            strcpy_P(posixOut, posixPtr);
            return true;
        }
    }

    return false;
}

bool getPOSIXFromRegionCity(const char* regionCity,
                            char* posixOut, size_t posixLen)
{
    char buf[64];
    strncpy(buf, regionCity, sizeof(buf));
    buf[sizeof(buf)-1] = 0;

    char* slash = strchr(buf, '/');
    if (!slash) return false;

    *slash = 0;
    char* region = buf;
    char* city   = slash + 1;

    if (strcmp(region, "Africa") == 0)
        return findTZInTable(tz_Africa, TZ_COUNT(tz_Africa), city, posixOut, posixLen);

    if (strcmp(region, "America") == 0)
        return findTZInTable(tz_America, TZ_COUNT(tz_America), city, posixOut, posixLen);

    if (strcmp(region, "Antarctica") == 0)
        return findTZInTable(tz_Antarctica, TZ_COUNT(tz_Antarctica), city, posixOut, posixLen);

    if (strcmp(region, "Arctic") == 0)
        return findTZInTable(tz_Arctic, TZ_COUNT(tz_Arctic), city, posixOut, posixLen);

    if (strcmp(region, "Asia") == 0)
        return findTZInTable(tz_Asia, TZ_COUNT(tz_Asia), city, posixOut, posixLen);

    if (strcmp(region, "Atlantic") == 0)
        return findTZInTable(tz_Atlantic, TZ_COUNT(tz_Atlantic), city, posixOut, posixLen);

    if (strcmp(region, "Australia") == 0)
        return findTZInTable(tz_Australia, TZ_COUNT(tz_Australia), city, posixOut, posixLen);

    if (strcmp(region, "Etc") == 0)
        return findTZInTable(tz_Etc, TZ_COUNT(tz_Etc), city, posixOut, posixLen);

    if (strcmp(region, "Europe") == 0)
        return findTZInTable(tz_Europe, TZ_COUNT(tz_Europe), city, posixOut, posixLen);

    if (strcmp(region, "Indian") == 0)
        return findTZInTable(tz_Indian, TZ_COUNT(tz_Indian), city, posixOut, posixLen);

    if (strcmp(region, "Pacific") == 0)
        return findTZInTable(tz_Pacific, TZ_COUNT(tz_Pacific), city, posixOut, posixLen);

    return false;
}

bool setTimezoneFromString(const char* regionCity)
{
    char posix[64];

    if (!getPOSIXFromRegionCity(regionCity, posix, sizeof(posix))) {
        log_write(String("Timezone not found: ") + regionCity);
        return false;
    }

    configTime(posix, "pool.ntp.org");

    log_write(String("Timezone set to ") + regionCity + " -> " + posix);

    return true;
}