#include "digit.h"

Digit::Digit() {
}

Digit::~Digit() {
}

bool Digit::IsEndOfLine() {
    return digit == '\n';
}

void Digit::ReadNext() {
    digit = _getchar_nolock();
}

char Digit::GetDigit() {
    return digit;
}