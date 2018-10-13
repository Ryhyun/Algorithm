
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 N(짝수)끼리 축구를 한다.
 N/2 , N/2로 나누어서 스타트팀 링크팀으로 나눔
 1 ~ N 로 배정
 능력치가 최소가 되도록
 */
int N ;
int arr[21][21];
int result ;

void evaluate(vector<int> tempVector){
    int teamStart=0 ;
    int teamLink =0 ;
    
    vector<int> anotherVector;
    int tempi= 0;
    for( int i=0; i<N; i++){
        
        if( tempi < N/2){
            if( tempVector[tempi] == i ){
                tempi++;
                continue;
            }
        }
        anotherVector.push_back(i);
    }
    for( int i=0; i<N/2; i++){
        for(int j= i+1; j<N/2; j++){
            int ti = tempVector[i];
            int tj = tempVector[j];
            teamStart += arr[ti][tj];
            teamStart += arr[tj][ti];
        }
    }
    for( int i=0; i<N/2; i++){
        for(int j= i+1; j<N/2; j++){
            int ti = anotherVector[i];
            int tj = anotherVector[j];
            teamLink += arr[ti][tj];
            teamLink += arr[tj][ti];
        }
    }
    if( abs( teamLink - teamStart ) < result){
        result = int( abs( teamLink - teamStart )) ;
    }
}
void recursive(int index , int depth ,vector<int> tempVector){

    if( index >= N)
        return;
    
    if( depth == N/2){
        evaluate(tempVector);
        return;
    }
    tempVector[depth] = index;
    recursive(index+1, depth, tempVector);
    recursive(index+1, depth+1, tempVector);

}
int main(int argc, const char * argv[]) {
    cin >> N;
    result =1000 ;
    for( int i=0; i< N; i++){
        for( int j=0; j<N ; j++){
            cin>> arr[i][j];
        }
    }
    vector<int> vec(11);
    recursive(0,0,vec);
    
    cout<<result<<endl;
    
    
    
    
    
    return 0;
}
