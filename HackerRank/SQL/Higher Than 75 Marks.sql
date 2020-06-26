/*
https://www.hackerrank.com/challenges/more-than-75-marks/problem
Enter your query here.
*/
select Name
from STUDENTS
where MARKS > 75
order by RIGHT(NAME,3) ,ID