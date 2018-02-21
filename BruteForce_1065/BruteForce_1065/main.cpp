
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>> n;
    int result =0;
    int gap;
    string temp;
    for(int i=1 ;i<= n ;i++){
        temp = to_string(i);
        if( temp.length() == 1 ){
            result++;
        }
        else{
            gap = int(temp[0] - temp[1]);
            bool chk = true;
            for(int j =0; j< temp.length()-1; j++){
                if( gap  != int(temp[j] - temp[j+1])){
                    chk = false;
                    break;
                }
            }
            if( chk == false)
                continue;
            else
                result++;
        }
    }
    cout<< result<<endl;
    return 0;
}
