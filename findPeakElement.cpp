#include<iostream>
#include<vector>

using namespace std;


class Solution{
public:
	int find(vector<int>& nums,int l,int r){
		int mid;
		cout<<l<<" "<<r<<endl;
		if(r-l==1){
			return(l);
		}
		else if(r-l==2){
			if(nums[l+1]>nums[l]){
				return(l+1);
			}
			else{
				return(l);
			}
		}
		else{
			mid = (l+r)/2;
			if((nums[mid-1]<nums[mid])&&
				(nums[mid]>nums[mid+1])){
				return mid;
			}
			else if(nums[mid-1]<nums[mid]){
				return find(nums,mid,r);
			}
			else{
				return find(nums,l,mid);
			}
		}
	}
	int findPeakElement(vector<int>& nums){
		return(find(nums,0,nums.size()));
	}
};

int main(){
	Solution s;
	int a[] = {1,2,3,1};
	int i,n = 4;
	vector<int> nums;
	for(i=0;i<n;i++){
		nums.push_back(a[i]);
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<s.findPeakElement(nums);
	return(0);
}
