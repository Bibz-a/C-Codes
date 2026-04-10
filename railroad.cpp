#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <deque>
#include <vector>

void rearrange(int n, int k){
    queue<int> input;
    cout<<"Enter the 1-n items for the input rail."<<endl;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        input.push(a);
    }
    //
    deque<int> output;
    int nextexpected = 1;
    vector<stack<int>> holdingtracks(k);

    while(!input.empty()){
        int element = input.front();
        input.pop();

        if(element == nextexpected){
            //input element matches output order
            cout<<"Moved car: "<<element<<" To OUTPUT FROM INPUT!"<<endl;
            output.push_back(element);
            nextexpected++;

            //one of the holding tracks had the element on top
            bool moved;
            do {
                moved = false;
                for (int i = 0; i < k; i++) {
                    if (!holdingtracks[i].empty() && holdingtracks[i].top() == nextexpected) {
                        int movedCar = holdingtracks[i].top();
                        output.push_back(movedCar);
                        nextexpected++;
                        holdingtracks[i].pop();
                        cout<<"Moved car: "<<movedCar<<" To OUTPUT FROM HOLDING TRACK: "<<i<<endl;
                        moved = true;
                        break;
                    }
                }
            } while (moved);
        }
        else{
            //keep it in holding
            //find best holding
            int bestTrack = -1;
            int bestTop = 9999;
            for(int i = 0; i < k ; i++){
                if (!holdingtracks[i].empty() && holdingtracks[i].top() > element && holdingtracks[i].top() < bestTop) {
                    bestTop = holdingtracks[i].top();
                    bestTrack = i;
                }
            }
            if (bestTrack == -1) {
                    // try to find an empty track
                for (int i = 0; i < k; i++) {
                    if (holdingtracks[i].empty()) {
                        bestTrack = i;
                        break;
                    }
                    }
            }
            if (bestTrack == -1) {
                cout << "No available holding track for car " << element << "! Rearrangement failed." << endl;
                return;
            }
            holdingtracks[bestTrack].push(element);
            cout<<"Moved Car: "<<element<<" To Holding Track: "<<bestTrack + 1<<" FROM INPUT"<<endl;
        }

    }
    bool moved;
    do {
        moved = false;
        for (int i = 0; i < k; i++) {
            if (!holdingtracks[i].empty() && holdingtracks[i].top() == nextexpected) {
                cout << "Moved car " << nextexpected 
                    << " To OUTPUT (from HOLDING TRACK " << i + 1 << ")" << endl;
                output.push_back(holdingtracks[i].top());
                holdingtracks[i].pop();
                nextexpected++;
                moved = true;
                break; 
            }
        }
    } while (moved);
    cout<<"FINAL OUTPUT!"<<endl;
    while (!output.empty()) {
        cout << output.front() << "->";
        output.pop_front();
    }
    cout << "END" << endl;


}
int main() {
    cout<<"Enter values for n and k"<<endl;
    int n,k;
    cin>>n;
    cin>>k;

    rearrange(n, k);
    return 0;
}
