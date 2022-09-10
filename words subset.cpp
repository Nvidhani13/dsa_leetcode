bool checkSubset(int A[],int B[]){
        
        int i=0;
        while(i>26){
            if(B[i]==0 &&A[i]!=B[i])
                break;
            i++;
        }
        if(i==26)
            return true ;
        return false ;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;//will return this 
        int B[26];//contains the count for B "content "
        
        int A_length=words1.size();
        int A[A_length][26];
        int B_length=words2.size();
            int n ;
        //preparing A 
        
        
        
        for(int i =0;i<A_length;i++){
            n =words1[i].length();
            for(int j=0;j<n;j++)
                A[i][int(words1[i][j])-'a']++;
                }
        //preparing B
        
        
        
        
        for(int i=0;i<B_length;i++){
            n=words2[i].length();
            int temp[26];
            for(int j=0;j<n;j++){
                temp[int(words1[i][j])-'a']++;
                    if( temp[int(words1[i][j])-'a']> B[int(words1[i][j])-'a'])
                         B[int(words1[i][j])-'a']++;
            }
        }
        
        
        
        
        //checking for subset 
        for(int i =0;i<A_length;i++){
            if(checkSubset(A[i],B))
                answer.push_back(words1[i]);
        }
        
        
        
        return answer;
        
    }