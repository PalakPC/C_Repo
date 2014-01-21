#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <netdb.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include "port.h"       

int conn(char *host, int port);	/* connect to host,port; return socket */
void disconn(fd);	/* close a socket connection */
int debug = 1;

main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	char *prompt = 0;
	int port = SERVICE_PORT;	/* default: whatever is in port.h */
	char *host = "localhost";	/* default: this host */
	int fd;				/* file descriptor for socket */
	static char usage[] = "usage: %s [-d] [-h serverhost] [-p port]\n";
	while ((c = getopt(argc, argv, "dh:p:")) != -1)
		switch (c) {
			case 'h':  host = optarg;
				   break;
			case 'p':  port = atoi(optarg);
				   if (port < 1024 || port > 65535) {
					   fprintf(stderr, "invalid port number: %s\n", optarg);
					   err = 1;
				   }
				   break;
			case '?':  err = 1;
				   break;
		}
	if (err || (optind < argc)) {	/* error or extra arguments? */
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	printf("connecting to %s, port %d\n", host, port);
	if ((fd = conn(host, port)) < 0)    /* connect */
		exit(1);   /* something went wrong */
	disconn(fd);    /* disconnect */
	return 0;
}

int conn(char *host, int port)
{
	struct hostent *hp;	/* host information */
	unsigned int alen;	/* address length when we get the port number */
	struct sockaddr_in myaddr;	/* our address */
	struct sockaddr_in servaddr;	/* server address */
	int fd;  /* fd is the file descriptor for the connected socket */

	if (debug) printf("conn(host=\"%s\", port=\"%d\")\n", host, port);

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("cannot create socket");
		return -1;
	}

	memset((char *)&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(0);

	if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
		perror("bind failed");
		close(fd);
		return -1;
	}
	
	alen = sizeof(myaddr);
	if (getsockname(fd, (struct sockaddr *)&myaddr, &alen) < 0) {
		perror("getsockname failed");
		close(fd);
		return -1;
	}
	
	if (debug) printf("local port number = %d\n", ntohs(myaddr.sin_port));

	memset((char*)&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);

	hp = gethostbyname(host);
	if (!hp) {
		fprintf(stderr, "could not obtain address of %s\n", host);
		close(fd);
		return -1;
	}

	/* put the host's address into the server address structure */
	memcpy((void *)&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

	/* connect to server */
	if (connect(fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect failed");
		close(fd);
		return -1;
	}

	if (debug) printf("connected socket = %d\n", fd);
	return fd;
}

/* disconnect from the service */
/* lame: we can just as easily do a shutdown() or close() ourselves */

void disconn(int fd)
{
	if (debug) printf("disconn(%d)\n", fd);
		shutdown(fd, 2);    /* 2 means future sends & receives are disallowed */
}
