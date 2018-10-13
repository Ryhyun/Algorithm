#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int result;
int N;
int arr[21][21];
int ni[4] = {1,1,-1,-1};
int nj[4] = {1,-1,-1,1};

// 같은 디저트 X
// 왔던 길 X
// 한 곳만 X

void DFS(int starti, int startj , vector<int> visited , int si, int sj ,int depth, int vec){
    visited[arr[starti][startj]] = 1;
    
    for( int i= vec ; i < vec+2; i++){
        if( i == 4)
            break;
        
        int nexti = starti + ni[i];
        int nextj = startj + nj[i];
        
        if( nexti < 0  || nextj < 0 || nexti >= N || nextj >=  N ){
            continue;
        }
        
    
        if( nexti == si && nextj == sj ){
            //cout<< nexti << nextj <<endl;
            if( result < depth  ){
                result = depth;
                //cout<< result<<endl;
            }
            //cout<< "-=-=-=-=-=-="<<endl;
            return;
            
        }
        if( visited[ arr[nexti][nextj]]==1  )
            continue;
        
        
        //cout<< nexti << nextj <<endl;
        vector<int> tempVisited = visited ;
        tempVisited[arr[nexti][nextj]] = 1;
        /*
        for( int j=0; j< 10 ; j++ ){
            cout<< tempVisited[j]<<" ";
        }
        cout<<endl;
         */
        DFS( nexti,nextj, tempVisited, si,sj ,depth+1, i);
        
    }
    

    
    
    return;
    
}
int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    
    for( int casei = 1; casei <= T; casei++){
        result = -1;
        
        cin >> N ;
        for( int i=0; i< N ; i++){
            for( int j=0 ; j<N ; j++){
                cin >> arr[i][j];
            }
        }
        //vector<int> visited;
        //DFS(0,2,visited,0,2);
        
        
        for( int i=0; i< N ; i++) {
            for( int j=0; j< N; j++){
                if( (i == 0 && j == 0)||(i == N-1 && j == 0)||(i == 0 && j == N-1)||(i == N-1 && j == N-1) ){
                    continue;
                }
                vector<int> visited(101,0);
                DFS(i,j,visited,i,j,1,0);
            }
        }
        
        
        
        cout<<"#"<<casei<<" "<< result<<endl;
        
    }
    
    
    
    return 0;
}
