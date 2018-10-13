#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[101][101] = {0,};

int nx[4] = { 1,0 , -1, 0};
int ny[4] = { 0,-1, 0, 1};
vector<int> Vvec;

int lastX ;
int lastY ;
void turnCurve(){
    int goLen = Vvec.size();
    vector<int> tempVec = Vvec;
    for( int i =0; i< goLen; i++){
        int nextV = (tempVec[(tempVec.size() - 1 -i ) ]  + 1) % 4 ;
        //cout<< nextV << "---:  "<< tempVec[(tempVec.size() - 1 -i ) ]  <<endl;;
        int nextX = lastX + nx[  nextV ] ;
        int nextY = lastY + ny[  nextV ] ;
        //cout<< nextX<<" "<<nextY <<endl;
        arr[nextX][nextY] = 1 ;
        lastX = nextX;
        lastY = nextY;
        Vvec.push_back(nextV);
    }
    
    
    
}
void dragonCurve(int X,int Y,int V, int Gen){
    
    int nowX = X ;
    int nowY = Y ;
    arr[nowX][nowY] = 1 ;
    Vvec.push_back(V);
    lastX = nowX + nx[V];
    lastY = nowY +ny[V];
    arr[lastX][lastY] = 1;
    for( int g=1; g<= Gen ; g++ ){
        
        turnCurve( );
        
    }
    
}
int main(int argc, const char * argv[]) {
    int N;
    cin>> N;
    
    for( int i=0; i< N ; i++){
        int X,Y,V,G;
        cin>> X >> Y >> V >> G;
        dragonCurve(X,Y,V,G);
        Vvec.clear();
    }
    int result= 0 ;
    for( int i =0 ; i< 100 ; i++){
        for( int j=0; j< 100; j++){
            if( arr[i][j] ==1 && arr[i+1][j]==1 && arr[i][j+1] ==1 && arr[i+1][j+1] ==1){
                result++;
            }
            else{
                continue;
            }
        }
        
        
    }
    cout<<result<<endl;
    
    return 0;
}
