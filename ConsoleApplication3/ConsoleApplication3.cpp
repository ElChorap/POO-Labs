#include "pch.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    unsigned contor = 0; int div1 = 0;
    try {
        for (contor; contor < 5; contor++)
        {
            Console::WriteLine("test Test Test {0},{1}", "Hello World", contor);
        }
        double div = contor / div1;
        Console::WriteLine(div);
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("0 exceptie" + ex->Message);
    }


    return 0;
}
