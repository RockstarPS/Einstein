#ifndef MSG_MAPS_HPP
#define MSG_MAPS_HPP

#include "msg_ids.hpp"
#include <dk_runtime2_cmsgvmf.hpp>

extern dk::runtime2::core::msg_map_t VmfMsgMap;

void logMessage(const uint32_t service, uint32_t method, const uint8_t *pData, uint32_t length);

#endif  //MSG_MAPS_HPP
