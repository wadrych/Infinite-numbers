#pragma once

#include "number.h"

class Comparer
{
public:
    Comparer();
    ~Comparer();

    bool IsBigger();
    bool IsLower();
    bool IsTheSame();

    void SetCurrentNumber(Number* currentNumber);
    void SetComparedToNumber(Number* comparedToNumber);
	
private:
    Number* currentNumber;
    Number* comparedToNumber;


    bool BothHaveTheSameSymbol();
    bool BothAreNegative();
    bool BothArePositive();
    bool IsLonger();
    bool IsShorter();
    bool IsTheSameLength();
    bool CompareLength();
    bool CompareSignificantFigures();
    bool DigitIsHigher(int index);
    bool DigitIsLower(int index);
    bool DecideIfNumberIsHigher(int index);
    bool IsTheSameDigits();
    int FindDifferentDigit();
};
