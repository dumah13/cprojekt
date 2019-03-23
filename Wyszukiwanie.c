#include <stdio.h>
int wypelnienie();
int wyszukaj();

int main(int argc, char* argv[])
{
	int len = 0;
	int liczba = 0;
    int i = 0;

	printf("Podaj dlugosc tablicy.\n");
	scanf("%d", &len);

    if (len == 0){
        printf("Błąd! Długość tablicy nie może wynosić 0");
        return 1;
    }

	printf("Podaj szukana liczbe.\n");
	scanf("%d", &liczba);

	int D[len];

	printf("Tablica to: [");

	for(i = 0; i < len; i++){
		D[i] = wypelnienie(len, i); //wypelnienie tablicy D

        if (i != 0)
        	printf(" %d", D[i]);
        else
        	printf(",%d", D[i]);
	}
	printf("]\n");

	int C = wyszukaj(len, liczba, D);

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
int wyszukaj(int dlugosc, int X, int D[])
{
	int C,A = 0;
	int B = dlugosc;

	if (X > dlugosc || X < 0)
		return -1;

	do{

        C = (A+B)/2;

        if (X > D[C])
        	B = C;
        else if (X < D[C])
		A = C;
	}while(D[C]!= X);

	return C;
}
