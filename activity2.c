#include <stdio.h>
#include <string.h>

// Generic swap function
void generic_swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

typedef struct Student {
    char a[10];
    int b;
    double c;
} Student;

int main() {
    int i1 = 10, i2 = 20;
    float f1 = 1.6, f2 = 8.9;
    int a1[3] = {1, 2, 3}, a2[3] = {10, 20, 30};
    Student s1 = {"Adil", 42, 5.2}, s2 = {"Bilal", 9, 3};

    
    printf("Before swap: i1 = %d, i2 = %d\n", i1, i2);
    generic_swap(&i1, &i2, sizeof(int));
    printf("After swap: i1 = %d, i2 = %d\n\n", i1, i2);

    
    printf("Before swap: f1 = %.1f, f2 = %.1f\n", f1, f2);
    generic_swap(&f1, &f2, sizeof(float));
    printf("After swap: f1 = %.1f, f2 = %.1f\n\n", f1, f2);

    
    printf("Before swap: a1 = {%d, %d, %d}, a2 = {%d, %d, %d}\n", a1[0], a1[1], a1[2], a2[0], a2[1], a2[2]);
    generic_swap(&a1, &a2, sizeof(a1));
    printf("After swap: a1 = {%d, %d, %d}, a2 = {%d, %d, %d}\n\n", a1[0], a1[1], a1[2], a2[0], a2[1], a2[2]);

    
    printf("Before swap: s1 = {%s, %d, %.1f}, s2 = {%s, %d, %.1f}\n", s1.a, s1.b, s1.c, s2.a, s2.b, s2.c);
    generic_swap(&s1, &s2, sizeof(Student));
    printf("After swap: s1 = {%s, %d, %.1f}, s2 = {%s, %d, %.1f}\n", s1.a, s1.b, s1.c, s2.a, s2.b, s2.c);

    return 0;
}
