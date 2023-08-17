class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) 
    {
        /*int n=arr.size();

        int low=0,high=n-2;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid%2==0)   //checking if are in right half
            {
                if(arr[mid]!=arr[mid+1]) 
                high=mid-1; //shrinking right half
                else
                low=mid+1;//shrinking the left half
            }
            else
            {
                if(arr[mid]==arr[mid+1])
                high=mid-1;
                else
                low=mid+1;
            }
        }
        return arr[low];*/

        int n=arr.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans=ans^arr[i];
        }
        return ans;
    }
};