#pragma once

#include "Number.h"
#include "Additor.h"
#include "Substractor.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();

    void Add(Number* number1, Number* number2);
    void Substract(Number* number1, Number* number2);

private:
    Additor additor;
    Substractor substractor;
    Number* addend1;
    Number* addend2;
    Number* minuend;
    Number* subtrahend;
};
