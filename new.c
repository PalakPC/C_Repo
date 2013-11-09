#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt();
void decrypt();

int main()
{
	int c;
choice: printf("Choose:\n1. Encrypt\n2.Decrypt\nEnter your choice: ");
	scanf("%d", &c);
	switch(c)
	{
		case 1: encrypt();
			break;
		case 2: decrypt();
			break;
		default:printf("Invalid choice. Reenter.");
			goto choice;
	};
	return 0;
}

void encrypt()
{
	char input[100];
	char passkey[100];
	char c, n=0;
	int size=0, l=0, i=0, j=0, p;
	FILE *ifile, *ofile;
	ifile=fopen("input.txt", "r");
	ofile=fopen("output.txt", "w");
	printf("Assuming message to be encrypted is already in input.txt");
	while(fgetc(ifile)!=EOF)
	{
		input[size]=fgetc(ifile);
		++size;
	}
	p=size;
	if(size<256)
	{
		c=p;
		fputc(c, ofile);
		fputc(n, ofile);
	}
	else
	{	
		while (p>=256)
		{
			p=-256;
			++n;
		}
		c=p;
		fputc(c, ofile);
		fputc(n, ofile);
	}
	printf("Enter passkey: ");
	gets(passkey);
	l=strlen(passkey);
	while(i<size)
	{
		c=input[i]+passkey[j];
		fputc(c, ofile);
		++i;
		++j;
		if(j==l)
		{
			j=0;
		}
	}
	i=i+2;
	while(i<2048)
	{
		c=random();
		fputc(c, ofile);
	}
	close(ifile);
	close(ofile);
	printf("Encryption done. Encrypted code in output.txt");
}

void decrypt()
{
	FILE *ifile, *ofile;
	ifile=fopen("input.txt", "r");
	ofile=fopen("output.txt", "w");	
	int size, n, l, i=0, j=0;
	char c;
	char input[100], passkey[100];	
	printf("Assuming the message to be decrypted is already in input.txt");
	size=fgetc(ifile);
	n=fgetc(ifile);
	if(n!=0)
	{
		size=size+(n*256);
	}
	while(i<size)
	{
		input[i]=fgetc(ifile);
		++i;
	}
	printf("Enter passkey: ");
	gets(passkey);
	l=strlen(passkey);
	i=0;
	while(i<size)
	{
		c=input[i]-passkey[j];
		fputc(c, ofile);
		++i;
		++j;
		if(j==l)
		{
			j=0;
		}
	}
	printf("Decryption done. Output in output.txt");
	close(ifile);
	close(ofile);
}


		
		
	



