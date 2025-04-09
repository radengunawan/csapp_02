#include <stdio.h>

// Typedef for convenience: pointer to a byte (unsigned char)
typedef unsigned char *byte_pointer;

// Function to show bytes in memory as hex values
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);  // Print each byte as a 2-digit hex
    }
    printf("\n");
}

// Show the byte representation of an integer
void show_int(int x) {
    printf("Bytes of int (%d):", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

// Show the byte representation of a float
void show_float(float x) {
    printf("Bytes of float (%f):", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

// Show the byte representation of a pointer
void show_pointer(void *x) {
    printf("Bytes of pointer (%p):", x);
    show_bytes((byte_pointer) &x, sizeof(void *));
}

// Entry point: where the byte-snooping fun begins
int main() {
    int a = 12345;
    float b = 123.45;
    int *p = &a;

    show_int(a);       // Show bytes of integer
    show_float(b);     // Show bytes of float
    show_pointer(p);   // Show bytes of pointer

    return 0;
}
