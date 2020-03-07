#include "Additor.h"

Additor::Additor() {
    smallerAddend = NULL;
    biggerAddend = NULL;
}

Additor::~Additor() {
}

Number* Additor::Add(Number* addend1, Number* addend2) {
    uint_fast8_t additional = 0;
    int i = 0;
    Number* result = new Number;
	
    if(addend1->Length() >= addend2->Length()) {
        biggerAddend = addend1;
        smallerAddend = addend2;
    }
    else {
        biggerAddend = addend2;
        smallerAddend = addend1;
    }

	if(addend1->IsNegative() && addend2->IsNegative()) {
        result->InverseSymbol();
	}
    else if(addend1->IsNegative() && addend2->IsPositive()) {
        result->InverseSymbol();
    }

    biggerAddend->InitiateCursor();
    smallerAddend->InitiateCursor();
    
    while(true) {
        uint_fast8_t bAd;
        uint_fast8_t sAd;
        uint_fast8_t sum;
        if (biggerAddend == smallerAddend)
        {
            bAd = biggerAddend->GetNextDigit();
            sAd = bAd;
        }
        else
        {
            bAd = biggerAddend->GetNextDigit();
            sAd = smallerAddend->GetNextDigit();
        }

        if(bAd == 0 && sAd == 0 && additional == 0 && i >= biggerAddend->Length()) {
            break;
        }
    	
    	sum = bAd + sAd + additional;
    	
        result->PushDigitToStart(sum % 10);
        additional = sum / 10;
        i++;      
    }

    return result;
}
