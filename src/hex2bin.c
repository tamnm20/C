#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char hexToByte(const char *hex) {
    unsigned int byte;
    sscanf(hex, "%2x", &byte);
    return (unsigned char)byte;
}

int main() {
    char inputFile[260], outputFile[260];
    printf("Enter Intel HEX file name: ");
    scanf("%259s", inputFile);
    printf("Enter output BIN file name: ");
    scanf("%259s", outputFile);

    FILE *fin = fopen(inputFile, "r");
    if (!fin) {
        perror("Error opening input file");
        return 1;
    }

    FILE *fout = fopen(outputFile, "wb");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        return 1;
    }

    char line[1024];
    unsigned int ext_addr = 0;

    while (fgets(line, sizeof(line), fin)) {
        if (line[0] != ':') continue;

        unsigned int len, addr, type;
        sscanf(line + 1, "%02x%04x%02x", &len, &addr, &type);

        if (type == 0x00) {
            // Data record
            unsigned int abs_addr = (ext_addr << 16) | addr;
            long current_pos = ftell(fout);
            if ((unsigned int)current_pos < abs_addr) {
                // pad with 0xFF if needed
                for (unsigned int i = current_pos; i < abs_addr; ++i) {
                    fputc(0xFF, fout);
                }
            } else {
                fseek(fout, abs_addr, SEEK_SET);
            }

            const char *data_ptr = line + 9;
            for (unsigned int i = 0; i < len; ++i) {
                unsigned char byte = hexToByte(data_ptr + i * 2);
                fputc(byte, fout);
            }

        } else if (type == 0x04) {
            // Extended Linear Address Record
            ext_addr = (hexToByte(line + 9) << 8) | hexToByte(line + 11);
        } else if (type == 0x01) {
            // End Of File
            break;
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Conversion complete! Output saved to: %s\n", outputFile);
    system("pause");
    return 0;
}
