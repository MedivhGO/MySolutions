public class Add {
    public int Add(int num1,int num2) {
        if (num1 == 0) return num2;
        return Add((num1&num2)<<1,num1 ^num2);
    }
}