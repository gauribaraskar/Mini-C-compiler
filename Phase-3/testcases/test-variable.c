#include <stdio.h>

int main()
{
    int a;

    // Undeclared Identifier
    a = c + 1;
    {
        int b;
    }
    // Variable out of scope
    a = b;

    // Duplicate variable declaration
    int a;

    // Duplicate variable new scope
    int b[10];

    return 1;
}
