#include <stdio.h>

int main (int argc, char*argv[])
{
	int i = 0;
	
	if(argc == 2){
		printf("Masz tylko jeden argument. trudno.\n");
	}else if (argc > 2 && argc < 5){
		printf("Oto argumenty: \n");
		
		for(i = 0; i < argc; i++)
			printf("%s ", argv[i]);
		printf("\n");
	}else{
		printf("Podałeś za dużo argumentów. zawiodłeś\n");
	}
	return 0;
}
	