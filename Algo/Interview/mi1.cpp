#include<iostream>
#include <string>
#include <map>
using namespace std;

/* 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。 */

int Generate(string s) {
    map<char, int> characterNum;
    for (int i = 0; i < int(s.length()); i++)
    {
        characterNum[s[i]]++;
    }
    int res = 0;
    bool addMidOdd = false;
    for (auto i : characterNum)
    {
        if(i.second%2 == 0)
        {
            res+=i.second;
            continue;
        } 
        else if (i.second > 2) {
            res = res + i.second - 1;
        }
        if (!addMidOdd) {
            res++;
            addMidOdd = true;
        } 
    }
    return res;
}

int main() {
    string s;
/*     char* a = nullptr;
    while (scanf("%c", a) != EOF)
    {
        s += a;
    }  */
    cin >> s;
    cout << Generate(s);
    return Generate(s);
}