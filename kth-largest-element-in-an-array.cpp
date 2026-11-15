// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
class Solution {
private:
    void build(vector<int>& heap, int num) {
        heap.push_back(num);
        heapify(heap, heap.size() - 1);
    }
    void heapify(vector<int>& heap, int i) {
        int pi = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;
        if (i > 0 && heap[i] < heap[pi]) {
            swap(heap[i], heap[pi]);
            heapify(heap, pi);
        }
    }
    void hipifeap(vector<int>& heap, int i) {
        int l = (i * 2) + 1;
        int r = (i * 2) + 2;
        if (l >= heap.size() && r >= heap.size()) return;
        if (l >= heap.size()) {
            if (heap[r] > heap[i]) return;
            swap(heap[r], heap[i]);return;
        }
        if (r >= heap.size()) {
            if (heap[l] > heap[i]) return;
            swap(heap[l], heap[i]);return;
        }
        if (heap[i] < heap[l] && heap[i] < heap[r]) return;
        if (heap[l] > heap[r]) {
            swap(heap[r], heap[i]);
            return hipifeap(heap, r);
        }
        swap(heap[l], heap[i]);
        hipifeap(heap, l);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap = {};
        // build heap from 0 - (k - 1) from nums
        for (int i = 0; i < k; i++) {
            build(heap, nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            if (heap[0] < nums[i]) {
                heap[0] = nums[i];
                hipifeap(heap, 0);
            }
        }
        return heap[0];
    }
};
