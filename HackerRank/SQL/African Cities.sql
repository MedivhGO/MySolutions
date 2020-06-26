select CITY.NAME
from CITY,COUNTRY
where CITY.CountryCode = COUNTRY.Code and CONTINENT = 'Africa'

/*
https://www.hackerrank.com/challenges/african-cities/problem
*/