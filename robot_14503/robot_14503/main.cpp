#include <iostream>

using namespace std;
int arr[51][51] = {1,};
// 북,동, 남, 서 순서
int nx[4] = { -1, 0,1 ,0};
int ny[4] = { 0,1 ,0, -1};
int result = 1 ;

void robot( int tn,int tm, int tv){
    for(int i=1 ; i< 5 ; i++){
        //벽이 아니거나 방문하지 않았다면
        int next = (4+tv - i) % 4 ;
        if( tn + nx[next] <0 or tm+ ny[next] <0 or  tn + nx[next] > 50 or tm+ ny[next] >50 ){
            continue;
        }
        if( arr[ tn + nx[next]][tm + ny[next]]  != 1 and  arr[ tn + nx[next]][tm + ny[next]] != -1 ){
            result++;
            arr[ tn+ nx[next]][tm+ ny[next]] = -1;
            robot( tn+ nx[next], tm+ ny[next], next);
            return;
        }
    }
    if( arr[ tn + nx[ (2 + tv) %4]][tm + ny[(2+tv) % 4 ]] != 1){
        robot(  tn + nx[ (2 + tv) %4],  tm + ny[ (2 + tv) %4] , tv  );
        return;
    }
    else{
        return;
    }
}
int main(int argc, const char * argv[]) {
    int n, m ;
    cin>> n >> m ;
    
    int fn,fm, v ;
    cin>> fn>> fm>> v ;
    for(int i=0 ; i< n; i++){
        for( int j=0; j<m; j++){
            cin>> arr[i][j];
        }
    }
    arr[fn][fm] = -1;
    robot( fn,fm,v);
    cout<<result<<endl;
    
    return 0;
}
