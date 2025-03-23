#include <stdio.h>
#include <stdint.h>

#define MAX_NumOfSID 5
#define MAX_NumOfSID_Map 9
typedef void (*func_test)(void);

void action0(){printf("active action0, data = 1\n");}
void action1(){printf("active action1, data = 3\n");}
void action2(){printf("active action2, data = 4\n");}
void action3(){printf("active action3, data = 7\n");}
void action4(){printf("active action4, data = 9\n");}

uint8_t Sid_map[MAX_NumOfSID_Map] = {0xff,0x00,0xff,0x01,0x02,0xff,0xff,0x03,0xff,0x04};

func_test lookup_table[MAX_NumOfSID] = {action0,action1, action2, action3, action4};

void callback(uint8_t sid){
    lookup_table[sid]();
}

int main()
{
    
    int data = 4;
    callback(Sid_map[data]);
    return 0;
}