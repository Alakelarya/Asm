#include <iostream>

int main()
{

	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int B[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int C[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int D[10] = { 5,5,5,5,5,5,5,5,5,5 };

	setlocale(LC_CTYPE, "Russian");

	//коды команд


	_asm {
		add eax, ebx //03 C3
		add eax, ecx //03 C1
		mov eax, 3   //B8 03
		mov ebx, 6   //B8 06
		cmp eax, ebx //3B C3
		and ecx, ecx //23 C9
		ror dl,1     //D0 CA
	}

	//Передача массива с командой jl
	_asm {
		mov ecx, 0
		lea ebx, A
		lea edi, B[0]

m1 :    mov eax, [ebx]
		mov[edi], eax
		add ebx, 4
		add edi, 4
		inc ecx
		cmp ecx, 10
		jl m1
	}

	//Передача массива с командой loops
	_asm {

		lea ebx, D
		lea edi, C
		mov ecx, 7
m2:     mov eax, [ebx]
		mov[edi], eax
		add ebx, 4
		add edi, 4
		loop  m2
	}
	_asm mov cx, 0;
	//Передача массива с командой movs
	_asm {

		cld //сборос флага наполнения
		lea esi, A
		lea edi, D

		mov ecx, 20
		rep movsb 
	}

	std::cout << "Полученный массив B = ";
	for (int i = 0; i < 10; i++) {
		std::cout << B[i] << " ";
	}
	std::cout << "\n";

	std::cout << "Полученный массив C = ";
	for (int i = 0; i < 10; i++) {
		std::cout << C[i] << " ";
	}	
	std::cout << "\n";

	std::cout << "Полученный массив D = ";
	for (int i = 0; i < 10; i++) {
		std::cout << D[i] << " ";
	}	std::cout << "\n";

	//getch()

	return 0;
}



