class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            vector<int> freq(26, 0);

            int l = 0;
            int unique = 0;
            int countAtLeastK = 0;

            for(int r = 0; r < n; r++) {
                int idx = s[r] - 'a';

                if(freq[idx] == 0)
                    unique++;

                freq[idx]++;

                if(freq[idx] == k)
                    countAtLeastK++;

                while(unique > targetUnique) {
                    int leftIdx = s[l] - 'a';

                    if(freq[leftIdx] == k)
                        countAtLeastK--;

                    freq[leftIdx]--;

                    if(freq[leftIdx] == 0)
                        unique--;

                    l++;
                }

                if(unique == targetUnique &&
                   countAtLeastK == targetUnique) {
                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};