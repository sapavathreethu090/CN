#include <stdio.h>

#define FLAG 'F'
#define ESC  'E'

int main() {
    char data[100], stuffed[200], destuffed[100];
    int i, j;

    printf("Enter data: ");
    scanf("%s", data);

    /* ---------- CHARACTER STUFFING ---------- */
    j = 0;
    stuffed[j++] = FLAG;

    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == FLAG || data[i] == ESC) {
            stuffed[j++] = ESC;       // add escape before flag/ESC
        }
        stuffed[j++] = data[i];
    }

    stuffed[j++] = FLAG;
    stuffed[j] = '\0';

    printf("\nStuffed Data: %s\n", stuffed);

    
    j = 0;
    for (i = 1; stuffed[i] != FLAG; i++) {   
        if (stuffed[i] == ESC) {
            i++;                             // skip escape
        }
        destuffed[j++] = stuffed[i];
    }
    destuffed[j] = '\0';

    printf("Destuffed Data: %s\n", destuffed);

    return 0;
}
