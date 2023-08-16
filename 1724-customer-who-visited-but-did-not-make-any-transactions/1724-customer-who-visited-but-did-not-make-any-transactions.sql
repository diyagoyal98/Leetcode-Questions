# Write your MySQL query statement below

select customer_id, count(visits.visit_id) as count_no_trans from Visits left JOIN Transactions
on visits.visit_id=transactions.visit_id
where transaction_id is NULL
group by customer_id;