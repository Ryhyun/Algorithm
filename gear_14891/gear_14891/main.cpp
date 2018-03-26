
#include <iostream>
#include <deque>
using namespace std;

deque<int> gearQue[5];
deque<int>:: iterator qi;

void Turn(int i, int v){
    if( v == 1){
        int temp = gearQue[i].back();
        gearQue[i].pop_back();
        gearQue[i].push_front(temp);
    }
    else{
        int temp = gearQue[i].front();
        gearQue[i].pop_front();
        gearQue[i].push_back(temp);
    }
}

void goLeft(int s, int d,int v){
    if( d  <= 0 ){
        return;
    }
    else{
        if( gearQue[s][6] == gearQue[d][2]){
            return;
        }
        else{
            goLeft(d , d-1 , v * -1 );
            Turn(d,v * -1);
        }
    }
}
void goRight(int s, int d ,int v){
    if( d > 4){
        return;
    }
    else{
        if( gearQue[s][2] == gearQue[d][6]){
            return;
        }
        else{
            goRight(d , d+1 ,v * -1);
            Turn(d,v * -1);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    
    string gear[5];
    for(int i=1; i<=4; i++){
        cin>> gear[i];
        for( int j=0; j< 8 ; j++){
            gearQue[i].push_back( int( gear[i][j] - '0') );
        }
    }
    int k;
    cin>> k;
    
    for( int i=0; i< k ; i++){
        int g,v;
        cin>>g>>v;
        //cout<<g<<v;
        goRight(g, g+1,v);
        goLeft(g, g-1,v);
        Turn(g,v);
    }
  
    cout<< gearQue[1][0] * 1 + gearQue[2][0]*2 + gearQue[3][0] * 4 + gearQue[4][0] * 8 <<endl;
    
    
    
    
    
    
    
    return 0;
}
