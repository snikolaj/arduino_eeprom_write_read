# arduino_eeprom_write_read
This repository contains a tool to read and write EEPROMs with an Arduino. Tested with a 8Kb (1KB) EEPROM (24LC08). Wiring is regular i2c wiring, except that A0, A1 and A2 are connected to digital IO pins 4, 3 and 2, respectively. It would need some additional code to work on larger EEPROMs, but it's simple to figure out, just look up an EEPROM address table on the internet and test all the combinations. For larger EEPROMs you would need special code, but you're smart people, you can figure it out (and I also can't afford the larger ones).
