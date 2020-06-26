select SUM(CITY.POPULATION)
from CITY,COUNTRY
where CITY.COUNTRYCODE = COUNTRY.CODE  and COUNTRY.CONTINENT = 'Asia'

/*
https://www.hackerrank.com/challenges/asian-population/problem
*/