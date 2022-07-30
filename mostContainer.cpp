



public:

    int maxArea(vector<int>& height) {
        int l=0;
        int r =height.size()-1;
        int area=0;
        while(l!=r){
            area=max(min(height[l],height[r])*(r-l),area);
            if(height[l]>height[r])
                r--;
            else
                l++;
        }
          return area ;  
        }
    
    
