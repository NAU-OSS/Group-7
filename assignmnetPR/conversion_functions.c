#include <stdio.h>

#define ASCII_0 48
typedef enum Boolean
{
    True = 1,
    False = 0
} bool_t;

bool_t is_digit(char c)
{
    return c - ASCII_0 < 10;
}

int to_int(char c)
{
    return c - ASCII_0;
}

bool_t characteristic(char numString[], int *c)
{
    char *curr_char;
    char *start_char = numString;
    bool_t is_negative;
    int power = 1;
    *c = 0;

    if (is_negative = *start_char == '-')
    {
        start_char++;
    }

    curr_char = start_char;
    while (*curr_char != '\0' && *curr_char != '.' && is_digit(*curr_char))
    {
        curr_char++;
    }
    if (!is_digit(*curr_char))
    {
        return False;
    }
    curr_char--;

    while (curr_char != start_char - 1)
    {
        *c += power * to_int(*curr_char);
        power *= 10;
        curr_char--;
    }

    if (is_negative)
    {
        *c *= -1;
    }
    return True;
}

bool_t mantissa(char numString[], int *numerator, int *denominator)
{
    char *curr_char, *decimal = 0, *start_char = numString, *end_char;
    int power = 1;
    *numerator = 0;
    *denominator = 10;

    if (*start_char == '-')
    {
        start_char++;
    }
    curr_char = start_char;

    while (*curr_char != '\0' && (*curr_char == '.' || is_digit(*curr_char)))
    {
        if (*curr_char == '.')
        {
            decimal = curr_char;
        }
        if (decimal != 0 && curr_char > decimal + 1)
        {
            *denominator *= 10;
        }
        curr_char++;
    }
    if (*curr_char == '\0')
    {
        end_char = curr_char;
    }
    else if (!is_digit(*curr_char))
    {
        return False;
    }
    if (decimal == 0)
    {
        return True;
    }

    curr_char = end_char - 1;

    while (curr_char != decimal)
    {
        *numerator += to_int(*curr_char) * power;
        power *= 10;
        curr_char--;
    }
    return True;
}

int main()
{
    char number[] = "123.456";
    int c, n, d;

    //if the conversion from C string to integers can take place
    if (characteristic(number, &c) && mantissa(number, &n, &d))
    {
        printf("Charictaristic: %d\nNumerator: %d\nDenominator: %d\n", c, n, d);
        //do some math with c, n, and d
    }
    else
    {
        fprintf(stderr, "The string was invalid!\n\n");
        return 42 + 27;
    }
    return 0;
}
