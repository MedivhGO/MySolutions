/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-10/submissions/code/69253647
*/
select  DISTINCT CITY
from STATION
where CITY REGEXP '[^aeiou]$'