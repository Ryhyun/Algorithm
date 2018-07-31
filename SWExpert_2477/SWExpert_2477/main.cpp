

#include <iostream>
#include <queue>
using namespace std;

/*
 고객이 이용했던
 1. 접수 창구번호
 2. 정비 창구번호
 
 N개 접수 ( 1 ~ N )
 M개 정비 ( 1 ~ M )
 
 
 */
int N,M,K,A,B;
//int firArr[10];

int firArr[1001]= {0,};
int secArr[1001]= {0,};
int firvis[11]= {0,};

int firCost[11]= {0,};
int secCost[11]= {0,};
int secvis[11]= {0,};
int visitArr[1001]= {0,};

int result[1001]= {0,};

int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    for( int t =1 ; t<= T ; t++){
        
        
        int resultV ;
        queue<int > q;

        resultV =0 ;
        cin>> N>> M>> K >> A >> B ;
        for(int n =1 ; n <= N ; n++){
            scanf("%d",&firCost[n]);
         
        }
        for(int m =1 ; m <= M ; m++){
            scanf("%d",&secCost[m]);
        }
        
        for(int k =1 ; k<= K; k++){
           
            scanf("%d",&visitArr[k]);
        }
        queue<int> userq;
        int count = visitArr[1];
        int finish =0 ;
        int top =1 ;
        //
        while( finish < K ){
            cout<<"-----"<< count<<endl;
            // user queue
            while( top <= K ){
                if( visitArr[ top] == count){
                    userq.push(top);
                    top++;
                }
                else{
                    break;
                }
            }
            
            // reception
            
            for(int n=1; n<= N; n++){
                if( firvis[n] == 0   && !userq.empty() && n != 0 ){
                    firvis[n] = userq.front() ;
                    firArr[userq.front()] = firCost[n];
                    cout<<"reception : "<< n<<" "<< firvis[n]<<endl;
                    userq.pop();
                }
                else if( firvis[n] != 0 && n !=0){
                    int temp = firvis[n];
                    firArr[temp]--;
                    
                    if( firArr[temp] == 0 ){
                        cout<<"pop : "<< temp<< " "<< firvis[n]<<endl;
                        q.push( temp);
                        firvis[n] =0 ;
                        result[temp]= n;
                        n--;
                        
                    }
                }
            }
            
            for(int m=1; m<= M; m++){
                if( secvis[m] == 0   && !q.empty() ){
                    secvis[m] = q.front();
                    secArr[q.front()] = secCost[m];
                    q.pop();
                }
                else if( secvis[m] != 0 ){
                    int temp = secvis[m];
                    secArr[temp]--;
                    
                    if( secArr[temp] == 0 ){
                        //qq.push( temp);
                        cout<< result[temp]<<" "<<m<<" "<< temp<<endl;
                        if( result[temp] == A  && m == B){
                            //cout<< result[temp]<<" "<<m<<" "<< temp<<endl;
                            resultV += temp;
                        }
                        cout<<"finish "<<finish<<endl;
                        finish++;
                       
                        secvis[m] =0 ;
                        m--;
                    }
                }
            }
            
            
            count++;
        }
        
        
        
        
        
        
        if( resultV == 0 )
            cout<<"#"<<t<<" "<< -1<<endl;
        else{
            cout<<"#"<<t<<" "<< resultV<<endl;
        }
        
    }
    
    return 0;
}
