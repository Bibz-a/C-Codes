#include <iostream>
#include <stack>
using namespace std;

void nge(int arr[], int n) {
    stack<int> s;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        // Remove all smaller elements from the stack
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        // If stack becomes empty, no greater element
        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();

        // Push current element onto the stack
        s.push(arr[i]);
    }

    // Print the results
    for (int i = 0; i < n; i++)
        cout << arr[i] << " -> " << result[i] << endl;
}

int main() {
    int arr[] = {5, 3, 2, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    nge(arr, n);
    return 0;
}
