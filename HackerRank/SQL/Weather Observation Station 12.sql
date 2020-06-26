/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-12/problem
*/
select DISTINCT CITY
from STATION
where CITY REGEXP '^[^aeiou]' and CITY REGEXP '[^aeiou]$'