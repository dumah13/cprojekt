#include <stdio.h>
void wypelnienie(int* tab, int len, int wartosc);

int main(int argc, char* argv[]){
    char znak;
    int dlg = 255;

    int znaki[dlg];
    int i;
    int i2;

    wypelnienie(znaki, dlg, 0);

    printf("Podaj tekst z pliku, albo wpisz tutaj, po zakonczeniu wpisywania wcisnij CTRL+Z.\nBEZ POLSKICH ZNAKOW!\n");

    while ((i = scanf("%c", &znak)) != EOF){
        (*(znaki + znak))++;
    }

    for (i = 0; i < dlg; i++){
        if (znaki[i] == 0)
            continue;
        else {
            if (i == '\n')
                printf("Ilosc znaku '\\n' = %d\t", znaki[i]);
            else
                printf("Ilosc znaku '%c' = %d\t", i, znaki[i]);
            for (i2 = 0; i2 < znaki[i]; i2++)
                printf("|-");
        }
        printf("|\n");
    }
}

void wypelnienie(int* tab, int len, int wartosc){
    int i;

    for (i = 0; i < len; i++)
        *(tab + i) = wartosc;
}
