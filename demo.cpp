
#include <iostream>

using namespace std;
#include<string.h>

int myAtoi(char * s){
    
    int n = strlen(s);
    int k =0;
    int ans=0;
    for(int i =0;i<n;i++)
    { 
        if(s[i]-48>=0&&s[i]-48<=9)
        {
            k=1;
            
            ans=ans*10+s[i]-48;
        }
        else
        {
            if(k==2) break;
        }
    }
    
    return ans;

}

int main()
{
    char * s="nikhil123";
    int h=myAtoi(s);
    cout<<h<<"\n";

    return 0;
}