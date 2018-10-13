
#include <iostream>
#include <vector>

using namespace std;
int N,M;
int arr[9][9];
vector<pair<int,int> > cctvVec;
int result ;
//int ni[4] = { -1, 0, 1, 0 };
//int nj[4] = {  0, 1, 0 ,-1};

/*
 1 -> 상하좌우
 2 -> 상하, 좌우
 3 -> 상우, 우하, 하좌, 좌상
 4 -> 상우하 , 우하좌, 하좌상, 좌상우
 5 ->
 */
void countResult(int tempArr[9][9]){
    int tempResult =0  ;
    for( int i=0; i< N ; i++){
        for( int j=0 ; j< M;j++){
            if( tempArr[i][j] == 0 ){
                tempResult++;
            }
        }
    }
    if( result > tempResult )
        result = tempResult;
}
void fillAndErase(int ci,int cj,int v ,int fe,int tempArr[9][9]){
    // fe == 0  erase
    // fe == 1  fill
    // 상
    if( v  > 3 )
        v = v % 4;
    
    if( v== 0 ){
        while( ci > 0  ){
            ci--;
            if( tempArr[ci][cj] == 6)
                return;
            tempArr[ci][cj] = ( fe == 0)? 0:1;
        }
    }
    // 우
    else if( v == 1){
        while( cj < M  ){
            cj++;
            if( tempArr[ci][cj] == 6)
                return;
            tempArr[ci][cj] = ( fe == 0)? 0:1;
        }
    }
    // 하
    else if( v== 2 ){
        while( ci < N   ){
            ci++;
            if( tempArr[ci][cj] == 6)
                return;
            tempArr[ci][cj] = ( fe == 0)? 0:1;
        }
    }
    // 좌
    else{
        while( cj > 0  ){
            cj--;
            if( tempArr[ci][cj] == 6)
                return;
            tempArr[ci][cj] = ( fe == 0)? 0:1;
        }
    }
}
void recursive(int depth,int tempA[9][9]){
    //cout<<depth<<" "<< cctvVec.size()<<endl;
    if( depth == cctvVec.size()){
        countResult(tempA);
        return;
    }
    int tempi = cctvVec[depth].first;
    int tempj = cctvVec[depth].second;
    
    
    if( arr[tempi][tempj] == 1 ){
        for( int v=0 ; v< 4; v++){
            int tempArr[9][9] ;
            for( int i=0; i< N ; i++){
                for( int j=0 ; j< M;j++){
                    tempArr[i][j] = tempA[i][j];
                }
            }
            fillAndErase(tempi,tempj,v,1,tempArr);
            recursive(depth+1,tempArr);
        }
    }
    else if( arr[tempi][tempj] == 2 ){
        for( int v = 0 ; v <2; v++){
            int tempArr[9][9] ;
            for( int i=0; i< N ; i++){
                for( int j=0 ; j< M;j++){
                    tempArr[i][j] = tempA[i][j];
                }
            }
            fillAndErase(tempi,tempj,v,1,tempArr);
            fillAndErase(tempi,tempj,v+2,1,tempArr);
            recursive(depth+1,tempArr);
        }
    }
    else if(  arr[tempi][tempj] == 3 ){
        for( int v=0 ; v< 4; v++){
            int tempArr[9][9] ;
            for( int i=0; i< N ; i++){
                for( int j=0 ; j< M;j++){
                    tempArr[i][j] = tempA[i][j];
                }
            }
            fillAndErase(tempi,tempj,v,1,tempArr);
            fillAndErase(tempi,tempj,v+1,1,tempArr);
            recursive(depth+1,tempArr);
        }
    }
    else if(  arr[tempi][tempj]== 4 ){
        for( int v=0 ; v< 4; v++){
            int tempArr[9][9] ;
            for( int i=0; i< N ; i++){
                for( int j=0 ; j< M;j++){
                    tempArr[i][j] = tempA[i][j];
                }
            }
            fillAndErase(tempi,tempj,v,1,tempArr);
            fillAndErase(tempi,tempj,v+1,1,tempArr);
            fillAndErase(tempi,tempj,v+2,1,tempArr);
            recursive(depth+1,tempArr);
        }
    }
    else if(  arr[tempi][tempj] == 5 ){
        int tempArr[9][9] ;
        for( int i=0; i< N ; i++){
            for( int j=0 ; j< M;j++){
                tempArr[i][j] = tempA[i][j];
            }
        }
        fillAndErase(tempi,tempj,0,1,tempArr);
        fillAndErase(tempi,tempj,1,1,tempArr);
        fillAndErase(tempi,tempj,2,1,tempArr);
        fillAndErase(tempi,tempj,3,1,tempArr);
        recursive(depth+1,tempArr);
    }
    
    
}

int main(int argc, const char * argv[]) {
    cin>> N >> M;
    result = 50;
    for( int i=0 ; i< N ; i++){
        for( int j=0 ; j< M ; j++){
            cin>> arr[i][j];
            if( arr[i][j] != 0 && arr[i][j] != 6){
                cctvVec.push_back(make_pair( i,j));
            }
        }
    }
   
    recursive(0,arr);
    
    cout<<result<<endl;
    
    
    

    return 0;
}
