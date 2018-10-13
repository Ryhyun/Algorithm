
#include <iostream>

#include <cstring>
#include <vector>

using namespace std;

int N,K;
int arr[101][101] ={0,};
int ni[4] = {0,1,0,-1};
int nj[4] = {1,0,-1,0};
int nowi,nowj;
int nowv;
vector<pair<int, char> > order;

int main(int argc, const char * argv[]) {
    cin>> N>>K;
    for( int k= 0; k< K; k++){
        int ti,tj;
        cin>> ti>> tj;
        arr[ti-1][tj-1] = -1;
    }
    int vT;
    cin >>vT;
    for(int v = 0; v < vT; v++){
        int X;
        char C;
        cin>> X >> C;
        order.push_back(make_pair(X,C));
    }
    nowi = 0; nowj = 0; nowv = 0;  // 0-오 1-아래 2 -좌 3 -위
    int length = 1;
    int nextAction =0 ;
    int nextSecond = order[nextAction].first; char nextVector = order[nextAction].second;
    int t;
    arr[nowi][nowj] = 1;
    for( t = 1; t< 10005 ; t++){
        int nexti = nowi + ni[nowv]; nowi = nexti;
        int nextj = nowj + nj[nowv]; nowj = nextj;
        
        if( nexti < 0 || nextj < 0 || nexti >= N || nextj >= N)
            break;
        
        if( arr[nexti][nextj] == -1){
            arr[nexti][nextj] = t + length;
            for( int i=0; i< N ; i++){
                for( int j=0; j< N;j++){
                    if( arr[i][j] >= t ){
                        arr[i][j]++;
                    }
                }
            }
            length++;
        }
        else if( arr[nexti][nextj] == 0 || arr[nexti][nextj] < t)
            arr[nexti][nextj] = t + length;
        else if( arr[nexti][nextj]  >= t)
            break;
        
        if( nextSecond == t ){
            nextAction++;
            nowv = ( nextVector == 'L') ? (nowv +3 ) % 4 : (nowv+1) % 4;
            if( nextAction < vT){
                nextSecond = order[nextAction].first;
                nextVector = order[nextAction].second;
            }
        }
    }
    cout<< t<<endl;
    return 0;
}








