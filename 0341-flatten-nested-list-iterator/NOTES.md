vector<int>ans;
int x=0;
void find(vector<NestedInteger> &nestedList)
{
int n=nestedList.size();
for(int i=0;i<n;i++)
{
if(nestedList[i].isInteger())
ans.push_back(nestedList[i].getInteger());
else
find(nestedList[i].getList());
}
}
NestedIterator(vector<NestedInteger> &nestedList)
{
find(nestedList);
}
int next()
{
return ans[x];
x++;
}
bool hasNext()
{
return x<ans.size();
}