#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <MQTTClient.h>

#define ADDRESS     "tcp://localhost:1883"
#define CLIENTID    "ExampleClient"
#define TOPIC       "system_info"
#define QOS         1
#define TIMEOUT     10000L

char* generate_client_id() {
    char* id = (char*)malloc(32);
    sprintf(id, "Client_%d", rand());
    return id;
}

double get_cpu_usage() {
    FILE* fp = popen("top -bn1 | awk '/%Cpu/ {print $2 + $4}'", "r");
    if (fp == NULL) {
        perror("Error executing CPU command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

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

double get_disk_usage() {
    FILE* fp = popen("df | awk '/dev\\/sda1/ {print $5}'", "r");
    if (fp == NULL) {
        perror("Error executing Disk command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

char* create_json(double cpu_usage, double ram_usage, double disk_usage) {
    char* json = (char*)malloc(256);
    sprintf(json, "{\"CPU Usage\": %.2f, \"RAM Usage\": %.2f, \"Disk Usage\": %.2f}", cpu_usage, ram_usage, disk_usage);
    return json;
}

void publish_data(MQTTClient client, double cpu_usage, double ram_usage, double disk_usage) {
    char* json_data = create_json(cpu_usage, ram_usage, disk_usage);
	printf("JSON Data: %s\n", json_data);
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = json_data;
    pubmsg.payloadlen = strlen(json_data);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, TIMEOUT);

    free(json_data);
}

int main() {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    char* client_id = generate_client_id();

    MQTTClient_create(&client, ADDRESS, client_id,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS) {
        fprintf(stderr, "Failed to connect to MQTT broker\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        double cpu_usage = get_cpu_usage();
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        double ram_usage = get_ram_usage();
        printf("RAM Usage: %.2f%%\n", ram_usage);

        double disk_usage = get_disk_usage();
        printf("Disk Usage: %.2f%%\n", disk_usage);

        publish_data(client, cpu_usage, ram_usage, disk_usage);

        sleep(1);  // Delay 1 giây trước khi lấy thông tin tiếp theo
    }

    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    free(client_id);

    return 0;
}
