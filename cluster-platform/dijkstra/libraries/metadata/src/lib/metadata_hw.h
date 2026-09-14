#ifndef METADATA_HW_H
#define METADATA_HW_H

#include <stdint.h>
#include "metadata.h"

int32_t Metadata_LoadWithOffset(SMetadata_t *pMetadata, uint32_t offset);
int32_t Metadata_SaveWithOffset(SMetadata_t *pMetadata, uint32_t offset);
int32_t Metadata_Lock(void);
int32_t Metadata_Unlock(void);

#endif /* METADATA_HW_H */
