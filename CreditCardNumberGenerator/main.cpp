#include "iostream"
#include "string.h"
#include <stdlib.h>
#include <sstream>

int checkValidity(long long int);
long long int generateCardNumber(std::string);

int main()
{
    std::cout << "Please Enter your Credit Card Choice:"<< std::endl;
    char inputString[100];
    std::cin.getline(inputString, sizeof(inputString));
    generateCardNumber(inputString);
}

long long int generateCardNumber(std::string cardName){
    srand((unsigned int)time(NULL));
    long long int r = 1;
    if (cardName == "MASTER CARD") {
        while (checkValidity(r)%10 != 0) {
            std::string x = "";
            for (int i = 0; i < 16; i++) {
                int r= 0 + rand() % (9 - 0);
                x = x + std::to_string(r);
            }
            std::istringstream ( x ) >> r;
        }
    }else if (cardName == "AMEX"){
        while (checkValidity(r)%10 != 0) {
            std::string x = "";
            for (int i = 0; i < 15; i++) {
                int r= 0 + rand() % (9 - 0);
                x = x + std::to_string(r);
            }
            std::istringstream ( x ) >> r;
        }
    }else if (cardName == "VISA"){
        while (checkValidity(r)%10 != 0) {
            std::string x = "";
            for (int i = 0; i < 13; i++) {
                int r= 0 + rand() % (9 - 0);
                x = x + std::to_string(r);
            }
            std::istringstream ( x ) >> r;
        }
    }else
        r = 0;
    std::cout << "The random generated credit card number is : " <<r << std::endl;
    return r;
}
int checkValidity(long long int inputNumber)
{
    int array[16]= {0};
    int x=0;
    while (inputNumber>0) {
        array[x++] = inputNumber % 10;
        inputNumber /= 10;
    }
    int copyOfLength=x-1,evenCounter=0,oddCounter=0,finalCount=0;
    for (int i = 0 ; i < x; i++) {
        if (i%2 == 1) {
            array[copyOfLength] = array[copyOfLength] * 2;
            if (array[copyOfLength] > 9) {
                evenCounter += array[copyOfLength--] - 9;
            }else
                evenCounter += array[copyOfLength--];
        }else
            oddCounter += array[copyOfLength--];
    }
    finalCount = evenCounter + oddCounter;
    return finalCount;
}
