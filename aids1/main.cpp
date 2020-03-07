#include "NumbersArray.h"
#include <stdlib.h>

int main() {

    NumbersArray numbersArray;
    bool run = true;

    numbersArray.Create();
    while (run)
    {
        char input[20];

        scanf_s("%s", input, (unsigned)_countof(input));

        if (input[0] == 'q')
        {
            run = false;
        }
        else if (input[0] == 'm')
        {
            scanf_s("%c", input, (unsigned)_countof(input));
        	if(input[1] == 'i')
        	{
                numbersArray.WriteMin();
        	}
            else
            {
                numbersArray.WriteMax();
            }
        }
        else if(input[0] == '?')
        {
            numbersArray.WriteAll();
        }
        else
        {
            char* end;
            int destination = strtol(input, &end, 10);
            int index1 = 0;
            int index2 = 0;
            char c;
        	scanf_s(" %c ", &c);
            
            scanf_s("%i", &index1);
            scanf_s(" %s ", input, (unsigned)_countof(input));
            scanf_s("%i", &index2);
        	if(input[0] == '+')
        	{
                numbersArray.Add(index1, index2, destination);
        	}
            else
            {
                numbersArray.Subtract(index1, index2, destination);
            }
        	

        	
        }
	}
    //numbersArray.Add(0, 1, 0);
    //numbersArray.Subtract(0, 1, 0);
    //numbersArray.WriteAll();

    return 0;
}