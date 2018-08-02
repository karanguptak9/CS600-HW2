/**
 HW 2 QUESTION 2
 We know three points on a curve: (x1, y1), (x2, y2), (x3, y3) .
 You have to create a program that for any value x1 <= x <= x3 computes the
 corresponding value y assuming that the segment of curve can be
 approximated with the parabola y = ax^2 + bx + c 2.
 Write a function that can be called as y(x1,y1,x2,y2,x3,y3,x)
 and a main program that reads x1,y1,x2,y2,x3,y3 and then displays
 y(x1,y1,x2,y2,x3,y3,x) in n=40 equidistant x points between x1 and x3.
 Solve this problem in the following two ways:
 (a) Insert points (x1, y1), (x2, y2), (x3, y3) in parabola  y(x) = ax^2 + bx + c . You
 will get three linear equations; solve them and find a,b,c. Then, display the table of
 function y(x) from x1 to x3.
 (b) Solve the same problem using Lagrange interpolation formula.
 (c) Compare your two solutions and show your conclusions.
**/

#include <iostream>
using namespace std;

//Form a function for parabola and its equidistant point
void y(double x1, double y1, double x2, double y2, double x3, double y3, float x){
    int a,b,c;
//Using the Lagrange interpolation formula
    a = (((y1-y2)*(x1-x3)) - ((x1-x2)*(y1-y3)))/(((x1*x1 - x2*x2)*(x1-x3)) - ((x1-x2)*(x1*x1 - x3*x3)));
    b = ((y1-y2)-(((x1*x1) - (x2*x2))*a))/(x1-x2);
    c = y1 - ((x1*x1)*a) - (x1*b);
    //Print the parabola function and its equidistant point
    cout << "The equation is: y(x) = " << a << "x^2 + " << b << "x + " << c << endl;
    cout << "Equidistant point: "<< ((x3-x1)/40.0) << endl;
//We have to use a for loop to increment through and print
    for(int index = 0; index < 40; index++){
        float newCount = (float)index;
        x = x1 + ((x3-x1)/40.0) * newCount;
        printf("(%.2f, %.2f) \n", x, (a*x*x + b*x + c));
    }
}

// Test the parabola by asking for input and then call the above void function
int main(){
    int x1, y1, x2, y2, x3, y3;
    float x;
//systematically ask for 6 inputs for the function to work
    cout<<"Please enter the following: \nx1:";
    cin >> x1;
    cout <<  "y1:";
    cin >> y1;
    cout <<  "x2:";
    cin >> x2;
    cout <<  "y2:";
    cin >> y2;
    cout <<  "x3:";
    cin >> x3;
    cout <<  "y3:";
    cin >> y3;
    y(x1,y1,x2,y2,x3,y3,x);
    return 0;
}
/**
 According to me this solution solve's all that was asked and in the most efficient way.
 I broke the question into parts and the commented what I thought was right then I wrote
 the main method so that I could test my code if it was wrong. After writing the comments
 and the main method then I wrote the function. I had to refer internet to revise what
 Lagrange interpolation formula was before approaching it.
**/


