#include <stdio.h>

void remove_character(char *str, char c) {
    if (str == NULL)
        return;

    char *read_ptr = str;
    char *write_ptr = str;

    while (*read_ptr) {
        if (*read_ptr != c) {
            *write_ptr = *read_ptr;
            write_ptr++;
        }
        read_ptr++;
    }

    *write_ptr = '\0'; // Add null terminator at the end of the new string
}

int main() {
    char s1[] = "Hello";
    char s2[] = "Hello World";
    char c = 'l';

    printf("Original string 1: %s\n", s1);
    remove_character(s1, c);
    printf("Modified string 1: %s\n", s1);

    printf("Original string 2: %s\n", s2);
    remove_character(s2, c);
    printf("Modified string 2: %s\n", s2);

    return 0;
}
