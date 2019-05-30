#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct rekord{
	int nr;
	char nazwa[100];
	char marka[100];
	char kolor[100];
	double cena;
	char nrrej[100];
	int ac;
	int oc;
	int przeglad;
	int kradzione;
};
typedef struct rekord rekord;

int zapetlbool(char tekst[], int* miejsce);
int dodajrekord(rekord* baza, int numer);
int strdoint(char* slowo);
char* lendostr(int boolean);
int wyswietlrekord(rekord* baza, int nr);
int usunrekord(rekord* baza, int nrpocz, int nrkonc);
int wczytajkonsola(char tekst[], char* miejsce);
void usage(char * name);
unsigned char* wczytajzplik(char argv[], int* dlugosc);
int wczytajrekordy(unsigned char* bufor,rekord* baza ,int len, int nr);
void zapisz(char nazwa[], rekord* baza, int ostatni);
int wyswietlwszystkie(rekord* baza, int tryb, int ostatni);
int wyszukaj(rekord* baza, int ostatni);

int main(int argc, char** argv){

	rekord baza[1000];

	int i = 2;
	int i2 = 2;
	int i3 = 0;
	int j;
	int k;
	int l;
	int m;
	int stareostatnie;
    int koncz = 0;
    int nr;
    int koniecpetli = 0;
    int ostatni = 1;
    int pomin = 0;
    int blad = 0;
    int trybsortowania = 1;
    rekord pusty;
    char c;
    char d;
    char slowo[100];
    int start = 1;
    unsigned char* bufor;
    int pomin2 = 0;

    char slowo2[] = "bazadanych.txt";

	bufor = wczytajzplik(slowo2, &k);
    if(bufor != NULL){ //wczytanie domyslnej bazy danych
        ostatni = wczytajrekordy(bufor, baza, k, 1);
    }

    while(!koncz){ //petla programu
        system("cls");
        if (start){
            printf("Wczytano plik %s\n", slowo2);
            printf("Ilosc wczytanych rekordow: %d\n", ostatni);
            start = 0;
        }
        printf("Witaj w bazie samochodow efbijaj!\nWybierz funkcje, wpisujac cyfre i zatwierdzajac klawiszem Enter.\n");
        printf("1 - Wyswietl liste rekordow\n2 - Dodaj rekord\n3 - Usun rekordy\n4 - Dodaj rekordy z pliku\n5 - Wczytaj rekordy z pliku\n6 - Zapisz rekordy do pliku\n7 - Wyjdz z programu\n");
        i2 = scanf("%d", &i);
        while((c = getchar()) != '\n' && c != EOF){}
        while (i2 <= 0 || i > 7 || i < 1){

            printf("Blad! Wpisz poprawna cyfre od 1 do 7\n");
            i2 = scanf("%d", &i);
            while((c = getchar()) != '\n' && c != EOF){}
        }
        if (i == 7){//wyjscie z programu
            zapetlbool("Czy na pewno? (tak/nie lub y/n)\n", &j);
            if (j == 1)
                koncz = 1;
            continue;
        }
        koniecpetli = 0;
        system("cls");
        while(!koniecpetli)
            {if (i == 1){ //wyswietlanie rekordow
                if (!pomin){
                    if(!pomin2){
                        system("cls");
                        if (blad == 1){
                            printf("Blad! Rekord o podanym numerze nie istnieje\n");
                            blad = 0;
                        }
                        else if (blad == 2){
                            printf("Blad! Nalezy podac prawidlowa cyfre\n");
                            blad = 0;
                        }
                        wyswietlwszystkie(baza, trybsortowania, ostatni);
                    }
                    else{
                        pomin2 = 0;
                        }
                    printf("Wpisz '1' aby wybrac nr rekordu do wyswietlenia\n");
                    printf("Wpisz '2' aby dodac rekord\n");
                    printf("Wpisz '3' aby usunac rekordy\n");
                    printf("Wpisz '4' aby wrocic do menu\n");
                    printf("Wpisz '5' aby sortowac skradzione\n");
                    printf("Wpisz '6' aby sortowac markami\n");
                    printf("Wpisz '7' aby sortowac kolorem\n");
                    printf("Wpisz '8' aby sortowac wartoscia (aby sortowac malejaco, wpisz '8' po raz drugi)\n");
                    printf("Wpisz '0' aby sortowac domyslnie\n");
                    printf("Wpisz 'F' aby wyszukac\n");
                    c = getchar();

                    while((d = getchar()) != '\n' && d != EOF){}
                    if (c == '1')
                        {
                        printf("Podaj numer rekordu do wyswietlenia\n");
                        scanf("%d", &nr);
                        }
                    else if (c == '2'){
                        i = 2;
                        continue;
                    }
                    else if (c == '3'){
                        i = 3;
                        continue;
                    }
                    else if (c == '4'){
                        break;
                    }
                    else if (c == '5'){
                        trybsortowania = 2;
                        continue;
                    }
                    else if (c == '0'){
                        trybsortowania = 1;
                        continue;
                    }
                    else if (c == '6'){
                        trybsortowania = 3;
                        continue;
                    }
                    else if (c == '7'){
                        trybsortowania = 4;
                        continue;
                    }
                    else if (c == '8'){
                        if (i3){
                            trybsortowania = 6;
                            i3 = 0;
                        }
                        else {
                            i3 = 1;
                            trybsortowania = 5;
                        }
                        continue;
                    }
                    else if (c == 'F' || c == 'f'){

                        if(!wyszukaj(baza, ostatni))
                            trybsortowania = 0;
                        else{
                            pomin2 = 1;
                        }
                        continue;
                    }
                    else{
                        blad = 2;
                        continue;
                    }
                    }
                else
                    pomin = 0;
                //if (nr == 0){
                //    continue;
                //}
                if (nr > ostatni || nr < 0){
                    blad = 1;
                    //getchar();
                    continue;
                }
                wyswietlrekord(baza, nr);
                printf("Wpisz '1' aby powrocic do menu\n");
                printf("Wpisz '2' aby powrocic do rekordow\n");
                printf("Wpisz '3' aby usunac rekord\n");
                scanf("%d", &i2);
                while((d = getchar()) != '\n' && d != EOF){}
                if (i2 == 1){

                    break;
                }else if (i2 == 2){
                    continue;
                }
                else if (i2 == 3){
                    j = usunrekord(baza, nr, nr);
                    if (j){
                        stareostatnie = ostatni;
                        ostatni--;
                        for(m = nr + 1; m <= stareostatnie; m++){
                            baza[m - 1].nr -= 1;
                            baza[m - 1 - 1] = baza[m - 1];
                            baza[m - 1] = pusty;
                        }
                    }
                }
                else{
                    break;
                }
            }
            else if (i == 2){ //dodawanie rekordow
                system("cls");
                if (ostatni == 999){
                    printf("Nie mozna dodac rekordu, przekroczono maksymalna ilosc rekordow.");
                    printf("\nWpisz dowolny znak aby powrocic do menu\n");
                    getchar();
                    while((c = getchar()) != '\n' && c != EOF){}
                    break;
                }
                j = dodajrekord(baza, ostatni);
                if (!j)
                    break;
                ostatni++;
                system("cls");
                printf("Nowy rekord dodany! Numer rekordu: %d\n", ostatni);
                printf("Wpisz '1' aby powrocic do menu\n");
                printf("Wpisz '2' aby dodac kolejny rekord\n");
                printf("Wpisz '3' aby wyswietlic rekord\n");
                i2 = -1;
                scanf("%d", &i2);
                if (i2 == 1){
                    break;
                }
                else if (i2 == 3){
                    i = 1;
                    pomin = 1;
                    nr = ostatni;
                }
                else if (i2 == 2){
                    while((c = getchar()) != '\n' && c != EOF){}
                    continue;
                }
                else{
                    while((c = getchar()) != '\n' && c != EOF){}
                    break;
                }
            }
            else if (i == 3){ //usuwanie rekordow
                i2 = 0;
                //system("cls");
                while (i2 != 2){

                    printf("Wpisz dowolny znak niebedacy cyfra, aby wrocic do menu\n\nPodaj zakres numerow rekordow do usuniecia w postaci\nNUMEPOCZATKOWY-NUMERKONCOWY\nlub wpisz '0', aby usunac wszystkie rekordy\nDopuszczalne jest rowniez podanie jednego numeru\n");

                    i2 = scanf("%d-%d", &j, &k);
                    while((c = getchar()) != '\n' && c != EOF){}
                    //printf("\n%d %d %d\n", j, k, i2);
                    if (i2 == 0){
                        koniecpetli = 1;
                        break;
                    }
                    //printf("\n%d %d\n", j, k);
                    if (i2 == 1){
                        i2 = 2;
                        k = j;
                        system("cls");
                        //printf("\n%d %d %d\n", j, k, i2);
                    }
                    else if (i2 != 2){
                        system("cls");
                        printf("Blad! Nalezy podac prawidlowe liczby\n");
                        continue;
                    }
                    if (j > k){
                        l = k;
                        k = j;
                        j = l;
                    }
                    if (j <= 0 || k <= 0 || j > ostatni || k > ostatni){
                        system("cls");
                        printf("Blad! Podane numery sa poza zakresem numerow z listy\n");
                        continue;
                    }
                    l = usunrekord(baza, j, k);
                    if (l){
                        stareostatnie = ostatni;
                        ostatni -= (k-j + 1);
                        for(m = k + 1; m <= stareostatnie; m++){
                            baza[m - 1].nr -= (k-j + 1);
                            baza[m - 1 - (k-j + 1)] = baza[m - 1];
                            baza[m - 1] = pusty;
                        }
                        system("cls");
                        printf("Usunieto rekordy o numerach od %d do %d\n", j, k);
                        printf("Wpisz '1' aby powrocic do menu\n");
                        printf("Wpisz '2' aby usunac kolejne rekordy\n");

                        scanf("%d", &l);
                        while((c = getchar()) != '\n' && c != EOF){}
                        if (l == 1){
                            koniecpetli = 1;
                            break;
                        }
                        else if (l == 2){
                            i2 = 0;
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        break;
                        koniecpetli = 1;
                    }

                }
            }
            else if (i == 4){ //wczytywanie z pliku
                printf("Wcisnij '1' aby wrocic do menu\n");
                printf("Wcisnij '2' aby podac nazwe pliku\n");
                i2 = 0;
                scanf("%d", &i2);
                while((c = getchar()) != '\n' && c != EOF){}
                if(i2 == 1){
                    break;
                }
                else if (i2 == 2){
                    system("cls");
                    l = wczytajkonsola("Podaj nazwe pliku wraz z rozszerzeniem (np. 'a.txt')\n", slowo);
                    bufor = wczytajzplik(slowo, &k);
                    if(l == -1){
                        printf("Blad! Przepelnienie bufora\n");
                        continue;
                    }
                    else if (l == 0)
                        break;
                    else if (bufor == NULL){
                        continue;
                    }
                    else{
                        printf("Wczytano plik %s\n", slowo);
                        stareostatnie = ostatni;
                        ostatni = wczytajrekordy(bufor, baza, k, ostatni+1);
                        printf("Ilosc dodanych rekordow: %d\n", ostatni-stareostatnie);
                        }
                    }
                else{
                    system("cls");
                    printf("Blad! podaj prawidlowa cyfre\n");
                    continue;
                }
            }
            else if (i == 5){ //dodawanie z pliku
                printf("Wcisnij '1' aby wrocic do menu\n");
                printf("Wcisnij '2' aby podac nazwe pliku\n");
                i2 = 0;
                scanf("%d", &i2);
                while((c = getchar()) != '\n' && c != EOF){}
                if(i2 == 1){
                    break;
                }
                else if (i2 == 2){
                    system("cls");
                    l = wczytajkonsola("Podaj nazwe pliku wraz z rozszerzeniem (np. 'a.txt')\n", slowo);
                    bufor = wczytajzplik(slowo, &k);
                    if(l == -1){
                        printf("Blad! Przepelnienie bufora\n");
                        continue;
                    }
                    else if (l == 0)
                        break;
                    else if (bufor == NULL){
                        continue;
                    }
                    else{
                        printf("Wczytano plik %s\n", slowo);

                        ostatni = wczytajrekordy(bufor, baza, k, 1);
                        printf("Ilosc wczytanych rekordow: %d\n", ostatni);
                        }
                    }
                else{
                    system("cls");
                    printf("Blad! podaj prawidlowa cyfre\n");
                    continue;
                }


            }
            else if (i == 6){ //zapis do pliku
                char slowo2[] = "bazadanych.txt";
                j = wczytajkonsola("Podaj nazwe pliku do jakiego baza ma zostac zapisana (np a.txt)\nbadz nie wpisuj nic i baza zostanie zapisana do domyslnego pliku\nZatwierdz wicskajac klawisz Enter\n", slowo2);
                if(j == -1){
                    printf("Blad! Przepelnienie bufora\n");
                    continue;
                }
                else if (j == 0)
                    break;
                else {
                    system("cls");
                    zapisz(slowo2, baza, ostatni);
                    printf("Zapisano do pliku %s\n", slowo2);
                }
                }
            else{
                koniecpetli = 1;
                break;
            }
        }
    }
    system("cls");

    //wyswietlrekord(baza, 1);
    //wyswietlrekord(baza, i);
	return 0;
}
int usunrekord(rekord* baza, int nrpocz, int nrkonc){
    rekord pusty;
    int i;
    zapetlbool("Czy na pewno? (tak/nie lub y/n)\n", &i);

    if (!i)
        return 0;

    for (i = nrpocz; i <= nrkonc; i++)
        baza[i-1] = pusty;
    return 1;

}
int dodajrekord(rekord* baza, int numer){
	rekord nowauto;
	int i = 0;
	int j = 0;
	char c;
	//char bufor[100];

	nowauto.nr = numer + 1;

    system("cls");
    while (j != 1){
        j = wczytajkonsola("Model samochodu:\n", nowauto.nazwa);
        if (j == -1){
            //printf("Blad! Przepelnienie bufora.");
            while((c = getchar()) != '\n' && c != EOF){}
            continue;
        }
        else if (j == 0){
            return 0;
        }
    }
    j = 0;

    system("cls");
    while (j != 1){
        j = wczytajkonsola("Marka samochodu:\n", nowauto.marka);
        if (j == -1){
            //printf("Blad! Przepelnienie bufora.");
            while((c = getchar()) != '\n' && c != EOF){}
            continue;
        }
        else if (j == 0){
            return 0;
        }
    }
    j = 0;

    system("cls");
    while (j != 1){
        j = wczytajkonsola("Kolor samochodu:\n", nowauto.kolor);
        if (j == -1){
            //printf("Blad! Przepelnienie bufora.");
            while((c = getchar()) != '\n' && c != EOF){}
            continue;
        }
        else if (j == 0){
            return 0;
        }
    }
    j = 0;

    system("cls");
    while (j != 1){
        j = wczytajkonsola("Numer rejestracyjny samochodu:\n", nowauto.nrrej);
        if (j == -1){
            //printf("Blad! Przepelnienie bufora.");
            while((c = getchar()) != '\n' && c != EOF){}
            continue;
        }
        else if (j == 0){
            return 0;
        }
    }
    j = 0;

    system("cls");
	do{
        printf("Wpisz ',' any przerwac\n\n");
        printf("Wartosc samochodu:\n");
        i = scanf("%lf", &nowauto.cena);
        system("cls");
        while ((c = getchar()) == ','){
            return 0;
        }
        if (i <= 0){
            printf("Blad! Podaj prawidlowa liczbe (format: xx.xx)\n");
            while((c = getchar()) != '\n' && c != EOF){}
        }
	}while(i <= 0);

	system("cls");
    if (!zapetlbool("Czy samochod posiada ubezpieczenie AC? (tak/nie lub y/n)\n", &(nowauto.ac)))
        return 0;
    if (!zapetlbool("Czy samochod posiada ubezpieczenie OC? (tak/nie lub y/n)\n", &(nowauto.oc)))
        return 0;
    if (!zapetlbool("Czy samochod posiada wazny przeglad? (tak/nie lub y/n)\n", &(nowauto.przeglad)))
        return 0;
    if (!zapetlbool("Czy samochod zostal skradziony? (tak/nie lub y/n)\n", &(nowauto.kradzione)))
        return 0;

    *(baza + numer) = nowauto;
    return 1;
}
int wczytajkonsola(char tekst[], char* miejsce){
    int j = 0;
    char c;


    printf("Wpisz ',' aby przerwac\n\n");
	printf("%s", tekst);

	while((c = getchar()) != '\n' && c != EOF){
        if (c == ',')
            return 0;
        else if (j >= 99){
            system("cls");
            printf("Blad! Przepelnienie bufora\n");
            return -1;
        }
        miejsce[j] = c;
        j++;
	}
	if (j != 0)
        miejsce[j] = '\0';
	for (j = 0; j < strlen(miejsce); j++)
		*(miejsce+j) = toupper(*(miejsce+j));

    return 1;
}

int zapetlbool(char tekst[], int* miejsce){
    int i;
    char com[100];

	do{
		printf("%s", tekst);
		scanf("%s", com);

		i = strdoint(com);

		if (com[0] == ',' && strlen(com) == 1)
            return 0;

		if (i >= 0){
			*miejsce = i;
			system("cls");

        }
		else {
            system("cls");
			printf("Blad! Nalezy wpisac 'tak' lub 'nie' badz 'y' lub 'n'.\n");
		}
	}while (i < 0);
	return 1;
}

int strdoint(char* slowo){
	int j;

	for (j = 0; j < 3; j++)
		*(slowo+j) = tolower(*(slowo+j));

    slowo[3] = '\0';

	if (!strcmp(slowo, "tak") || !strcmp(slowo, "y"))
		return 1;

	else if (!strcmp(slowo, "nie") || !strcmp(slowo, "n"))
		return 0;

	else
		return -1;
}

int wyswietlrekord(rekord* baza, int nr){
    system("cls");
    printf("Marka: %s\nModel: %s\nKolor: %s\nWartosc: %.2f PLN\nNumer rejestracyjny: %s\nPosiada AC: %s\nPosiada OC: %s\nWazny przeglad: %s\nSkradziony: %s\n",
           baza[nr - 1].marka, baza[nr - 1].nazwa, baza[nr - 1].kolor, baza[nr - 1].cena, baza[nr - 1].nrrej, lendostr(baza[nr - 1].ac),
           lendostr(baza[nr - 1].oc), lendostr(baza[nr - 1].przeglad), lendostr(baza[nr - 1].kradzione));
    return 0;
}

char* lendostr(int boolean){
    if (boolean)
        return "TAK";
    else
        return "NIE";
}
void usage(char * name){
            printf("Uzycie: \n" \
           "        %s <nazwa pliku>\n" \
           "        koncze prace!\n", name);
}
unsigned char* wczytajzplik(char argv[], int* dlugosc){

    int status;

    FILE * plik;
    plik = fopen(argv, "rb");
    if ( plik == NULL )
    {
        printf("Nie moge otworzyc pliku!\n");
        return 0;
    }

    fseek(plik, 0L, SEEK_END);     // Przesuwamy wskaŸnik na koniec pliku
    *dlugosc = ftell(plik);         // Odczytujemy d³ugoœæ pliku
    //printf("plik ma dlugosc %d bajtow\n", *dlugosc);

    unsigned char * bufor = malloc(*dlugosc);
    if (bufor == NULL)
    {
        printf("Nie moge przydzielic pamieci\n");
        return 0;
    }
    rewind(plik);
    status = fread(bufor, 1, *dlugosc, plik);
    if ( status != *dlugosc )
    {
        printf("Cos poszlo zle!");
        free(bufor);
        fclose(plik);
        return 0;
    }
    fclose(plik);
    return bufor;
}
int wczytajrekordy(unsigned char* bufor,rekord* baza ,int len, int nr){

    char c;
    char slowo[100];
    int m;
    int i = 0;
    int j = 0;
    int k = 0;

    for(m = 0; m < len; m++){
        c = bufor[m];
        if (bufor[m] == ' ' && j == 0){
            continue;
        }
        if (c == '\n'){
            slowo[j] = '\0';
            baza[nr-1].nr = nr;
            printf("%s", slowo);
            baza[nr-1].kradzione =  strdoint(slowo);
            nr++;
            i = 0;
            j = 0;
        }
        else if (c == ';'){
            slowo[j] = '\0';
        	for (k = 0; k < strlen(slowo); k++)
                *(slowo+k) = toupper(*(slowo+k));
            j = 0;
            switch (i){
                case 0:
                    strcpy(baza[nr-1].nazwa, slowo);
                    break;
                case 1:
                    strcpy(baza[nr-1].marka, slowo);
                    break;
                case 2:
                    strcpy(baza[nr-1].kolor, slowo);
                    break;
                case 3:
                    sscanf(slowo, "%lf", &baza[nr-1].cena);
                    break;
                case 4:
                    strcpy(baza[nr-1].nrrej, slowo);
                    break;
                case 5:
                    baza[nr-1].ac = strdoint(slowo);
                    break;
                case 6:
                    baza[nr-1].oc =  strdoint(slowo);
                    break;
                case 7:
                    baza[nr-1].przeglad =  strdoint(slowo);
                    break;
            }
            i++;
        }
        else {
            slowo[j] = c;
            j++;
        }
    }
    return nr-1;
}
int wyszukaj(rekord* baza, int ostatni){

    int j;
    int i = 0;
    char slowo[100];

    wczytajkonsola("Wpisz tekst do wyszukania\n", slowo);
    system("cls");

    printf("Rekordy: \n");
    printf("   NR                MARKA                KOLOR                    WARTOSC\n\n");
    for (j = 1; j <= ostatni; j++){
            if (!strcmp(baza[j-1].marka, slowo) || !strcmp(baza[j-1].nazwa, slowo) || !strcmp(baza[j-1].nrrej, slowo) || !strcmp(baza[j-1].kolor, slowo)){
                printf("%5d %20s %20s", baza[j-1].nr, baza[j-1].marka, baza[j-1].kolor);
                if (baza[j-1].kradzione)
                    printf("     SKRADZIONE     ");
                else
                    printf("                    ");
                printf("%.2f PLN\n", baza[j-1].cena);
                i++;
            }
        }
    printf("\n");
    if (i)
        return 1;
    return 0;

}

void zapisz(char nazwa[], rekord* baza, int ostatni){
    int i;
    FILE* plik;
    plik = fopen(nazwa, "w");

    for (i = 0; i < ostatni; i++){
        fprintf(plik,"%s",baza[i].nazwa);
        fprintf(plik, "; ");
        fprintf(plik,"%s", baza[i].marka);
        fprintf(plik, "; ");
        fprintf(plik,"%s", baza[i].kolor);
        fprintf(plik, "; ");
        fprintf(plik,"%.2lf", baza[i].cena);
        fprintf(plik, "; ");
        fprintf(plik, "%s", baza[i].nrrej);
        fprintf(plik, "; ");
        fprintf(plik, "%s", lendostr(baza[i].oc));
        fprintf(plik, "; ");
        fprintf(plik, "%s", lendostr(baza[i].ac));
        fprintf(plik, "; ");
        fprintf(plik, "%s", lendostr(baza[i].przeglad));
        fprintf(plik, "; ");
        fprintf(plik, "%s", lendostr(baza[i].kradzione));
        fprintf(plik, "\n");
    }
    fclose(plik);
}
int wyswietlwszystkie(rekord* baza, int tryb, int ostatni){

    int i = 0;
    int m = 0;
    int j = 0;
    int k = 0;
    int l = 1;
    int i2 = 0;
    int malejaco = 0;
    int nr;
    int tab[ostatni];

    printf("Rekordy: \n");

    if (ostatni == 0){
        printf("\nBrak rekordow w bazie danych.\n");
        return 0;
    }
    else if (tryb == 0){
        printf("\nNie znaleziono zadnych pasujacych rekordow\n");
    }

    else
        printf("   NR                MARKA                KOLOR                    WARTOSC\n\n");
    if (tryb == 6){
        tryb = 5;
        malejaco = 1;

    }
    if (tryb == 1){
        for (j = 1; j <= ostatni; j++){
            printf("%5d %20s %20s", baza[j-1].nr, baza[j-1].marka, baza[j-1].kolor);
            if (baza[j-1].kradzione)
                printf("     SKRADZIONE     ");
            else
                printf("                    ");
            printf("%.2f PLN\n", baza[j-1].cena);
            }
    }

    else if (tryb == 2){
        for (j = 1; j <= ostatni; j++){
            if (baza[j-1].kradzione){
                printf("%5d %20s %20s", baza[j-1].nr, baza[j-1].marka, baza[j-1].kolor);
                    printf("     SKRADZIONE     ");
                    printf("%.2f PLN\n", baza[j-1].cena);
            }
            else{
                tab[m] = j-1;
                m++;
            }

        }
        for (j = 0; j < m; j++){
            printf("%5d %20s %20s", baza[tab[j]].nr, baza[tab[j]].marka, baza[tab[j]].kolor);
            printf("                    ");
            printf("%.2f PLN\n", baza[tab[j]].cena);
        }

    }

    else if (tryb == 3){
        k = 0;
        for (j = 1; j <= ostatni; j++){
            if (j == 1){
                tab[0] = 1;
            }
            m = 0;
            while (m < k){
                if (strlen(baza[j-1].marka) > strlen(baza[tab[m] - 1].marka)){
                    l = strlen(baza[tab[m] - 1].marka);
                    i2 = 1;
                }
                else{
                    l = strlen(baza[j-1].marka);
                    i2 = 0;
                }
                i = strncmp(baza[j-1].marka, baza[tab[m] - 1].marka, l);
                //printf("\n\n i = %d, l = %d, k = %d, m = %d, tab = %s, nowe = %s\n\n", i, l, k, m, baza[tab[m] - 1].marka, baza[j-1].marka);
                if (i > 0){

                    if (m+1 == k){
                        tab[k] = j;
                        //printf("\ntab[k]= %s\n", baza[tab[k] - 1].marka);
                    }
                    m++;
                }else if (i == 0 && i2){

                    if (m+1 == k){
                        tab[k] = j;
                    }
                    m++;
                }else{
                    nr = j;
                    for(m = m; m <= k; m++){
                        i = tab[m];
                        tab[m] = nr;
                        //printf("\ntab[m]= %s, m = %d\n", baza[tab[m] - 1].marka, m);
                        nr = i;
                    }
                }
            }
            k++;
        }
        for (j = 0; j < ostatni; j++){
            //printf("\n\n tab[j] = %d, j = %d", tab[j], j);
            printf("%5d %20s %20s", baza[tab[j] - 1].nr, baza[tab[j] - 1].marka, baza[tab[j] -1].kolor);
            if (baza[tab[j] - 1].kradzione)
                printf("     SKRADZIONE     ");
            else
                printf("                    ");
            printf("%.2f PLN\n", baza[tab[j] - 1].cena);
        }

    }
    else if (tryb == 4){
        k = 0;
        for (j = 1; j <= ostatni; j++){
            if (j == 1){
                tab[0] = 1;
            }
            m = 0;
            while (m < k){
                if (strlen(baza[j-1].kolor) > strlen(baza[tab[m] - 1].kolor)){
                    l = strlen(baza[tab[m] - 1].kolor);
                    i2 = 1;
                }
                else{
                    l = strlen(baza[j-1].kolor);
                    i2 = 0;
                }
                i = strncmp(baza[j-1].kolor, baza[tab[m] - 1].kolor, l);
                //printf("\n\n i = %d, l = %d, k = %d, m = %d, tab = %s, nowe = %s\n\n", i, l, k, m, baza[tab[m] - 1].kolor, baza[j-1].kolor);
                if (i > 0){

                    if (m+1 == k){
                        tab[k] = j;
                        //printf("\ntab[k]= %s\n", baza[tab[k] - 1].kolor);
                    }
                    m++;
                }else if (i == 0 && i2){

                    if (m+1 == k){
                        tab[k] = j;
                    }
                    m++;
                }else{
                    nr = j;
                    for(m = m; m <= k; m++){
                        i = tab[m];
                        tab[m] = nr;
                        //printf("\ntab[m]= %s, m = %d\n", baza[tab[m] - 1].kolor, m);
                        nr = i;
                    }
                }
            }
            k++;
        }
        for (j = 0; j < ostatni; j++){
            //printf("\n\n tab[j] = %d, j = %d", tab[j], j);
            printf("%5d %20s %20s", baza[tab[j] - 1].nr, baza[tab[j] - 1].marka, baza[tab[j] -1].kolor);
            if (baza[tab[j] - 1].kradzione)
                printf("     SKRADZIONE     ");
            else
                printf("                    ");
            printf("%.2f PLN\n", baza[tab[j] - 1].cena);
        }

    }
    else if (tryb == 5){
        k = 0;
        for (j = 1; j <= ostatni; j++){
            if (j == 1){
                tab[0] = 1;
            }
            m = 0;
            while (m < k){
                i = baza[j-1].cena - baza[tab[m] - 1].cena;
                if (malejaco){
                    i *= -1;
                }
                if (i <= 0){
                    if (m+1 == k){
                        tab[k] = j;
                        //printf("\ntab[k]= %s\n", baza[tab[k] - 1].kolor);
                    }
                    m++;
                }else{
                    nr = j;
                    for(m = m; m <= k; m++){
                        i = tab[m];
                        tab[m] = nr;
                        //printf("\ntab[m]= %s, m = %d\n", baza[tab[m] - 1].kolor, m);
                        nr = i;
                    }
                }
            }
            k++;
        }
        for (j = 0; j < ostatni; j++){
            //printf("\n\n tab[j] = %d, j = %d", tab[j], j);
            printf("%5d %20s %20s", baza[tab[j] - 1].nr, baza[tab[j] - 1].marka, baza[tab[j] -1].kolor);
            if (baza[tab[j] - 1].kradzione)
                printf("     SKRADZIONE     ");
            else
                printf("                    ");
            printf("%.2f PLN\n", baza[tab[j] - 1].cena);
        }

    }
    printf("\n");
    return -1;
}
