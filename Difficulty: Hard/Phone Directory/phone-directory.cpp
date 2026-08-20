class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
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
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void printSuggestion(TrieNode* curr, vector<string>& temp, string& prefix){
        if(curr->isTerminal) temp.push_back(prefix);
        
        for(char ch = 'a'; ch<='z'; ch++){
            TrieNode* next = curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for(int i=0; i<str.length(); i++){
            char lastch = str[i];
            
            prefix.push_back(lastch);
            TrieNode* curr = prev->children[lastch-'a'];
            if(curr==NULL){
                for (int j = i; j < str.length(); j++) {
                    output.push_back({"0"});
                }
                break;
            }
            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

class Solution {
  public:
    vector<vector<string>> displayContacts(vector<string> contact, string s) {

        // code here
        Trie* t = new Trie();
        for(int i=0; i<contact.size(); i++){
            string str = contact[i];
            t->insertWord(str);
        }
        return t->getSuggestions(s);
    }
};