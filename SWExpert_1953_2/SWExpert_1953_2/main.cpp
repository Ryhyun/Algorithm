
#include <iostream>
#include <queue>
using namespace std;


int N,M,R,C,L;
int arr[51][51];
int visited[51][51];
int resultArr[51][51];
int nx[4] = { 0,1,0, -1};
int ny[4] = { 1,0,-1,0};
int result;



bool tunnel( int tun, int v){
    switch(tun){
        case 1:
            return true;
        case 2:
            if( v == 1 || v== 3)
                return true;
            else
                return false;
        case 3:
            if( v == 0 || v== 2)
                return true;
            else
                return false;
        case 4:
            if( v == 3 || v== 0)
                return true;
            else
                return false;
        case 5:
            if( v == 1 || v== 0)
                return true;
            else
                return false;
        case 6:
            if( v == 1 || v== 2)
                return true;
            else
                return false;
        case 7:
            if( v == 2 || v== 3)
                return true;
            else
                return false;
        default:
            break;
    }
    return false;
}

bool isConnect(int n,int r,int iv){
    
    int base = arr[n][r];
    int next = arr[ n+ nx[iv]][ r+ ny[iv]];
    //cout<< "isConnect: "<< base<< " " << next<<endl;
    if( tunnel(base, iv) == true && tunnel( next, (iv+2)% 4 )== true)
        return true;
    else
        return false;
}
void BFS(){
    
    int depth =1 ;
    queue< pair<int,int> > q;
    q.push( make_pair( R,C));
    q.push( make_pair( 100,100));
    visited[R][C] =1;
    
    while( !q.empty() && depth < L){
        
        int nowN = q.front().first;
        int nowM = q.front().second;
        //cout<< nowN<<" "<< nowM << endl;
        if( nowN == 100 && nowM == 100 && q.back().first != 100){
            //cout<<"--------------"<< depth<<endl;
            depth++;
            q.push( make_pair( 100,100));
        }
        q.pop();
        
        
        for(int iv=0; iv< 4; iv++){
            int nextN = nowN + nx[iv];
            int nextM = nowM + ny[iv];
            if ( nextN >= N ||  nextN < 0 || nextM >= M || nextM <0  ){
                continue;
            }
            if( isConnect(nowN, nowM, iv ) && visited[nextN][nextM] != 1  ){//  현재 위치 랑 i 방향과 연결 됨?
                //cout<< "in "<< nextN<<" "<< nextM <<endl;
                visited[nextN][nextM] = 1;
                q.push(make_pair( nextN, nextM));
                
                
                
            }
        }
    }
    
}


void DFS(int r, int c , int depth){
    if( depth == L ){
        return;
    }
    
    for(int iv=0; iv< 4; iv++){
        int nextN = r + nx[iv];
        int nextM = c + ny[iv];
        if ( nextN >= N ||  nextN < 0 || nextM >= M || nextM <0  ){
            continue;
        }
        if( isConnect(r, c, iv ) && visited[nextN][nextM] != 1  ){//  현재 위치 랑 i 방향과 연결 됨?
            //cout<< "in "<< nextN<<" "<< nextM <<endl;
            visited[nextN][nextM] = 1;
            resultArr[nextN][nextM] = 1;
            DFS( nextN ,nextM, depth + 1  );
            visited[nextN][nextM] = 0;
            
        }
    }
    
}
int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    for( int t = 1 ; t <= T ; t++){
        result = 0 ;
        cin>> N >> M >> R >> C >> L ;
        
        for(int i=0; i<N; i++){
            for( int j=0; j< M ; j++){
                cin>> arr[i][j];
                visited[i][j] =0 ;
                resultArr[i][j]=0;
            }
        }
        
        visited[R][C] = 1;
        //BFS();
        resultArr[R][C] = 1;
        DFS( R,C,1);
        
        
        for( int i=0; i<N ;i++){
            for( int j=0; j< M ; j++){
                if( resultArr[i][j] == 1){
                    result++;
                }
            }
        }
        
        
        
        
        
        cout<<"#"<<t<<" "<< result<<endl;
    }
    return 0;
}
