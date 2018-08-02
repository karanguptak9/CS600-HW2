/**
HW2 QUESTION 4
Write a program BigInt(n) that displays an arbitrary positive integer n using big
characters of size 7x7, as in the following example for BigInt(170):
**/

#include <iostream>
using namespace std;
//We create a function that makes the numbers in a 2D matrix way.
void BigInt(int n){
    //All the numbers created should be in 2D matrix of string variable.
    string numbers[7][10] = {
            { " @@@@@ "  ,  "    @   "  ,  "  @@@@@  "  ,  " @@@@@   "  ,  "    @  "  ,  "  @@@@@ "  ,  " @@@@@  "  ,  "  @@@@@ "  ,  " @@@@@ "  ,  "  @@@  " } ,
            { " @   @ "  ,  "  @ @   "  ,  "      @  "  ,  "     @   "  ,  "   @@  "  ,  "  @     "  ,  " @      "  ,  "      @ "  ,  " @   @ "  ,  " @   @ " } ,
            { " @   @ "  ,  "    @   "  ,  "      @  "  ,  "     @   "  ,  "  @ @  "  ,  "  @     "  ,  " @      "  ,  "      @ "  ,  " @   @ "  ,  " @   @ " } ,
            { " @   @ "  ,  "    @   "  ,  "  @@@@@  "  ,  "  @@@@   "  ,  " @  @  "  ,  "  @@@@@ "  ,  " @@@@@  "  ,  "      @ "  ,  " @@@@@ "  ,  "  @@@@ " } ,
            { " @   @ "  ,  "    @   "  ,  "  @      "  ,  "     @   "  ,  " @@@@@ "  ,  "      @ "  ,  " @   @  "  ,  "      @ "  ,  " @   @ "  ,  "     @ " } ,
            { " @   @ "  ,  "    @   "  ,  "  @      "  ,  "     @   "  ,  "    @  "  ,  "      @ "  ,  " @   @  "  ,  "      @ "  ,  " @   @ "  ,  " @   @ " } ,
            { " @@@@@ "  ,  "  @@@@@ "  ,  "  @@@@@  "  ,  " @@@@@   "  ,  "    @  "  ,  "  @@@@@ "  ,  " @@@@@  "  ,  "      @ "  ,  " @@@@@ "  ,  "  @@@  " }
    };
    // Need to have a while loop so that we could segment the input into the desired number that need to be printed
    int i = 0, j = 0, allNumbers[10] ;
    while(n > 0){
        //We divide the number by 10 which helps us giving us a single number to print each time its iterated
        allNumbers[i] = n % 10;
        n /= 10;
        i++;
        j++;
    }
    // We print the numbers using a nested for loop.
    int index, index1;
    for(index=0; index<7; index++){
        for(index1= j-1; index1>=0 ; index1--){
            cout<< numbers [index][allNumbers[index1]];
        }
            cout << endl;
    }
}

// We test the above function in the main function by just giving it a random input which I am taking from the question since we know the output
int main(){
    //We call the function with any random output
    BigInt(170);
    return 0;
}

/**
I feel this is the best solution for this question, even though we used a while loop and 2 for loops for
dividing the input and printing respectively, even then this is the most efficient code for this question.
I was confused between two approaches for this question, I was first thinking to store the number into switch
and each case would represent a number but then I decided to go with 2D matrix and then priting it accordingle
besides calling the switch cases.
**/
