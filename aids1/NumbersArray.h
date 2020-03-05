#pragma once

#include <stdio.h>

#include "Number.h"
#include "Comparer.h"

class NumbersArray
{
private:
    Number** numbersArray;
    Comparer comparer;
    int recordsAmount;
    int indexOfMax;
    int indexOfMin;

    void GetRecordsAmountFromUser();
    void InitializeNumbersArray();
    void PopulateArrayWithNumbersFromUser();
    void AddNewNumberAndCompareToExtremes(int position);
    void CompareToExtremes(int currentIndex);
    void CompareToMax(int currentIndex);
    void CompareToMin(int currentIndex);

public:
    NumbersArray();
    ~NumbersArray();

    void Create();
    void WriteAll();
    void WriteMax();
    void WriteMin();
    void Add(int index1, int index2);
};
