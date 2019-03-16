#include <stdio.h>

int main(int argc, char*argv[]){
	int m = 0;
	int n = 0;
	int r = 0;
	
	printf("Podaj m.\n");
	scanf("%d", &m);
	
	printf("Podaj n.\n");
	scanf("%d", &n);
	
	while (1){
		r = m%n;
		if (r == 0){
			printf("NWD to %d.\n", n);
			break;
		}
		else {
			m = n;
			n = r;
		}
	}
	
	
}