#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void get_mem() {
    FILE* fp = popen("free -b | grep Mem", "r");
    if (fp == NULL) {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    char out[128];
    if (fgets(out, sizeof(out), fp) != NULL) {
        int total, used;
        sscanf(out, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %d %*s %d", &total, &used);
        double percent = ((double)used * 100) / total;

        printf("Phan tram used: %f\n", percent);
    }

    pclose(fp);
}

void get_cpu() {
    FILE* fp = popen("cat /proc/stat | grep 'cpu '", "r");
    if (fp == NULL) {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    char out[128];
    if (fgets(out, sizeof(out), fp) != NULL) {
        int x, y, z;
        sscanf(out, "%*s %d %*s %*s %d %*s %d", &x, &y, &z);

        printf("Old: %d\t%d\t%d\n", x, y, z);
    }

    pclose(fp);
}

int main() {
    while (1) {
        sleep(5); // Delay 5 giây trước khi lấy thông tin tiếp theo
        get_mem();
        get_cpu();
    }

    return 0;
}
