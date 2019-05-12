#include <iostream>
#include <assert.h>
#include <cstdint>
#include <cstring>
using namespace std;

char nibble_to_hex (uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char symbols []="0123456789abcdef";
    return symbols[i];
}

void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

const uint8_t*
as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}

void
print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

char
bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}

void
print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 7; bit >= 0; bit--)
    {
        cout << bit_digit(byte, bit);
        if (bit==0)
            return;
    }
}

void
print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

void byte_calc (uint16_t op1, char operat, uint16_t op2)
{
    print_in_hex (&op1, sizeof(op1));
    cout<<operat<<" ";
    print_in_hex (&op2, sizeof(op2));
    cout<<'=';
    uint16_t byteand = op1 & op2;
    uint16_t byteor = op1 | op2;
    uint16_t bytexor = op1 ^ op2;
    if (operat=='&')
    {
        print_in_hex(&byteand, sizeof(byteand) );
        cout << "\n";
        print_in_binary( &op1, sizeof(op1) );
        cout << "& ";
        print_in_binary( &op2, sizeof(op2));
        cout << "= ";
        print_in_binary( &byteand, sizeof(byteand) );
        return;
    }
    if(operat=='|')
    {
        print_in_hex( &byteor, sizeof(byteor) );
        cout << "\n";
        print_in_binary( &op1, sizeof(op1) );
        cout << "| ";
        print_in_binary( &op2, sizeof(op2) );
        cout << "= ";
        print_in_binary( &byteor, sizeof(byteor) );
        return;
    }
    if (operat=='^')
    {
        print_in_hex( &bytexor, sizeof(bytexor) );
        cout << "\n";
        print_in_binary( &op1, sizeof(op1) );
        cout << "^ ";
        print_in_binary( &op2, sizeof(op2) );
        cout << "= ";
        print_in_binary( &bytexor, sizeof(bytexor) );
        return;
    }
}

struct Student
{
    char name [17];
    uint16_t year;
    float average;
    uint8_t gender: 1;
    uint8_t courses;
    Student* starosta;
};

int main()
{
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
    Student students[3]={{"Ilya", 18, 4.5, 1, 1, &students[0]}, {"Nastya", 18, 3.7, 0, 1, nullptr}, {"Olya", 18, 4.6, 0, 1, &students[0]}};
    cout << "Adres massiva: " << &students
         << "\nRazmer massiva: " << sizeof(students)
         << "\nHexadecimal: ";
    cout << "\n\nAdres elementa massiva: " << &students[0]
         << "\nRazmer elementa massiva: " << sizeof(students[0]);
    print_in_hex( &students[0], sizeof( students[0] ) );
    cout << "\n\nAdres elementa massiva: " << &students[1]
         << "\nRazmer elementa massiva: " << sizeof(students[1])
         << "\nHexadecimal: ";
    print_in_hex( &students[1], sizeof( students[1] ) );
    cout << "\n\nAdres elementa massiva: " << &students[2]
         << "\nRazmer elementa massiva: " << sizeof(students[2])
         << "\nHexadecimal: ";
    print_in_hex( &students[2], sizeof( students[2] ) );

    cout << "\n\nDlya pervogo elementa massiva:" << endl;

    cout << "\nName:"
         << "\nAdres: " << &students[0].name
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, name )
         << "\nRazmer: " << sizeof( students[0].name )
         << "\nBinary: ";
    print_in_binary( &students[0].name, sizeof( students[0].name ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[0].name, sizeof( students[0].name ) );

    cout << "\n\nYear:"
         << "\nAdres: " << &students[0].year
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, year )
         << "\nRazmer: " << sizeof( students[0].year )
         << "\nBinary: ";
    print_in_binary( &students[0].year, sizeof( students[0].year ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[0].year, sizeof( students[0].year ) );

    cout << "\n\nAverage:"
         << "\nAdres: " << &students[0].average
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, average )
         << "\nRazmer: " << sizeof( students[0].average )
         << "\nBinary: ";
    print_in_binary( &students[0].average, sizeof( students[0].average ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[0].average, sizeof( students[0].average ) );

    cout << "\n\nCourses:"
         << "\nAdres: " << &students[0].courses
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, courses )
         << "\nRazmer: " << sizeof( students[0].courses )
         << "\nBinary: ";
    print_in_binary( &students[0].courses, sizeof( students[0].courses ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[0].courses, sizeof( students[0].courses ) );

    cout << "\n\nStarosta:"
         << "\nAdres: " << &students[0].starosta
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, starosta )
         << "\nRazmer: " << sizeof( students[0].starosta )
         << "\nBinary: ";
    print_in_binary( &students[0].starosta, sizeof( students[0].starosta ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[0].starosta, sizeof( students[0].starosta ) );
}
