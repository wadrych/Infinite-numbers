#include "NumbersArray.h"

NumbersArray::NumbersArray() {
    indexOfMax = 0;
    indexOfMin = 0;
}

NumbersArray::~NumbersArray() {
    for (int i = 0; i < recordsAmount; i++) {
        numbersArray[i]->DeleteNumber();
        delete numbersArray[i];
    }
    delete[] numbersArray;
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
    numbersArray = new Number*[recordsAmount];
	for(int i = 0; i < recordsAmount; i++) {
        numbersArray[i] = new Number;
	}
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
    numbersArray[indexOfMax]->WriteNumber();
}

void NumbersArray::WriteMin() {
    numbersArray[indexOfMin]->WriteNumber();
}

void NumbersArray::Add(int index1, int index2)
{
	
}
