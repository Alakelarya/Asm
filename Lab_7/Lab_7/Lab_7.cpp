#include <iostream>

int main()
{
    float k = 9.6f, l = 0.2f, m = 5.9f,sum,nan, pr;
    short cwword;
    _asm {
        finit
        //сумма 3х чисел
        fld k                   // добавляем в стек k
        fld l                   // добавляем в стек l
        fld m                   // добавляем в стек m
        fadd                    //складывем k+l+m
        fadd
        fstp sum                // сохраняем результат в sum
        //NaN, исключений не будет потому что они по умолчанию отключены 
        fld l                   // кладем в стек l
        fldz                   // кладем в стек 0 
        fdiv                    // делим а/0
        fstp nan                // сохраняем результат в nan
    //    //вызывающая и реагирующая на особый случай
        fld m                   // кладем в стек m
        fldz                    //кладем в стек 0
        fstcw cwword              //запомнить слово усправления
        not cwword                // проставляем разряд чтобы включить исключения
        or cwword,1               //оставляем 3ий бит
        not cwword                //ставим в качестве регистра упавления наше новое значеие
 //       fldcw cwword              //деление на 0 - исключение
        fdiv
        fstp pr
        fld pr
        fld pr
        fldcw cwword
   
        fdiv
        fstp pr
    }
    std::cout << sum<< '\n';
    std::cout << nan << '\n';

}
