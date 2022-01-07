#https://www.codewars.com/kata/53da3dbb4a5168369a0000fe
EvenOrOdd()
{
  if(($1%2==0)); then
    echo "Even"
  else
    echo "Odd"
  fi
}
EvenOrOdd "$1"