class Solution {
public:
    bool static cmp(vector<int>&x,vector<int>&y)
    {
        return x[1]>y[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(int i=0;i<boxTypes.size();i++)
        {
            cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
            ans+=min(boxTypes[i][0],truckSize)*boxTypes[i][1];
            truckSize=truckSize-min(boxTypes[i][0],truckSize);    
            if(truckSize==0)
            break;
        }
        return ans;
    }
};