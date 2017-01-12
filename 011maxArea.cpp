#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int help(vector<int> &height, int left,int right){
		int wid,hei,area =0,areal=0,arear=0,l,r;
		if(right-left==1){
			return(height[left]<height[right]?height[left]:height[right]);
		}
		else{
			wid = right-left;
			hei = height[left]<height[right]?height[left]:height[right];
			area = wid*hei;
			//cout<<area<<endl;
			if(height[left]<height[right]){
				l = left+1;
				while(l<right && height[l]<=height[left])l+=1;
				if(l<right)areal=help(height,l,right);
				area = area>areal?area:areal;
			}
			else{
				r = right-1;
				while(r>left && height[r]<height[right])r-=1;
				if(r>left)arear = help(height,left,r);
				area = area>arear?area:arear;
			}
			return(area);
		}
	}
	int maxArea(vector<int> & height){
		int area= help(height,0,height.size()-1);
		return(area);
	}
};

int main(){
	Solution s;
	int array[] = {1,2,4,3};
	vector<int> height(array,array+sizeof(array)/sizeof(int));
	cout<<s.maxArea(height)<<endl;
	return(1);
}

