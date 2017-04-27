// $Id: icmp6.h 1.17 2006-05-07 21:52:43+03:00 anttit@tcs.hut.fi $
// Copyright (c) 2008, Thibault VANCON and Sebastien VINCENT

//!
//!  \file icmp6.h
//!  \brief ICMPv6 related function (send/receive).
//!

#ifndef _ICMP6_H
#define _ICMP6_H

// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
#include <netinet/ip6.h> // in6_addr

#if defined(__APPLE__)
#include <netinet/in_pcb.h>
#include <sys/socketvar.h>
#endif

//!
//!  \brief ICMPv6 socket.
//!
struct icmpv6_socket {
  int fd; //!< Socket descriptor
};

//!
//!  Join/leave multicast group on interface.
//!
//!  cmd must be either IPV6_JOIN_GROUP or IPV6_LEAVE_GROUP.
//!  Also turns off local multicast loopback.
//!
//!  \param sock socket
//!  \param ifindex interface to join/leave
//!  \param mc_addr multicast address
//!  \param cmd join/leave command
//!  \return 0 if success, -1 otherwise
//!
int if_mc_group(int sock, int ifindex, const struct in6_addr *mc_addr,
                int cmd);

//!
//!  \brief Initialize ICMPv6 socket.
//!  \return 0 if success, -1 otherwise
//!
int icmp6_init(void);

//!
//!  \brief Create an ICMPv6 header.
//!  \param iov vector to put header in
//!  \param type ICMPv6 type
//!  \param code ICMPv6 code
//!  \return header or NULL if failure
//!
void *icmp6_create(struct iovec *iov, uint8_t type, uint8_t code);

//!
//!  \brief Send an ICMPv6 packet.
//!  \param oif output interface
//!  \param hoplimit ttl of the packet
//!  \param src IPv6 source address
//!  \param dst IPv6 destination address
//!  \param datav headers and data
//!  \param iovlen number of element if datav
//!  \return number of bytes sent or -1 if failure
//!
int icmp6_send(int oif, uint8_t hoplimit, const struct in6_addr *src,
               const struct in6_addr *dst, struct iovec *datav, size_t iovlen);

//!
//!  \brief Cleanup ICMPv6 socket.
//!
void icmp6_cleanup(void);

#endif // !_ICMP6_H
