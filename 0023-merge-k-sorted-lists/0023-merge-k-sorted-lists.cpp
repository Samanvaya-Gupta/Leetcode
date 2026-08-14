/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                pq.push(head->val);
                head=head->next;
            }
        }
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            ListNode* head = new ListNode(curr);
            temp -> next = head;
            temp = temp->next;
        }
        return ans->next;
    }
};