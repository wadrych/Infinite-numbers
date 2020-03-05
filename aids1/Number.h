#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "Digit.h"
#include <cinttypes>

/*typedef struct DigitsList {
    uint_fast8_t digit;
    DigitsList* nextDigit;
} DigitsList;
*/
class Number
{
private:
    const int doubleSize = 2;

    char* number;
    Digit digit;
    size_t numberOfDigits;
    size_t digitsArraySize;

    void CreateDigitsArray();
    void ClearDigitsArray(int beginning = 0);
    void AppendNewDigit();
    void CloseNumberArray();
    void AddNextDigitToArray();
    void ExtendDigitsArray();
    void ExitProgram();
    void AddNewDigit();
    bool DigitsArrayIsFull();
    char* CreateNewDoubledArray();

	
    //bool isPositive;
   // DigitsList* digitList;

public:
    Number();
    ~Number();

    void WriteNumber();
    void CreateNumber();
    void DeleteNumber();

    bool IsPositive();
    bool IsNegative();
    char* GetNumber();
    size_t GetLength();
};

