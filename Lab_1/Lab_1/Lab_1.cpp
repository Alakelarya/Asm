#include <iostream>

int main(){
	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int B[10] = { 0,0,0,0,0,0,0,0,0,0 }; 
	
	//коды команд
	__asm {
		add eax, ebx //03c3
		add eax, ecx //03c1

	}

	//Передача массива с командой ja/dl
	_asm {
		lea ebx, A
		lea edi, B[0]
		mov ecx, 0
m1:		mov eax, [ebx]
		mov [edi], eax
		add ebx, 4
		add edi, 4
		inc ecx
		cmp ecx, 5
		jl m1
	}

	//Передача массива с командой loops
	//_asm {
		//mov ecx, 10
		//m2:

	
	//loop  m2}

	//Передача массива с командой movs
//	__asm {
//		lea ebx, A
//		cld //сборос флага наполнения
//		lea esi, A
//	}

	//_asm rep movs;

	for (int i = 0; i < 10; i++) {
		std::cout << B[i] << " ";
	}
	return 0;
}

