/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-8/submissions/code/69253448
*/
select distinct CITY
from STATION
where CITY REGEXP '^[aeiou]' and  CITY REGEXP '[aeiou]$'