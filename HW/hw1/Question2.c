#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

int main(){
	char *inputstring = malloc(MAX_STRING_SIZE);
	int index = 0;
	
	if(inputstring ==  NULL){
		printf("No memory!\n");
		return 1;
	}
	
	printf("Please input a string: ");

	fgets(inputstring, MAX_STRING_SIZE, stdin);

	while(index < strlen(inputstring)){
		if(inputstring[index]<='9'&&inputstring[index]>='0')
			putchar(inputstring[index]);
		index++;
	}
	printf("\n");
	
	free(inputstring);
	return 0;
}
