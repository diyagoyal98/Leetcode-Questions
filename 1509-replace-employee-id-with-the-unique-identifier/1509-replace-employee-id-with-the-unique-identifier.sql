# Write your MySQL query statement below

select unique_id,name From EmployeeUNI as e1 
RIGHT JOIN Employees as e
ON e.id=e1.id;
