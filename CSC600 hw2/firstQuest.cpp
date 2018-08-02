/**
HW2 QUESTION 1
The array a(1..n) contains sorted integers. Write a function maxlen(a,n) that returns the
length of the longest sequence of identical numbers (for example, if
a=(1,1,1,2,3,3,5,6,6,6,6,7,9) then maxlen returns 4 because the longest sequence 6,6,6,6
contains 4 numbers. Write a demo main program for testing the work of maxlen. Explain
your solution, and insert comments in your program. The solution should have time
complexity O(n).
**/

#include <iostream>
using namespace std;

//create an array maxlen of a specific size
int maxlen (int newArg[], int size){
    //create a variable which will be the streak number and a comparing count
    int streakNumber=0, count=0;
    //To check the previous number in the array we declare it to a variable
    int previousNum = newArg[0];

    //Iterating through the array to compare it with the previous number is the array.
    for(int index=1; index<size; index++)
    {
        //since we started comparing from the next number in the array we initialise it to a variable
        int currentNumber = newArg[index];
        //check if they the previous number and the current number are same and if not then count remains the same
        if(previousNum == currentNumber)
        {
            count++;
            //check if the count is incremented if yes then make that as the streakNumber
            if(count > streakNumber){streakNumber = count;}
        }else{count = 1;}
        previousNum = currentNumber;
    }
    return streakNumber;
}
//Testing code above with a testing array for the longest streak of numbers
int main(){
    int testingArray[10] = {1,1,1,1,2,3,4,5,5,5};
    cout << "The longest streak is: "  << maxlen (testingArray,10);
    return 0;
}
/**
Since we use only one for loop in the code with iteration to n, this seems to be the most efficient code
to find the longest streak in an array with time complexity of O(n).
**/