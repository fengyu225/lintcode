/*
strstr (a.k.a find sub string), is a useful function in string operation. Your task is to implement this function.

For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.


Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.
*/

#include "header.h"

//int strStr(const char *source, const char *target) {
//    if(!source || !target) return -1;
//    int s_len = strlen(source), t_len = strlen(target);
//    if(t_len>s_len) return -1;
//    const char* s_curr = source, *t_curr = target;
//    while(*s_curr){
//        if(!*t_curr) return s_curr-(t_curr-target)-source;
//        if(*s_curr == *t_curr){
//            s_curr++;
//            t_curr++;
//        }
//        else{
//            s_curr = s_curr-(t_curr-target)+1;
//            t_curr = target;
//        }
//    }
//    if(!*t_curr) return s_curr-(t_curr-target)-source;
//    return -1;
//}

void build_next(vector<int>& next, const char* target, int t_len){
    int k = -1, curr = 0;
    next[0] = -1;
    while(curr<t_len){
        if(k == -1 || target[curr] == target[k]){
            k++;
            curr++;
            next[curr]=k;
        }
        else k = next[k];
    }
}

int strStr(const char *source, const char *target) {
    //kmp 
    if(!source || !target) return -1;
    int s_len = strlen(source), t_len = strlen(target);
    if(t_len>s_len) return -1;
    vector<int> next(t_len+1, -1);
    build_next(next, target, t_len);
    int s_curr = 0, t_curr = 0;
    while(s_curr<s_len){
        if(t_curr == t_len) return s_curr-t_curr;
        if(source[s_curr] == target[t_curr]){
            s_curr++;
            t_curr++;
        }
        else if(next[t_curr] == -1){
            s_curr++;
            t_curr = 0;
        }
        else t_curr = next[t_curr];
    }
    if(t_curr == t_len) return s_curr-t_curr;
    return -1;
}   

int main(){
    cout<<strStr("source", "rc")<<endl;
    return 0;
}
