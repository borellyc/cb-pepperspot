// $Id: ndisc.h 1.13 2004-09-20 12:47:39+03:00 vnuorval@tcs.hut.fi $
// Copyright (c) 2008, Thibault VANCON and Sebastien VINCENT

//!
//!  \file ndisc.h
//!  \brief IPv6 neighbor discovery.
//!

#ifndef _NDISC_H
#define _NDISC_H

#include <net/if_arp.h> // ARPHRD_ETHER, ARPHRD_IEEE802, ...
#include <netinet/in.h> // in_addr
#include <stdint.h>     // ISO C99 types: uint8_t, uint16_t, ...

#ifndef ARPHRD_IEEE80211
#define ARPHRD_IEEE80211 801 //!< 802.11 type
#endif

//!
//!  \brief Send Neighbor Advertisement.
//!  \param ifindex output interface index
//!  \param src source address
//!  \param dst destination address
//!  \param target target IPv6 address
//!  \param flags NA flags
//!  \return 0 if success, -1 otherwise
//!
int ndisc_send_na(int ifindex, const struct in6_addr *src,
                  const struct in6_addr *dst, const struct in6_addr *target,
                  uint32_t flags);

#endif // !_NDISC_H
