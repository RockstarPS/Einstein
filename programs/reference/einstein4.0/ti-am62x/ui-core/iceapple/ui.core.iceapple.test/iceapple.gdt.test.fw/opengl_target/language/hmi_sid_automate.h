#include "hmi_language_identifiers.h"

#define NUM_LANGUAGES           3
#define NUM_SIDS                2

int language_array[NUM_LANGUAGES] = {
   HMI_LANGUAGE_UK_ENGLISH,
   HMI_LANGUAGE_FRENCH,
   HMI_LANGUAGE_US_ENGLISH
};

char language_names[NUM_LANGUAGES][100] = {
   "UK_ENGLISH",
   "FRENCH",
   "US_ENGLISH"
};

int sid_array[NUM_SIDS] = {
   SID_HELLO,
   SID_WORLD
};

char sid_names[NUM_SIDS][100] = {
   "SID_HELLO",
   "SID_WORLD"
};

