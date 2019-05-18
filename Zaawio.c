#include <stdio.h>
#include <string.h>

void wypelnienie(char* tab, int len, char wartosc);

int main(int argc, char **argv)
{
    FILE * plik;
    int i = 0;
    int i2 = 1;
    int i3 = 0;
    int dlg;
    char test;
    int status;

    if (argc == 1)
    {
        printf("Tylko jeden argument (nazwa programu)"
               " -- czytam z stdin, max dlugosc 255 znakow\n");
        plik = stdin;
        dlg = 256;
        test = 0;
    }
    else
    {
        printf("Argumentów wiecej, zakladam, ¿e pierwszy"
               " to nazwa pliku: %s\n", argv[1]);
        plik = fopen(argv[1], "r");
        while ((status = fgetc(plik))!= EOF){

            if (status == '\n'){
                if (i2 == 1)
                    i3 = i;
                i2++;
            }
            i++;
        }
        dlg = i + 1;
        test = 1;
        printf("Dlugosc pliku to: %d\nIlosc linii: %d\n", dlg, i2);
        if ( plik == NULL )
        {
            printf("Nie mogê otworzyc pliku!\n");
            return 2;
        }
    }

    i = 0;
    char napis[dlg];
    //wypelnienie(napis, dlg, ' ');

    if (test == 1){
        char *bufor = napis;
        int i3 = 0;
        for (i = 0; i < i2; i++){
            fgets(bufor, dlg, plik);
            i3 = strlen(bufor);
            bufor += i3;
        }
    }
    else while ((status = fscanf(plik, "%c" , napis + i )) != EOF)
        i++;

    printf("Napis to: \n%s\n", napis);
    fclose(plik);
    return 0;
}
void wypelnienie(char* tab, int len, char wartosc){
    int i;

    for (i = 0; i < len; i++)
        *(tab + i) = wartosc;
}
