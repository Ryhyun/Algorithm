#include <iostream>


using namespace std;

int N,M;
int arr[51][51]= { 0,} ;
int roboti, robotj, robotv;

int ni[4]= {-1,0,1,0 };
int nj[4]= {0, 1, 0, -1 };
int result;
/*
 0 - 상
 1-  우
 2-  하
 3 - 좌

 */
int main(int argc, const char * argv[]) {
    cin>>N>>M;
    cin>> roboti >> robotj >> robotv;
    result = 1 ;
    for( int i=0; i<N ;i++){
        for( int j=0; j<M ; j++){
            cin>> arr[i][j] ;
        }
    }
    bool endChk = false;
    
    while( endChk == false){
        arr[roboti][robotj]= 2;
        for( int i= robotv ; i >  robotv-4; i--){
            int tempV = (i+ 3 ) % 4;
            int nexti = roboti + ni[tempV];
            int nextj = robotj + nj[tempV];
            if( arr[nexti][nextj] == 0 ){
                roboti = nexti;
                robotj = nextj;
                robotv= tempV;
                result++;
                break;
            }
            
            if( arr[nexti][nextj] == 1 || nexti < 0 || nextj < 0 || nexti >= N || nextj >= M  || arr[nexti][nextj] == 2){
                if( i == robotv - 3){
                    if( tempV == 0 ){
                        roboti += 1;
                        robotv = tempV;
                        if( roboti >= N || arr[roboti][robotj] ==1)
                            endChk =true;
                        
                    }
                    else if( tempV == 1){
                        robotj -= 1 ;
                        robotv = tempV;
                        if( robotj < 0 || arr[roboti][robotj] ==1)
                            endChk =true;
                    }
                    
                    else if( tempV == 2){
                        roboti -= 1 ;
                        robotv = tempV;
                        if( roboti <0  || arr[roboti][robotj] ==1)
                            endChk =true;
                    }
                    else{
                        robotj += 1;
                        robotv = tempV;
                        if( robotj >=M || arr[roboti][robotj] ==1)
                            endChk =true;
                    }
                    
                }
                continue;
            }
            
            
        }
    }
    cout<< result<<endl;
    
    return 0;
}
