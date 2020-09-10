#include <stdio.h>

typedef enum Boolean { True = 1, False = 0} bool_t;

bool_t characteristic(char numString[], int &c) {

}

bool_t mantissa(char numString[], int &numerator, int &denominator) {

}


int main() {
    char number[] = "123.456";
    int c, n, d;
 
    //if the conversion from C string to integers can take place
    if(characteristic(number, c) && mantissa(number, n, d))
    {
        //do some math with c, n, and d
    }
    else
    {
        
    }
    return 0;
}
