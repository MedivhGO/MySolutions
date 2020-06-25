#https://www.codewars.com/kata/5b853229cfde412a470000d0
#!/bin/sh

dad_years_old=$1
son_years_old=$2

#implement me
echo $((dad_years_old-2*son_years_old)) | tr  -d  -

exit