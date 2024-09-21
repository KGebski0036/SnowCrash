// do {
//         // If all characters are processed, break
//         if (uVar8 == 0) break;
//         uVar8 = uVar8 - 1;
//         cVar1 = *pcVar5;  // Fetch the current character
//         pcVar5 = pcVar5 + (uint)bVar9 * -2 + 1;  // Move to the next character
//     } while (cVar1 != '\0');

#include <stdio.h>
#include <stdlib.h>

void printFileContent(const char *filename) {
    int i = 0;
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch - i); // Print the character to the console
        i++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printFileContent(argv[1]);
    return 0;
}
