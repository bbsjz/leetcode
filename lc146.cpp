#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
struct node
{
    int value;
    int time;
};

class LRUCache {
    int capacity;
    int longest_key;
    int cnt;
    unordered_map<int,node> map;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->cnt=0;
    }
    
    int get(int key) {
        if(map.find(key)==0) return -1;
        map[key].time=cnt++;
        return map[key].value;
    }
    
    void put(int key, int value) {
        if(map.find(key)==0&&map.size()<capacity) 
        {
            map.insert({key,{value,cnt++}});
            return;
        }
        else if(map.find(key)==0) 
        {
            getlongest();
            map.erase(longest_key);
            map.insert({key,{value,cnt++}});
            return;
        }
        map[key].value=value;
        map[key].time=cnt++;
        return;
    }

    void getlongest()
    {
        int mint=-1;
        for(auto it = map.begin();it!=map.end();it++)
        {
            if(mint=-1) {mint=(*it).second.time;longest_key=(*it).first;}
            else if((*it).second.time<mint){mint=(*it).second.time;longest_key=(*it).first;}
        }
    }
};

int main()
{
    LRUCache cache=LRUCache(2);
    cache.put(1,1);
    cache.put(2,2);
    cache.get(1);
    cache.put(3,3);
    cache.get(2);
    cache.put(4,4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
    return 0;
}