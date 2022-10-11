/* 现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能，每一个技能会有一个伤害，同时若怪物低于一定的血量，则该技能可能造成双倍伤害，
每一个技能最多只能释放一次，已知怪物有m点血量，现在想问你最少用几个技能能消灭掉他（血量小于等于0）。

输入描述:
第一行输入一个整数T，代表有T组测试数据。

对于每一组测试数据，一行输入2个整数n和m，代表有n个技能，怪物有m点血量。

接下来行，每一行输入两个数A和x，代表该技能造成的伤害和怪物血量小于等于x的时候该技能会造成双倍伤害

输出描述:
对于每一组数据，输出一行，代表使用的最少技能数量，若无法消灭输出-1。 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calMinSkills(int HP, vector<pair<int, int>>& skills);
int main() {
    int T;
    cin >> T;
    vector<pair<int, int>> skills;
    for (int i = 0; i < T; i++)
    {
        int n, m;
        cin >> n >> m;
        skills.clear();

        for (int j = 0; j < n; i++)
        {
            int A, x;
            cin >> A >> x;
            skills.push_back(make_pair(A, x));
            
        }
        
    }
    
}

int calMinSkills(int HP, vector<int>& skills) {
    
}