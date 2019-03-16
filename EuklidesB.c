#include <stdio.h>

int main(int argc, char*argv[])
{
	int u, v, t ,k = 0;
	
	printf("Podaj pierwszą liczbę (u).\n");
	scanf("%d", &u);
	
	printf("Podaj drugą liczbę (v).\n");
	scanf("%d", &v);
	
	while ((~u & 1) & (~v & 1)){
		k = k+1;
		u = u >> 1;
		v = v >> 1;
	}
	if (u & 1){
		t = -v;
	}
	else {
		t = u;
		t = t >> 1;
		
	}
	while (t) {
		while (~t & 1){
			t = t >> 1;
		}
		if (~t & (-32768)){
			u = t;
		}
		else {
			v = -t;
		}
		t = u - v;
	}
	v = u << k;
	printf("rozwiązanie to %d\n", v);
	
	return 0;

}