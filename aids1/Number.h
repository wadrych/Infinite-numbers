#pragma once

#include "stdio.h"
#include "stdlib.h"
#include <cinttypes>

typedef struct DigitsList {
    uint_fast8_t digit;
    DigitsList* nextDigit;
    DigitsList* previousDigit;
} DigitsList;

class Number
{
public:
    Number();
    ~Number();

    void WriteNumber();
    void CreateNumber();
    void DeleteNumber();
    void PushDigitToStart(uint_fast8_t digit);

    bool IsPositive();
    bool IsNegative();
    char GetDigit(int index);
    size_t Length();
    void InitiateCursor();
    uint_fast8_t GetNextDigit();
    void InverseSymbol();
    void CleanZerosInfront();
	
private:
    bool isPositive;
    bool isInitiated; 
    DigitsList* firstDigit;
    DigitsList* lastDigit;
    size_t numberOfDigits;
    char buffer;
    DigitsList* cursor;

    void ReadNextCharToBuffer();
    void DetermineSymbol();
    void InitiateList();
    void AppendNewDigitFromBufferToList();
    bool IsNotEOL();
    void CreateNextDigit();
    void InitiateNumber();
    void AddNewDigit();
    void CreateNewListElement();
    bool IsEmpty();
    void PrintSymbol();
    void PrintDigits();
    void DeleteDigit(DigitsList* &digit);
};

