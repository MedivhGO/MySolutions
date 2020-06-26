/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-9/problem
*/
select DISTINCT CITY
from STATION
where CITY regexp '^[^aeiou]'