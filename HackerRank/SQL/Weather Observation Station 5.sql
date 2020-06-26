/*
Enter your query here.
https://www.hackerrank.com/challenges/weather-observation-station-5/problem
*/
select CITY,length(CITY) from STATION
order by length(CITY),
city  limit 1;
select CITY,length(CITY) from STATION
order by length(CITY) desc ,
city limit 1;