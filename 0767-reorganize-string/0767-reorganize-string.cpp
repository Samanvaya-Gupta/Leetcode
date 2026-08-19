class node{
public:
    char ch;
    int freq;
    node(int f, char c){
        ch = c;
        freq = f;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->freq < b->freq;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        string ans = "";
        priority_queue<node*, vector<node*>, compare> pq;
        map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        for(auto& p: mp){
            char c = p.first;
            int f = p.second;
            pq.push(new node(f, c));
        }
        while(pq.size()>1){
            node* temp1 = pq.top();
            pq.pop();
            node* temp2 = pq.top();
            pq.pop();
            ans.push_back(temp1->ch);
            temp1->freq--;
            ans.push_back(temp2->ch);
            temp2->freq--;
            if(temp1->freq>0) pq.push(temp1);
            if(temp2->freq>0) pq.push(temp2);
        }
        if(pq.empty()){
            return ans;
        }
        else{
            node* temp = pq.top();
            if(temp->freq==1){
                ans.push_back(temp->ch);
                return ans;
            }
        }
        return "";
    }
};