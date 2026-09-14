// Copyright (C) 2014-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_VSOMEIP_HPP
#define VSOMEIP_VSOMEIP_HPP

/**
 * \brief The central vsomeip header. Include this to use vsomeip.
 */

//#include <vsomeip/constants.hpp>
//#include <vsomeip/defines.hpp>
//#include <vsomeip/application.hpp>
//#include <vsomeip/message.hpp>
//#include <vsomeip/payload.hpp>
//#include <vsomeip/runtime.hpp>

#include <chrono>
#include <memory>
#include <set>
#include <map>
#include <vector>

namespace vsomeip {

typedef uint32_t message_t;
typedef uint16_t service_t;
typedef uint16_t method_t;
typedef uint16_t event_t;

typedef uint16_t instance_t;
typedef uint16_t eventgroup_t;

typedef uint8_t major_version_t;
typedef uint32_t minor_version_t;

typedef uint32_t length_t;
typedef uint8_t byte_t;

const major_version_t DEFAULT_MAJOR = 0x00;
const minor_version_t DEFAULT_MINOR = 0x00000000;


class payload {
public:
    ~payload() {}

    void set_data(const byte_t *_data,
            length_t _length);

};

class message {
public:
    virtual ~message() {}

    /**
     * \brief Returns a pointer to the message payload.
     */
    virtual std::shared_ptr<payload> get_payload() const = 0;

    /**
     * \brief Set the message payload.
     */
    virtual void set_payload(std::shared_ptr<payload> _payload) = 0;
};

typedef std::function< void (const std::shared_ptr< message > &) > message_handler_t;

class application {
public:
    ~application() {}

    application() {}

    bool init();

    void offer_event(service_t _service,
            instance_t _instance, event_t _event,
            const std::set<eventgroup_t> &_eventgroups);

    void offer_service(service_t _service, instance_t _instance,
            major_version_t _major = DEFAULT_MAJOR, minor_version_t _minor =
                    DEFAULT_MINOR);
    void start();

    void unregister_message_handler(service_t _service,
            instance_t _instance, method_t _method);

    void stop_offer_event(service_t _service,
            instance_t _instance, event_t _event);

    void release_event(service_t _service, instance_t _instance,
            event_t _event);

    void stop_offer_service(service_t _service, instance_t _instance,
            major_version_t _major = DEFAULT_MAJOR, minor_version_t _minor =
                    DEFAULT_MINOR);

    void register_message_handler(service_t _service,
            instance_t _instance, method_t _method,
            message_handler_t _handler);

    void release_service(service_t _service, instance_t _instance);

    void notify(service_t _service, instance_t _instance,
                event_t _event, std::shared_ptr<payload> _payload);

};

class runtime {
public:
    ~runtime() {
    }
    static std::shared_ptr<runtime> get();

   std::shared_ptr<application> create_application(
            const std::string &_name = "");

   std::shared_ptr<payload> create_payload();

};

}
#endif // VSOMEIP_VSOMEIP_HPP
