#include <stdio.h>

void reverse(char *str, int len) {
	char reversed[len+1];
	int pos = 0;
	int caret = len;
	reversed[len] = '\0';
	int i = len - 1; 
	while(i >= -1){
		if (i == -1 || str[i] == ' '){
			int j = i + 1; 
			while(j < caret){
				reversed[pos++] = str[j];
				j++;
			}
			if (i != -1) {
				reversed[pos++] = ' ';
			}
			caret = i;
		}
		i--;
	}
	printf("%s\n", reversed);
}
