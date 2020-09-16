#include <stdio.h>
#include <stdbool.h>


bool is_digit(char c)
{
    int intval = c - '0';
    return intval < 10 && intval >= 0;
}

// Checks if string is valid
bool is_valid(char *numstring)
{
    char *curr_char = numstring;
    bool seen_decimal_point = false;
    bool seen_negative_sign = false;
    while (*curr_char != '\0' && (is_digit(*curr_char) || (*curr_char == '.' && !seen_decimal_point) || (*curr_char == '-' && !seen_negative_sign)))
    {
        seen_decimal_point = seen_decimal_point || *curr_char == '.';
        seen_negative_sign = seen_negative_sign || *curr_char == '-';
        curr_char++;
    }
    return *curr_char == '\0';
}

// Takes largest integer from a string representation of a float.
// Returns true if the the numstring is valid, else false
bool characteristic(char numString[], int *c)
{
    int index = 0;
    int signValue = 1;
    int cval = 0;

    //validate numstring
   
    if (!is_valid(numString))
    {
        return false;
    } 
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

// Gets the numerator and denominator of the fraction part of a float
// Returns true if the the numstring is valid, else false
bool mantissa(char numString[], int *numerator, int *denominator)
{
    int index = 0;
    int denominator_val = 1;
    int numerator_val = 0;
    
    //validate numstring

    if (!is_valid(numString))
    {
        return false;
    }
    //get to '.' or end of string
    while(numString[index] != '\0')
    {
        if(numString[index] == '.')
        {
            index++;

            while(isdigit(numString[index]))
            {
                denominator_val *= 10;
                numerator_val = (numerator_val *10) + (numString[index] - '0');

                index++;
            }
        }

        index ++;
    }

    *numerator = numerator_val;
    *denominator = denominator_val;

    return true;
}


int main()
{
    int charactaristic = 0;
    int numerator = 0;
    int denominator = 0;
    char test_number_string[] = "   ----12.5987907  ";
    
    characteristic(test_number_string,  &charactaristic);

    printf("%d\n", charactaristic);

    mantissa(test_number_string, &numerator, &denominator);

    printf("numerator: %d\n", numerator);
    printf("denominator: %d\n", denominator);
    return 0;
}
