#include <stdio.h>

unsigned int insert_number_at_position(unsigned int X, unsigned int N, int P) {
    unsigned int mask = ~(1 << P);

    
    N &= (1 << (P + 1)) - 1;

    
    unsigned int result = (X & mask) | (N << P);

    return result;
}

int main() {
    
    unsigned int X1 = 10;
    unsigned int N1 = 5;
    int P1 = 6;
    unsigned int result1 = insert_number_at_position(X1, N1, P1);
    printf("%08x\n", result1);

    
    unsigned int X2 = 10;
    unsigned int N2 = 5;
    int P2 = 2;
    unsigned int result2 = insert_number_at_position(X2, N2, P2);
    printf("%08x\n", result2);

    return 0;
}
