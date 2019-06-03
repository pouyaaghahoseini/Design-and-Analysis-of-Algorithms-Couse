#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > board;
vector<vector<int> > row_vertex;
vector<vector<int> >graph;
vector<int> match;
vector<bool> visited;

//void print2D(vector<vector<char> > V){
//    int row=V.size();
//    int column=V[0].size();
//    for (int i=0 ; i<row ; i++){
//        for(int j=0; j<column; j++){
//            cout<<board[i][j];
//        }
//        cout<<endl;
//    }
//}
//
//void print_rowvertex(vector<vector<int> > V){
//    for (int i=0 ; i<V.size() ; i++){
//        for(int j=0; j<V[i].size(); j++){
//            cout<<V[i][j];
//        }
//        cout<<endl;
//    }
//}
//void print_graph(vector<vector<int> > g){
//    for (int i=0 ; i<g.size() ; i++){
//        cout<<i<<") ";
//        for(int j=0; j<g[i].size(); j++){
//            cout<<g[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//}

bool isChosen(int u){
    for (auto v = graph[u].begin(); v != graph[u].end(); v++){
        if (!visited[*v])
        {
            visited[*v] = true;
            if (match[*v] < 0 || isChosen(match[*v]) ){
                match[*v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(int col_count){
    match.assign(col_count,-1);
    int result = 0;
    for (int u = 0; u < graph.size() ; u++)
    {
        visited.assign(col_count,false);
        if ( isChosen(u) )
            result++;
    }
    return result;
}


int main() {
    int n,m;
    cin>>n>>m;
    board.assign(n,vector<char>(m));
    row_vertex.assign(n,vector<int>(m,-1));
    for (int i=0 ; i<n ; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    int row_count=-1;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <m ; ++j) {
            if (board[i][j] == '.') {
                row_count++;
                while (j < n && board[i][j] == '.') {
                    row_vertex[i][j] = row_count;
                    j++;
                }
            }
        }
    }
//    print_rowvertex(row_vertex);
    graph.assign(row_count+1,vector<int>());

    int col_count=-1;
    for (int j = 0; j <m ; ++j) {
        for (int i = 0; i <n ; ++i) {
            if (board[i][j]=='.') {
                col_count++;
                while (i<n && board[i][j]=='.'){
                    graph[row_vertex[i][j]].push_back(col_count);
                    i++;
                }
            }
        }
    }
//    print_graph(graph);
//    cout<<row_count<< " -- "<<col_count<<endl;
    cout<<maxBPM(col_count+1);
    return 0;
}
