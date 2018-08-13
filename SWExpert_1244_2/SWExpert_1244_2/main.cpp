
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int result ;
string input;
int inputLength;
int swapC;

void swap(int ptr, int next){
    char temp = input[ptr];
    input[ptr] = input[next];
    input[next] = temp;
}
/*
void rec(int ptr,int next, int cnt){
    cout<< ptr<<" "<<next<<" "<<cnt<<endl;
    for( int i=0; i< inputLength;i++){
        cout<< input[i];
    }
    cout<<endl;
    if( cnt == swapC){
        result = result > stoi( input) ? result: stoi(input);
        return;
    }
    if( next == inputLength){
     //   cout<< "----------!"<<endl;
        return;
    }
    rec( ptr ,next +1 , cnt );
    rec( ptr+1, next+1, cnt);
    swap( ptr,next);
    rec( 0 ,1 , cnt+1 );
    
    //rec( ptr+1, next+1, cnt+1);
    swap(ptr,next);
}
*/


void rec(int c, int cnt){
    //cout<< c<< " "<< cnt<<"=-=-=-=-=-=--=-=-"<<endl;
    
    if( cnt== swapC){
        result = result > stoi( input) ? result: stoi(input);
        return;
    }
    
    int biggest= input[c] - '0';
    int bigI = c;
    vector<int> vec;
    for( int i =c; i< inputLength;i++){
        
        if( biggest < input[i] - '0' ){
            biggest = input[i] - '0';
            bigI  = i ;
            vec.clear();
            vec.push_back(i);
        }
        else if(biggest == input[i] - '0'){
            vec.push_back(i);
        }
        
    }
    //cout<< biggest<<" "<< bigI<<endl;
    
    for( int i= 0; i< vec.size(); i++){
        if( vec[i] == c ){
            if( c == inputLength-1 ){
                swap( c, c-1);
                rec( c-1, cnt+1);
                swap( c, c-1) ;
            }
            else{
             //   cout<< "continue"<<endl;
                rec(c+1, cnt);
            }
        }
        else{
            swap( c, vec[i]);
           // cout<< input<<endl;
            rec(c+1, cnt+1);
            swap( c, vec[i]);
        }
        
    }
    
}
int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    for( int t= 1; t<=T ;t++){
        
        cin>> input>> swapC;
        result = stoi( input);
        inputLength = input.length();
        
        //rec(0,1,0);
        rec( 0,0);
        
        
        
        
        cout<<"#"<<t<<" "<< result<<endl;
    }
    
    
    return 0;
}
