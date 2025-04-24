#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputFile[260];
    char outputFile[260];

    printf("Enter input .bin file name: ");
    scanf("%259s", inputFile);

    printf("Enter output file name: ");
    scanf("%259s", outputFile);

    FILE *fin = fopen(inputFile, "rb");
    if (!fin) {
        perror("Error opening input file");
        return 1;
    }

    FILE *fout = fopen(outputFile, "w");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        return 1;
    }

    int byte;
    while ((byte = fgetc(fin)) != EOF) {
        fprintf(fout, "%02x\n", byte); // mỗi byte in dạng hex thường, 2 chữ số, mỗi dòng
    }

    fclose(fin);
    fclose(fout);

    printf("Done! Output saved to: %s\n", outputFile);
    system("pause"); // Để giữ cửa sổ mở sau khi chạy xong
    return 0;
}
