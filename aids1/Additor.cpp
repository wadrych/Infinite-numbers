#include "Additor.h"

Additor::Additor() {
    smallerAddend = NULL;
    biggerAddend = NULL;
}

Additor::~Additor() {
}

void Additor::Add(Number* addend1, Number* addend2) {
    if(addend1->Length() >= addend2->Length()) {
        biggerAddend = addend1;
        smallerAddend = addend2;
    }
    else {
        biggerAddend = addend2;
        smallerAddend = addend1;
    }

    for(int i=smallerAddend->Length-1; i >= 0; i++) {
        uint_fast8_t bAd = biggerAddend->GetDigit(i);
        uint_fast8_t sAd = smallerAddend->GetDigit(i);

        
    }


}
