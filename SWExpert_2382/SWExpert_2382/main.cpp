
#include <iostream>
#include <vector>
using namespace std;
int result;
int N,M,K;
int nx[4] = {-1,0 ,1,0};
int ny[4] = { 0,-1,0,1};

// 벽에 부딪히면 미생물 수 1/2   + 방향 반대
// 미생물 끼리 부딪혔을 때 미생물수는 합해지고 방향은 많았던 미생물 방향
class Virus{
public:
    int n,m,c,v;
    int maxC;
    
    Virus(){
    }
    ~Virus(){
    }
    void init( int tn, int tm, int tc, int tv){
        n=tn ;
        m=tm;
        c=tc;
        v=tv;
        maxC =0 ;
    }
    void meetMedicine(){
        c = c /2 ;
        v = (v +2 ) % 4;
    }
    bool checkMedicine(){
        if( n == 0 || n == N-1 || m == 0 || m == N-1 ){
            // medicine
            return true;
        }
        else
            return false;
    }
};
vector< Virus> vec;

void solve(){
    for( int time = 0; time < M; time++){
        //cout<< time<<"------------"<<endl;
        //vector<int> tarr[101][101];
        
        int tempArr[101][101][2] ={0,};
        
        for( int i =0 ; i< vec.size() ; i++ ){
            if( vec[i].c != 0 ){
                vec[i].n += nx[ vec[i].v];
                vec[i].m += ny[ vec[i].v];
                //tarr[vec[i].n][vec[i].m].push_back( i);
                if( vec[i].checkMedicine()){
                    vec[i].meetMedicine();
                }
                tempArr[vec[i].n][vec[i].m][1] += vec[i].c;
                if(  tempArr[vec[i].n][vec[i].m][0] < vec[i].c){
                    tempArr[vec[i].n][vec[i].m][0] = vec[i].c;
                    
                }
            }
        }
        for( int i=0; i< vec.size(); i++){
            if( vec[i].c < tempArr[vec[i].n][vec[i].m][0] ){
                vec[i].c = 0;
            }
            else{
                vec[i].c = tempArr[vec[i].n][vec[i].m][1];
            }
        }
        
        /*
        for(int i=0; i<N ; i++){
            for( int j=0; j<N ;j++){
                if( tarr[i][j].size() > 1){
                    //cout<< i<<" "<< j <<endl;
                    int biggest = vec[tarr[i][j][0]].c;
                    int bigI = 0;
                    for( int k =1; k< tarr[i][j].size(); k++){
                        if(  vec[tarr[i][j][k]].c > biggest){
                            biggest = vec[tarr[i][j][k]].c;
                            bigI = k;
                        }
                    }
                    int sum = 0;
                    int tarrLen =  tarr[i][j].size();
                    for( int k =0; k<tarrLen; k++){
                        if( k!= bigI ) {
                            sum += vec[tarr[i][j][k]].c;
                            vec[tarr[i][j][k]].c =0 ;
                        }
                    }
                    vec[tarr[i][j][bigI]].c += sum ;
                }
            }
        }
        */
        
    }
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    for(int t= 1; t<= T ; t++){
        result =0 ;
        vec.clear();
        cin>> N>> M>>K;
        for(int k=0; k< K ; k++){
            int n,m,c,v;
            cin>> n>>m>>c>>v;
            Virus tempVirus;
            
            if( v==  1)
                tempVirus.init( n,m,c,0);
            else if( v== 2)
                tempVirus.init( n,m,c,2);
            else if( v== 3)
                tempVirus.init( n,m,c,1);
            else
                tempVirus.init( n,m,c,3);
            
            vec.push_back(tempVirus);
        }
        
        solve();
        for( int i =0 ; i< vec.size() ; i++ ){
            result += vec[i].c;
        }
        
        cout<<"#"<<t<<" "<< result<<endl;
    }
    
    
    return 0;
}
