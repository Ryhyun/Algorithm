
#include <iostream>
using namespace std;

int N,L;
int arr[101][101];

int result ;

void countClimb(int si,int sj, int rc){
    // 세로
    if( rc== 0 ){
        int pre= arr[si][sj];
        int tempL=1 ;
        for(int i=1; i< N ; i++){
            if( abs( pre- arr[si+i][sj] ) > 1 )
                return;
            if( pre < arr[si+i][sj] ){
                if( tempL >= L ){
                    tempL= 1;
                    pre= arr[si+i][sj];
                }
                else{
                    return;
                }
            }
            else if( pre> arr[si+i][sj]){
                if( tempL >= 0 ){
                    tempL=(L-1) * -1 ;
                    pre= arr[si+i][sj];
                }
                else{
                    return;
                }
            }
            else{
                tempL++;
            }
        }
        if( tempL < 0 ){
            return;
        }
    }
    // 가로
    else{
        
        int pre= arr[si][sj];
        int tempL=1 ;
        for(int i=1; i< N ; i++){
            if( abs( pre- arr[si][sj+i] ) > 1 )
                return;
            if( pre < arr[si][sj+i] ){
                if( tempL >= L ){
                    tempL= 1;
                    pre= arr[si][sj+i];
                }
                else{
                    return;
                }
            }
            else if( pre> arr[si][sj+i]){
                if( tempL >= 0  ){
                    tempL=(L-1) * -1 ;
                    pre= arr[si][sj+i];
                }
                else{
                    return;
                }
            }
            else{
                tempL++;
            }
        }
        if( tempL < 0 ){
            return;
        }
    }
    //cout<< si<<" "<< sj<<" "<< rc<<endl;
    result++;
    
}
int main(int argc, const char * argv[]) {
    cin>>N>>L;
    result =0 ;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i <N; i++){
        countClimb(0,i,0);
    }
    for(int i=0;i <N; i++){
        countClimb(i,0,1);
    }
    cout<< result<<endl;
    
    
    
    return 0;
}
