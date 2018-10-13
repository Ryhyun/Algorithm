#include <iostream>
#include <vector>
using namespace std;
int numArr[12];
int operatorArr[12]={-1,};
int oper[4] ={0,};
int N;
int maxV ,minV;

void calculate(){
    int tempResult = numArr[0] ;
    
    for( int i=1; i< N ;i++){
        if( operatorArr[i-1] == 0 ){
            tempResult += numArr[i];
        }
        else if(operatorArr[i-1] == 1 ){
            tempResult -= numArr[i];
        }
        else if(operatorArr[i-1] == 2 ){
            tempResult *= numArr[i];
        }
        else{
            tempResult /= numArr[i];
        }
    }
    maxV = ( maxV > tempResult )? maxV: tempResult;
    minV = ( minV < tempResult )? minV: tempResult;
    
    
}

void recursive(int index, int depth, int value,int limit){
    if( value == 4){
        calculate();
        return;
    }
    if( index == N )
        return;
    if( depth == limit){
        recursive(0,0,value+1, oper[value+1]);
        return;
    }
    
    
    recursive(index+1, depth  , value,limit);
    if( operatorArr[index] == -1 ){
        operatorArr[index] = value;
        recursive(index+1, depth+1, value,limit);
        operatorArr[index] = -1;
    }
    
    
}


int main(int argc, const char * argv[]) {
    cin>>N;
    minV = 1000000000;
    maxV = -1000000000 ;
    for(int i=0; i<N; i++){
        cin>> numArr[i];
        operatorArr[i] = -1;
    }
    for(int i=0; i< 4 ;i++){
        cin>> oper[i];
    }
    recursive(0,0, 0,oper[0]);
    
    
    
    
    cout<< maxV <<endl<< minV<<endl;
    
    
    return 0;
}
