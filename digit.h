#pragma once

#include "stdio.h"
#include "stdlib.h"

class Digit
{
private:
    char digit;
public:
    Digit();
    ~Digit();

    bool IsEndOfLine();
    void ReadNext();
    char GetDigit();
    void ClearInputBuffor();

};