#include <stdio.h>
#include <math.h>
void przenoszenie();
int zdjecie();
void nalozenie();
void drukuj();

int main(int argc, char* argv[]){
    int liczba_krazkow = 0;
    int i = 0, i2 = 0;

    printf("Podaj liczbe krazkow.\n");
    scanf("%d", &liczba_krazkow);

    if (liczba_krazkow > 16){
        printf("Za duza liczba krazkow! Wizualizacja nie zadziala i zapewne bedzie sie liczylo w nieskonczonosc. \n");
        return -1;
    }
    else if (liczba_krazkow < 0){
        printf("Liczba krazkow nie moze byc ujemna.\n");
        return -1;
    }
    int slupki[liczba_krazkow + 1][3];

    for(i = 1; i <= liczba_krazkow; i++){
        slupki[i - 1][0] = i;
        slupki[i - 1][1] = 0;
        slupki[i - 1][2] = 0;
        if (i == liczba_krazkow){
            for (i2 = 0; i2 < 3; i2++)
                slupki[i][i2] = -1;
        }
    }

    int L[3] = {liczba_krazkow, 0, 0};

    drukuj(slupki,liczba_krazkow,L);

    przenoszenie(&slupki[0][0], &slupki[0][1], &slupki[0][2], liczba_krazkow, L, &slupki[0][1]);

    return 0;
}

void przenoszenie(int* wejscie, int* wyjscie, int* pomoc, int N, int* L, int* test){
    int krazek;
    if (N == 1){
        krazek = zdjecie(wejscie, L, test);
        nalozenie(wyjscie, krazek, L, test);
        drukuj(test - 1, *(L+1)+*L+*(L+2), L);
    }
    else {
        przenoszenie(wejscie, pomoc, wyjscie, N-1, L, test);
        krazek = zdjecie(wejscie, L, test);
        nalozenie(wyjscie, krazek, L, test);
        drukuj(test - 1, *(L+1)+*L+*(L+2), L);
        przenoszenie(pomoc, wyjscie, wejscie, N-1, L, test);
    }
}
int zdjecie(int* slupek, int* L, int* test){
    int i = 0;
    if (test > slupek)
        L = L;
    else if (test == slupek)
        L += 1;
    else if (test < slupek)
        L += 2;
    while (*(slupek + 3*i) == 0)
        i++;
    int krazek = *(slupek + 3*i);
    *(slupek + 3*i) = 0;
    (*L)--;
    return krazek;
}

void nalozenie(int* slupek, int krazek, int* L, int* test){
    int i = 0;

    if (test > slupek)
        L = L;
    else if (test == slupek)
        L += 1;
    else if (test < slupek)
        L += 2;
    while (*(slupek + 3*i) == 0){
        i++;
        }
    (*L)++;
    *(slupek + 3*(i - 1)) = krazek;
}
void drukuj(int* slupki, int liczba_krazkow, int L[]){
    int i, i2, i3, i4 = 0;
    int liczba_tabow = (2*liczba_krazkow - 1);

    printf("\n\n");

    for (i = 0; i < liczba_krazkow; i++){
        for (i2 = 0; i2 < 3; i2++){
            if (*(slupki + i*3 +i2) != 0){
                for(i4 = 1; i4 <= liczba_krazkow - *(slupki + i*3 +i2); i4++)
                    printf(" ");
                for (i3 = 1; i3 <= 2*(*(slupki + i*3 +i2))-1; i3++){
                    printf("%x", *(slupki + i*3 +i2));
                }
                for (i3 = 1; i3 <= liczba_krazkow - *(slupki + i*3 +i2); i3++)
                    printf(" ");
            }
            else{
                for (i3 = 1; i3 <= liczba_tabow; i3++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 0; i <= liczba_tabow; i++)
        printf("---");
    printf("\n");

    int spacje = liczba_tabow/2;

    for (i = 0; i <3; i++){
        if (L[i] >= 10)
            spacje--;
        for(i2 = 1; i2 <= spacje; i2++)
            printf(" ");
        printf("%d", L[i]);
        for(i2 = 1; i2 <= liczba_tabow/2; i2++)
            printf(" ");
    }
    printf("\n\n");
}
