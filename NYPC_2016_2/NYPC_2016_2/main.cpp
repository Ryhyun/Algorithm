
#include <iostream>
#include <vector>
using namespace std;

//char input[100] = { };
string input;
int l ;
bool endChk = false;
int number[10][7] = {
    // 0
    { 1,1,1,0,1,1,1},
    // 1
    { 0,0,1,0,0,1,0},
    // 2
    { 1,0,1,1,1,0,1},
    // 3
    { 1,0,1,1,0,1,1},
    // 4
    { 0,1,1,1,0,1,0},
    // 5
    { 1,1,0,1,0,1,1},
    // 6
    { 1,1,0,1,1,1,1},
    // 7
    { 1,0,1,0,0,1,0},
    // 8
    { 1,1,1,1,1,1,1},
    // 9
    { 1,1,1,1,0,1,0}
};
 // + , -
int oper[2]  = { 0,1};
vector< vector<int> > subVec;
vector< vector<int> > addVec;
int calculate(){
    int total = int(input[0] - '0');
    
    for( int i= 1 ; i <= l /2 ; i++ ){
        if( input[ i * 2  -1 ] == '+'){
            total += input[i*2] - '0';
        }
        else{
            total -= input[i*2] - '0';
        }
    }
    return total;
}
void preprocess(){
    // chk 0 -> sub , chk 1 -> add
    for(int n = 0 ; n < 10; n++ ){
        // 숫자가 n 일 때
        vector<int> subtempV;
        //cout<<"-=-=-=-=-=-=-=-=- "<< n<<endl;
        //cout<< "sub"<<endl;
        for( int i =0 ; i< 7; i++){
            if( number[n][i] == 1){
                number[n][i] = 0 ;
                for( int j=0; j< 10; j++){
                    
                    if( n != j ){
                        int cnt = 0 ;
                        for( int k =0 ; k< 7; k++){
                            if( number[n][k] == number[j][k])
                                cnt++;
                        }
                        if( cnt == 7 ){
                        //cout<<j<<endl;
                        subtempV.push_back(j);
                        }
                    }
                    
                }
                number[n][i] = 1; ;
            }
        
        }
        subVec.push_back(subtempV);
        vector<int> addtempV;
        //cout<<"add"<<endl;
        for( int i =0 ; i< 7; i++){
            if( number[n][i] == 0){
                number[n][i] = 1;
                for( int j=0; j< 10; j++){
                    
                    if( n != j ){
                        int cnt = 0 ;
                        for( int k =0 ; k< 7; k++){
                            if( number[n][k] == number[j][k])
                                cnt++;
                        }
                        if( cnt == 7 ){
                            //cout<<j<<endl;
                            addtempV.push_back(j);
                        }
                    }
                }
                number[n][i] = 0; ;
            }
            
        }
        addVec.push_back(addtempV);
    
    }
}
void add(int preI ){
    
    for( int i=0; i< l; i++){
        if( i != preI){
            if( i % 2 == 0){
                for( int j=0 ; j < addVec[input[i]- '0'].size(); j++){
                    char temp = input[i];
                    input[i] = addVec[input[i]- '0'][j] + '0';
                    
                    cout<< input<<endl;
                    
                    if (calculate() == 0){
                        endChk = true;
                        return ;
                    }
                    input[i] = temp;
                }
                
            }
            else{
                if( input[i] ==  '-'){
                    input[i]  = '+';
                    if (calculate() == 0){
                        endChk = true;
                        return ;
                    }
                    input[i]  = '-';
                    
                }
            }
        }
    }
    return ;
}

void sub(int num, int index){
    if( endChk == true){
        return ;
    }
    // chk == 0 -> 숫자 , chk == 1 -> 부호
    if( index % 2 == 0){
        for( int i=0 ; i < subVec[input[index]- '0'].size(); i++){
            cout <<"? "<< subVec[input[index] - '0'][i]  <<endl;;
            input[index ] = subVec[input[index] - '0'][i]  + '0';
            cout<< "sub "<< input<<endl;
            add(index);
            if( endChk == true){
                return ;
            }
            input[index] = num  +'0';
        }
    }
    // chk == 1 일 때 num ==0 -> 마이너스 num == 1-> 플러스
    else{
        if( input[index] ==  '+'){
            input[index]  = '-';
            add(index);
            if( endChk == true){
                return ;
            }
            input[index]  = '+';
        }
    }
}


int main(int argc, const char * argv[]) {
    
    
    l=0;
    //string temp ;
    cin>>input;
    l= input.length();
    
    preprocess();
    
    
    for( int i=0; i< l; i++){
        if( endChk == true){
            break;
        }
        sub(input[i] - '0', i);
    }
    
    cout<< input<<endl;
    
    
    
    return 0;
}
