#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <queue>
#include <cmath>
#include <stack>
#include <string.h>
#define INF 1000000
using namespace std;
struct word{
    int id;
    string term;
};

string lower(string s){
    for (char &m : s) {
        m =char(tolower(int(m)));
    }
    return s;
}
int lcs( string X, string Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

bool hasEdge(string A, string B){
    long int n=A.size();
    long int m=B.size();
    A=lower(A);
    B=lower(B);
    if (n==m){
        int f=0;
        for (int i = 0; i < n; ++i) {
            if (A.at(i)!=B.at(i))
                f++;
            if (f==2)
                return false;
        }
        return true;
    }
    else if (n-m==1 || m-n==1) {
        if (lcs(A,B,n,m)==min(n, m)) {
            return 1;
        }
    }
    return 0;
}

vector<bool> visited;
vector<vector<int> > Graph;
vector<vector<string> >allPaths;
void edge(int a, int b)
{
    Graph[a].push_back(b);
    Graph[b].push_back(a);
}

void bfs(int u,vector<word> w) {
    queue<int> Q;
    Q.push(u);
    vector<bool> visited;
    visited.assign(Graph.size(),false);
    visited[u] = true;
    allPaths[u][u]=w[u].term;
    while (!Q.empty()) {
        int Front = Q.front();
        Q.pop();
        for (auto i = Graph[Front].begin(); i != Graph[Front].end(); i++) {
            if (!visited[*i]) {
                Q.push(*i);
                string temp = allPaths[u][Front];
                temp.append(" ");
                allPaths[u][*i]=temp.append(w[*i].term);
                visited[*i] = true;
            }
        }
    }
}
int main()
{
    int n,q;
    cin >> n >>q;
    Graph.assign(n, vector<int>());
    allPaths.assign(n,vector<string>(n,"*"));
    vector<word> w;
    vector<string> lowerW;
    word x;
    for (int k = 0; k <n ; ++k) { //Input
        string temp;
        cin >> temp;
        x.term=temp;
        x.id = k;
        w.push_back(x);
        lowerW.push_back(lower(temp));
    }
    for (int i = 0; i < n-1; i++) { //constructing graph
        string a=w.at(i).term;
        for (int j = i+1; j <n ; ++j) {
            string b=w.at(j).term;
            if (hasEdge(a,b)){
                edge(i,j);
            }
        }
    }
    for (int i = 0; i < n; i++) {//constructing all paths
        bfs(i,w);
    }
//    printallPaths(allPaths);
    //Querying
    for (int count = 0; count < q; ++count) {
        string start,target;
        int startId=-1;
        int targetId=-1;
        cin >> start >> target;
        for (int i = 0; i <n ; ++i) { //checking if start and target are in vocabulary
            if (lowerW[i]==lower(start))
                startId=i;
            if (lowerW[i]==lower(target))
                targetId=i;
        }
        if (targetId ==-1 || startId==-1){
            cout<<"*"<<endl;
            continue;
        }
        if (startId==targetId){
            cout<<w[startId].term<<" "<<w[targetId].term<<endl;
            continue;
        }
        cout<<allPaths[startId][targetId]<<endl;
    }
    return 0;
}
