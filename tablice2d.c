#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int **poczatek;
    int lw;
    int lk;
    int pk;
    int pw;
    int ok;
    int ow;
}tab;

void wypelnienie(int** tablica, int lw, int lk);
double srednia(tab tablica);
void drukowanie(tab dane, int lw, int lk);
double wariancja(tab tablica, double sred);

int main()
{
    int i;

    int w = 0;

    int k = 0;

    printf("Podaj liczbe wierszy i kolumn. \n");
    scanf("%d %d", &w, &k);

    if (!w || !k){
        printf("Blad! Tablica nie moze miec 0 kolumn/wierszy\n");
        return 1;
    }
    int **t;

    t = malloc(w * sizeof(*t));
    if (t == NULL)
    {
        printf("Nie moge przydzielic pamieci!\n");
        return 1;
    }
    for ( i = 0; i < w; i++ )
    {
        t[i] = malloc(k * sizeof (**t));
        if (t[i] == NULL)
        {
            printf("Nie moge przydzielic pamieci!\n");
            return 1;
        }
    }

    wypelnienie(t, w, k);

    tab dane = {t, w, k, 0, 0, w, k};

    drukowanie(dane, w, k);
    return 0;
}
void drukowanie(tab dane, int lw, int lk){
    int pole;
    int i;
    int j;

    int** t = dane.poczatek;
    double sredkol;
    double sredwiersz;
    double warkol[lk];
    double sred = srednia(dane);
    double warian = wariancja(dane, sred);

    for ( i = 0; i < lw; i++ )
    {
        for ( j = 0; j < lk; j++ ){
            printf("%8d" , t[i][j]);
        }
        dane.pw = i;
        dane.ow = i+1;
        sredwiersz =  srednia(dane);
        printf("    sw = %.2f", sredwiersz);
        printf("    ww = %.2f", wariancja(dane, sredwiersz));
        printf("\n");
        dane.pw = 0;
        dane.ow = lw;
    }

    for (j = 0; j < 2; j++){
        if(j == 0)
            printf("sk:");
        else
            printf("wk:");
        for ( i = 0; i < lk; i++ ){
            dane.pk = i;
            dane.ok = i+1;
            if (j==0){
                sredkol = srednia(dane);
                if (sredkol < 10)
                    pole = 2;
                else
                    pole = 1;
                printf("  %.*f  ", pole, sredkol);
                warkol[i] = wariancja(dane, sredkol);
            }
            else{
                if (warkol[i] < 10)
                    pole = 2;
                else
                    pole = 1;
                printf("  %.*f  ", pole, warkol[i]);
            }
        }
        printf("\n");
    }
    dane.pk = 0;
    dane.ok = lk;
    printf("\n\n");
    printf("Srednia to: %.2f\n", sred);
    printf("Wariancja to: %.2f\n", warian);
}

void wypelnienie(int **tablica, int lw, int lk){
    int i, j;
    srand(time(NULL));
    for (i = 0; i < lw; i++)
        for ( j = 0; j < lk; j++)
            tablica[i][j] = rand() % 100;
}

double srednia(tab tablica){
    int i,j;
    double suma = 0;
    int le = 0;
    int** t = tablica.poczatek;

    for (i = tablica.pw; i < tablica.ow; i++){
        for ( j = tablica.pk; j < tablica.ok; j++){
            le++;
            suma += t[i][j];
        }
    }
    return (suma/le);
}
double wariancja(tab tablica, double sred){
    int i,j;
    double suma = 0;
    int le = 0;
    int** t = tablica.poczatek;

    for (i = tablica.pw; i < tablica.ow; i++){
        for ( j = tablica.pk; j < tablica.ok; j++){
            le++;
            suma += pow((t[i][j] - sred), 2);
        }
    }
    return pow((suma/le), 0.5);
}

