
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int arr[9][9] = { 0,};
vector<pair<int,int> > vec;
vector<int > tempVec(3);
vector<pair<int,int> > virusVec;
int ni[4] = { 1,0,-1,0};
int nj[4] = {0, 1, 0, -1};
int result = 0 ;
void calculate(){
    int tempArr[9][9] ;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tempArr[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<3 ;i++){
        //cout<< tempVec[i]<<" ";
        tempArr[ vec[tempVec[i]].first][vec[tempVec[i]].second] = 1 ;
    }
    //cout<<endl;
    
    
    for(int i=0; i< virusVec.size(); i++){
        queue<pair<int,int> > que;
        que.push(make_pair( virusVec[i].first, virusVec[i].second));
        
        while( !que.empty()){
            int ti = que.front().first;
            int tj = que.front().second;
            que.pop();
            
            for( int j=0; j< 4; j++){
                int nexti = ti + ni[j];
                int nextj = tj + nj[j];
                
                if( nexti < 0 || nextj < 0 || nexti >= N || nextj >= M)
                    continue;
                if( tempArr[nexti][nextj] == 0 ){
                    que.push(make_pair(nexti,nextj));
                    tempArr[nexti][nextj] = 2;
                }
            }
            
        }
        
    }
    int tempResult = 0 ;
    for(int i=0; i< N ; i++){
        for(int j=0; j< M;j++){
            //cout<< tempArr[i][j];
            if( tempArr[i][j] == 0 ){
                tempResult++;
            }
        }
        //cout<<endl;
    }
    //cout<< tempResult<<endl;
    //cout<<"-=-=-=-=-="<<endl;
    
    result = ( result> tempResult )? result: tempResult;
    
    
}
void recursive(int index, int depth ){
    //cout<< index<< " " << depth<<endl;
    if( index > vec.size() )
        return;
    if( depth >= 3 ){
        calculate();
        return;
    }
    tempVec[depth] = index;
    recursive(index+1, depth+1);
    recursive(index+1, depth);
    tempVec[depth] = index;
}

int main(int argc, const char * argv[]) {
    cin>>N>>M;
    for(int i=0; i<N ; i++){
        for( int j=0; j< M ; j++){
            cin>> arr[i][j];
            if( arr[i][j] == 0) {
                vec.push_back(make_pair(i,j));
             
            }
            else if( arr[i][j] == 2){
                virusVec.push_back(make_pair(i,j));
            }
        }
    }
    recursive(0,0);
    cout<< result<<endl;
    
    return 0;
}
