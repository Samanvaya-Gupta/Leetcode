class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';    //assuming all characters are uppercase
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string str, string& ans){
        TrieNode* curr = root;

        for (int i = 0; i < str.length(); i++) {
            if (curr->childCount == 1 && !curr->isTerminal) {

                char ch = str[i];
                ans.push_back(ch);

                int index = ch - 'a';

                curr = curr->children[index];
            }
            else {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        for(int i=0; i<strs.size(); i++){
            t->insertWord(strs[i]);
        }
        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }
};