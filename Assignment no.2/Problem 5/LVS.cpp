#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void printArray(int *A , int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
bool isLeft(char c) {
    if (c=='(' || c =='<' || c=='[' || c=='{')
        return true;
    return false;
}
bool isRight(char c) {
    if (c==')' || c =='>' || c==']' || c=='}')
        return true;
    return false;
}

bool isPal(char *A, int start, int end){
    if ( A[start]=='(' && A[end]==')' )
        return true;
    if ( A[start]=='{' && A[end]=='}' )
        return true;
    if ( A[start]=='[' && A[end]==']' )
        return true;
    if ( A[start]=='<' && A[end]=='>' )
        return true;
    else
        return 0;
}
int main() {
    int n;
    cin >> n;
    char *Exp = new char[n]();
    int *maxBalanced = new int[n]();

    for (int i = 0; i < n; ++i) {
        cin >> Exp[i];
    }
    maxBalanced[n - 1] = 0;
    maxBalanced[n - 2] = 0;
    if (isPal(Exp, n-2, n-1 ))
        maxBalanced[n-2] = 2;

    for (int i = n - 3; i >= 0; i--) {
        maxBalanced[i] = 0;
        if (isPal(Exp, i, i + 1))
            maxBalanced[i] = 2 + maxBalanced[i + 2];
        else if (Exp[i] == '(' && isLeft(Exp[i+1]) && Exp[i + maxBalanced[i + 1] + 1] == ')')
            maxBalanced[i] = 2 + maxBalanced[i+1] + maxBalanced[ i+maxBalanced[i+1]+2 ];
        else if (Exp[i] == '<' && isLeft(Exp[i+1]) && Exp[i + maxBalanced[i + 1] + 1] == '>')
            maxBalanced[i] = 2 + maxBalanced[i+1] + maxBalanced[ i+maxBalanced[i+1]+2 ];
        else if (Exp[i] == '{' && isLeft(Exp[i+1]) && Exp[i + maxBalanced[i + 1] + 1] == '}')
            maxBalanced[i] = 2 + maxBalanced[i+1] + maxBalanced[ i+maxBalanced[i+1]+2 ];
        else if (Exp[i] == '[' && isLeft(Exp[i+1]) && Exp[i + maxBalanced[i + 1] + 1] == ']')
            maxBalanced[i] = 2 + maxBalanced[i+1] + maxBalanced[ i+maxBalanced[i+1]+2 ];


//        if (Exp[i] == ')' or Exp[i] == ']' or Exp[i] == '}' or Exp[i] == '>')
//            maxBalanced[i] = 0;
    }
    printArray( maxBalanced, n);
}
