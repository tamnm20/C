#include <stdio.h>

// function prototypes
int foo();
double goo();
int hoo();

//function pointer assignments
int (*funcPtr1)() = foo; //okay
//int (*funcPtr2)() = goo; //wrong -- return types don't match!
double (*funcPtr3) = goo; //okay
//funcPtr4 = hoo; //wrong -- fcnPtr4 has no parameters, but hoo()
int (*funcPtr5)(int) = hoo; //okay

void FuncA(void);
void FuncB(void);
void FuncC(void);
void FuncD(void);

typedef void(* pFunc)(void);

int main()
{
	struct pFunc list_func[] = {FuncA, FuncB, FuncC, FuncD};
	
	list_func[0]; //Excecute FuncA
	list_func[1];
	list_func[2];
	list_func[3];
	
	return 0;
}