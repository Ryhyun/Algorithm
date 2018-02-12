
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
    scanf("%d", &total);

    int stairScore[300] = {0,};

    for(int i=1;i <= total;i++){
        scanf("%d", &stairScore[total-i]);
    }


    //ÃÑ±æÀÌ 7
    int stairMemo[300][100][2] = {0,};
    int result=0 ;

    stairMemo[0][0][0] = stairScore[0];


    for( int i=0; i< total; i++){
        for( int j=0; j< total; j++){
            if( stairMemo[i][j][0] != 0 ){
                if( stairMemo[i][j][0] + stairScore[j+1] > stairMemo[i][j+1][0]  ){
                    stairMemo[i+1][j+1][1] = stairMemo[i][j][0] + stairScore[j+1];
                    if( result < stairMemo[i+1][j+1][1] )
                        result=stairMemo[i+1][j+1][1];
                }
                if( stairMemo[i][j][0] + stairScore[j+2] > stairMemo[i][j+2][0]  or stairMemo[i][j][0] + stairScore[j+2]> stairMemo[i][j+2][1]){
                    stairMemo[i+1][j+2][0] = stairMemo[i][j][0] + stairScore[j+2];
                    if( result < stairMemo[i+1][j+2][0] )
                        result=stairMemo[i+1][j+2][0];
                }
            }

            if( stairMemo[i][j][1] != 0){
                if( stairMemo[i][j][1] + stairScore[j+2] > stairMemo[i][j+2][0]  or stairMemo[i][j][1] + stairScore[j+2]> stairMemo[i][j+2][1]){
                    stairMemo[i+1][j+2][0] = stairMemo[i][j][1] + stairScore[j+2];
                    if( result < stairMemo[i+1][j+2][0] )
                        result=stairMemo[i+1][j+2][0];
                }
            }
        }
    }

    /*
    for( int i=0; i< total; i++){
        for( int j=0; j< total; j++){
            cout<<"i: "<<i<<" j: "<<j<<" result: "<<stairMemo[i][j][0] << " "<< stairMemo[i][j][1]<< " ";
        }
        cout<<endl;
    }
    */

    cout<< result<<endl;


    return 0;
}
