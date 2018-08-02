/**
HW2 QUESTION 3
The array a(1..n) contains arbitrary integers. Write a function reduce(a,n) that reduces
the array a(1..n) by eliminating from it all values that are equal to three largest different
integers. For example, if a=(9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9) then three largest different
integers are 6,7,9 and after reduction the reduced array will be a=(1,1,1,2,3,3,5), n=7. The
solution should have time complexity O(n).
 **/

#include <iostream>
using namespace std;
// Form a function that finds the largest number takes them out and the prints the rest with its size
void reduce(int* a, int n){
//We need three variables for large numbers, a number for the left over size and then an array
    int firstLargest =0, secondLargest=0, thirdLargest=0, size = 0;
    int *newArray=new int[size];

    // iterate through the loop to get the largest 3 value
    for(int index = 0; index< n; index++){
        if(firstLargest < a[index])
            firstLargest = a[index];  // first largest number
        if(secondLargest < a[index] && a[index] < firstLargest)
            secondLargest= a[index];   // second largest number
        if(thirdLargest < a[index] && a[index] < secondLargest)
            thirdLargest= a[index];   // third largest number
    }
    //print the three largest number
    cout<< "Three Largest different Integers: "
        << firstLargest << " " << secondLargest << " " << thirdLargest << endl << endl;

    //Form a new array removing the largest numbers and then print it
    cout<<"Array Elements After Reduction: a= ";
    for(int index=0; index< n; index++){
        if((a[index] != firstLargest) && (a[index] != secondLargest) && (a[index] != thirdLargest)) {
            newArray[size] = a[index];
            cout<<newArray[size]<<",";
            size++;
            //print the size after the loop ends
        }
    }
    cout<<" n = "<< size << endl;
}
//Test the function above with the same example in the question to be sure about the output in the main function
int main(){
    int a[]={9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
    //We call the reduce function for separating and printing
    reduce(a, 16);
    return 0;
}
/**
I feel this is the best solution for the problem as it solves what is asked with the most efficient
method. We used total of 2 for loops but not in a nested format therefore the n is iterated once
in both for loops that means the efficiency for this is O(n). The first for loop is separating the
largest numbers and the second for loop is used for reducing and printing them as sorted.
**/
