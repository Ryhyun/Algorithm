#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int result = 0;
int swapG;

string swapString( string tempV, int s, int e){
    string V = tempV;
    
    char temps = V[s];
    V[s] = V[e];
    V[e] = temps;
    
    return V;
}
/*
 
 1
 777770 5
 
1
 436659 2

 */


void swap_recursive( string tempV,int s, int swapV ){
    // 자리 안 바꿨을 때
    
    if( swapV < swapG){
        //cout<< swapV <<" "<< s<<" "<<tempV<<endl;
        int biggest=0 ;
        vector<int> indexVec;
        vector<int>::iterator iv;
        for( int i = s; i < tempV.length(); i++){
        
            if( int(tempV[i]- '0') == biggest ){
                indexVec.push_back( i);
            }
            else if( int(tempV[i] - '0') > biggest ){
                biggest = int(tempV[i] - '0');
                //cout<<biggest<<endl;
                indexVec.clear();
                indexVec.push_back( i);
                
            }
        }
        
        //cout<< "s: "<< s<< " "<< biggest<<endl;
        if( s == tempV.length() -2 ){
            swap_recursive(swapString(tempV, s,s+1 ) ,0, swapV+1);
            swap_recursive(swapString(tempV, s,s-1 ) ,0, swapV+1);
        }
        
        if( int( tempV[s] - '0') == biggest){
            swap_recursive( tempV, s+1 , swapV);
        }
        else{
            for( iv =indexVec.begin(); iv != indexVec.end() ; iv++){
                swap_recursive(swapString(tempV, s, *iv) ,0, swapV+1);
            }
        }
        
    }
    // 다 자리 바꿨을 때
    else{
        //cout<< tempV << " "<< swapV<< endl;
        if(  atoi(tempV.c_str()) > result) {
            result = atoi( tempV.c_str());
        }
        
    }

}

int main(int argc, const char * argv[]) {
    
    int N;
    cin>> N ;
    // N번만큼 출력
    for(int i = 1; i<= N ; i++){
        //
        result= 0;
        string value;
        cin>> value;
        cin>> swapG;
        // swap 만큼 반복
        swap_recursive(value,0, 0);
        
        
        cout<<"#"<<i<<" "<< result<<endl;
    }
    
    return 0;
}

