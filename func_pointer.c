
#include <stdio.h>
//con tro ham la cai gi: chua dia chi cua 1 ham void function1()
void function1(){
	printf("toi la function1 \r\n");
}
void function2()
{
	printf("toi la function2 \r\n");
}
void main(){
	void (*con_tro_ham)();
	con_tro_ham = function1; 
	con_tro_ham();
}
