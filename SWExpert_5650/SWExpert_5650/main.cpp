
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int result;
int N;
int arr[MAX][MAX];
int ni[4] = {0,1,0,-1};
int nj[4] = {1,0,-1,0};
int starti, startj;
struct hole{
    int i;
    int j;
    int v;
    int connecti;
};
vector< hole > holeVec;

void pushhole(int pi,int pj, int pv){
    int len = holeVec.size();
    for(int i=0; i< len ;i++){
        if( holeVec[i].v == pv){
            hole tempHole = { pi,pj, pv,i};
            holeVec.push_back( tempHole);
            holeVec[i].connecti = len;
            return;
        }
    }
    hole tempHole = { pi,pj, pv,0};
    holeVec.push_back(tempHole);
    
    
}
void recursive(int si,int sj, int sv,int value){
    bool endChk = false;
    int nexti = si;
    int nextj = sj;
    while(!endChk){
        nexti = nexti + ni[sv];
        nextj = nextj + nj[sv];
        //cout<< nexti<<" "<< nextj<< endl;
        // 종료조건
        if( (nexti == starti && nextj == startj) || arr[nexti][nextj] == -1 ){
            result = ( result > value) ? result: value;
            endChk = true;
            return;
        }
        // 맵 바깥
        else if( nexti < 0 || nextj < 0 || nexti >= N || nextj >= N){
            //recursive(nexti,nextj, (sv+2) %4, value+1);
            sv = (sv+2) %4;
            value++;
        }
        
        
        // 벽
        // 우 하 좌 상
        else if( arr[nexti][nextj] > 0 && arr[nexti][nextj] < 6){
            // if 1
            if( arr[nexti][nextj]== 1){
                if( sv == 0 || sv == 3){
                    //recursive(nexti,nextj, (sv+2) % 4, value+1);
                    sv = ( sv+2) % 4;
                    value++;
                }
                else if( sv == 1 || sv == 2){
                    int tempV = (sv == 1)? 0 : 3;
                    //recursive( nexti,nextj, tempV, value+1);
                    sv = tempV;
                    value++;
                }
            }
            // if 2
            else if( arr[nexti][nextj]== 2){
                if( sv == 0 || sv == 1){
                    //recursive(nexti,nextj, (sv+2) % 4, value+1);
                    sv = (sv+2)%4;
                    value++;
                }
                else if( sv == 2 || sv == 3){
                    int tempV = (sv == 2)?  1 : 0;
                    //recursive( nexti,nextj, tempV, value+1);
                    sv = tempV;
                    value++;
                }
            }
            // if 3
            else if( arr[nexti][nextj]== 3){
                if( sv == 1 || sv == 2){
                    //recursive(nexti,nextj, (sv+2) % 4, value+1);
                    sv = (sv+2)%4;
                    value++;
                }
                else if( sv == 0 || sv == 3){
                    int tempV = (sv == 0)? 1 : 2;
                    //recursive( nexti,nextj, tempV, value+1);
                    sv= tempV;
                    value++;
                }
            }
            // if 4
            else if( arr[nexti][nextj]== 4){
                if( sv == 2 || sv == 3){
                    recursive(nexti,nextj, (sv+2) % 4, value+1);
                    sv = (sv+2)%4;
                    value++;
                }
                else if( sv == 0 || sv == 1){
                    int tempV = (sv == 0)? 3 : 2;
                    //recursive( nexti,nextj, tempV, value+1);
                    sv = tempV;
                    value++;
                }
            }
            // if 5
            else if( arr[nexti][nextj] == 5){
                //recursive(nexti,nextj, (sv+2) %4, value+1);
                sv= (sv+2)%4;
                value++;
            }
        }
        // 웜홀
        else if( arr[nexti][nextj] > 5 && arr[nexti][nextj] < 11){
            for( int i=0; i< holeVec.size(); i++){
                if( holeVec[i].i == nexti && holeVec[i].j == nextj){
                    int anotherHolei = holeVec[i].connecti;
                    //recursive(  holeVec[ anotherHolei].i, holeVec[anotherHolei].j, sv,value);
                    nexti = holeVec[ anotherHolei].i;
                    nextj = holeVec[anotherHolei].j;
                    break;
                }
            }
            
        }
        //else if( arr[nexti][nextj] == 0 )
            //recursive(nexti, nextj, sv, value);
            
    }
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for(int casei =1; casei <= T ; casei++ ){
        result= 0;
        holeVec.clear();
        cin>>N;
        for(int i=0; i< N; i++){
            for(int j=0; j<N; j++){
                cin>> arr[i][j];
                if( arr[i][j] >5 && arr[i][j] < 11){
                    pushhole(i,j, arr[i][j]);

                }
            }
        }
        /*
        for(int i=0; i< holeVec.size(); i++){
            //cout<< holeVec[i].i<<" " << holeVec[i].j<<" "<< holeVec[i].v<<" "<< holeVec[i].connecti<<endl;
        }
        */
        
        for(int i=0; i< N; i++){
            for(int j=0; j<N; j++){
                starti = i; startj = j ;
                for( int v= 0 ; v < 4; v++){
                    if( arr[starti][startj] == 0 ){
                        //cout<<"!!@!@!@!@!@ "<< starti <<" "<< startj<<" "<< v<<endl;
                        recursive(starti, startj, v,0);
                    }
                }
            }
        }
        
        cout<<"#"<<casei<<" "<< result<<endl;
    }
    
    return 0;
}
