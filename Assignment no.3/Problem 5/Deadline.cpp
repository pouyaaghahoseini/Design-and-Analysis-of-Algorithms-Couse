#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct assignment{
    int id;
    int p;
    int w;
    long double ratio;
};
struct course{
    int number;
    int k;
    long double ratio;
    int startIndex;
};
bool compareCourse(course a, course b){
    return (a.ratio>b.ratio);
}
bool compareAssignment(assignment a, assignment b){
    return (a.ratio>b.ratio);
}
void printCourses(course *C,int n){
    for (int i = 0; i < n; ++i) {
        cout<<"num="<<C[i].number<<" ratio="<<C[i].ratio<<endl;
    }
}
void printAssignments(assignment *A,int all){
    for (int i = 0; i < all; ++i) {
        cout<<"id="<<A[i].id<<" ratio="<<A[i].ratio<<endl;
    }
}
course C[500];
assignment A[50000];
int main() {
    int n;
    cin >> n;
    long int allAssignments=0;
//    course *C=new course[n];
    for (int i = 0; i < n; ++i) { //courses array with k and starting index
        C[i].number=i;
        C[i].startIndex=allAssignments;
        cin>>C[i].k;
        allAssignments+=C[i].k;
    }
//    assignment* A=new assignment[allAssignments];
    for (int i = 0; i < allAssignments; ++i) { // get all assignments p and setting id
        A[i].id=i;
        cin>>A[i].p;
    }
    for (int i = 0; i < allAssignments; ++i) { // get all assignments w and setting ratio
        cin>>A[i].w;
        A[i].ratio=(long double)A[i].w/(long double)A[i].p;
    }
    for (int i = 0; i < n ; ++i) { //course ratios
        long double time=0;
        long double cost=0;
        for (int j = C[i].startIndex; j <C[i].startIndex+C[i].k ; ++j) {
            time += (long double)A[j].p;
            cost += (long double)A[j].w;
        }
        C[i].ratio=cost/time;
    }
    sort(&C[0],&C[n],compareCourse);
    for (int i = 0; i < n ; ++i)
        sort(&A[C[i].startIndex],&A[C[i].startIndex+C[i].k],compareAssignment);
    long int totalcost=0;
    long int cummulativeTime=0;

    for (int i = 0; i < n ; ++i) {
        for (int j = C[i].startIndex; j <C[i].startIndex+C[i].k ; ++j) {
            cummulativeTime+=A[j].p;
            totalcost+=A[j].w*cummulativeTime;
        }
    }
    cout<<totalcost<<endl;
    for (int i = 0; i < n ; ++i) {
        for (int j = C[i].startIndex; j <C[i].startIndex+C[i].k ; ++j) {
            cout<<A[j].id+1<<" ";
            cummulativeTime+=A[j].p;
            totalcost+=A[j].w*cummulativeTime;
        }
    }
}
