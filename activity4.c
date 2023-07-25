#include <stdio.h>
#define SET_BIT(num, bit) ((num) |= (1U << (bit)))

#define CLEAR_BIT(num, bit) ((num) &= ~(1U << (bit)))

#define TOGGLE_BIT(num, bit) ((num) ^= (1U << (bit)))

unsigned char set_bit(unsigned char num, unsigned char bit) {
    return num | (1U << bit);
}

unsigned char clear_bit(unsigned char num, unsigned char bit) {
    return num & ~(1U << bit);
}

unsigned char toggle_bit(unsigned char num, unsigned char bit) {
    return num ^ (1U << bit);
}

int main() {
    unsigned char num = 0x5A; 
    unsigned char bit_to_operate = 3; 
    printf("Original number: 0x%02X\n", num);

    
    SET_BIT(num, bit_to_operate);
    printf("After setting bit %d: 0x%02X\n", bit_to_operate, num);

    CLEAR_BIT(num, bit_to_operate);
    printf("After clearing bit %d: 0x%02X\n", bit_to_operate, num);

    TOGGLE_BIT(num, bit_to_operate);
    printf("After toggling bit %d: 0x%02X\n", bit_to_operate, num);

    
    num = set_bit(num, bit_to_operate);
    printf("After setting bit %d: 0x%02X\n", bit_to_operate, num);

    num = clear_bit(num, bit_to_operate);
    printf("After clearing bit %d: 0x%02X\n", bit_to_operate, num);

    num = toggle_bit(num, bit_to_operate);
    printf("After toggling bit %d: 0x%02X\n", bit_to_operate, num);

    return 0;
}
