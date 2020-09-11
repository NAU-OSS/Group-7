#include <stdio.h>
#include <stdbool.h>

bool characteristic(char numString[], int *c)
{
    int index = 0;
    int signValue = 1;
    int cval = 0;

    //TODO: validate numstring
    
    //find sign of numstring and find start index of number
    while (numString[index] != '\0' && numString[index] != '.')
    {
        if(numString[index] == '-')
        {
            signValue = -1;
        }
        
        if( isdigit(numString[index]))
        {
            cval = (cval * 10) + (numString[index] - '0');
                
        }

        index++;
    }
    
    *c = cval * signValue;

    return true;
}

bool mantissa(char numString[], int *numerator, int *denominator)
{
    int index = 0;
    int dvalue = 1;
    int nvalue = 0;
    
    //TODO: validate numstring

    //get to '.' or end of string
    while(numString[index] != '\0')
    {
        if(numString[index] == '.')
        {
            index++;

            while(isdigit(numString[index]))
            {
                dvalue *= 10;
                nvalue = (nvalue *10) + (numString[index] - '0');

                index++;
            }
        }

        index ++;
    }

    *numerator = nvalue;
    *denominator = dvalue;

    return true;
}


int main()
{
    int c = 0;
    int n = 0;
    int d = 0;
    char number[] = "   ----12.5987907  ";
    
    characteristic(number,  &c);

    printf("%d\n", c);

    mantissa(number, &n, &d);

    printf("numerator: %d\n", n);
    printf("denominator: %d\n", d);
    return 0;
}