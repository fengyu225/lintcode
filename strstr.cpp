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

int strStr(const char *source, const char *target) {
    if(!source || !target) return -1;
    int s_len = strlen(source), t_len = strlen(target);
    if(t_len>s_len) return -1;
    const char* s_curr = source, *t_curr = target;
    while(*s_curr){
        if(!*t_curr) return s_curr-(t_curr-target)-source;
        if(*s_curr == *t_curr){
            s_curr++;
            t_curr++;
        }
        else{
            s_curr = s_curr-(t_curr-target)+1;
            t_curr = target;
        }
    }
    if(!*t_curr) return s_curr-(t_curr-target)-source;
    return -1;
}

int main(){
    cout<<strStr("source", "rcd")<<endl;
    return 0;
}
