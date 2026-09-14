#ifndef MSG_CACHE_IDS_GAC_HPP
#define MSG_CACHE_IDS_GAC_HPP

#include <iostream>
#include <vector>
#include <vsomeip/vsomeip.hpp>

extern std::map< vsomeip::service_t, std::map< vsomeip::event_t, uint8_t > > MsgCacheIds;

#endif  //MSG_CACHE_IDS_GAC_HPP
