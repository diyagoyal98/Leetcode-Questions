class Solution {
public:
    
    /*int gcd(int n1,int n2)
    {
        if(n1==0)
            return n2;
        return gcd(n2,n1);
    }
    int lcm(int n1,int n2)
    {
        return (n1*n2)/gcd(n1,n2);
    }*/
    int subarrayLCM(vector<int>& nums, int k) 
    {
        /*int n=nums.size();
        int count=0;
        
        for(int i=0;i<n-1;i++)
        {
            int n1=nums[i];
            int n2=nums[i+1];
            if(lcm(n1,n2)==k)
                count++;
        }
        return count;*/
        
        int n=nums.size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            int num=1;
            for(int j=i;j<n;j++)
            {
                num=lcm(num,nums[j]);
                if(num==k)
                    count++;
                else if(num>k)
                    break;
            }
        }
        return count;
    }
};