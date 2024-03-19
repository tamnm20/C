#include <stdio.h>

typedef struct message
{
	char head_byte;
	short message_id;
	unsigned int length;
} message_header;

void receive_data(void *buffer)
{
	message_header m;
	if(7==sizeof(m))	{
		m= *((message_header *)buffer);
		printf("length m = %d \n", m.length);
	}

}

int main()
{
	message_header m1;
	m1.length =99;
	receive_data(&m1);
	
	return 0;
}