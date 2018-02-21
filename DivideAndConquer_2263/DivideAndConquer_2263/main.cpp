
#include <iostream>


using namespace std;

/*
3
1 2 3
1 3 2
 
9
1 2 3 4 5 6 7 8 9
1 3 2 4 7 9 8 6 5
*/
int n;
int inOrder[100001];
int postOrder[100001];
int specialEnd ;


void DAC(int is,int ie, int ps,int pe ){
    if( is >  ie || ps > pe ){
        return;
    }
    
    int root = postOrder[pe];
    printf("%d ",root);
    int rootIndex = inOrder[root];
    
    DAC( is,rootIndex-1, ps, ps + rootIndex -is -1);
    DAC( rootIndex +1,ie , ps + rootIndex - is , pe-1);
    
}
 int main(int argc, const char * argv[]) {
    
    cin>> n;
    specialEnd = n-1;
    // 인오더
    for(int i=0,in ; i< n ;i++){
        scanf("%d",&in);
        inOrder[in] = i;
    }
    // 포스트오더
    for(int i=0 ; i< n ;i++){
        scanf("%d",&postOrder[i]);
    }
    DAC(0 ,n-1, 0 ,n-1);
    
    return 0;
}
