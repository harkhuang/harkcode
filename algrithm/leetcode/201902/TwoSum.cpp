#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        for (int i = 0;i < nums.size();i++ )
            for (int j = i; j < nums.size();j++)
            {
                 cout<<"i="<<i<<"j="<<j<<endl;
                if (nums[i] + nums[j] == target)
                {
                   
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        return ret;
    }
    
};

vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> ret;
    for (int i = 0;i  < nums.size() - 1;i++ )
     {
        for (int j = i + 1; j < nums.size();j++)
        {
            cout<<"i="<<nums[i]<<"j="<<nums[j]<<endl;
            if (nums[i] + nums[j] == target)
            {                
                ret.push_back(i);
                ret.push_back(j);
                return ret;
            }
        }
     }  
    return ret;
};


int main() {
   vector<int> vect1{ 3, 2, 4 }; 
  
   twoSum(vect1, 6);
   return 0;
}




