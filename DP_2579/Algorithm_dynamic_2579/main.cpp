
/*
6
10
20
15
25
10
20
*/
#include <iostream>

using namespace std;

int main() {
    int total;
    cin>> total;

    int stairScore[302] = {0,};

    for(int i=1;i <= total;i++){
        cin>> stairScore[total-i] ;
    }
    
    int stairMemo[302][2] = {0,};
    stairMemo[0][0] = stairScore[0];
    
    for(int i=0; i<total ; i++){
        stairMemo[i+2][0] = max( stairMemo[i][0] +stairScore[i+2], stairMemo[i][1] + stairScore[i+2] );
        stairMemo[i+1][1] = stairMemo[i][0] + stairScore[i+1];
        
    }


    cout<< max( max( stairMemo[total-1][0], stairMemo[total-1][1]), stairMemo[total-2][1]);
    
    return 0;
}
