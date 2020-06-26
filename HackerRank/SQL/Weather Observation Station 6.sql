/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-6/problem
*/
select CITY
from STATION
where CITY REGEXP '^[aeiou]'