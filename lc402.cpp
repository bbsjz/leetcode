#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
//在去掉的过程中，会存在位置发生改变的情况，这怎么办
//就是本来要去掉的位置是0，1，3
//但是去掉0，之后，原本1的位置就变成了0，再去掉1，实际上去掉的是原来2对应的位置
//额，直接弹出，而不是记录位置，再根据位置擦除，就是143发现4不对就直接把4弹出去，而不是记住4在1这个位置然后去擦除4
string removeKdigits(string num, int k) {
    vector<char> stack;
    for(auto digit:num)
    {
        //只有严格大于的情况下才可以，相等也不可以，参考1111999，2
        while(stack.size()&&stack.back()>digit&&k)
        {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }
    for(;k>0;k--)
    {
        stack.pop_back();
    }
    while(stack.size()>1&&(*stack.begin())=='0') stack.erase(stack.begin());
    string s;
    for(auto digit:stack)
        s.append(1,digit);
    return s==""?"0":s;
}

int main()
{
    cout<<removeKdigits("112",1);
    return 0;
}