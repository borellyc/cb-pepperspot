// Copyright (c) 2008, Thibault VANCON and Sebastien VINCENT
// Copyright (c) 2006, Jens Jakobsen
// Copyright (C) 2003, 2004, 2005 Mondru AB.

//!
//!  \file iphash.h
//!  \brief Hash function for IPv4 and IPv6 addresses.
//!

#ifndef _IPHASH_H
#define _IPHASH_H

#include "ippool.h"

/* IP hash functions are used to generate a hash table of IP addresses.
   The functions build on ippool.c.
   ippool_get_ip() is used to check if an address is in the hash table. */

//!
//!  \brief Create new IPv4 address pool.
//!  \param this pointer that will receive newly allocated pool.
//!  \param list linked-list of member
//!  \param listsize size of the list
//!  \return 0 if success, -1 otherwise
//!
int iphash_new(struct ippool_t **this, struct ippoolm_t *list, int listsize);

//!
//!  \brief Create new IPv6 address pool.
//!  \param this pointer that will receive newly allocated pool.
//!  \param list linked-list of member
//!  \param listsize size of the list
//!  \return 0 if success, -1 otherwise
//!
int iphash_new6(struct ippool_t **this, struct ippoolm_t *list, int listsize);

//!
//!  \brief Delete existing address pool.
//!  \param this pointer to the ippol_t list.
//!  \return 0
//!
int iphash_free(struct ippool_t *this);

#endif // !_IPHASH_H

/*
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 *   Neither the names of copyright holders nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The contents of this file may be used under the terms of the GNU
 * General Public License Version 2, provided that the above copyright
 * notice and this permission notice is included in all copies or
 * substantial portions of the software.
 */

