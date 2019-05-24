#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct rekord{
	int nr;
	char nazwa[100];
	char marka[100];
	char typ[100];
	double cena;
	char nrrej[100];
	int ac;
	int oc;
	int przeglad;
	int kradzione;
};
typedef struct rekord rekord;

void zapetlbool(char tekst[], int* miejsce);
void dodajrekord(rekord* baza, int numer);
int strdoint(char* slowo);
char* lendostr(int boolean);
int wyswietlrekord(rekord* baza, int nr);
void usunrekord(rekord* baza, int nr);


int main(int argc, char** argv){

	rekord baza[1000];

	rekord auto1 = {1, "Thalia","Renault", "sedan", 8000.00, "FZ12345", 1, 1, 1, 0};

	baza[0] = auto1;

	int i = 2;
	int i2 = 2;
	int j;
    int koncz = 0;
    int nr;
    int koniecpetli = 0;
    int ostatni = 1;
    char c;
	//dodajrekord(baza, i);
    while(!koncz){
        system("cls");
        printf("Witaj w bazie danych efbijaj!\nWybierz funkcje, wpisujac cyfre i zatwierdzajac klawiszem Enter.\n");
        printf("1 - Wyswietl rekord.\n2 - Dodaj rekord\n3 - Usun rekord\n4 - Dodaj rekordy z pliku\n5 - Wczytaj rekordy z pliku\n");
        i2 = scanf("%d", &i);
        while((c = getchar()) != '\n' && c != EOF){}
        while (i2 <= 0 || i > 5 || i < 1){

            printf("Blad! Wpisz poprawna cyfre od 1 do 5\n");
            i2 = scanf("%d", &i);
            while((c = getchar()) != '\n' && c != EOF){}
        }
        while(!koniecpetli){
            if (i == 1){
                system("cls");
                printf("Rekordy: \n");
                for (j = 1; j <= ostatni; j++)
                    printf("%d\n", j);
                printf("Podaj numer rekordu do wyswietlenia\n");
                scanf("%d", &nr);
                wyswietlrekord(baza, nr);
                printf("Wpisz '1' aby powrocic do menu\n");
                printf("Wpisz '2' aby powrocic do rekordow\n");
                scanf("%d", &i2);
                if (i2 == 1){
                    break;
                }else if (i2 == 2)
                    continue;
                }
            else if (i == 2){
                system("cls");
                dodajrekord(baza, ostatni + 1);
                ostatni++;
                system("cls");
                printf("Nowy rekord dodany! Numer rekordu: %d\n", ostatni);
                printf("Wpisz '1' aby powrocic do menu\n");
                printf("Wpisz '2' aby dodac kolejny rekord\n");
                scanf("%d", &i2);
                if (i2 == 1){
                    break;
                }
            }
        }
}

    wyswietlrekord(baza, 1);
    //wyswietlrekord(baza, i);
	return 0;
}
void dodajrekord(rekord* baza, int numer){
	rekord nowauto;
	int i =-100;
	char c;

	nowauto.nr = numer + 1;
	printf("Model samochodu\n");
	scanf("%s", nowauto.nazwa);
	system("cls");
	while((c = getchar()) != '\n' && c != EOF){}

	printf("Marka samochodu\n");
	scanf("%s", nowauto.marka);
	system("cls");
	while((c = getchar()) != '\n' && c != EOF){}

	printf("Typ samochodu\n");
	scanf("%s", nowauto.typ);
	system("cls");
	while((c = getchar()) != '\n' && c != EOF){}

    printf("Numer rejestracyjny samochodu\n");
	scanf("%s", nowauto.nrrej);
	system("cls");
	while((c = getchar()) != '\n' && c != EOF){}

	do{
        printf("Wartosc samochodu\n");
        i = scanf("%lf", &nowauto.cena);
        printf("\n%d\n", i);
        system("cls");
        if (i <= 0){
            printf("Blad! Podaj prawidlowa liczbe (format: xx.xx)\n");
            while((c = getchar()) != '\n' && c != EOF){}
		/* discard */
        }
	}while(i <= 0);

    zapetlbool("Czy samochod posiada ubezpieczenie AC? (tak/nie lub y/n)\n", &(nowauto.ac));
    zapetlbool("Czy samochod posiada ubezpieczenie OC? (tak/nie lub y/n)\n", &(nowauto.oc));
    zapetlbool("Czy samochod posiada wazny przeglad? (tak/nie lub y/n)\n", &(nowauto.przeglad));
    zapetlbool("Czy samochod zostal skradziony? (tak/nie lub y/n)\n", &(nowauto.kradzione));

    *(baza + numer - 1) = nowauto;

}

void zapetlbool(char tekst[], int* miejsce){
    int i;
    char com[100];

	do{
		printf("%s", tekst);
		scanf("%s", com);

		i = strdoint(com);

		if (i >= 0){
			*miejsce = i;
			system("cls");

        }
		else {
            system("cls");
			printf("Blad! Nalezy wpisac 'tak' lub 'nie' badz 'y' lub 'n'.\n");
		}
	}while (i < 0);
}

int strdoint(char* slowo){
	int i = strlen(slowo);
	int j;

	for (j = 0; j < i; j++)
		*(slowo+j) = tolower(*(slowo+j));

	if (!strcmp(slowo, "tak") || !strcmp(slowo, "y"))
		return 1;

	else if (!strcmp(slowo, "nie") || !strcmp(slowo, "n"))
		return 0;

	else
		return -1;
}

int wyswietlrekord(rekord* baza, int nr){
    system("cls");
    printf("Marka: %s\nModel: %s\nTyp: %s\nWartosc: %.2f\nNumer rejestracyjny: %s\nPosiada AC: %s\nPosiada OC: %s\nWazny przeglad: %s\nSkradziony: %s\n",
           baza[nr - 1].marka, baza[nr - 1].nazwa, baza[nr - 1].typ, baza[nr - 1].cena, baza[nr - 1].nrrej, lendostr(baza[nr - 1].ac),
           lendostr(baza[nr - 1].oc), lendostr(baza[nr - 1].przeglad), lendostr(baza[nr - 1].kradzione));
    return 0;
}

char* lendostr(int boolean){
    if (boolean)
        return "tak";
    else
        return "nie";
}


