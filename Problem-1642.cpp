class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        long long sum=0;
        int i=1;
        for(;i<heights.size() && ladders>=0 && bricks>=0;i++){
            if(heights[i-1]<heights[i]){
                pq.push(heights[i]-heights[i-1]);
                sum+=heights[i]-heights[i-1];
            }
            while(sum>bricks && ladders>0){
                ladders--;
                sum-=pq.top();
                pq.pop();
            }
            
            if(sum>bricks && ladders==0){
                return i-1;
            }
        }
        return i-1;
        
    }
};