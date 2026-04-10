#include <iostream>
using namespace std;
#include <vector>
  //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //forward traversal
        //backwards traversal
        int length = 0;
        ListNode* temp = head;
        while(temp!= nullptr){
            length++;
            temp = temp->next;
        }
        //when this loop finishes, temp is at tail
        int* arr1 = new int[length];
        int* arr2 = new int[length];

        ListNode* c1 = head;
        int count = 0;
        while(c1!=nullptr){
            arr1[count] = c1->val;
            c1 = c1->next;
            count++; 
        }
        ListNode* p = nullptr;
        ListNode* c = head;
        ListNode* n = nullptr;

        while(c!=nullptr){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
        count = 0;
        c = head;
        while(c!=nullptr){
            arr2[count] = c->val;
            c = c->next;
            count++; 
        }
        bool istrue = true;
        for(int i =0; i < length; i++){
            if(arr1[i] != arr2[i]){
                istrue = false;
                break;
            }
        }
        return istrue;

    }
};

class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;

        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;        
    }
};
int main() {
    
    return 0;
}
