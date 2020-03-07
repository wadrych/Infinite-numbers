#include "Subtractor.h"

Subtractor::Subtractor(){
}

Subtractor::~Subtractor(){
}

Number* Subtractor::Subtract(Number* number1, Number* number2) {
    Number* result = new Number;
	uint_fast8_t loan = 0;

	comparer.SetCurrentNumber(number1);
	comparer.SetComparedToNumber(number2);
	
	if(comparer.CompareLength()) {
		minuend = number1;
		subtrahend = number2;
	}
	else {
		result->InverseSymbol();
		if(number1->IsNegative()) {
			minuend = number1;
			subtrahend = number2;
		}
		else {
			minuend = number2;
			subtrahend = number1;
		}
	}

	minuend->InitiateCursor();
	subtrahend->InitiateCursor();
	
	while (true) {
		uint_fast8_t min;
		uint_fast8_t sub;
		uint_fast8_t difference = 0;
		if (minuend == subtrahend)
		{
			min = minuend->GetNextDigit();
			sub = min;
		}
		else
		{
			min = minuend->GetNextDigit();
			sub = subtrahend->GetNextDigit();
		}

		if ( result->Length() >= minuend->Length() ) {
			break;
		}

		if(min-sub >= 0) {
			difference = min - sub;
			loan = 0;
		}
		else {
			difference = (min + 10) - sub;
			loan = -1;
		}
		result->PushDigitToStart(difference);
	}
	result->CleanZerosInfront();
	
	return result;
}
