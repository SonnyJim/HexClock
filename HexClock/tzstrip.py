import re
from collections import defaultdict

regions = defaultdict(list)

pattern = re.compile(r'\{"TZ_([^_]+)_(.+?)",\s*"PSTR\(\\"([^"]+)\\"\)"\}')

with open("tzlist.txt", "r", encoding="utf-8") as f:
    for line in f:
        m = pattern.search(line)
        if not m:
            continue

        region = m.group(1)       # Africa
        city = m.group(2)         # Argentina_Buenos_Aires
        tz_value = m.group(3)     # GMT0

        # Strip underscores
        city = city.replace("_", " ")

        regions[region].append((city, tz_value))

with open("tz_regions.txt", "w", encoding="utf-8") as out:
    for region in sorted(regions):
        out.write(f'const char* const tz_{region}[][2] PROGMEM = {{\n')
        for city, val in regions[region]:
            out.write(f'    {{"{city}", "{val}"}},\n')
        out.write("};\n\n")

print("Done. Regions written to tz_regions.txt")