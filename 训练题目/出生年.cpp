/*
L1-033. 出生年
以上是新浪微博中一奇葩贴：“我出生于1988年，直到25岁才遇到4个数字都不相同的年份。”
也就是说，直到2013年才达到“4个数字都不相同”的要求。
本题请你根据要求，自动填充“我出生于y年，直到x岁才遇到n个数字都不相同的年份”这句话。

输入格式：
输入在一行中给出出生年份y和目标年份中不同数字的个数n，其中y在[1, 3000]之间，
n可以是2、或3、或4。注意不足4位的年份要在前面补零，例如公元1年被认为是0001年，有2个不同的数字0和1。

输出格式：
根据输入，输出x和能达到要求的年份。数字间以1个空格分隔，行首尾不得有多余空格。
年份要按4位输出。注意：所谓“n个数字都不相同”是指不同的数字正好是n个。
如“2013”被视为满足“4位数字都不同”的条件，但不被视为满足2位或3位数字不同的条件。

输入样例1：
1988 4
输出样例1：
25 2013
输入样例2：
1 2
输出样例2：
0 0001

分析：对于从y开始一直到3012（因为就算最大值3000，一直检验到3012也满足题意了～后面的就没必要了～），
将它的每一位的数字放入集合s里面，因为集合是不允许重复数字的，所以集合s的大小就是当前这个数字的不重复数字的个数～
当集合s的大小和n相等时，说明满足题意，输出就可以了 

*/ 

#include <cstdio>
#include <set>
using namespace std;
int main() {
    int y, n;
    scanf("%d%d", &y, &n);
    for (int i = y; i <= 3012; i++) {
        set<int> s;
        int num = i;
        for (int j = 0; j < 4; j++) {
            s.insert(num % 10);
            num /= 10;
        }
        if (s.size() == n) {
            printf("%d %04d", i - y, i);
            break;
        }
    }
    return 0;
}
