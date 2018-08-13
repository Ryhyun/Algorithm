#include <iostream>
#include <queue>
using namespace std;

int result =0 ;
int D,W,K;

// 0 은 A  , 1 은 B
int arr[14][21];
int origin[14][21];

bool is_ok(int col ){
    int cnt=0 ;
    for(int i=1 ; i< D; i++){
        if( arr[i][col] == arr[i-1][col]){
            cnt++;
            if( cnt >= K-1 )
                return true;
        }
        else
            cnt= 0 ;
    }
    return false;
}

bool all_ok(){
    if( K == 1) {
        return true;
    }
    for( int i=0; i< W; i++){
        if( is_ok(i) != true){
            return false;
        }
    }
    return true;
}
void fill_erase(int row , int med, int fe){
   
    for( int i=0; i< W ; i++){
        arr[row][i] = (fe==1?med:origin[row][i]);
    }
}

void DFS(int ptr, int depth){
    //cout<< depth<<endl;
    if( ptr == D){
        if( all_ok()){
            if( depth < result ){
                result = depth;
                return ;
            }
            
        }
        return;
    }
    if( depth >= result ){
        return;
    }
    
    DFS( ptr +1 , depth);
    fill_erase(ptr, 0, 1);
    DFS( ptr+1 ,depth +1);
    fill_erase(ptr, 1, 1);
    DFS( ptr+1 ,depth +1 );
    //지우기
    fill_erase(ptr, 2, 0);
    /*
    for( int i =0; i< D ; i++){
        if( visited[i] == 0 ){
            visited[i] = 1;
            fill_erase(i, 0, 1);
            DFS( depth +1);
            fill_erase(i, 1, 1);
            DFS( depth +1 );
            //지우기
            fill_erase(i, 2, 0);
            visited[i] = 0 ;
        }
        
    }
     */
    
}


int main(int argc, const char * argv[]) {
    
    int T;
    cin>> T;
    
    for(int t= 1; t <= T ; t++){
        
        cin>> D >> W >> K;
        result = K  ;
        for(int d=0 ;d < D ; d++){
            for(int w =0; w< W ; w++){
                cin>> arr[d][w];
                origin[d][w] = arr[d][w];
            }
        }
        DFS(0,0);
        
        
        cout<<"#"<<t<<" "<< result << endl;
    }
    
    
    
    
    return 0;
}
