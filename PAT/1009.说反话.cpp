/*
1009. 说反话 (20)
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
输出格式：每个测试用例的输出占一行，输出倒序后的句子。
输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/ 

#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<string> s;
	string a;
    while(cin >> a) s.push(a);
    //s.push(a);
    
    //控制输出，第一个字符串前没有空格 
	cout << s.top();
    s.pop();
    while(!s.empty()) {
        cout << " " << s.top();
        s.pop();
    }
    return 0;
}

/*知识点复习 
c++ stl栈stack的头文件为: 

#include<stack>

stack<int> S;//声明一个对象

S.empty();//栈空返回true 否则false

int x=S.size();//返回栈中元素个数于x

S.pop();//移除栈顶元素

S.push(x);将x置于栈顶

x=S.top();返回栈顶元素
*/ 
