/*	$NetBSD: print-tcp.c,v 1.9 2007/07/26 18:15:12 plunky Exp $	*/

/*
 * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997
 *	The Regents of the University of California.  All rights reserved.
 *
 * Copyright (c) 1999-2004 The tcpdump.org project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sbuf.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

const struct tok ipproto_values[] = {
    { IPPROTO_HOPOPTS, "Options" },
    { IPPROTO_ICMP, "ICMP" },
    { IPPROTO_IGMP, "IGMP" },
    { IPPROTO_IPV4, "IPIP" },
    { IPPROTO_TCP, "TCP" },
    { IPPROTO_EGP, "EGP" },
    { IPPROTO_PIGP, "IGRP" },
    { IPPROTO_UDP, "UDP" },
    { IPPROTO_DCCP, "DCCP" },
    { IPPROTO_IPV6, "IPv6" },
    { IPPROTO_ROUTING, "Routing" },
    { IPPROTO_FRAGMENT, "Fragment" },
    { IPPROTO_RSVP, "RSVP" },
    { IPPROTO_GRE, "GRE" },
    { IPPROTO_ESP, "ESP" },
    { IPPROTO_AH, "AH" },
    { IPPROTO_MOBILE, "Mobile IP" },
    { IPPROTO_ICMPV6, "ICMPv6" },
    { IPPROTO_MOBILITY_OLD, "Mobile IP (old)" },
    { IPPROTO_EIGRP, "EIGRP" },
    { IPPROTO_OSPF, "OSPF" },
    { IPPROTO_PIM, "PIM" },
    { IPPROTO_IPCOMP, "Compressed IP" },
    { IPPROTO_VRRP, "VRRP" },
    { IPPROTO_PGM, "PGM" },
    { IPPROTO_SCTP, "SCTP" },
    { IPPROTO_MOBILITY, "Mobility" },
    { IPPROTO_CARP, "CARP" },
    { IPPROTO_PFSYNC, "pfsync" },
    { 0, NULL }
};

/* These tcp optinos do not have the size octet */
#define ZEROLENOPT(o) ((o) == TCPOPT_EOL || (o) == TCPOPT_NOP)
#define TCP_SIGLEN 16

#define TCPOPT_EOL		0
#define TCPOPT_NOP		1
#define TCPOPT_MAXSEG		2
#define TCPOPT_WSCALE		3	/* window scale factor (rfc1323) */
#define TCPOPT_SACKOK		4	/* selective ack ok (rfc2018) */
#define TCPOPT_SACK		5	/* selective ack (rfc2018) */
#define TCPOPT_ECHO		6	/* echo (rfc1072) */
#define TCPOPT_ECHOREPLY	7	/* echo (rfc1072) */
#define TCPOPT_TIMESTAMP	8	/* timestamp (rfc1323) */
#define TCPOPT_CC		11	/* T/TCP CC options (rfc1644) */
#define TCPOPT_CCNEW		12	/* T/TCP CC options (rfc1644) */
#define TCPOPT_CCECHO		13	/* T/TCP CC options (rfc1644) */
#define TCPOPT_SIGNATURE	19	/* Keyed MD5 (rfc2385) */
#define TCPOPT_SCPS		20	/* SCPS-TP (CCSDS 714.0-B-2) */
#define TCPOPT_UTO		28	/* tcp user timeout (rfc5482) */
#define TCPOPT_TCPAO		29	/* TCP authentication option (rfc5925) */
#define TCPOPT_MPTCP		30	/* MPTCP options */
#define TCPOPT_FASTOPEN		34	/* TCP Fast Open (rfc7413) */
#define TCPOPT_EXPERIMENT2	254	/* experimental headers (rfc4727) */

struct tok tcp_option_values[] = {
        { TCPOPT_EOL, "eol" },
        { TCPOPT_NOP, "nop" },
        { TCPOPT_MAXSEG, "mss" },
        { TCPOPT_WSCALE, "wscale" },
        { TCPOPT_SACKOK, "sackOK" },
        { TCPOPT_SACK, "sack" },
        { TCPOPT_ECHO, "echo" },
        { TCPOPT_ECHOREPLY, "echoreply" },
        { TCPOPT_TIMESTAMP, "TS" },
        { TCPOPT_CC, "cc" },
        { TCPOPT_CCNEW, "ccnew" },
        { TCPOPT_CCECHO, "ccecho" }, /* filled out for convenience */
        { TCPOPT_SIGNATURE, "md5" },
        { TCPOPT_SCPS, "scps" },
        { TCPOPT_UTO, "uto" },
        { TCPOPT_TCPAO, "tcp-ao" },
        { TCPOPT_MPTCP, "mptcp" },
        { TCPOPT_FASTOPEN, "tfo" },
        { TCPOPT_EXPERIMENT2, "exp" },
        { 0, NULL }
};

