
#include <iostream>
using namespace std;

char arr[101][101];
int N;
/*
 축은 3
 ( 2, 3) -> (3 , 4)
 ( 3, 3) -> (3, 3);
 ( 4, 2) -> ( 2,2);
  (4,4) -> (4 ,2)
 
 
 */



void turn(){
    
    char tempA[101][101] ={0,};
    
    for( int i=0; i< N; i++){
        for(int j=0; j< N ; j++){
            tempA[j][N- i- 1] = arr[i][ j];
        }
    }
    for( int i=0; i< N; i++){
        for(int j=0; j< N ; j++){
            arr[i][j] = tempA[i][j];
            cout<< arr[i][j];
        }
        cout<<endl;
    }
}
int checkBottom(int col){
    for( int i=N-1; i>= 0  ; i--){
        if( arr[i][col]  == '.'){
            return i;
        }
        else{
            continue;
        }
    }
    return N;
}
void push(){
    for( int i=0; i< N; i++){
        for(int j= N- 1; j>= 0  ; j--){
            
            if( arr[j][i] != '.'){
                int tempRow = checkBottom(i);
                if( tempRow != N){
                    char tempC = arr[j][i];
                    arr[j][i] = arr[tempRow][i];
                    arr[tempRow][i] = tempC;
                }
            }
        }
    }
    for( int i=0; i< N; i++){
        for(int j=0; j< N ; j++){
            cout<< arr[i][j];
        }
        cout<< endl;
    }
}
void SpinAndSlide(){
    turn();
    push();
}
int main(int argc, const char * argv[]) {
    cin>> N;
    
    int play;
    cin >>play;
    
    for( int i=0; i< N; i++){
        for(int j=0; j< N ; j++){
            cin>> arr[i][j];
        }
    }
    for( int i=0 ; i< play; i++){
        SpinAndSlide();
        cout<< " -=-=- =-=- = -=- = -=- =- =- "<<endl;
    }
    
    return 0;
}
