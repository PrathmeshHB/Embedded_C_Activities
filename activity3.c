#include <stdio.h>


unsigned char dec_to_bcd(unsigned char decimal) {
    return (((decimal / 10) << 4) | (decimal % 10));
}

int main() {
    unsigned char decimal = 42; 
    unsigned char bcd = dec_to_bcd(decimal);

    printf("Decimal: %d\n", decimal);
    printf("BCD: 0x%02X\n", bcd);

    return 0;
}