void
tcp_print(struct sbuf *sbuf, const u_char *bp, u_int length)
{
        const struct tcphdr *tp;
        u_char flags;
        u_int hlen;
        char ch;
        u_int16_t sport, dport, win, urp;
        u_int32_t seq, ack;
        char ubuf[64];

        tp = (const struct tcphdr *)bp;

        hlen = (tp->th_off & 0x0f) * 4;
        if (hlen < sizeof(*tp)) {
                sbuf_printf(sbuf, "errormsg='tcp %d [bad hdr length %u - too short < %lu]',",
                             length - hlen, hlen, (unsigned long)sizeof(*tp));
                return;
        }

        ch = '\0';
        sport = EXTRACT_16BITS(&tp->th_sport);
        dport = EXTRACT_16BITS(&tp->th_dport);

	sbuf_printf(sbuf, "%u,%u,%d,", sport, dport, length - hlen);

        seq = EXTRACT_32BITS(&tp->th_seq);
        ack = EXTRACT_32BITS(&tp->th_ack);
        win = EXTRACT_16BITS(&tp->th_win);
        urp = EXTRACT_16BITS(&tp->th_urp);

        flags = tp->th_flags;
        sbuf_printf(sbuf, "%s%s%s", flags & TH_FIN ? "F" : "", flags & TH_SYN ? "S" : "", flags & TH_RST ? "R" : "");
        sbuf_printf(sbuf, "%s%s%s", flags & TH_PUSH ? "P" : "", flags & TH_ACK ? "A" : "", flags & TH_URG ? "U" : "");
        sbuf_printf(sbuf, "%s%s,", flags & TH_ECE ? "E" : "", flags & TH_CWR ? "C" : "");

        if (hlen > length) {
                sbuf_printf(sbuf, "errormsg='[bad hdr length %u - too long, > %u]',",
                             hlen, length);
                return;
        }

        length -= hlen;
        if (length > 0 || flags & (TH_SYN | TH_FIN | TH_RST)) {
                if (length > 0)
                        sbuf_printf(sbuf, "%u:%u,", seq, seq + length);
		else
			sbuf_printf(sbuf, "%u,", seq);
        } else
		sbuf_printf(sbuf, ",");

        if (flags & TH_ACK)
                sbuf_printf(sbuf, "%u,", ack);
	else
		sbuf_printf(sbuf, ",");

        sbuf_printf(sbuf, "%d,", win);

        if (flags & TH_URG)
                sbuf_printf(sbuf, "%d,", urp);
	else
		sbuf_printf(sbuf, ",");

        /*
         * Handle any options.
         */
        if (hlen > sizeof(*tp)) {
                const u_char *cp;
                u_int opt, datalen;
                u_int len;

                hlen -= sizeof(*tp);
                cp = (const u_char *)tp + sizeof(*tp);
                while (hlen > 0) {
                        if (ch != '\0')
                                sbuf_printf(sbuf, "%c", ch);
                        opt = *cp++;
                        if (ZEROLENOPT(opt))
                                len = 1;
                        else {
                                len = *cp++;	/* total including type, len */
                                if (len < 2 || len > hlen)
                                        goto bad;
                                --hlen;		/* account for length byte */
                        }
                        --hlen;			/* account for type byte */
                        datalen = 0;

                        sprintf(ubuf, "unknown(%u)", opt);
                        sbuf_printf(sbuf, "%s", code2str(tcp_option_values, ubuf, opt));

			switch (opt) {
                        case TCPOPT_MAXSEG:
                                datalen = 2;
                                break;
                        case TCPOPT_WSCALE:
                                datalen = 1;
                                break;
                        case TCPOPT_SACK:
                                datalen = len - 2;
                                break;
                        case TCPOPT_CC:
                        case TCPOPT_CCNEW:
                        case TCPOPT_CCECHO:
                        case TCPOPT_ECHO:
                        case TCPOPT_ECHOREPLY:
                                datalen = 4;
                                break;
                        case TCPOPT_TIMESTAMP:
                                datalen = 8;
                                break;
                        case TCPOPT_SIGNATURE:
                                datalen = TCP_SIGLEN;
                                break;
                        case TCPOPT_SCPS:
                                datalen = len - 3;
                                break;
                        case TCPOPT_EOL:
                        case TCPOPT_NOP:
                        case TCPOPT_SACKOK:
                                /*
                                 * Nothing interesting.
                                 * fall through
                                 */
                                break;
                        case TCPOPT_UTO:
                                datalen = 2;
                                break;
                        default:
                                datalen = len - 2;
                                break;
                        }

                        /* Account for data printed */
                        cp += datalen;
                        hlen -= datalen;

                        /* Check specification against observed length */
                        ++datalen;			/* option octet */
                        if (!ZEROLENOPT(opt))
                                ++datalen;		/* size octet */
                        ch = ';';
                        if (opt == TCPOPT_EOL)
                                break;
                }
        }

        if (length <= 0)
                return;

        return;
 bad:
        sbuf_printf(sbuf, "[bad opt],");
        if (ch != '\0')
                sbuf_printf(sbuf, ">,");
        return;
}
