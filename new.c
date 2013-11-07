#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>

void encrypt();
void decrypt();

void main()
{
	clrscr();
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
	getch();
}

void encrypt()
{
	char *input;
	char *passkey;
	char c, n=0;
	int size=0, l=0, i=0, j=0;
	ifstream ifile;
	ifile.open("input.txt");
	ofstream ofile;
	ofile.open("output.txt");
	printf("Assuming message to be encrypted is already in input.txt");
	while(!ifile.eof())
	{
		*(input+size)=ifile.get();
		++size;
	}
	c=size;
	if(size<256)
	{
		ofile.put(c);
		ofile.put(n);
	}
	else
	{	
		while (c>=256)
		{
			c=c-256;
			++n;
		}
		ofile.put(c);
		ofile.put(n);
	}
	printf("Enter passkey: ");
	gets(passkey);
	l=strlen(passkey);
	while(i<size)
	{
		c=(*(input+i))+(*(passkey+j));
		ofile.put(c);
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
		c=random(256);
		ofile.put(c);
	}
	ifile.close();
	ofile.close();
	printf("Encryption done. Encrypted code in output.txt");
}

void decrypt()
{
	ifstream ifile;
	ifile.open("input.txt");
	ofstream ofile;
	ofile.open("output.txt");	
	int size, n, l, i=0, j=0;
	char c;
	char *input, *passkey;	
	printf("Assuming the message to be decrypted is already in input.txt");
	size=ifile.get();
	n=ifile.get();
	if(n!=0)
	{
		size=size+(n*256);
	}
	while(i<size)
	{
		*(input+i)=ifile.get();
		++i;
	}
	printf("Enter passkey: ");
	gets(passkey);
	l=strlen(passkey);
	i=0;
	while(i<size)
	{
		c=(*(input+i))-(*(passkey+j));
		++i;
		++j;
		if(j==l)
		{
			j=0;
		}
	}
	printf("Decryption done. Output in output.txt");
	ifile.close();
	ofile.close();
}


		
		
	



