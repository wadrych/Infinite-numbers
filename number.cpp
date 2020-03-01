#include "number.h"

Number::Number() {
    numberOfDigits = 0;
    digitsArraySize = 50;

    CreateDigitsArray();
    ClearDigitsArray();
}

void Number::CreateDigitsArray() {
    number = (char*)malloc(digitsArraySize * sizeof(char));
}

void Number::ClearDigitsArray(int beginning) {
    for(int i = beginning; i < digitsArraySize; i++) {
        number[i] = '\0';
    }
}

Number::~Number() {
}

void Number::WriteNumber() {
    printf("%s \n", number);
}

void Number::CreateNumber() {
    digit.ClearInputBuffor();

    while(!digit.IsEndOfLine()) {
        AddNextDigitToArray();
    }
}

void Number::AddNextDigitToArray() {
    digit.ReadNext();
    
    if(!digit.IsEndOfLine()) {
        AppendNewDigit();
    }
}

void Number::AppendNewDigit() {
    if(DigitsArrayIsFull()) {
        ExtendDigitsArray();
    }
    AddNewDigit();
}

bool Number::DigitsArrayIsFull() {
    return digitsArraySize == numberOfDigits;
}

void Number::ExtendDigitsArray() {
    int previousSizeOfArray = digitsArraySize;
    char* tempNumber;

    tempNumber = CreateNewDoubledArray();
    if(!tempNumber) {
        ExitProgram();
    }
    number = tempNumber;
    ClearDigitsArray(previousSizeOfArray);
}

char* Number::CreateNewDoubledArray() {
    digitsArraySize *= doubleSize;

    return (char*)realloc(number, digitsArraySize);
}

void Number::ExitProgram(){
    DeleteNumber();
    exit(0);
}
void Number::DeleteNumber() {
    delete number;
}

void Number::AddNewDigit() {
    number[numberOfDigits] = digit.GetDigit();
    numberOfDigits++;
}

bool Number::IsPositive() {
    return (number[0] != '-');
}

bool Number::IsNegative() {
    return !IsPositive();
}

size_t Number::GetLength() {
    return numberOfDigits;
}

char* Number::GetNumber() {
    return number;
}