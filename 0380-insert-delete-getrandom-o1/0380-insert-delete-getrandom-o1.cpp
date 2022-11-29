class RandomizedSet {
public:
    set<int>s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(s.find(val)==s.end())
        {
            s.insert(val);
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) 
    {
        for(auto it=s.begin();it!=s.end();it++)
        {
            if(*it==val)
            {
                s.erase(it);
                return true;
            }
        }
        return false;
    }
    
    int getRandom() 
    {
        int random=rand()%s.size();
        auto it=s.begin();
        for(int i=0;i<random;i++)
        {
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */