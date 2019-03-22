#include <stdio.h>
int wypelnienie();
int wyszukaj();

int main(int argc, char* argv[])
{
	int len = 0;
	int liczba = 0;

	printf("Podaj dlugosc tablicy.\n");
	scanf("%d", &len);

	printf("Podaj szukana liczbe.\n");
	scanf("%d", &liczba);


	int C = wyszukaj(len, liczba);

	if (C == -1){
		printf("Blad - liczba nie znajduje sie w tablicy.\n");
		return 1;
	}

	printf("Liczba %d jest na miejscu %d.\n", wypelnienie(len,C), C);
	return 0;
}
int wypelnienie(int dlugosc,int i){
	return dlugosc - i; //wypełnienie tablicy
}
int wyszukaj(int dlugosc, int X)
{
	int C,A = 0,i = 0;
	int B = dlugosc;
	int D[dlugosc];
	if (X > dlugosc || X < 0)
		return -1;
	printf("Tablica to: [");
	for(i = 0; i < dlugosc; i++){
		D[i] = wypelnienie(dlugosc, i); //wypelnienie tablicy D
        if (i != 0)
            printf(" %d", D[i]);
        else
            printf("%d", D[i]);
	}
	printf("]\n");
	do{
            C = (A+B)/2;
			if (X > D[C]){
				B = C;
			}
			else if (X < D[C]){
				A = C;
			}
		}while(D[C]!= X);
	return C;

}
