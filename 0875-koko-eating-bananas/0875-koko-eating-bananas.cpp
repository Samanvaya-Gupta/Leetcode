class Solution {
private:
    int maxi(vector<int>& piles) {
        int mx = piles[0];
        for (int x : piles) {
            mx = max(mx, x);
        }
        return mx;
    }

    long long hrs(vector<int>& piles, int mid) {
        long long reqtime = 0;   // 🔥 FIX HERE
        for (int x : piles) {
            reqtime += (x + mid - 1) / mid;
        }
        return reqtime;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, hi = maxi(piles);
        int ans = hi;

        while (l <= hi) {
            int mid = l + (hi - l) / 2;
            long long reqtime = hrs(piles, mid);

            if (reqtime <= h) {
                ans = mid;
                hi = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};