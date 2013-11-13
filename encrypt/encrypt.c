#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char c, msg[50], pw[30];
	FILE *ofile;
	int lm, lp, i=0, j=0;
	printf("Choose:\n1.Encrypt\n2.Decrypt\nEnter your choice (1-2): ");
	scanf("%d", &n);
	fflush(stdin);		
	if(n==1)
	{
		printf("Enter a message to encrypt: ");
		scanf("%s", &msg);
		printf("The string is: %s\n", msg);						
		printf("Enter passkey: ");
		scanf("%s", &pw);		
		printf("The passkey is: %s\n", pw);
		printf("The encrypted text is written to output.txt\n");
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
		close(ofile);
	}
	else if(n==2)
	{
		printf("Enter passkey: ");
		scanf("%s", &pw);
		printf("The passkey is: %s\n", pw);
		lp=strlen(pw);
		ofile=fopen("output.txt", "r");
		lm=fgetc(ofile);
		printf("The message is: ");
		fgets(msg, lm, ofile);
		while(i<lm)
		{
			c=msg[i]-pw[j];
			printf("%c", c);
			++i;
			++j;
			if(j==lp)
				j=0;
		}
		printf("\n");
		close(ofile);
	}
	else
		printf("Invalid choice\n");
	return 0;
}
