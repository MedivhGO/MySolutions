#https://www.codewars.com/kata/582cd9033c1acf1d45000052
#!/bin/bash

countToTwenty() {
   i=1
  while ((i<=20));do
   echo "Count: $i"
   ((i++))
   done
}


countToTwenty() {
  for i in {1..20};do echo "Count: $i" ;done
}