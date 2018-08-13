
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[11][11];
vector<pair<int,int> > userV;
vector<pair<int,int> > stairV;

int result ;
int N ;


int distance( int u , int s){
    return abs( userV[u].first - stairV[s].first )+ abs( userV[u].second - stairV[s].second) + 1  ;
}

int solve(vector<int> user, int stair){
    // stair :  0 or 1
    int dist[11] ;
    //int visited[11];
    if( user.size() ==0 ){
        return 0;
    }
    queue<pair<int, int> > que;
    queue<int> waitQ;
    
    
    for( int i =0; i< user.size(); i++){
        //cout<< user[i]<<" : ";
        dist[i] = distance( user[i], stair);
    }
    //cout<<endl;
    
    int chk = 0 ;
    
    int t;
    for( t = 1;  t< 1000 ;t++){
        
        if( chk != 0 && que.empty() && waitQ.empty()  ){
            int chk =0 ;
            for( int i=0; i< user.size();i++){
                if( dist[i] == 100000){
                    chk++;
                }
            }
            if( chk == user.size()){
                break;
            }
        }
        
        //cout<< "==-=-=-=-=--=-=-=-="<< t<<endl;
        // que pop
        while( !que.empty() && que.front().second == t ){
            //cout<< " pop? " <<que.front().first<<" "<< que.front().second<<endl;
            que.pop();
        }
        while( que.size() < 3  && !waitQ.empty()){
            que.push( make_pair( waitQ.front(), t + arr[stairV[stair].first][stairV[stair].second] ) );
            waitQ.pop();
        }
        
        // que 에 넣기
        
        for(int i=0; i<user.size() ; i++){
            //cout<< t<<" "<< i <<" "<< dist[i]<<endl;
            if( t == dist[i]){
                chk = 1;
                //cout<< t<<" "<< i <<" "<< dist[i]<<endl;
                if( que.size() < 3 ){
                    que.push( make_pair( i,  t + arr[stairV[stair].first][stairV[stair].second] ));
                    dist[i] = 100000;
                }
                else{
                    waitQ.push( i);
                    dist[i]  = 100000;
                }
            }
        }
    }
    
    return t-1 ;
    
    
    /*
    for(int i=0; i< user.size(); i++){
        int smallest =1000  ;
        int smallJ = 0 ;
        for( int j=0; j< user.size(); j++){
            if( dist[j]  <  smallest){
                smallest = dist[j];
                smallJ = j;
            }
        }
        //cout<<"-------- "<< smallJ <<" "<< smallest<<endl;
        if( now < 3) {
            //cout<< " !"<<endl;
            now++;
            que.push( smallest + arr[stairV[stair].first][stairV[stair].second] ) ;
            tempR = smallest + arr[stairV[stair].first][stairV[stair].second] ;
            dist[smallJ] = 1000 ;
        }
        else{
            //cout<< "?"<<endl;
            int tempT = que.front();
            if( tempT > smallest ){
                que.push( tempT  + arr[stairV[stair].first][stairV[stair].second]   +1) ;
                tempR = tempT  + arr[stairV[stair].first][stairV[stair].second] + 1;
            }
            else{
                que.push( smallest  + arr[stairV[stair].first][stairV[stair].second]   ) ;
                tempR = smallest  + arr[stairV[stair].first][stairV[stair].second] ;
            }
            dist[smallJ] = 1000 ;
            que.pop();
        }
        //cout<<"tempR : "<< tempR<<endl;
    }
    */
    //return tempR;
}
int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    for( int tk =1 ; tk<= T ; tk++){
        cin>> N;
        result = 100000;
        userV.clear();
        stairV.clear();
        for(int i=0 ; i< N; i++){
            for(int j=0; j<N; j++){
                cin>> arr[i][j];
                if( arr[i][j] == 1 )
                    userV.push_back(make_pair( i,j));
                else if( arr[i][j] > 1 )
                    stairV.push_back(make_pair(i,j));
            }
        }
        
        for( int i=0; i < (1  <<  userV.size()) ; i++){
            vector<int> temp1;
            vector<int> temp2;
            //cout<<i << endl;
            for( int j =0 ; j< userV.size(); j++){
                //cout<< i<< " "<< j <<" "<< (i & ( 1 << j)) << endl;
                if(  i & ( 1 << j)  ){
                    temp1.push_back(j);
                }
                else{
                    temp2.push_back(j);
                }
            }
            //cout<<"!!!!!!!!!!!!!"<<endl;
            int r1 = solve( temp1, 0);
            int r2 = solve( temp2, 1);
            //cout<< r1<<" "<< r2 <<endl;
            int tempR = r1 < r2 ? r2: r1;
            
            result = result > tempR ? tempR: result;
        }
        
        
        cout<< "#"<<tk<<" "<< result<<endl;
        
    }
    return 0;
}
