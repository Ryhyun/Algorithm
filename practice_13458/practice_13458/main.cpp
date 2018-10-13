#include <iostream>
using namespace std;


int N;
long long student[1000001];
int sup, sub;
long long result = 0 ;
int main(int argc, const char * argv[]) {
    cin>> N;
    
    for(int i=0; i< N; i++){
        cin>> student[i];
    }
    cin>> sup >> sub;
    for( int i=0; i< N ;i++){
        long long tempSup = 0 ;
        //int tempSub = 0;
        
        //tempSub = ( student[i] % sub == 0)? student[i]/sub : student[i]/sub + 1;
        
        
        if( student[i] <= sup){
            tempSup += 1;
            
        }
        else{
            int tempStudent = student[i];
            tempStudent -= sup;
            tempSup += 1;
            int tempCnt= ( tempStudent % sub == 0)? tempStudent/sub : tempStudent/sub + 1;
            tempSup += tempCnt;
            
            
            
        }
        result+= tempSup;
        //result += ( tempSup > tempSub) ? tempSub: tempSup;
    }
    
    cout<< result<<endl;
    
    return 0;
}
