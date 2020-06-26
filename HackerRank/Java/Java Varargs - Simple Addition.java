//https://www.hackerrank.com/challenges/simple-addition-varargs/problem

class Add
{
    public void add(int ... nums)
    {
        String res = "";
        int sum = 0;
        for ( int n : nums ) {
            sum+=n;
            res += n+ "+";
        }


        res = res.substring(0,res.length()-1) + "=" + sum;

        System.out.println(res);
    }

}
