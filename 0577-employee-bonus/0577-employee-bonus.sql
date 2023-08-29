# Write your MySQL query statement below
select name , bonus from employee e left join bonus
on e.empId=bonus.empId 
Where bonus<1000 or bonus is null;