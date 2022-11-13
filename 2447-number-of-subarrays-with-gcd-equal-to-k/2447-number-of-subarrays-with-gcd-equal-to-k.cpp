class Solution {
public:
    /*int gcd(int a,int b)
    {
        if(a==0)
            return b;
        return gcd(b,a);
    }*/
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            for(int j=i;j<n;j++)
            {
                num=__gcd(num,nums[j]);
                if(num==k)
                    count++;
            }
        }
        return count;
    }
};