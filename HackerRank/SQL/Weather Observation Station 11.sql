/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-11/problem
*/
select DISTINCT CITY
from STATION
where CITY REGEXP '[^aeiou]$' or CITY REGEXP '^[^aeiou]'