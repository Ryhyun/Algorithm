
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[51][51];
int result ;
vector<pair<int,int> > homeVec;
vector<pair<int,int> > chickenVec;
int marr[14];

void calculate(){
    
    int tempResult = 0;
    for( int hi = 0 ; hi < homeVec.size(); hi++){
        int homeI = homeVec[hi].first;
        int homeJ = homeVec[hi].second;
        int distance = 10000;
        for( int i=0 ;i< M; i++){
            int chiI = chickenVec[marr[i]].first;
            int chiJ = chickenVec[marr[i]].second;
            //cout<< chiI <<" "<< chiJ<<endl;
            int tempDistance = abs( chiI - homeI) + abs( chiJ - homeJ);
            if( tempDistance < distance){
                distance = tempDistance;
            }

        }
        tempResult+= distance ;
    }
    
    
    if( result > tempResult ){
        result = tempResult;
    }
}

void recursive(int index,int cnt){
    //cout<< index<< " "<< cnt<<endl;
    if( cnt == M ){
        calculate();
        return;
    }
    if( index == chickenVec.size() ){
        return;
    }
    
    marr[cnt] = index;
    recursive(index +1 , cnt+1 );
    recursive(index +1, cnt);
    //marr[cnt] = 0;
    
}

int main(int argc, const char * argv[]) {

    
    cin>> N >> M ;
    result = 100000 ;
    for( int i=0 ; i< N ; i++){
        for( int j=0 ; j<N; j++){
            cin>> arr[i][j];
            if( arr[i][j] == 1 ){
                homeVec.push_back( make_pair(i,j));
            }
            else if( arr[i][j] == 2) {
                chickenVec.push_back(make_pair(i,j));
            }
        }
    }
    // 치킨집 중 3개 뽑기
    
    recursive(0,0);
    
    cout<< result<<endl;
    
    return 0;
}
