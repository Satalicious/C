
#include <stdio.h>
#include <string.h>


    int GetDayNr (int Mont, int Day) {
        int Months[] = {31,28,31,30,31,30,31,30,31,30,31};
        int total = 0;

        Mont = Mont -2;
        for (int i = 0; i <= Mont; i++) {
            total+=Months[i];
        }
        return total + Day;
    }

    void insert (char x, int pos) {
        char Text[] = "Das Haus";
        for (int i = 0; i < strlen(Text); i++) {
            if (i == pos) {
                for (int j = 0; j < strlen(Text)-i ; j++) {
                    Text[i+1] = Text[j];
                }
            }
        }
        Text[pos-1] = x;
    }

int main() {
    int zahl1=0,zahl2=0,abs = 0;
    int feld[1000];
    printf("%d",GetDayNr(3,14));
    do
    {
        printf("Geben sie die erste Zahl ein: ");
        scanf("%d",&zahl1);
        printf("Geben Sie die zweite Zahl ein: ");
        scanf("%d",&zahl2);
/*        if (zahl1 < 0)
            zahl1 *= -1;
        if (zahl2 < 0)
            zahl2 *= -1; */
        if (zahl1 == zahl2) {
            abs = zahl1;
            break;
        }
        if (zahl1 > abs)
            abs = zahl1;
        if (zahl2 > abs)
            abs = zahl2;
    } while (zahl1 != zahl2);
    printf("%d",abs);
    
}