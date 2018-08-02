
#include <iostream>
#include <vector>
using namespace std;

int result;
int N;
int arr[13][13];
int chk[13][13];
vector<pair<int,int> > vec;
int veclen;
int processorC = 0;
int resultLength = 10000 ;
/*
 
 N * N 에서
 각 칸에 1개의 core 혹은 1개의 전선이 올수 있음
 가장자리엔 전원이 흐름
 Core와 전원을 연결하는 전선은 직선으로만 설치가 가능
 선이 교차해서는 안됨
 가장자리에 위치한 Core는 전원이 연결된 것으로 간주
 
 가장 많은 Core에 전원을 연결하였을 때 전선 길이의 합?
 여러 방법이 있을 때 전선 길이가 최소가 되도록
 
  7 <= N <= 12
 Core는 12개 이하
 
 */
bool isPossible(int n,int m,int v){
    //우
    if( v == 0){
        for( int i=n+1; i< N; i++){
            if( chk[i][m] != 0 ){
                return false;
            }
        }
        return true;
    }
    // 하
    else if( v == 1){
        for( int j=m+1; j< N; j++){
            if( chk[n][j] != 0 ){
                return false;
            }
        }
        return true;
    }
    // 좌
    else if( v== 2){
        for( int i=n-1; i >= 0; i--){
            if( chk[i][m] != 0 ){
                return false;
            }
        }
        return true;
    }
    // 상
    else{
        for( int j= m -1 ; j >= 0 ; j--){
            if( chk[n][j] != 0 ){
                return false;
            }
        }
        return true;
    }
}

int delOrPill(int n,int m,int v, int deleteOrPill){
    //우
    int length=0;
    if( v == 0){
        for( int i=n+1; i< N; i++){
            if( deleteOrPill ==0 ){
                chk[i][m] = 0;
            }
            else{
                chk[i][m] = 2;
                length++;
            }
        }
    }
    // 하
    else if( v == 1){
        for( int j=m+1; j< N; j++){
            if( deleteOrPill ==0 ){
                chk[n][j] = 0;
            }
            else{
                chk[n][j] = 2;
                length++;
            }
        }
        
    }
    // 좌
    else if( v== 2){
        for( int i=n-1; i >= 0; i--){
            if( deleteOrPill ==0 ){
                chk[i][m] = 0 ;
            }
            else{
                chk[i][m] = 2;
                length++;
            }
        }
        
    }
    // 상
    else{
        for( int j= m -1 ; j >= 0 ; j--){
            if( deleteOrPill ==0 ){
                chk[n][j] = 0 ;
            }
            else{
                chk[n][j] = 2;
                length++;
            }
        }
    }
    return length;
}
void solve(int index, int count, int length){
    if( veclen == index){
    /*
        cout<<index << " "<< count<< " "<<length<<endl;
        for(int i=0 ; i<N;i++){
            for(int j=0; j<N; j++){
                cout<< chk[i][j]<<" ";
            }
            cout<<endl;
        }
     */
     
        if( count > processorC ){
            processorC = count;
            resultLength = 100000;
            if(resultLength > length){
                //cout<< "!! "<<count <<" "<< length<<endl;
                resultLength = length;
            }
        }
        else if( count == processorC){
            if(resultLength > length){
                //cout<< "!! "<<count <<" "<< length<<endl;
                resultLength = length;
            }
        }
        return;
    }
   
    int startN = vec[index].first;
    int startM = vec[index].second;
    
    for( int v=0; v< 4; v++){
        if( startN == 0 || startM==0 || startN == N-1 || startM == N-1){
            solve(index+1, count+1 , length );
            return;
        }
        if( isPossible(startN, startM, v)){
            //cout<< startN <<" "<< startM<< endl;
            int newLength = delOrPill(startN, startM, v, 1);
            solve(index+1, count+1 , length+ newLength );
            delOrPill(startN, startM, v ,0);
            
        }
    }
    solve(index+1, count , length  );
}
int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for(int t= 1; t<= T ; t++){
        processorC =0 ;
        resultLength = 10000 ;
        vec.clear();
        result=0;
        veclen =0 ;
        cin>>N ;
        for( int i=0; i< N ; i++){
            for( int j=0; j< N ; j++){
                cin>> arr[i][j];
                chk[i][j] = arr[i][j];
                if( arr[i][j] == 1){
                    vec.push_back(make_pair( i,j));
                    veclen++;
                }
            }
        }
        
        
        solve(0,0,0);
        
        cout<<"#"<<t<<" "<< resultLength<<endl;
    }
    
    
    return 0;
}
