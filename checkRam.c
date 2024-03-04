#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Khai báo biến
int user = 0;
int system = 0;
int idle = 0;

char* floatToString(double input_num) {
    // Chuyển đổi số kiểu double thành chuỗi
    char* str = (char*)malloc(16);
    snprintf(str, 16, "%.3f", input_num);
    return str;
}

void sleep_ms(int ms) {
    usleep(ms * 1000); // Chuyển đổi mili giây sang micro giây
}

int main() {
    while (1) {
        sleep_ms(2000);
        FILE* fp = popen("cat /proc/stat | grep 'cpu '", "r");
        if (fp == NULL) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }

        char out[128];
        if (fgets(out, sizeof(out), fp) != NULL) {
            int x, y, z;
            sscanf(out, "%*s %d %*s %*s %d %*s %d", &x, &y, &z);

            printf("Old: %d\t%d\t%d\n", user, system, idle);

            user = x - user;
            system = y - system;
            idle = z - idle;
            double avg = ((double)(user + system) * 100) / (user + system + idle);

            printf("New: %d\t%d\t%d\n", x, y, z);
            printf("Sub: %d\t%d\t%d\n", user, system, idle);
            printf("Persen: %f\n\n", avg);

            char* payload = floatToString(avg);
            printf("%s\n", payload);

            free(payload);

            user = x;
            system = y;
            idle = z;
        }

        pclose(fp);
    }

    return 0;
}

