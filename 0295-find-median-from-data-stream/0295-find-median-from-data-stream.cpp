class MedianFinder {
private:
    priority_queue<int> leftMax; 
    priority_queue<int, vector<int>, greater<int>> rightMin;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftMax.empty() || num <= leftMax.top()) {
            leftMax.push(num);
        }
        else {
            rightMin.push(num);
        }

        // balance heaps
        if (leftMax.size() > rightMin.size() + 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }
        else if (rightMin.size() > leftMax.size() + 1) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if (leftMax.size() == rightMin.size()) {
            return ((double)leftMax.top() + rightMin.top()) / 2.0;
        }

        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        }

        return rightMin.top();
    }
};