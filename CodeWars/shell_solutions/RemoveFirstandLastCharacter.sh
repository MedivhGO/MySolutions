#https://www.codewars.com/kata/56bc28ad5bdaeb48760009b0
function removeChar() {
      str=$1
      len1=${#str}
      len1=$[len1-1]
      echo $str | cut -c  2-$len1
}
removeChar $1