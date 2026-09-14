#ifndef STAT_H
#define STAT_H

#include <stdint.h>

struct stat
{
   uint32_t st_size; 
    
};

int stat( const char * path, 
          struct stat * buf );

#endif
