/*
1003. 我要通过！(20)
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/

//分析三个条件
//1.只能由P\A\T三种字母组成
//2.就是中间一个A左右加上等量的A（不加也行）都是正确的。
//3.规律就是，可以在P和T中间加A并且在T后面加A，要求必须是，中间加上一个A，末尾就得加上几倍的(P前面A的那个字符串)。
//所以一句话总结字符串的要求：只能有一个P一个T，中间末尾和开头可以随便插入A。但是必须满足开头的A的个数 * 中间的A的个数 = 结尾的A的个数

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	string s;
	int n, p = 0, t = 0;//用p表示P前面的字符数，用t表示T前面的字符数
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>s;
		map<char, int> m;
		for(int j = 0; j<s.length();j++){
			m[s[j]]++;
			if(s[j] == 'P'){p = j;
			}
			if(s[j] == 'T'){t = j;
			}
		}
	 if(m['P'] == 1 && m['A'] != 0 && m['T'] == 1 && m.size() == 3 && p * (t-p-1) == s.length()-t-1)
            printf("YES\n");
        else
            printf("NO\n");
	} 
	
	return 0;
} 

/*知识点复习

Map是STL的一个关联容器，
它提供一对一（其中第一个可以称为关键字，每个关键字只能在map中出现一次，
第二个可能称为该关键字的值）的数据 处理能力，
由于这个特性，它完成有可能在我们处理一对一数据的时候，在编程上提供快速通道。
这里说下map内部数据的组织，map内部自建一颗红黑树(一 种非严格意义上的平衡二叉树)，
这颗树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的，
*/
