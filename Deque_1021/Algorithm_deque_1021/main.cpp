#include <iostream>
#include <deque>

using namespace std;

class circularQueue{
    int length;
    int result;
    deque<int> deQ;
    deque<int>::iterator deQi;
public:
    //생성자
    circularQueue(){}
    
    circularQueue(int n){
        this->length = n;
        this->result =0;
        for(int i=1; i<= n ; i++ ){
            deQ.push_back(i);
        }
    }
    void pop(){
        this->deQ.pop_front();
    }
    
    void shiftLeft(){
        int temp = this->deQ.front();
        this->deQ.pop_front();
        this->deQ.push_back(temp);
        
    }
    void shiftRight(){
        int temp = this->deQ.back();
        this->deQ.pop_back();
        this->deQ.push_front(temp);
    }
    void computeRange(int destination){
        int leftDist, rightDist;
        int cnt =0 ;
        for( this->deQi = this->deQ.begin(); this->deQi != this->deQ.end(); this->deQi++){
            if( *this->deQi != destination){
                cnt+=1;
            }
            else
                break;
        }
        rightDist = cnt;
        leftDist = int(this->deQ.size()) - cnt ;
    
        if( leftDist < rightDist){
            this->result += leftDist;
            for(int i=0; i< leftDist; i++)
                this->shiftRight();
        }
        else{
            this->result+= rightDist;
            for(int i=0; i< rightDist; i++)
                this->shiftLeft();
        }
        this->pop();
    }
    int getResult(){
        return this->result;
    }
    
    //소멸자
    ~circularQueue(){
        
    }
};

/*
10 3
1 2 3
 */
int main(int argc, const char * argv[]) {
    int N,M;
    cin>>N>>M;
    int popArray[50] = {0,};
    for( int i=0; i<M;i++){
        scanf("%d", &popArray[i]);
    }
    circularQueue cirQ(N);
    for(int i=0; i< M; i++){
        cirQ.computeRange(popArray[i]);
    }
    cout<< cirQ.getResult();
    
    
    
    return 0;
}
