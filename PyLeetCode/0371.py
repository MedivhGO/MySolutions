class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        unsigned int carry = a & b;
        return getSum(carry << 1, a ^ b);
    }
};

# 使用python不容易处理移位问题, 所以使用C++实现
# 使用递归实现
# 一个数的和包含两部分, 进位所带来的值 + 对应数位求和的值.
# 1. a ^ b就是对应数位的相加的值,不带进位
# 2. a & b << 1的结果就是在求和过程中所需进位的值所生成的中间数
# 其结果就是 1 + 2, 可以递归处理
# 递归的出口为其中一个值为0
# 进位产生的中间值可能会使中间值溢出, 所以使用无符号数处理

# 时间复杂度 O(C ) (a&b<<1)最多执行 C次,C为a,b的二进制位数
# 空间复杂度 O(1)

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) { # 如果进位不为0
            unsigned  int carry = (unsigned int)(a & b) << 1;
            a = a ^ b; # 无进位加法
            b = carry; # 设置进位的值
        }
        return a;
    }
};

# 使用迭代模拟二进制加法
# 以进位为循环条件, 如果进位不为0,先做 a,b的无进位加法, 也就是异或
# 让b = 进位值, 继续迭代.
# 这个写法包含了一个技巧,可以使代码美观, 循环第一次执行, b值其含义并不是进位值.

# 时间复杂度 O(C ) (a&b<<1)最多执行 C次,C为a,b的二进制位数
# 空间复杂度 O(1)