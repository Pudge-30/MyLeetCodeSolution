#pragma once

#include <string>
#include <cmath>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    void get_next(string t, vector<int> &next)
    {
        int i = 0, j =-1;
        next[0] = -1;

        //next[i] = j, ��t[i]ƥ��ʧ�ܺ���Ҫ���º�t[j]����ƥ�䣬Ҳ�����Ϊ��t[0]_t[i-1]�Ӵ��У�����ǰ��׺�ĳ���Ϊj
        //���Խ�����Ҫ�Ƚ�t[i]��t[j]�Ƿ����
        //����ȣ���t[i+1] = j+1
        //�����ȣ���Ҫ�ҵ�t[j]ǰ������ǰ��׺����j=next[j]
        while (i < t.size() - 1)
        {
            // ���׸���ĸ��ʼƥ��(j = -1)������t[i] = t[j]
            if (j == -1 || t[i] == t[j])
            {
                ++i; ++j;
                if (t[i] != t[j])   next[i] = j;    //j = -1
                    else next[i] = next[j];     //�Ż����kmp����t[i] = t[j]ʱ����next[j]����Ϊnext[next[j]]
            } else
            {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        get_next(needle, next);

        int i = 0, j = 0;   //i,j�ֱ�ָ�����ڱȽϵ���ĸ
        //�����Ƚϣ�ֱ����һָ�볬���ȽϷ�Χ
        while ((i < (int)haystack.size()) && (j < (int)needle.size()))  //c++ string.size()�ķ���ֵΪ�޷��������븺���Ƚ�ʱ��Ҫ����ת��
        {
            //j = -1�� ��Ϊ���Ӵ�������ĸ���޷�ƥ�䣬��ʱ��Ҫ��i��j������ƶ�һ��j=0��������������ĸ����ƥ�䣩
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i; ++j;
            } else{
                j = next[j];
            }
        }

        if (j >= needle.size())
            return (i - needle.size());
        else 
            return -1;
    }
};