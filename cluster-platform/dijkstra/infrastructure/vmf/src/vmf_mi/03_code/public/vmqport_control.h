#ifndef VMQPORT_CONTROL_H
#define VMQPORT_CONTROL_H

#define VMF_SEND_PORTNAME    "VMF_send_port"
#define VMF_RECEIVE_PORTNAME "VMF_receive_port"
#define VMF_QPORT_MAX_MSGSIZE (4096)

int open_vmqportdev_by_portname(const char *portname, int flags);

#endif
