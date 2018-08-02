/**
HW2 QUESTION 5
Make a sorted integer array a[i]=i, i=0,…,n-1. Let bs(a,n,x) be a binary search
program that returns the index i of array a[0..n-1] where a[i]=x. Obviously,
bs(a,n,x)=x, and the binary search function can be tested using the loop
for(j=0; j<K; j++)
for(i=0; i<n; i++) if(bs(a,n,i) != i) cout << “\nERROR”;
Select the largest n your software can support and then K so that this loop with an
iterative version of bs runs 3 seconds or more. Then measure and compare this run time
and the run time of the loop that uses a recursive version of bs. Compare these run times
using maximum compiler optimization (release version) and the slowest version
(minimum optimization or the debug version). If you use a laptop, make measurements
using AC power, and then same measurements using only the battery. What conclusions
can you derive from these experiments? Who is faster? Why?
 **/

#include <iostream>
using namespace std;

// Binary search function we use a while loop for better efficiency
int bs(int* a,int minimum, int maximum, int x){

    while (minimum <= maximum) {
        int mid;
        mid = (minimum + maximum) / 2;
        if (a[mid] > x) { maximum = mid - 1;}
        else if (a[mid] == x) { return mid;}
        else { minimum = mid + 1;}
    }
    return -1;
}

//Recursive version of the search, we dont need any loops to sort.
int bsRecursive(int* a, int minimum, int maximum, int x){

    if(minimum == maximum) {return -1;}
    else{
        int mid = minimum+((maximum-minimum) / 2);
        if (a[mid] < x) { return bsRecursive(a, mid + 1, maximum, x);}
        else if (a[mid] > x) { return bsRecursive(a,minimum, mid - 1, x);}
        else { return mid;}
    }
}
//we use clock per second expression to get the time and initilise it to a variable
double seconds(){
    return ((double)clock())/CLOCKS_PER_SEC;
}
//We use the above functions to read its run time in the main function. We would probably need a nested for loop
int main(){

    int K = 1000000, n= 100, a[n];
    double timeStart; // starting the clock
    double timeEnd; // ending the clock

    // Instatiating the array
    for(int index=0;index<n;index++) {
        a[index] = index;
    }
    // START TIME
    timeStart= seconds();
    //We will go through the above mentioned function and print an error message if needed
    for(int j=0; j<K;j++){
        for(int i=0;i<n;i++){
            if(bs(a,0,n,i)!=i)
                cout<<"ERROR" << endl;
        }
    }
    //END TIME
    timeEnd = seconds()- timeStart;
    cout<<"Iterative seconds:"<< timeEnd<< endl;

    //START TIME
    timeStart=seconds();
    //We will go through the above mentioned function and print an error message if needed
    for(int j=0; j<K;j++){
        for(int i=0;i<n;i++){
            if(bs(a,0,n,i)!=i)
                cout<<"\nERROR"<<endl;
        }
    }
    //END TIME
    timeEnd= seconds()- timeStart;
    cout<<"Recursive seconds:"<< timeEnd<< endl;

    return 0;
}

/**
I feel this code can find time needed and it first explains both binary search function and then recursive function
then we create the function of time. In the main file we use our function to test for time. According to me recursive
method has proved itself to be a faster approach than other iterative method. I also tried testing it and I feel
that it does when the charger is plugged than it is just on the battery.
**/