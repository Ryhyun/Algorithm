
#include <iostream>
#include <queue> 
#include <deque>

using namespace std;
int n,m;
int miro[101][101];
int result =0 ;
int visitedArray[101][101] ;

void search(int cN, int cM){
    int moveN[4] = {1,0,0,-1};
    int moveM[4] = {0,1,-1,0};
    //cout<< cN<<" "<<cM<<" "<<cnt<<endl;
    queue<int> qN;
    queue<int> qM;
    queue<int> length;
    
    qN.push(cN);
    qM.push(cM);
    length.push(1);
    
    while( !qN.empty() and !qM.empty() ){
        int tempN = qN.front(); qN.pop();
        int tempM = qM.front(); qM.pop();
        //int tt = qTemp.front();
        int len = length.front(); length.pop();
        miro[tempN][tempM] = len++;
        
        if( tempN == n-1 and tempM == m-1){
            break;
        }
        for( int i=0; i< 4; i++){
            if( tempN + moveN[i] < 0 || tempN +  moveN[i] > n-1 ||  tempM + moveM[i] <0 || tempM+ moveM[i] > m-1 )
                continue;
            
            if( miro[tempN + moveN[i]][ tempM + moveM[i]] != 0  and visitedArray[tempN + moveN[i]][ tempM + moveM[i]] ==0){
                visitedArray[tempN + moveN[i]][ tempM + moveM[i]] = 1;
                qN.push( tempN+moveN[i]);
                qM.push( tempM+moveM[i]);
                length.push( len);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    scanf("%d%d", &n,&m);
    char input;
    for( int i=0; i<n;i++){
        scanf("%c",&input);
        //cin>> line;
        for(int j=0; j<m;j++){
            scanf("%c",&input);
            miro[i][j]= int(input - '0');
            visitedArray[i][j] = 0;
        }
    }
    visitedArray[0][0] =1 ;
    search(0,0);
    
    cout<<miro[n-1][m-1]<<endl;
    return 0;
}
