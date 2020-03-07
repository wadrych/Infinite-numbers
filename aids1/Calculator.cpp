#include "Calculator.h"

Calculator::Calculator(){
    addend1 = NULL;
    addend2 = NULL;
    minuend = NULL;
    subtrahend = NULL;
}

Calculator::~Calculator(){
    addend1 = NULL;
    addend2 = NULL;
    minuend = NULL;
    subtrahend = NULL;
}

Number* Calculator::Add(Number* number1, Number* number2)
{
    Comparer comparer;
    comparer.SetCurrentNumber(number1);
    comparer.SetComparedToNumber(number2);

	if(comparer.BothHaveTheSameSymbol()) {
        return additor.Add(number1, number2);
	}
    else {
	    return subtractor.Subtract(number1, number2);
    }
}

Number* Calculator::Subtract(Number* number1, Number* number2)
{
    Comparer comparer;
    comparer.SetCurrentNumber(number1);
    comparer.SetComparedToNumber(number2);

    if (comparer.BothHaveTheSameSymbol()) {
        return subtractor.Subtract(number1, number2);
    }
    else {
        return additor.Add(number1, number2);
    }
}
