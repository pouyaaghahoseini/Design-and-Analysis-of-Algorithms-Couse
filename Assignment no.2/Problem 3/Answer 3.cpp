#include <iostream>

using namespace std;
#define MAXTIME 2001
int timetable[10000][MAXTIME];
void printArray(int *A , int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
void print2d(int** A, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<< endl;
}
int findMax(int * paperCost, int ** TaskTime, int n, int time){
    if (n<=0)
        return 0;
    if (n==1) {
        for (int t = 0; t <= MAXTIME; ++t) {
            TaskTime[n-1][t] = 1;
        }
    }
    if (n==2){
        if (time>=paperCost[1])
           TaskTime[n-1][time]=2;
    }
    if (TaskTime[n-1][time]!=-1)
        return TaskTime[n-1][time];
    else{
        int Erfan = findMax(paperCost, TaskTime, n-1, paperCost[n-1]);
        int Etime=paperCost[n-1]-time;
        int count =0;
        for (int p = n-2; (p>=0 && Etime>0); --p) {
            Etime-=paperCost[p];
            count++;
        }
        Etime= Etime*(-1);
        int Javad = findMax( paperCost,TaskTime, n-count-1 , Etime ) + 1;
        return TaskTime[n-1][time]=max( Javad, Erfan);
    }
}
int main() {
    int n;
    cin>>n;
    int *paperCost = new int [n]();
    int **TaskTime = new int* [n]();
    for (int i = 0; i < n; ++i) {
        TaskTime[i] = new int [MAXTIME]();
    }
    for (int i = 0; i <n ; ++i) {
        cin >> paperCost[i];
    }
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < MAXTIME; ++j) {
            TaskTime[i][j]=-1;
        }
    }
    for (int t = 0; t <= MAXTIME; ++t) {
        TaskTime[0][t] = 1;
    }
//    print2d(TaskTime,n,10);
    int x= findMax(paperCost,TaskTime,n,0);
//    print2d(TaskTime,n,10);
    cout<<x;
    }
