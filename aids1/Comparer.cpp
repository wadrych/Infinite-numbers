#include "Comparer.h"

Comparer::Comparer() {
}

Comparer::~Comparer() {
}

void Comparer::SetCurrentNumber(Number* currentNumber) {
    this->currentNumber = currentNumber;
}

void Comparer::SetComparedToNumber(Number* comparedToNumber) {
    this->comparedToNumber = comparedToNumber;
}

bool Comparer::IsBigger() {
    if (BothHaveTheSameSymbol()) {
        return CompareLength();
    }
    else {
        return currentNumber->IsPositive();
    }
}

bool Comparer::IsLower() {
    return !IsBigger();
}

bool Comparer::BothHaveTheSameSymbol() {
    if (BothAreNegative() || BothArePositive()) {
        return true;
    }

    return false;
}

bool Comparer::BothAreNegative() {
    return (currentNumber->IsNegative() && comparedToNumber->IsNegative());
}

bool Comparer::BothArePositive() {
    return (currentNumber->IsPositive() && comparedToNumber->IsPositive());
}

bool Comparer::CompareLength() {
    if (IsTheSameLength()) {
        return CompareSignificantFigures();
    }
    else if (currentNumber->IsPositive()) {
        return IsLonger();
    }
    else if (currentNumber->IsNegative()) {
        return IsShorter();
    }

    return false;
}

bool Comparer::CompareSignificantFigures() {
    int indexOfDifference = FindDifferentDigit();

    return DecideIfNumberIsHigher(indexOfDifference);
}

int Comparer::FindDifferentDigit() {
    int i = 0;

    for (i; i < currentNumber->GetLength(); i++) {
        if (currentNumber->GetDigit(i) != comparedToNumber->GetDigit(i)) {
            break;
        }
    }

    return i;
}

bool Comparer::DecideIfNumberIsHigher(int index) {
    if (DigitIsHigher(index) && currentNumber->IsPositive()) {
        return true;
    }
    else if (DigitIsLower(index) && currentNumber->IsPositive()) {
        return false;
    }
    else if (DigitIsHigher(index) && currentNumber->IsNegative()) {
        return false;
    }
    else if (DigitIsLower(index) && currentNumber->IsNegative()) {
        return true;
    }
    return false;
}

bool Comparer::DigitIsHigher(int index) {
    return currentNumber->GetDigit(index) > comparedToNumber->GetDigit(index);
}

bool Comparer::DigitIsLower(int index) {
    return currentNumber->GetDigit(index) < comparedToNumber->GetDigit(index);
}

bool Comparer::IsLonger() {
    return currentNumber->GetLength() > comparedToNumber->GetLength();
}

bool Comparer::IsShorter() {
    return !IsLonger();
}

bool Comparer::IsTheSameLength() {
    return currentNumber->GetLength() == comparedToNumber->GetLength();
}

bool Comparer::IsTheSame() {
    if (IsTheSameLength()) {
        return IsTheSameDigits();
    }
    else {
        return false;
    }
}

bool Comparer::IsTheSameDigits() {
    for (int i = 0; i < currentNumber->GetLength(); i++) {
        if (currentNumber->GetDigit(i) != comparedToNumber->GetDigit(i)) {
            return false;
        }
    }
    return true;
}