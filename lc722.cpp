#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// // /*
// /* // */
//  /*   */ if //
// /*/
// /*/*/
// */ //
// many /* */ /* */
vector<string> removeComments(vector<string> &source)
{
    vector<string> re;
    int long_flag = false;
    string tmp_s;
    for (string s : source)
    {
        if (long_flag == false) // not in "/*/" mod
        {
            int short_anno = s.find("//");
            int long_anno = s.find("/*");
            if (short_anno != -1 && long_anno != -1) // both // /* in one sentence
            {
                if (short_anno < long_anno) // // /*
                {
                    s = s.substr(0, short_anno);
                }
                else
                {
                    string tmp = s.substr(long_anno + 2, s.length() - long_anno - 2);
                    int end = tmp.find("*/");
                    if (end == -1) // /* // or // /*/ //
                    {
                        tmp_s = s.substr(0, long_anno);
                        long_flag = true;
                    }
                    else if (end < short_anno) // /* */ //
                    {
                        end = end + long_anno + 2;
                        string tmp = s.substr(end + 2, s.length() - end - 2);
                        int end_=tmp.find("//");
                        tmp=tmp.substr(0,end_);
                        s = s.substr(0, long_anno) + tmp;
                    }
                }
            }
            else if (short_anno != -1) // only short
                s = s.substr(0, short_anno);
            else if (long_anno != -1) // only long
            {
                string tmp = s.substr(long_anno + 2, s.length() - long_anno - 2);
                int end = tmp.find("*/");
                if (end == -1) // /*  or  /*/
                {
                    tmp_s = s.substr(0, long_anno);
                    long_flag = true;
                }
                else // /* */ /*/*/
                {
                    end = end + long_anno + 2;
                    string t = s.substr(0, long_anno);
                    string t2 = s.substr(end + 2, s.length() - end - 2);
                    s = t + t2;
                }
            }
            if (long_flag == false && s != "")
                re.push_back(s);
        }
        else
        {
            int long_anno = s.find("*/");
            if (long_anno == -1)
                continue;
            else
            {
                int short_anno = s.find("//");
                if (short_anno < long_anno) // // */
                    tmp_s = tmp_s + s.substr(long_anno + 2, s.length() - 2 - long_anno);
                else // */ //
                {
                    s = s.substr(long_anno + 2, s.length() - 2 - long_anno);
                    int end = s.find("//");
                    tmp_s = tmp_s + s.substr(0, end);
                }
                long_flag = false;
            }
            if (tmp_s != "")
                re.push_back(tmp_s);
        }
    }
    return re;
}

int main()
{
    vector<string> v = {"/*/bcbc//*ebdb/*/bab/*/a/*//*/d/*///*de/*///*d*//dc*///*/cd//*ccd//*a//*caacad"};
    removeComments(v);
    return 0;
}
