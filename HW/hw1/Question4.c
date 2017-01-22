#include <stdio.h>

int main(){
	int count = 0;
	char inputchar_1, inputchar_2;

	printf("Please input a series of words: ");

	inputchar_1 = getchar();

	if(inputchar_1 != EOF)
		inputchar_2 = getchar();
	else{
		printf("\nNumber of words is 0.\n");
		return 0;
	}

	if(inputchar_1 !=' '&&inputchar_1!='\t'&&inputchar_1!='\n')
			count ++;

	while(inputchar_2 != EOF){
		if(inputchar_1 ==' '||inputchar_1=='\t'||inputchar_1=='\n')
			if(inputchar_2 !=' '&&inputchar_2!='\t'&&inputchar_2!='\n')
				count++;
		inputchar_1 = inputchar_2;
		inputchar_2 = getchar();
	}

	printf("\nNumber of words is %d.\n", count);

	return 0;
}


