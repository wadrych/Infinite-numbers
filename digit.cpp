#include "digit.h"

Digit::Digit(){
}

Digit::~Digit(){
}

bool Digit::IsEndOfLine() {
    return digit == '\n';
}

void Digit::ReadNext() {
    digit = getchar_unlocked();
}

char Digit::GetDigit() {
    return digit;
}