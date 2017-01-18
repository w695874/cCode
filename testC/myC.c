#include "stdio.h"
#include "ntdef.h"

VOID _stdcall showHello(){
printf("hello world");
}
VOID showHello2(){
	printf(" goodbye hook");
}

VOID _declspec(naked) _stdcall show(){
	_asm{
		push ebp
		mov ebp,esp

		call showHello

		pop ebp
		retn
	}
}


VOID main(){

 show();
 getchar();
}