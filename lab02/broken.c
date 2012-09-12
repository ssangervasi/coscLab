#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* need a function prototype before any of this */

char *remove_whitespace(char *s) {
    char buffer[strlen(s) + 1]; 
/* Don't we actually need a malloc()? Otherwise it's not able to be returned... This will later require a free()*/
    int i = 0, j = 0;
    for ( ; i < strlen(s); i += 1) {
        if (!isspace(s[i])) {
            buffer[j] = s[i]; /*I don't know why but this might not work*/
            j += 1;
        }
    }
    buffer[j] = '\0';
    printf("%s\n", buffer);
    return buffer;
}

int main(int argc, char **argv) {
    char *s = strdup("  the \tinternet\t\nis a series of tubes  ");
    char *newstr = remove_whitespace(s);
    printf("%s\n", newstr);
    return 0;
}
