#ifndef _FT_PING_H_
#define _FT_PING_H_

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <netinet/icmp6.h>
#include <signal.h>
#include <stdlib.h>
#include <netinet/ip6.h>

typedef struct s_hdr
{
	union
	{
		struct iphdr v4;
		struct ip6_hdr v6;
	} ip;
	struct icmphdr icmp;

} t_hdr;

typedef struct s_ping
{
	char *hostname;
	char ip[INET6_ADDRSTRLEN];

	struct addrinfo *res;
	int socket;
	struct icmphdr icmp;

	int done;
	int received;

	int sent;
	int reply;

	int verbose;
} t_ping;

extern t_ping g_ping;

#endif