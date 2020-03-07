#pragma once

#include <stdio.h>

#include "Number.h"
#include "Comparer.h"
#include "Calculator.h"

class NumbersArray
{
public:
    NumbersArray();
    ~NumbersArray();

    void Create();
    void WriteAll();
    void WriteMax();
    void WriteMin();
    void Add(int index1, int index2, int destination);
    void Subtract(int index1, int index2, int destination);
	
private:
    Number** numbersArray;
    Comparer comparer;
    Calculator calculator;
	
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
    void DeleteNumber(int index);
    void InitializeNumber(int index);
    void InitializeNumbers();
    void InitializeArray();
};
