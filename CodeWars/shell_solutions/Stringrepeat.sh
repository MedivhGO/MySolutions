https://www.codewars.com/kata/57a0e5c372292dd76d000d7e
#!/bin/bash
repeat=$1
string=$2
ret=""
for((i=repeat;i>=1;i--)); do
  ret=$ret$string
done
echo $ret