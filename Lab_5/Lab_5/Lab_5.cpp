#include <iostream>
long long var1, var2;
long long shift_stack(long long a, long long& b) {
    _asm {
        mov eax, [ebp + 8]              // читаем аргумент функции в eax
        shl eax, 1                      // сдвиг младших разрядов влево, логический сдвиг ax на 1 бит влево
        mov ebx, [ebp + 12]             // читаем старшие разряды а
        rcl ebx, 1                      // сдвиг старших разрядов влево с учетом бита переноса, циклический сдвиг bx на 1 бит влево
        mov esi, [ebp + 16]             // читаем адрес &b, записываем в esi
        mov [esi], eax                   // младшие разряды а из eax записываем в [esi]
       mov [esi + 4], ebx               // старшие а разряды из ebx записываем в [esi + 4](читаем ip)
    }
}
long long shift_register() {
    _asm {

        mov eax, [ebx]
        mov edx, [ebx + 4]
        rcl edx, 1
        shl eax, 1
    }
}
long long shift_global() {
    _asm {
        lea esi, var1
        mov ebx, [esi]
        shl ebx, 1
        mov eax, [esi+4]
        rcl eax, 1
        lea esi, var2
        mov[esi+4], eax
        mov[esi], ebx
    }
}

//&b--- a---  eip--- ebp
int main()
{
    setlocale(LC_ALL, "rus");
    long long a;
    long long b;

    std::cout << "Введите значение - ";
    std::cin >> a;

    //через стек
    var1 = shift_stack(a, b);
    std::cout << "Сдвиг через стек - " << b << '\n';
    //через регистры

    _asm    lea ebx, a
    std::cout << "Сдвиг через регистры - " << shift_register() << '\n';
    //через общую область памяти
    var1 = a;
    shift_global();
    std::cout << "Сдвиг через общую область памяти - " << var2 << '\n';

    return 0;
}