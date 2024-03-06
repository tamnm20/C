#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

double get_ram_usage() {
    FILE* fp = popen("free | awk '/Mem:/ {print ($3/$2)*100}'", "r");
    if (fp == NULL) {
        perror("Error executing RAM command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

int main() {
    while (1) {
        double ram_usage = get_ram_usage();
        printf("RAM Usage: %.2f%%\n", ram_usage);
        sleep(1);  // Delay 1 giây trước khi lấy thông tin tiếp theo
    }

    return 0;
}