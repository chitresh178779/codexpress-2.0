#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
            }
        }
        sort(nums.begin(),nums.end());
        int k=nums.size();
        return k;
        
    }
void display(vector<int> nums){
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}


int main(){
    vector<int> nums={0,1,2,2,3,0,4,2};
    removeElement(nums,2);
    display(nums);
    return 0;
}


