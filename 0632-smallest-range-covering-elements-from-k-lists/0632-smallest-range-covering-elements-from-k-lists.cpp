class node{
public:
    int data;
    int col;
    int row;

    node(int d, int r, int c){
        data = d;
        col = c;
        row = r;
    }
};

class compare{
public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> pq;
        for(int i=0; i<n; i++){
            int ele = nums[i][0];
            mini = min(mini, ele);
            maxi = max(maxi, ele);
            pq.push(new node(ele, i, 0));
        }
        int start = mini, end = maxi;
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();
            mini = temp->data;
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            if(temp->col+1 < nums[temp->row].size()){
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                pq.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col+1));
            }
            else break;
        }
        return {start, end};
    }
};