#pragma once

#include "Number.h"
#include "Additor.h"
#include "Subtractor.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();

    Number* Add(Number* number1, Number* number2);
    Number* Subtract(Number* number1, Number* number2);

private:
    Additor additor;
    Subtractor subtractor;
    Number* addend1;
    Number* addend2;
    Number* minuend;
    Number* subtrahend;
};
