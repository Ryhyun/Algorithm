#include <iostream>
using namespace std;

int N,M;
int arr[21][21]= {0,};
int si,sj;
int orderN;
int ni[4] ={0,0,-1,1};
int nj[4] ={1,-1,0,0};

// 아래, 앞, 위 , 뒤 , 좌 , 우
int dice[6] = {0,0,0,0,0,0};


void move(int pi, int pj, int order){
    int nexti = pi + ni[order];
    int nextj = pj + nj[order];
    if( nexti < 0 || nextj < 0 || nexti >= N || nextj >=M)
        return;
    
    si = nexti;
    sj = nextj;
    
    int tempD[6];
    for(int i=0; i< 6;i++){
        tempD[i] = dice[i];
    }
    // 동
    if( order == 0 ){
        if( arr[si][sj] == 0 ){
            dice[0] = tempD[5];
            dice[2] = tempD[4];
            dice[4] = tempD[0];
            dice[5] = tempD[2];
            arr[si][sj] = dice[0];
        }
        else{
            dice[0] = arr[si][sj];
            dice[2] = tempD[4];
            dice[4] = tempD[0];
            dice[5] = tempD[2];
            arr[si][sj] = 0;
        }
    }
    // 서
    else if( order ==1 ){
        if( arr[si][sj] == 0 ){
            dice[0] = tempD[4];
            dice[2] = tempD[5];
            dice[4] = tempD[2];
            dice[5] = tempD[0];
            arr[si][sj] = dice[0];
        }
        else{
            dice[0] = arr[si][sj];
            dice[2] = tempD[5];
            dice[4] = tempD[2];
            dice[5] = tempD[0];
            arr[si][sj] = 0;
        }
    }
    // 북
    // 아래, 앞, 위 , 뒤 , 좌 , 우
    else if( order == 2 ){
        if( arr[si][sj] == 0 ){
            dice[0] = tempD[3];
            dice[1] = tempD[0];
            dice[2] = tempD[1];
            dice[3] = tempD[2];
            arr[si][sj] = dice[0];
        }
        else{
            dice[0] = arr[si][sj];
            dice[1] = tempD[0];
            dice[2] = tempD[1];
            dice[3] = tempD[2];
            arr[si][sj] = 0;
        }
    }
    // 남
    else {
        if( arr[si][sj] == 0 ){
            dice[0] = tempD[1];
            dice[1] = tempD[2];
            dice[2] = tempD[3];
            dice[3] = tempD[0];
            arr[si][sj] = dice[0];
        }
        else{
            dice[0] = arr[si][sj];
            dice[1] = tempD[2];
            dice[2] = tempD[3];
            dice[3] = tempD[0];
            arr[si][sj] = 0;
        }
    }
    //for(int i=0; i<6; i++){
    cout<< dice[2]<<endl;;
    
    //cout<<endl;
}

int main(int argc, const char * argv[]) {
    cin>>N>>M;
    cin>> si>> sj;
    cin>> orderN;
    for(int i=0; i< N; i++){
        for(int j=0 ; j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i< orderN; i++){
        int order;
        cin>>order;
        move(si,sj,order-1);
    }
    
    
    return 0;
}
