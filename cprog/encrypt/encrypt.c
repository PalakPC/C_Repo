/*C program to encrypt and decrypt messages using a passkey.*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
   char c, f, msg[50], pw[30], pw1[30];
   FILE *ofile;
   int ch, lm, lp, lp1, i = 0, j = 0, count = 0;
   time_t t;
   printf("Choose:\n1.Encrypt\n2.Decrypt\nEnter your choice (1-2): ");
   scanf("%d%c", &ch, &f);	/*f is used to remove the newline from return character.*/
   if(ch == 1) {
      printf("\nEnter a message to encrypt: ");
      fgets(msg, 50, stdin);
      printf("Enter passkey: ");
      fgets(pw, 30, stdin);				
      ofile = fopen("output.txt", "w");		
      lm = strlen(msg);
      msg[lm - 1] = '\0';	/*To skip return character.*/
      lm--;		
      c = lm;
      fputc(c, ofile);
      ++count;
      lp = strlen(pw);
      pw[lp - 1] = '\0';	/*To skip return character.*/
      lp--;		
      c = lp;
      fputc(c, ofile);
      ++count;
      printf("\nThe encrypted text is written to output.txt\n");
      while(i < lp) {
         c = pw[i] + lm;
         fputc(c, ofile);
         ++i;
         ++count;
      }		
      i = 0;
      while(i < lm) {
         c = msg[i] + pw[j];	/*Encrypting.*/
         fputc(c, ofile);
         ++i;
         ++j;
         ++count;
         if(j == lp)
            j = 0;
      }
      srand((unsigned)time(&t));
      while(count < 500) {
         c = rand() % 256;
         fputc(c, ofile);	/*Creating random encryption code.*/
         ++count;
      }
      close(ofile);
   }
   else if(ch == 2) {
      printf("\nEnter passkey: ");
      fgets(pw1, 30, stdin);
      lp1 = strlen(pw1);
      pw1[lp1 - 1] = '\0';	/*To skip return character.*/
      lp1--;
      ofile = fopen("output.txt", "r");
      lm = fgetc(ofile);
      lp = fgetc(ofile);
      for(i = 0; i < lp; ++i)
         pw[i] = fgetc(ofile);
      pw[i] = '\0';
      i=0;
      while(i < lp) {
         pw[i] = pw[i] - lm;
         ++i;
      }
      if(strcmp(pw, pw1) == 0) {
         for(i = 0; i < lm; ++i)
            msg[i] = fgetc(ofile);
         msg[i] = '\0';
         i = 0;
         while(i < lm) {
            msg[i] = msg[i] - pw[j];	/*Decrypting.*/
            ++i;
            ++j;
            if(j == lp)
               j=0;
         }
         printf("\nThe message is: %s\n", msg);
      }
      else
         printf("\nInvalid passkey\n");
      close(ofile);
   }
   else
      printf("\nInvalid choice\n");
   return 0;
}
