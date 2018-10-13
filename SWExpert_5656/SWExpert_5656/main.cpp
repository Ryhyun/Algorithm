
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int N,W,H;
int result;
int arr[16][13];
void bomb(int ti, int tj,int(* pArr)[13]){
    int value = pArr[ti][tj] ;
    pArr[ti][tj] = 0 ;
    //cout<<"bomb "<< ti<<" "<< tj<<endl;
    for( int j = tj+1 ; j < tj+ value && j < W ; j++){
        if( pArr[ti][j] != 0 ){
            //pArr[ti][j] = 0 ;
            bomb( ti,j,pArr);
        }
    }
    for( int j = tj-1 ; j > tj - value && j >= 0 ; j--){
        if( pArr[ti][j] != 0 ){
            //pArr[ti][j] = 0 ;
            bomb( ti,j,pArr);
        }
    }
    for( int i = ti+1 ; i < ti+ value && i < H ; i++){
        if( pArr[i][tj] != 0 ){
            //pArr[i][tj] = 0 ;
            bomb( i,tj,pArr);
        }
    }
    for( int i = ti-1 ; i > ti - value && i >= 0 ; i--){
        if( pArr[i][tj] != 0 ){
            //pArr[i][tj] = 0 ;
            bomb( i,tj,pArr);
        }
    }
    
    
}
void dash(int(* pArr)[13]){
    for( int i= 0; i< W; i++){
        
        int zero=0;
        for(int j= H-1; j>= 0 ; j--){
            if( pArr[j][i] == 0){
                zero = j;
                for(int k= j-1; k >= 0 ;k--){
                    if( pArr[k][i] != 0 ){
                        int temp = pArr[k][i];
                        pArr[k][i] = pArr[zero][i];
                        pArr[zero][i] = temp;
                        break;
                    }
                }
            }
        }
        
    }
}
void tuha(int n,int w,int pArr[16][13]){
    
    
    if( n == N){
        //count
        //cout<<"-=-=-=-=-=-= "<< n<<endl;
        int tempResult=0;
        for(int i=0; i< H; i++){
            for(int j=0; j< W; j++){
                if( pArr[i][j] !=0){
                    tempResult++;
                }
            }
        }
        result = (result < tempResult)? result: tempResult;
        return;
    }
    if( w == W){
        return;
    }
    int tempArr[16][13];
    
    bool endchk =false;
    for(int k= 0 ; k< W ; k++){
        
        for( int i=0; i< H; i++){
            for(int j=0; j< W; j++){
                tempArr[i][j]= pArr[i][j];
            }
        }
        for( int i =0; i< H;i++){
            if( pArr[i][k] != 0 ){
                endchk =true;
                bomb(i,k,tempArr);
                dash(tempArr);
                /*
                cout<< n<<" "<<i <<" "<< k<<endl;
                for(int ii=0; ii< H; ii++){
                    for(int j=0; j< W; j++){
                        cout<< tempArr[ii][j]<<" ";
                    }
                    cout<<endl;
                }
                 */
                
                tuha( n+1, k,tempArr);
                //tuha( n , w + 1, pArr);
                break;
            }
            else
                continue;
        }
    }
    if( endchk == false){
        result= 0;
        return;
    }
}
/*
1
 1 10 10
 0 0 0 0 0 0 0 0 0 0
 1 0 1 0 1 0 0 0 0 0
 1 0 3 0 1 1 0 0 0 1
 1 1 1 0 1 2 0 0 0 9
 1 1 4 0 1 1 0 0 1 1
 1 1 4 1 1 1 2 1 1 1
 1 1 5 1 1 1 1 2 1 1
 1 1 6 1 1 1 1 1 2 1
 1 1 1 1 1 1 1 1 1 5
 1 1 7 1 1 1 1 1 1 1
 */

int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    
    for( int casei=1 ; casei<= T; casei++){
        
        cin>> N>> W>>H;
        result =10000 ;
        memset(arr, 0, sizeof(arr));
        for(int i=0; i< H;i++){
            for(int j=0; j< W; j++){
                cin>> arr[i][j];
            }
        }
        
        tuha(0,0,arr);
      
        
        cout<<"#"<<casei<<" "<< result<<endl;
    }
    
    
    
    return 0;
}
