//C code of server that serves the client through socket.

#include <stdio.h>
#include <stdlib.h>	//Needed for OS X.
#include <string.h>	//Needed for memset.
#include <sys/socket.h>
#include <arpa/inet.h>	// for printing an internet address in a user-friendly way.
#include <netinet/in.h>
#include <sys/errno.h>   //Defines ERESTART, EINTR.
#include <sys/wait.h>    //Defines WNOHANG, for wait().

#define SERVICE_PORT 8888	//hard-coded port number.

#ifndef ERESTART
	#define ERESTART EINTR
#endif

extern int errno;
void serve (int port);	//Main server function.

int main (int argc, char **argv) {
	extern char *optarg;
	extern int optind;

	int c, err = 0; 
	int port = SERVICE_PORT;
	static char usage[] = "usage: %s [-d] [-p port]\n";

	while ((c = getopt (argc, argv, "dp:")) != -1) {
		switch (c) {
			case 'p': port = atoi (optarg);
				  if (port < 1024 || port > 65535) {
					  fprintf (stderr, "invalid port number: %s\n", optarg);
					  err = 1;
				  }
				  break;
			case '?': err = 1;
				  break;
		}
	}

	if (err || (optind < argc)) {
		fprintf (stderr, usage, argv[0]);
		exit (1);
	}
	serve (port);
}

//serve: set up the service.

void serve (int port) {
	int svc;	//For listening socket providing service.
	int rqst;	//Socket accepting the request.
	int sockoptval = 1;
	socklen_t alen;	//Length of address structure.
	struct sockaddr_in my_addr;	//Stores the address of service.
	struct sockaddr_in client_addr;	//Stores the client's address.
	char hostname[128];	//Host name for debugging.

	gethostname (hostname, 128);

	if ((svc = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		perror ("cannot create socket");
		exit (1);
	}

	setsockopt (svc, SOL_SOCKET, SO_REUSEADDR, &sockoptval, sizeof (int));

	memset ((char*) &my_addr, 0, sizeof (my_addr));	//To 0 out the structure.
	my_addr.sin_family = AF_INET;	//Address family
	my_addr.sin_port = htons (port);
	my_addr.sin_addr.s_addr = htonl (INADDR_ANY);

	//To bind to the address to which the service will be offered.
	if (bind (svc, (struct sockaddr *) &my_addr, sizeof (my_addr)) < 0) {
		perror ("bind failed");
		exit (1);
	}

	//To set up the socket for listening with a queue length of 5.
	if (listen (svc, 5) < 0) {
		perror ("listen failed");
		exit (1);
	}

	printf ("server started on %s, listening on port %d\n", hostname, port);

	//Loop forever - wait for connection requests and perform the service.
	alen = sizeof (client_addr);	//Length of address.
	for ( ; ; ) {
		while ((rqst = accept (svc,(struct sockaddr *) &client_addr, &alen)) < 0) {
			if ((errno != ECHILD) && (errno != ERESTART) && (errno != EINTR)) {
				perror ("accept failed");
				exit (1);
			}
		}
		printf ("received a connection from: %s port %d\n", inet_ntoa (client_addr.sin_addr), ntohs (client_addr.sin_port));
		shutdown (rqst, 2);	//To close the connection.
	}
}
