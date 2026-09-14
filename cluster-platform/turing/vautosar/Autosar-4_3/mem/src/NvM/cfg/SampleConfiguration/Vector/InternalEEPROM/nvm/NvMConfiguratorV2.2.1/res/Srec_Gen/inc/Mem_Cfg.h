#ifndef MEM_CFG_H
#define MEM_CFG_H

typedef struct {
   uint32 eraseValue;
   uint32 baseAddress;
   uint32 length;
} memCfgFeeType;

typedef struct {
   uint32 baseAddress;
   uint32 length;
} memCfgSecType;

#endif /* MEM_CFG_H */
