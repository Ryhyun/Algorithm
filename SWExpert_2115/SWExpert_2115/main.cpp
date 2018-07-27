
#include <iostream>
#include <math.h>
using namespace std;

int arr[11][11] ;
int N,M,C;
int resultArr[11];
int result =0 ;


int ifBiggerThanLimit(int Marr[]){
    
    int bigger =0 ;
    for (int i = 1; i < (1 << M); i++) {
        
        
        int Sum = 0;
        int Check = 0;
        
        for (int j = 0; j < M; j++){
            
            //cout<<":  "<< (i & (1 << j)) << endl;
        
            if (i & (1 << j)) {
                Sum += Marr[ j] ;
                Check += pow(Marr[j],2);
            }
        }
        if( Sum <= C && bigger < Check ){
            bigger = Check;
        }
    }
    return bigger;
}
// 같은 라인일 때

int honey_sameLine(int columni){
    int* farr = new int[M];
    int* sarr = new int[M];
    int tempresult = 0 ;
    
    for( int i=0 ; i < N - M*2 +1 ; i++ ){
        int fsum =0 ;
        int fbig =0 ;
        int ftotal = 0;
        int sbig =0 ;
        
        int tempi =0 ;
        for( int j= i ; j< i+ M ; j++){
            farr[tempi] = arr[columni][j];
            fsum += arr[columni][j];
            tempi++;
        }
        
        // 최대 채취량보다 적을 때
        if( fsum <= C ){
            for( int j=0 ; j< M; j++){
                ftotal += pow(farr[j],2);
            }
            if( ftotal > fbig){
                fbig = ftotal;
            }
            
        }
        // 최대 채취량보다 많을 때
        else{
            // i 부터 M 개
            int tempbig= ifBiggerThanLimit(farr);
            if( tempbig> fbig ){
                fbig = tempbig;
            }
            
        }
        for( int j= i + M  ; j< N -M +1;j++){
            int ssum= 0 ;
            int tempi =0 ;
            int stotal =0 ;
            for( int k= j ; k< j+ M ; k++){
                
                sarr[tempi] = arr[columni][k];
                ssum +=arr[columni][k];
                tempi++;
            }
            // 최대 채취량보다 적을 때
            if( ssum <= C ){
                for( int k=0 ; k< M; k++){
                    stotal += pow(sarr[k],2);
                }
                if( stotal > sbig){
                    sbig = stotal;
                }
            }
            // 최대 채취량보다 많을 때
            else{
                // i 부터 M 개
                int tempbig= ifBiggerThanLimit(sarr);
                if( tempbig> sbig ){
                    sbig = tempbig;
                }
            }
        
        }
     //   cout<< fbig<<" "<< sbig<<endl;
        if( tempresult < fbig + sbig  ){
            tempresult = fbig + sbig;
        }
        
    }
    return tempresult;
}
// 다른 라인일 때
void honey_anotherLine(int columni){
    int big= 0 ;
    // columni 에서
    for( int i=0;i < N- M +1 ; i++ ){
        int sum=0;
        int total=0;
        int tempbig=0;
        int* Marr = new int[M];
        for( int j=0 ; j< M; j++){
            sum += arr[columni][ i+j];
            Marr[j] = arr[columni][ i+j];
        }
        // 최대 채취량보다 적을 때
        if( sum <= C ){
            for( int j=0 ; j< M; j++){
                total += pow(arr[columni][ i+j],2);
            }
            if( total > big){
                big = total;
            }
        }
        // 최대 채취량보다 많을 때
        else{
            // i 부터 M 개
            tempbig= ifBiggerThanLimit(Marr);
            if( tempbig> big ){
                big = tempbig;
            }
        }
    }
    if( big > resultArr[ columni]){
        resultArr[ columni] = big;
    }
}

int main(int argc, const char * argv[]) {
    int T;
    
    cin>> T;
    for( int t = 1; t<= T ; t++){
        result = 0 ;
        cin>> N>>M>>C;
        for(int i=0; i<N ; i++){
            for(int j=0; j<N; j++){
                cin>> arr[i][j];
            }
        }
        for(int i=0; i<N ; i++){
            resultArr[i]=0 ;
            honey_anotherLine(i);
            //cout<< resultArr[i]<<endl;;
        }
        
        for(int i=0; i<N ; i++){
            for(int j=0; j<N; j++){
                if( i != j  && result < resultArr[i] + resultArr[j]){
                    result = resultArr[i] + resultArr[j];
                }
            }
        }
        for(int i=0; i<N ; i++){
            int tempResult = honey_sameLine(i);
            //cout<< tempResult<<endl;
            if( result < tempResult ){
                result = tempResult;
            }
        }
        
        cout<< "#"<<t<<" "<< result<<endl;
    }
    
    
    return 0;
}
