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
private:
    ListNode* Merge(ListNode* list1, ListNode* list2){
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->next==NULL){
            list1->next = list2;
            return list1;
        }
        if(list1->val > list2->val)
            swap(list1, list2);
        ListNode* curr1 = list1;
        ListNode* curr2=list2;
        ListNode* next1 = list1->next;
        ListNode* next2;
        while(next1!=NULL && curr2!=NULL){
            if(curr2->val>=curr1->val && curr2->val<=next1->val){
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->next;
                if(next1==NULL){
                    curr1->next=curr2;
                    return list1;
                }
            }
        }
        return list1;
    }
    void MergeSort(vector<ListNode*>& lists, int l, int h){
        if(l>=h) return;
        int mid = l + (h-l)/2;
        MergeSort(lists, l, mid);
        MergeSort(lists, mid+1, h);
        if(lists[l] == NULL)
            lists[l] = lists[mid+1];
        else if(lists[mid+1] == NULL)
            return;
        else if(lists[l]->val > lists[mid+1]->val)
            lists[l] = Merge(lists[mid+1], lists[l]);
        else
            lists[l] = Merge(lists[l], lists[mid+1]);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==1) return lists[0];
        if(n==0) return NULL;
        MergeSort(lists, 0, n-1);
        return lists[0];
    }
};