#include <iostream>
#include <typeinfo>

using namespace std;

int main(){
    unsigned char test = 33; // !
    unsigned char overflowTest = 289; // Equivalente a 256 + 33 --> !
    cout << "unsigned char\n" << "Test: " << test << "\noverflowTest: " << overflowTest << "\n";
    cout << "Tamaño de test: " << sizeof test << ". Tamaño de overflowTest: " << sizeof overflowTest << '\n';
    cout << "Tamaño de unsigned char: " << sizeof(unsigned char) << "\n\n";
    /*
    Utilizando el operador sizeof, se obtiene que el tamaño es de 1 byte, 8 bits.
    No obstante, esto se puede verificar notando que si se ingresa el número de 289, ocurre
    un overflow, donde el noveno bit se pierde y queda solo lo que cabe en los 8 bits. Esto ocurre
    porque los números mayores a 256 no caben en 8 bits, por lo que solo queda lo que está en los últimos 8 bits.
    */

    // Verificación del tañamo de signed int

    signed int testNum =  -2147483648; // menor numero posible en 32 bits
    /* Debido al sistema del complemento a 2, el menor número posible en 32 bits es -2147483648, el cual equivale
    a 80 00 00 00 en hexadecimal. Por lo tanto, si se le resta 1, se obtiene el número mayor posible en el rango de 32 bits.
    Esto demuestra el rango total del signed int, el cual equivale al rango máximo de números con 32 bits.
    */
    
    cout << "signed int\n";
    cout << "Tamaño de signed int: " << sizeof(signed int) << ". Tamaño de testNum: " << sizeof testNum << ". testNum: "  << testNum << ".\ntestNum - 1 = " << testNum - 1 << "\n\n";

    // char to unsigned char
    char caracter = 'a';
    cout << "char to unsigned char\n" << "Tipo de caracter "  << caracter << " : " << typeid(caracter).name() << "\n";
    cout << "Tamaño de caracter " << caracter << " : " << sizeof caracter << "\n";

    unsigned char caracterConv = caracter;
    cout << "Tipo de caracterConv "  << caracterConv << " : " << typeid(caracterConv).name() << "\n";
    cout << "Tamaño de caracterConv " << caracterConv << " : " << sizeof caracterConv << "\n\n";

    // float to double
    float flotante = 123.45;
    double doubleConv = flotante;

    cout << typeid(flotante).name() << ' ' << flotante << "\n";
    cout << typeid(doubleConv).name() << ' ' << doubleConv << "\n";
    cout << "float to double char\n" << "Tipo de flotante "  << flotante << " : "<< typeid(caracterConv).name() << "\n";
    cout << "Tamaño de flotante " << flotante << " : " << sizeof flotante << "\n";
    cout << "Tipo de doubleConv "  << doubleConv << " : "<< typeid(doubleConv).name() << "\n";
    cout << "Tamaño de doubleConv " << doubleConv << " : " << sizeof doubleConv << "\n\n";

    // int to char
    int entero = 289;
    char caracterInt = entero;
    int enteroConv = caracterInt;
    cout << "int to char\n" << "Tipo de entero "  << entero << " : "<< typeid(entero).name() << "\n";
    cout << "Tamaño de entero " << entero << " : " << sizeof entero << "\n";
    cout << "Tipo de caracterInt "  << caracterInt << " : "<< typeid(caracterInt).name() << "\n";
    cout << "Tamaño de caracterInt " << caracterInt << " : " << sizeof caracterInt << "\n";
    cout << "Tipo de enteroConv "  << enteroConv << " : "<< typeid(enteroConv).name() << "\n";
    cout << "Tamaño de enteroConv " << enteroConv << " : " << sizeof enteroConv << "\n\n";

    //short to char
    short shortNum = 289;
    char caracterShort = shortNum;
    short shortConv = caracterShort;
    cout << "short to char\n" << "Tipo de shortNum "  << shortNum << " : "<< typeid(shortNum).name() << "\n";
    cout << "Tamaño de shortNum " << shortNum << " : " << sizeof shortNum << "\n";
    cout << "Tipo de caracterShort "  << caracterShort << " : "<< typeid(caracterShort).name() << "\n";
    cout << "Tamaño de caracterShort " << caracterShort << " : " << sizeof caracterShort << "\n";
    cout << "Tipo de shortConv "  << shortConv << " : "<< typeid(shortConv).name() << "\n";
    cout << "Tamaño de shortConv " << shortConv << " : " << sizeof shortConv << "\n\n";

    //int to char32_t
    int entero32 = 827253424;
    char32_t char32Int = entero32;
    int entero32Conv = char32Int;

    cout << "int to char32_t\n" << "Tipo de entero32 "  << entero32 << " : "<< typeid(entero32).name() << "\n";
    cout << "Tamaño de entero32 " << entero32 << " : " << sizeof entero32 << "\n";
    cout << "Tipo de char32Int "  << char32Int << " : "<< typeid(char32Int).name() << "\n";
    cout << "Tamaño de char32Int " << char32Int << " : " << sizeof char32Int << "\n";
    cout << "Tipo de entero32Conv "  << entero32Conv << " : "<< typeid(entero32Conv).name() << "\n";
    cout << "Tamaño de entero32Conv " << entero32Conv << " : " << sizeof entero32Conv << "\n\n";

    // int to bool
    int enteroBool = 0;
    bool booleano = enteroBool;
    int boolInt = booleano;

    cout << "int to bool\n" << "Tipo de enteroBool "  << enteroBool << " : "<< typeid(enteroBool).name() << "\n";
    cout << "Tamaño de enteroBool " << enteroBool << " : " << sizeof enteroBool << "\n";
    cout << "Tipo de booleano "  << booleano << " : "<< typeid(booleano).name() << "\n";
    cout << "Tamaño de booleano " << booleano << " : " << sizeof booleano << "\n";
    cout << "Tipo de boolInt "  << boolInt << " : "<< typeid(boolInt).name() << "\n";
    cout << "Tamaño de boolInt " << boolInt << " : " << sizeof boolInt << "\n\n";

}

// 0111 1111 1111 1111