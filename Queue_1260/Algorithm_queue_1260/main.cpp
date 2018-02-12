#include <iostream>
#include <queue>
using namespace std;

int M,N;
int dfsVisited[1000] = {0,};
void DFS(int edge[][1000],const int start){
    dfsVisited[start] = 1;
    for( int i=0; i< M; i++){
        if( edge[start][i] == 1 and dfsVisited[i] != 1){
            dfsVisited[i] =1;
            cout<< i+1<<" ";
            DFS( edge, i);
        }
    }
}
void BFS( int edge[][1000],const int start){
    queue<int> vertexQueue;
    
    int tempVertex;
    int visited[1000] = {0,};
    visited[start] =1 ;
    vertexQueue.push(start);
    
    
    while( !vertexQueue.empty() ){
        tempVertex = vertexQueue.front();
        vertexQueue.pop();
        
        for(int i=0; i<M;i++){
            if( edge[tempVertex][i] == 1 and visited[i] != 1){
                vertexQueue.push(i);
                visited[i] = 1;
                cout<< i+1 <<" ";
            }
        }
    }
}
/*
5 6 1
1 2
1 3
1 4
1 5
2 4
3 4
 
4 5 1
1 2
1 3
1 4
2 4
3 4
 
*/


int main(int argc, const char * argv[]) {
    int startVertex;
    cin>>M>>N>>startVertex;
    
    /*
    int** edgeArray = new int*[M];
    for(int i=0; i<M;i++){
        edgeArray[i] = new int[M];
        memset(edgeArray[i], 0, sizeof(int)*M);
    }
    */
    int edgeArray[1000][1000] ={0,} ;
    for(int i =0 ; i<N;i++){
        int fromV,toV;
        cin>> fromV>> toV;
        //cout<< fromV<< toV;
        edgeArray[fromV-1][toV-1] = 1;
        edgeArray[toV-1][fromV-1] = 1;
    }
    cout<<startVertex<<" ";
    DFS(edgeArray, startVertex -1);
    cout<<"\n"<< startVertex<<" ";
    BFS(edgeArray, startVertex -1);

    return 0;
}
