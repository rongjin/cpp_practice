#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution{
public:
	vector<int> twoSum(vector<int> &nums,int target){
		vector<int> result;
		map<int,int> mymap;
		map<int,int>::iterator it;
		int i;
		for(i=0;i<nums.size();i++){
			//cout<<nums[i]<<endl;
			it = mymap.find(target-nums[i]);
			if(it!=mymap.end()){
				result.push_back(it->second);
				result.push_back(i);
			}
			else{
				mymap.insert(pair<int,int>(nums[i],i));
			}
		}
		for(i=0;i<result.size();i++){
			cout<<result[i]<<endl;
		}
		return(result);
	}
};
int main(){
	Solution s;
	int array[] = {2,7,11,15};
	vector<int> nums(array,array+sizeof(array)/sizeof(int));
	vector<int> result;
	result = s.twoSum(nums,9);
	return 1;
}
