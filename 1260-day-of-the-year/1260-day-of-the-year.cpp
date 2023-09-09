class Solution {
public:
    bool isleap(int yr)
    {
        return (yr%4==0 && yr%100!=0) || (yr%400==0);
    }
    int findmonth(int mn,int yr)
    {
        if(mn==1 || mn==3 || mn==5 || mn==7 || mn==8 || mn==12 || mn==10)
        return 31;
        if(mn==2)
        {
            if(isleap(yr))
            return 29;
            else
            return 28;
        }
        return 30;
    }
    int dayOfYear(string date) 
    {
        int yr=stoi(date.substr(0,4));
        int mn=stoi(date.substr(5,2));
        int d=stoi(date.substr(8,2));

        int days=0;
        days+=d;

        for(int i=1;i<mn;i++)
        {
            days+=findmonth(i,yr);
        }
        return days;
    }
};