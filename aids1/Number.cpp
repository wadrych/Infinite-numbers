#include "Number.h"

Number::Number() {
    numberOfDigits = 0;
    isPositive = true;
    firstDigit = NULL;
    lastDigit = NULL;
    buffer = NULL;
    isInitiated = false;
}

Number::~Number() {
}

void Number::WriteNumber() {
    DigitsList* current = firstDigit;

	if(IsNegative()) {
        printf("-");
	}
	
    do {
        printf("%c", (char)current->digit);
        current = current->nextDigit;
    } while (current != NULL);
    printf("\n");
}

void Number::CreateNumber() {
    ReadNextCharToBuffer();
    while (IsNotEOL()) {
        CreateNextDigit();
	}
}
bool Number::IsNotEOL()
{
    return buffer != '\n';
}

void Number::CreateNextDigit()
{
    if (!isInitiated) {
        InitiateNumber();
    }
    else {
        AddNewDigit();
    }
	
    ReadNextCharToBuffer();
}

void Number::ReadNextCharToBuffer()
{
    buffer = _getchar_nolock();
}

void Number::InitiateNumber()
{
    DetermineSymbol();
    if (isPositive) {
        AddNewDigit();
    }
    isInitiated = true;
}

void Number::DetermineSymbol()
{
	if(buffer == '-') {
        isPositive = false;
	}
    else {
        isPositive = true;
    }
}

void Number::AddNewDigit() {
    CreateNewListElement();
    AppendNewDigitToList();
}

void Number::CreateNewListElement()
{
	if(IsEmpty()) {
        InitiateList();
	}
    else {
        lastDigit->nextDigit = new DigitsList;
        lastDigit = lastDigit->nextDigit;
    }
}

bool Number::IsEmpty()
{
    return  numberOfDigits == 0;
}


void Number::InitiateList()
{
    firstDigit = new DigitsList;
    firstDigit->nextDigit = NULL;
    lastDigit = firstDigit;
}

void Number::AppendNewDigitToList()
{
    lastDigit->digit = (uint_fast8_t)buffer;
    lastDigit->nextDigit = NULL;
    numberOfDigits++;
}


void Number::DeleteNumber() {
    DigitsList* current = firstDigit;
	
    while (current != NULL) {
        DigitsList* temp = current->nextDigit;
        delete current;
        current = temp;
    }
}

bool Number::IsPositive() {
    return isPositive;
}

bool Number::IsNegative() {
    return !isPositive;
}

size_t Number::GetLength() {
    return numberOfDigits;
}

char Number::GetDigit(int index) {
    DigitsList* searched_digit = firstDigit;
    for(int i=0;i<index-1;i++) {
        searched_digit = searched_digit->nextDigit;
    }

    return (char)searched_digit->digit;
}