#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <errno.h>

void my_func(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char* packet);

char ** data;
int count=0;
int cdata[50];

char ** allocate2D(int rows, int columns);

int main(int argc, char **argv)
{
	int i;
	char *dev;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t* descr;
	const u_char *packet;
	struct pcap_pkthdr hdr;
	struct ether_header *eptr;
	u_char *ptr;

//	int fd = fileno(stdin);
//	struct timeval tv = {0,0};
//	fd_set fdset;
//	int s;

	dev = pcap_lookupdev(errbuf);
	data = allocate2D(50, 30);
	if(dev == NULL)
	{
		printf("%s\n", errbuf);
		exit(1);
	}
	descr = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);
	if(descr == NULL)
	{
		printf("pcap_open_live(): %s\n", errbuf);
		exit(1);
	}
	
	//sleep(5);

//	do
//	{
//		sleep(1);
//		FD_ZERO(&fdset);
//	        FD_SET(fd, &fdset);
//		packet = pcap_next(descr, &hdr);
		/*if(packet == NULL)
		{
			printf("Didn't grab packet\n");
			exit(1);
		}*/

		pcap_loop(descr, 5, my_func, NULL);
//		struct ip *ip;
//		int j;
//		struct tcphdr *tcp;
//		ip = (struct ip*)(packet+sizeof(struct ether_header));
//		tcp = (struct tcphdr*)(packet+sizeof(struct ether_header)+sizeof(struct ip));
//		char *src = inet_ntoa(ip->ip_src);
//		data[count] = src;
//		cdata[count] = 1;
//		if(count!=0)
//		{
//	        	for(j=0; j<count; ++j)
//			{
//				if(data[count]==data[j])
//				{
//					count--;
//					cdata[j]++;
//				}
//			}
//		}	
//		count++;
//	}while((s = select(fd+1, &fdset, NULL, NULL, &tv)) == 0);	
	
	printf("******************************************************************");
	printf("\nIP Address\tPacket Count\n");
	for (i=0; i<count; ++i)
	{
		printf("%s %d\n", data[i], cdata[i]);
	}
	printf("******************************************************************\n");
	return 0;
}

char ** allocate2D(int rows,int cols)
{
	char **arr2D;
	int *i;
	i=(int *)malloc(sizeof(int));
	arr2D = (char**)malloc((rows)*sizeof(char*));
	for((*i)=0;(*i)<(rows);(*i)++)
	{
		arr2D[*i] = (char*)malloc((cols)*sizeof(char));
	}
	return arr2D;
}

void my_func(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char* packet)
{
	struct ip *ip;    
	int j;
	struct tcphdr *tcp;                                       
	ip = (struct ip*)(packet+sizeof(struct ether_header));    
	tcp = (struct tcphdr*)(packet+sizeof(struct ether_header)+sizeof(struct ip));                                               	
	char *src = inet_ntoa(ip->ip_src);          
	data[count] = src;
	cdata[count] = 1;
	if(count!=0)
	{
		for(j=0; j<count; ++j)
		{
			if(data[count]==data[j])
			{
				count--;
				cdata[j]++;
			}
		}
	}
	count++;
	//printf("%s\n",src);                         
//	char* dst = inet_ntoa(ip->ip_dst);                       
//	printf(" %s:%d\n", dst, tcp->dest);                       
	//static int count = 1;
	//fprintf(stdout,"%d, ",count);
//	fflush(stdout);
//	count++;
}
