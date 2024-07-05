
#include <arpa/inet.h>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <dirent.h>
#include <errno.h>
#include <filesystem>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#include <tester.hpp>

void printinfo(struct addrinfo *p)
{
	char ipstr[INET6_ADDRSTRLEN];
	std::string ipver;
	void *addr;

	if (p->ai_family == AF_INET)
	{ // IPv4
		struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
		addr = &(ipv4->sin_addr);
		ipver = "IPv4";
	}
	else
	{ // IPv6
		struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
		addr = &(ipv6->sin6_addr);
		ipver = "IPv6";
	}

	// Convert the IP to a string and print it:
	inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
	std::cout << "\t" << ipver << ":\t\t" << ipstr << "\n";

	// Print the port number and protocol:
	struct sockaddr_in *sa = (struct sockaddr_in *)p->ai_addr;
	std::cout << "\tPort:\t\t" << ntohs(sa->sin_port) << "\n";

	// Print the canonical name:
	if (p->ai_canonname != NULL)
		std::cout << "\tCanon Name:\t" << p->ai_canonname << "\n";
	else
		std::cout << "\tCanon Name:\t(none)\n";
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	(void)argc;

	struct addrinfo hints, *p;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET; // AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo *res = NULL;
	int ret;

	if ((ret = getaddrinfo(argv[1], argv[2], &hints, &res)) != 0)
	{
		std::cerr << "getaddrinfo:\t" << gai_strerror(ret) << std::endl;
		return (2);
	}
	for (p = res; p != NULL; p = p->ai_next)
	{
		printinfo(p);
	}

	freeaddrinfo(res);
}
