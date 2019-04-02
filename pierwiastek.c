#include <stdio.h>
#include <math.h>
int blisko();
double lepszy();
double pierwiastek();


int main(int argc, char* argv[]){
    double n = 0;
    double w = 0;
    double g = 0;

    printf("Podaj liczbê pierwiastkowan¹ (w).\n");
    scanf("%lf", &w);

    printf("Podaj przybli¿enie (g).\n");
    scanf("%lf", &g);

    printf("Podaj stopieñ pierwiastka (n).\n");
    scanf("%lf", &n);

    double wynik;

    if (g == 0){
        printf("Blad! Przyblizenie nie moze wynosic 0\n");
        return 1;
        }
    if (n == 0)
        wynik = 1;
    else
        wynik = pierwiastek(g,w,n);

    printf("Wynik to: %lf", wynik);

    return 0;
}
int blisko(double g, double gprim){
    double epsi = 0.0001;
    if (fabs(g-gprim) <= epsi)
        return 1;
    else
        return 0;

}
double pierwiastek(double g, double w, double n){
    double gprim = lepszy(g,w,n);
    while (!blisko(g,gprim)){
        g = gprim;
        gprim = lepszy(g,w,n);
    }
    return gprim;
}
double lepszy(double g, double w, double n){
    return (1/n)*((n-1)*g + (w/pow(g, n-1)));
}
