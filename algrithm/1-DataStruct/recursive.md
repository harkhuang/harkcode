
##递归倒序输出
```
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int > v;
        print(head,v);
        return v;
    }
// 递归遍历
    void print(ListNode *p,vector <int  > &v){
        if(p != nullptr){//递归出口
            //printf("%d ",p->val); 
            print(p->next,v);
            v.push_back(p->val);
        }

    }
};

```