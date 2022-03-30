#include <stdio.h>
#include <string.h>



int main() {
    //char text[] = "annna";
    char text[] = "Ein Esel lese nie";
    int cnt = 0, textlen = strlen(text);

    for (int i = 0; i < textlen; i++) {
        if (text[i] >= 65 && text[i] <= 90){
            text[i] += 32;
        }
    }

    printf("Text zu überprüfen: ");
    for (int j = 0; j < textlen; j++) {
        printf("%c", text[j]);
        if (text[j] == text[textlen-j-1])
            cnt+=1;
    }
    printf("\n");
    printf("cnt: %d\n", cnt);
    printf("textlen: %d\n", textlen);

    if (cnt == textlen)
        printf("Das ist ein Palindrom\n");
    else
        printf("Das ist kein Palindrom\n");
    
    return 0;
}