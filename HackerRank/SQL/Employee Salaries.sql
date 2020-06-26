/*
Enter your query here.
https://www.hackerrank.com/challenges/salary-of-employees/problem
*/
select Name
from Employee
where Salary > 2000 and months < 10
order by Employee_id