 
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        char dummy;
        int answer=0;
            int l=0;
            int r=0;
        while(s.size()>r){
            if(map.count(s[r])==0){
                dummy=s[r];
                map[dummy]=r;
                if((r-l+1)>answer){
                    answer=r-l+1;
                }
                r++;
            }
            else{
                dummy=s[r];
                if(map[dummy]+1>l)
                    l=map[dummy]+1;
                    map[dummy]=r;
                    if((r-l+1)>answer)
                        answer=r-l+1;
                r++;
            }
        }
        return answer
    }
};