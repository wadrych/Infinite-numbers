#include "NumbersArray.h"

NumbersArray::NumbersArray() {
    indexOfMax = 0;
    indexOfMin = 0;
    indexOfLastMax = 0;
    indexOfLastMin = 0;
    recordsAmount = 0;
    numbersArray = NULL;
}

NumbersArray::~NumbersArray() {
    for (int i = 0; i < recordsAmount; i++) {
        DeleteNumber(i);
    }
    delete[] numbersArray;
}

void NumbersArray::DeleteNumber(int index) {
    numbersArray[index]->DeleteNumber();
    delete numbersArray[index];
}

void NumbersArray::Create() {
    GetRecordsAmountFromUser();
    InitializeNumbersArray();
    PopulateArrayWithNumbersFromUser();
}

void NumbersArray::GetRecordsAmountFromUser() {
    scanf_s("%i\n", &recordsAmount);
}

void NumbersArray::InitializeNumbersArray() {
    InitializeArray();
    InitializeNumbers();
}

void NumbersArray::InitializeArray() {
    numbersArray = new Number*[recordsAmount];
}

void NumbersArray::InitializeNumbers() {
	for(int i = 0; i < recordsAmount; i++) {
        InitializeNumber(i);
	}
}

void NumbersArray::InitializeNumber(int index) {
    numbersArray[index] = new Number;
}

void NumbersArray::PopulateArrayWithNumbersFromUser() {
    for (int i = 0; i < recordsAmount; i++) {
        AddNewNumberAndCompareToExtremes(i);
    }
}

void NumbersArray::AddNewNumberAndCompareToExtremes(int position) {
    numbersArray[position]->CreateNumber();
    CompareToExtremes(position);
}

void NumbersArray::CompareToExtremes(int currentIndex) {
    CompareToMax(currentIndex);
    CompareToMin(currentIndex);
}

void NumbersArray::CompareToMax(int currentIndex) {
    comparer.SetCurrentNumber(numbersArray[currentIndex]);
    comparer.SetComparedToNumber(numbersArray[indexOfMax]);

    if (comparer.IsBigger() || comparer.IsTheSame()) {
        indexOfMax = currentIndex;
    }
}

void NumbersArray::CompareToMin(int currentIndex) {
    comparer.SetCurrentNumber(numbersArray[currentIndex]);
    comparer.SetComparedToNumber(numbersArray[indexOfMin]);

    if (comparer.IsLower() || comparer.IsTheSame()) {
        indexOfMin = currentIndex;
    }
}

void NumbersArray::WriteAll() {
    for (int i = 0; i < recordsAmount; i++) {
        numbersArray[i]->WriteNumber();
    }
}

void NumbersArray::WriteMax() {
    indexOfMax = 0;
    indexOfMin = 0;
	for(int i=1;i<recordsAmount;i++)
	{
        CompareToMax(i);
	}
    numbersArray[indexOfMax]->WriteNumber();
}

void NumbersArray::WriteMin() {
    indexOfMax = 0;
    indexOfMin = 0;
    for (int i = 1; i < recordsAmount; i++)
    {
        CompareToMin(i);
    }
    numbersArray[indexOfMin]->WriteNumber();
}

void NumbersArray::Add(int index1, int index2, int destination) {
    Number* oldNumber = numbersArray[destination];

    numbersArray[destination] = calculator.Add(numbersArray[index1], numbersArray[index2]);
    CompareToExtremes(destination);
    delete oldNumber;
}

void NumbersArray::Subtract(int index1, int index2, int destination) {
    Number* oldNumber = numbersArray[destination];
	
    numbersArray[destination] = calculator.Subtract(numbersArray[index1], numbersArray[index2]);
    CompareToExtremes(destination);
    delete oldNumber;
}
