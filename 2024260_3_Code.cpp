#include <iostream>
using namespace std;
#define MAX 100
class Stack{
    private:
    int top;
    int arr[MAX];
    public:
    Stack(){
        top = -1;
    }
    void push(int val){
        if(!isfull()){
            top++;
            arr[top] = val;
        }
        else{
            cout<<"Holding track full!"<<endl;
            return;
        }
        
    }

    int pop(){
        if(isempty()){
            cout<<"Holding track empty!"<<endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }

    bool isfull(){
        if(top == MAX - 1){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isempty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int peek(){
        if(!isempty()){
            return arr[top];
        }
        else{
            return -1;
        }

    }
};
class Queue{
  private:
  int rear;
  int front;
  int* arr;
  int size;
  
  public:
  Queue(int n){
    size = n;
    arr = new int[size];
    rear = front = -1;
  }
  bool isfull(){
    return rear == size -1; 
  }
  bool isempty(){
    return front == -1 || front > rear;
  }
  void push(int val){
    if(!isfull()){
        if(rear == -1){
            rear++;
            front++;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }
    else{
        cout<<"INPUT TRACK FULL!"<<endl;
    }
  }
  int pop(){
    if(isempty()){
        cout<<"Input track empty!"<<endl;
        return -1;
    }
    else{
        int val = arr[front];
        front++;
        return val;
    }
  }
  int seefront(){
    return arr[front];
  }
};

void railway(int n, int k){
    Queue input(n);
    int val;
    for(int i = 0; i < n; i++){ //populate the input track
        cout<<"Enter car number for input track:"<<endl;
        cin>>val;
        input.push(val);
    }
    Stack holding[k];
    int output[n];
    int next = 1;
    int outindex = 0;
    while(!input.isempty()){
        int car = input.pop();
        if(car == next){
            output[outindex] = car;
            next++;
            outindex++;
            cout<<"Moved car: "<<car<<" from INPUT to OUTPUT!"<<endl;

            for(int i = 0; i < k; i++){
                while(!holding[i].isempty() && holding[i].peek() == next){
                    int moved = holding[i].pop();
                    output[outindex++] = moved;
                    cout<<"Moved car: "<<moved<<" from holding: "<<i+1<< " to OUTPUT!"<<endl;
                    next++;
                }
            }
        }
        else{
            int best = -1;
            int besttop = n+1;
            for(int i = 0; i < k; i++){
                int top = holding[i].peek();
                if(top>car && top<besttop){
                    best = i;
                    besttop = top;
                }
                if(top == -1 && best == -1){
                best = i;
                }
            }
            if(best == -1){
                cout<<"No place for car: "<<car<<" Rearrangement not possible."<<endl;
                return;
            }
            cout<<"Moved car: "<<car<<" from INPUT: "<< " to HOLDING "<<best+1<<endl;
            holding[best].push(car);
        }
    }
    for(int i = 0; i<k;i++){
        while(!holding[i].isempty() && holding[i].peek() == next){
                    int moved = holding[i].pop();
                    output[outindex++] = moved;
                    cout<<"Moved car: "<<moved<<" from holding: "<<i+1<< " to OUTPUT!"<<endl;
                    next++;
                }
    }
    cout<<"FINAL OUTPUT ORDER!"<<endl;
    for(int i = 0; i < outindex; i++){
    cout << output[i] << " ";
    }
    cout << endl;
}
int main() {
    cout<<"Enter the value of n"<<endl;
    int n,k;
    cin>>n;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    railway(n,k);
    return 0;
}
