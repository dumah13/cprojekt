#include <stdio.h>
int main()
{
    char z[128];
    int i;
    while ( ( i = scanf("%s", z) ) > 0 )
        printf("z = %s i = %d\n", z, i);
    printf("Koniec\n");
    return 0;
}
