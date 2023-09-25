#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;


bool cmp2(pair<int, int>a, pair<int, int> b) {
    return a.second > b.second;//值降序排列
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> hash;
        int total_time=0;
        if(n==0)
        {
            return tasks.size();
        }

        for(int i=0;i<tasks.size();i++)
        {
            if(hash.find(tasks[i])==hash.end())
            {
                hash[tasks[i]]=1;
            }
            else
            {
                hash[tasks[i]]=hash[tasks[i]]+1;
            }
        }

        vector<pair<int, int>> vecs;
        for (auto it = hash.begin();it!= hash.end();it++) 
        {
            vecs.push_back(make_pair(it->first, it->second));
        }
        sort(vecs.begin(), vecs.end(),cmp2);
        while(vecs.size()!=0)
        {
            int left=n+1;//每轮要凑出n+1个任务
            //从大到小从每种任务中抓取一个任务，直到所有种类都抓取完全或者已经达到目标任务数
            for(int i=0;i<vecs.size()&&left!=0;i++)
            {
                vecs[i].second-=1;
                left--;
            }
            //经过一轮抓取，部分任务已经减少，还剩0个没有执行的任务已经可以被剔除出列表
            for(vector<pair<int,int>>::iterator it=vecs.begin();it!=vecs.end();)
            {
                if(it->second==0)
                {
                    vecs.erase(it);
                }
                else
                {
                    it++;
                }
            }
            //还有任务没有完成，则此轮无论抓没抓满，都要加一轮任务的时间
            if(vecs.size()!=0)
            {
                total_time+=n+1;
            }
            else
            {
                total_time+=n+1-left;
            }
            sort(vecs.begin(), vecs.end(),cmp2);
        }
        return total_time;
    }
};

int main()
{
    Solution s;
    vector<char> tasks={'A','A','A','B','B','B'};
    cout<<s.leastInterval(tasks,2)<<endl;
    return 0;
}