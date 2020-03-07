#pragma once

#include <cinttypes>
#include "Number.h"
#include "Comparer.h"

class Subtractor
{
public:
    Subtractor();
    ~Subtractor();

    Number* Subtract(Number* number1, Number* number2);
private:
    Number* minuend;
    Number* subtrahend;

    Comparer comparer;
};