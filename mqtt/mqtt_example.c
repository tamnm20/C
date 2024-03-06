#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MQTTClient.h>

#define ADDRESS     "tcp://localhost:1883"
#define CLIENTID    "ExampleClient"
#define TOPIC       "test"
#define PAYLOAD     "Hello from Raspberry Pi!"
#define QOS         1
#define TIMEOUT     10000L

char* generate_client_id() {
    char* id = (char*)malloc(32);
    sprintf(id, "Client_%d", rand());
    return id;
}

int main() {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;

    char* client_id = generate_client_id();

    MQTTClient_create(&client, ADDRESS, client_id,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS) {
        fprintf(stderr, "Failed to connect to MQTT broker\n");
        exit(EXIT_FAILURE);
    }

    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;

    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
           "on topic %s for client with ClientID: %s\n",
           (int)(TIMEOUT/1000), PAYLOAD, TOPIC, client_id);

    MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);

    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    free(client_id);

    return EXIT_SUCCESS;
}
