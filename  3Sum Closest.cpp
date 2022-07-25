
 
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l;
        int r,sum;
        int closest_sum=30000;
        int n=nums.size();
         sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            l=i+1;
            r=nums.size()-1;
            while(l<r){
            sum=nums[i]+nums[l]+nums[r];
            if(sum==target)
                return sum;
            if(abs(target-sum)<abs(target-closest_sum))
                closest_sum=sum;
            if(sum>target)
                r--;
            else
                l++;}
        }
        return closest_sum ;
        
    
};