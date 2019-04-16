#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lowercase();
int podzial();
int sprawdzenie();

int main(int argc, char*argv[]){
    int len = 128;
    char napis[len];
    int test;

    printf("Podaj dwa napisy oddzielone spacja.\n");
    fgets(napis, len, stdin);

    if (strlen(napis) == len - 1){
        printf("Blad 0, podany napis jest za dlugi.");
        return 1;
    }
    lowercase(napis, len);

    test = podzial(napis, len);

    char* napis2 = napis + test;

    if (test == -1){
        printf("Blad -1, podano za duzo slow.\n");
        return 1;
    }else if(test == -2){
        printf("Blad -2, podano jedno slowo (albo nie podano znaku ' ')!");
        return 1;
    }

    printf("Pierwsze slowo to: %s\nDrugie slowo to: %s\n", napis, napis2);

    test = sprawdzenie(napis, napis2);

    if (test == 0)
        printf("Podane napisy sa anagramami.\n");
    else
        printf("Podane napisy nie sa anagramami.\n");
    return 0;
}

void lowercase(char* napis, int len){
    int i;
    for (i = 0; i < len; i++)
        *(napis + i) = tolower(*(napis + i));
}

int podzial(char* napis, int len){
    int i = 0;
    char litera;
    int flagaslowa = 0;

    for (i = 0; i < len; i++){
        litera = *(napis+i);
        if (litera == ' '){
            if (flagaslowa == 0){
                flagaslowa++;
                *(napis+i) = '\0';
                return (i+1);
            }else
            return -1;
        }
    }
    return -2;
}

int sprawdzenie(char* slowo1, char* slowo2){
    int len1 = strlen(slowo1);
    int len2 = strlen(slowo2) - 1;
    int i = 0;
    int i2 =0;

    if (len2 != len1)
        return -1;
    else {
        for(i = 0; i < len1; i++){
            i2 = 0;
            char litera = *(slowo1 + i);
            while (litera != *(slowo2 + i2)){
                i2++;
                if (i2 == len1)
                    return -1;
            }
        }
    }
    return 0;
}
