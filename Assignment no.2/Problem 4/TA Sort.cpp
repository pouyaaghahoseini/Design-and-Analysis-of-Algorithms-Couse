#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
bool isSorted(int *A, int l, int r){
    for (int i = l; i < r-1; ++i) {
        if (A[i]>A[i+1])
            return false;
    }
    return true;
}
void printArray(int *A , int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
void print2d( int m, int A[][11]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n,q,li,ri;
    cin>>n>>q;
    int *Array= new int [n];
    int** TAcost = new int*[n+1];
    for(int i = 0; i < n+1; ++i)
        TAcost[i] = new int[n+1];
//    int TAcost[n+1][n+1];
    for (int i = 0; i < n; ++i) {
    cin>>Array[i];
    }
    for (int i=0; i<n; i++)
        TAcost[i][i]=0;
    for (int i=0; i<n; i++)
        TAcost[i][i+1]=1;
    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i < n-k+1; ++i) {
            if (isSorted(Array , i , i+k))
                TAcost [i][i+k]=1;
            else{
                int mid = i+ k/2;
                TAcost[i][i+k]=1+TAcost[i][mid]+TAcost[mid][i+k];
            }
        }
    }
//    printArray(Array,n);
//    for (int i = 0; i < n+1; ++i) {
//        for (int j = 0; j < n+1; ++j) {
//            if (j<i)
//                cout<<"  ";
//            else
//            cout << TAcost[i][j] << " ";
//        }
//        cout << endl;
//    }
    for (int k = 0; k < q; ++k) {
        cin>>li>>ri;
        cout<<TAcost[li-1][ri-1]<<endl;
    }
//    print2d(n,TAcost);
}
