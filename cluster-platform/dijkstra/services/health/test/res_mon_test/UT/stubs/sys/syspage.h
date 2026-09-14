#ifndef SYSPAGE_H
#define SYSPAGE_H

#include <stdint.h>

struct qtime_entry {
	uint64_t cycles_per_sec;	
};

struct syspage_entry {
    int32_t num_cpu;
};

struct asinfo_entry {
    int name;
    uint64_t start;
    uint64_t end;
};

struct strings_entry {
    char data[64];
};

struct syspage_entry *_syspage_ptr; 

struct qtime_entry *stub_qtime;

struct asinfo_entry *stub_asinfo;

struct strings_entry *stub_strings;

#define SYSPAGE_ENTRY(entry) stub_##entry
#define SYSPAGE_ENTRY_SIZE( entry ) sizeof( *stub_##entry )

#endif
