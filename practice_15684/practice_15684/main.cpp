#include <iostream>
#include <vector>
using namespace std;
int N,M,H;

int colArr[11][31] = { 1, };
int rowArr[11][31] = { 0, };
int result ;
int finresult;
vector<pair<int,int> > vec(5);
void down(){
    int cnt =0 ;
    for( int i=1; i<= N; i++ ){
        int nowi = i ;
        int depth = 1;
        while( depth <= H  ) {
            if( rowArr[nowi][depth] == 1 ){
                nowi++;
            }
            else if(rowArr[nowi-1][depth] == 1 ){
                nowi--;
            }
            depth++;
        }
        if( i != nowi){
            return;
        }
        else{
            cnt++;
        }
    }
    if( cnt == N){
        finresult = result;
    }
}

void recursive(int num ,int depth){
    if( finresult != -1 )
        return ;
    if( depth == result ){
        down();
        if( depth != 0 )
            rowArr[vec[depth-1].first][vec[depth-1].second] = 0 ;
        return;
    }
    int i =  num % (N-1)  ;
    int j = num  / (N-1) +1 ;
    if(  num % (N-1) == 0){
        i = N-1;
        j -=1 ;
    }
    //cout<<"?? "<<num<<" "<< i << " "<< j <<endl;
    if( i >= N || j > H){
        return;
    }
    if( rowArr[i][j] == 0 && rowArr[i-1][j] == 0 && rowArr[i+1][j] == 0 ){
        rowArr[i][j] = 1 ;
        vec[depth] = make_pair( i, j);
        //cout<<"! "<< i << " "<< j <<endl;
        
        
        recursive(num + 1, depth+1 );
        rowArr[i][j] = 0 ;
        recursive(num+1, depth );
        
        
    }
    else{
        recursive(num+1, depth );
    }
}
int main(int argc, const char * argv[]) {
    // N- 세로줄 , M- 가로줄 개수, H- 세로선 마다 가로선을 높을 수 있는 위치
    cin>>N >>M >>H;
    
    finresult = -1 ;
    for(int i=0; i< M; i++){
        int a,b;
        cin>>a>>b;
        rowArr[b][a] = 1;
    }
    
    
    for( result =0; result < 4; result++ ){
        //cout<< "result: "<<result<<endl;
        
        recursive(1,0);
        
        if( finresult != -1 )
            break;;
    }
     
    if( result ==4 ){
        cout<< "-1"<<endl;
    }
    else{
        cout<< finresult;
    }
    
    return 0;
}

/*
 5 5 6
 1 1
 3 2
 2 3
 5 1
 5 4
 */
 
