#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("syntax: add-nbo <file1> <file2>\n");
        printf("sample: add-nbo a.bin b.bin\n");
        return 1;
    }

    char *file1_name = argv[1];
    char *file2_name = argv[2];

    FILE *file1 = fopen(file1_name, "rb");
    FILE *file2 = fopen(file2_name, "rb");

    if (!file1 || !file2) {
        printf("Error: Cannot open input files.\n");
        return 1;
    }

    uint32_t num1, num2;
    size_t read1, read2;

    read1 = fread(&num1, sizeof(uint32_t), 1, file1);
    read2 = fread(&num2, sizeof(uint32_t), 1, file2);

    if (read1 != 1 || read2 != 1) {
        printf("Error: Cannot read data from input files.\n");
        return 1;
    }

    num1 = ntohl(num1);
    num2 = ntohl(num2);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    fclose(file1);
    fclose(file2);

    return 0;
}
