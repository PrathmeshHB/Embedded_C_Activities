#include <stdio.h>
#include <stdint.h>

// Define the INTCON register address
#define INTCON_ADDR 0x0B

// Define individual bit positions in the INTCON register
#define GIE_BIT 7
#define INTF0IF_BIT 1

// Macro to access the INTCON register bitwise
#define INTCON_BIT(x) ((INTCON & (1U << (x))) != 0)

// Function to access the INTCON register bytewise
void write_to_INTCON(uint8_t value) {
    *((volatile uint8_t *)INTCON_ADDR) = value;
}

// Example usage
int main() {
    // Set GIE bit to 1 (enable global interrupts)
    write_to_INTCON(1 << GIE_BIT);

    // Set INTF0IF bit to 1 (set external interrupt flag 0)
    write_to_INTCON(1 << INTF0IF_BIT);

    // Access INTCON bitwise and print the value of GIE and INTF0IF bits
    printf("GIE: %d\n", INTCON_BIT(GIE_BIT));
    printf("INTF0IF: %d\n", INTCON_BIT(INTF0IF_BIT));

    return 0;
}
