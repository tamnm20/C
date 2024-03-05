#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

double get_cpu_usage() {
    FILE* fp = popen("top -bn1 | awk '/%Cpu/ {print $2 + $4}'", "r");
    if (fp == NULL) {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

int main() {
    while (1) {
        double cpu_usage = get_cpu_usage();
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1);  // Delay 1 giây trước khi lấy thông tin tiếp theo
    }

    return 0;
}
