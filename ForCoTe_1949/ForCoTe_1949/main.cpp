#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[8][8];
int ni[4] = {1,0,-1,0};
int nj[4] = {0,1,0,-1};
int result;
int N, K ;

void BFS(int starti,int startj, int ti,int tj,int tk){
    int tempArr[8][8];
    for( int i=0; i< N ; i++){
        for( int j=0 ; j<N ; j++){
            tempArr[i][j] = arr[i][j];
        }
    }
    tempArr[ti][tj]  -= tk;
    
    queue<pair<int,int> > que;
    que.push(make_pair(starti,startj));
    que.push(make_pair(100,100));
    int depth = 1 ;
    while( !que.empty()){
        
        //cout<< "-=-=-=-=-"<<endl;
        int nowi = que.front().first;
        int nowj = que.front().second;
        if( nowi ==100 && nowj==100 && que.back().first !=100 ){
            depth++;
            //cout<<depth<<endl;
            que.push(make_pair(100,100));
        }
        que.pop();
        
        
        for( int i=0; i< 4; i++){
            int nexti = nowi + ni[i];
            int nextj = nowj + nj[i];
            if( nexti >= N || nexti < 0 || nextj >= N || nextj <0 )
                continue;
            
            if( tempArr[nexti][nextj] < tempArr[nowi][nowj]){
                que.push( make_pair( nexti,nextj));
                //cout<< nexti<<nextj<<endl;
            }
        }
    }
    if( depth > result){
        result = depth;
    }
    
        
    
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    
    for( int casei = 1 ; casei<= T ;casei++){
        result=0 ;
        
        cin>>N>>K;
        int top= 0;
        vector<pair<int,int> > topI;
        for( int i= 0; i<N;i++){
            for( int j=0; j<N; j++){
                cin>> arr[i][j];
                if( top < arr[i][j]  ){
                    top = arr[i][j];
                    topI.clear();
                    topI.push_back(make_pair(i,j));
                }
                else if( top == arr[i][j]){
                    topI.push_back(make_pair(i,j));
                }
            }
        }
        
        
            //cout<< topI[i].first<<" "<< topI[i].second<<endl;
        for(int k =0 ; k<= K ; k++){
            for(int i=0; i< N; i++){
                for(int j=0; j<N; j++){
                    for( int t=0; t< topI.size(); t++){
                        
                        BFS( topI[t].first, topI[t].second, i,j,k);
                    }
                }
            }
            
        }
            
        
        
        
        
        
        
        
        cout<<"#"<<casei<<" " << result<<endl;
    }
    
    
    
    return 0;
}
