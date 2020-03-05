#pragma once

#include "stdio.h"
#include "stdlib.h"
#include <cinttypes>

typedef struct DigitsList {
    uint_fast8_t digit;
    DigitsList* nextDigit;
} DigitsList;

class Number
{
public:
    Number();
    ~Number();

    void WriteNumber();
    void CreateNumber();
    void DeleteNumber();

    bool IsPositive();
    bool IsNegative();
    char GetDigit(int index);
    size_t GetLength();
	
private:
    bool isPositive;
    bool isInitiated; 
    DigitsList* firstDigit;
    DigitsList* lastDigit;
    size_t numberOfDigits;
    char buffer;

    void ReadNextCharToBuffer();
    void DetermineSymbol();
    void InitiateList();
    void AppendNewDigitToList();
    bool IsNotEOL();
    void CreateNextDigit();
    void InitiateNumber();
    void AddNewDigit();
    void CreateNewListElement();
    bool IsEmpty();
};

