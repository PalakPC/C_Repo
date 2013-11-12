#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char c, msg[50], pw[30];
	FILE *ifile, *ofile;
	int lm, lp, i=0, j=0;
	printf("Choose:\n1.Encrypt\n2.Decrypt\nEnter your choice (1-2): ");
	scanf("%d", &n);			
	if(n==1)
	{
		printf("Enter a message to encrypt: ");
		gets(msg);
		printf("The string is: ");		
		puts(msg);						
		printf("Enter passkey: ");
		gets(pw);		
		printf("The passkey is: ");
		puts(pw);
		printf("The encrypted text is written to output.txt");
		ifile=fopen("input.txt", "w");
		fprintf(ifile, "%s, %s", msg, pw);
		ofile=fopen("output.txt", "w");
		lm=strlen(msg);
		c=lm;
		fputc(c, ofile);
		lp=strlen(pw);
		while(i<lm)
		{
			c=msg[i]+pw[j];
			fputc(c, ofile);
			++i;
			++j;
			if(j==lp)
				j=0;
		}
		close(ifile);
		close(ofile);
	}
	else if(n==2)
	{
		printf("Enter passkey: ");
		gets(pw);
		printf("The passkey is: ");
		puts(pw);
		lp=strlen(pw);
		ifile=fopen("input.txt", "w");
		ofile=fopen("output.txt", "r");
		lm=fgetc(ofile);
		printf("The message is: ");
		fgets(msg, lm, ofile);
		while(i<lm)
		{
			c=msg[i]-pw[j];
			printf("%c", c);
			fputc(c, ifile);
			++i;
			++j;
			if(j==lp)
				j=0;
		}
		fprintf(ifile, "%s", pw);
		close(ifile);
		close(ofile);
	}
	else
		printf("Invalid choice");
	return 0;
}
