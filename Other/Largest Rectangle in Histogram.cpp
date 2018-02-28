int largestRectangleArea(vector<int>& heights) {
    stack<int> indx;
    int mx = 0, n = heights.size();
    for (int i = 0; i < n;) {
        if (indx.empty() || heights[indx.top()] <= heights[i]) {
            indx.push(i++);
        } else {
            int top = indx.top();
            indx.pop();
            mx = max(mx, heights[top] * (indx.empty() ? i : i - indx.top() - 1));
        }
    }
    while (!indx.empty()) {
        int top = indx.top();
        indx.pop();
        mx = max(mx, heights[top] * (indx.empty() ? n : n - indx.top() - 1));
    }
    return mx;
}