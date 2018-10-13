
#include <iostream>
using namespace std;

int N,M;
int arr[501][501];
int result= -100000;
// 일자
void polyomino1(int pi, int pj){
    if( pi +3 < N)
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+2][pj] + arr[pi+3][pj])?
                    result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+2][pj] + arr[pi+3][pj];
    if( pj +3 < M)
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi][pj+2] + arr[pi][pj+3])?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi][pj+2] + arr[pi][pj+3];
}
// 정사각형
void polyomino2(int pi, int pj){
    if( pi+1 <N && pj +1 < M)
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj] + arr[pi+1][pj+1]) ?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj] + arr[pi+1][pj+1];
}
// L
void polyomino3(int pi, int pj){
    // L
    if( pi+2 <N && pj +1 < M){
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+2][pj] + arr[pi+2][pj+1]) ?
                    result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+2][pj] + arr[pi+2][pj+1];
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi+2][pj+1])?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi+2][pj+1];
    }
    if( pi+2 <N && pj >0 ){
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+2][pj] + arr[pi+2][pj-1]) ?
                    result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+2][pj] + arr[pi+2][pj-1];
        result = ( result > arr[pi][pj] + arr[pi][pj-1] + arr[pi+1][pj-1] + arr[pi+2][pj-1])?
                    result :  arr[pi][pj] + arr[pi][pj-1] + arr[pi+1][pj-1] + arr[pi+2][pj-1];
    
    }
    // ㄱ
    if( pi+1 <N && pj +2 < M){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi][pj+2] + arr[pi+1][pj+2])?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi][pj+2] + arr[pi+1][pj+2];
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+1][pj+2])?
                    result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+1][pj+2];
    }
    if( pi >0 && pj +2 < M){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi][pj+2] + arr[pi-1][pj+2])?
                result : arr[pi][pj] + arr[pi][pj+1] + arr[pi][pj+2] + arr[pi-1][pj+2];
        result = ( result > arr[pi][pj] + arr[pi-1][pj] + arr[pi-1][pj+1] + arr[pi-1][pj+2])?
                result :arr[pi][pj] + arr[pi-1][pj] + arr[pi-1][pj+1] + arr[pi-1][pj+2];
    
    }

}
// 번개
void polyomino4(int pi, int pj){
    if( pi+1 <N && pj +2 < M){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi+1][pj+2])?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi+1][pj+2];
        if( pi > 0 )
            result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi-1][pj+1] + arr[pi-1][pj+2])?
                        result : arr[pi][pj] + arr[pi][pj+1] + arr[pi-1][pj+1] + arr[pi-1][pj+2];
    }
    if( pi+2 <N && pj +1 < M){
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+2][pj+1])?
                    result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+2][pj+1];
        if( pj > 0 )
            result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj-1] + arr[pi+2][pj-1])?
                        result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj-1] + arr[pi+2][pj-1];
    }
}
// ㅜ
void polyomino5(int pi, int pj){
    if( pi+1 <N && pj +2 < M){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi][pj+2])?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi][pj+2];
    }
    if(pi+1 <N && pi > 0 ){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi-1][pj+1] + arr[pi][pj+2])?
                    result : arr[pi][pj] + arr[pi][pj+1] + arr[pi-1][pj+1] + arr[pi][pj+2];
    }

    if( pi+2 <N && pj +1 < M){
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+2][pj])?
                    result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+2][pj];
    }
    if(pi+2 <N && pj > 0 ){
            result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj-1] + arr[pi+2][pj])?
                        result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj-1] + arr[pi+2][pj];
    }
}

int main(int argc, const char * argv[]) {
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j< M ;j++){
            cin>> arr[i][j];
        }
    }
    
    for(int i=0; i< N ; i++){
        for(int j=0; j<M; j++){
            polyomino1(i,j);
            //cout<< result<<endl;
            polyomino2(i,j);
            //cout<< result<<endl;
            
            polyomino3(i,j);
            //cout<< result<<endl;
            polyomino4(i,j);
            //cout<< result<<endl;
            polyomino5(i,j);
            //cout<< result<<endl;
        }
    }
    cout<< result<<endl;
    
    return 0;
}
