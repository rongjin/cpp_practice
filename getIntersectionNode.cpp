#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) {}
};
class Solution{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		if(!headA || !headB)return NULL;
		if(headA==headB)return headA;
		ListNode *pa,*pb,*result;
		int la, lb;
		la = lb = 0;
		pa = headA;
		while(pa){
			la+=1;
			pa = pa->next;
		}
		pb = headB;
		while(pb){
			lb+=1;
			pb = pb->next;
		}
		cout<<la<<" "<<lb<<endl;
		pa = headA;
		pb = headB;
		if(la>lb){
			while(la>lb){
				pa = pa->next;
				la -=1;
			}
		}else if(lb>la){
			while(lb>la){
				pb = pb->next;
				lb-=1;
			}
		}
		while(pa && pb && pa!=pb){
			pa = pa->next;
			pb = pb->next;
		}
		if(!pa ||!pb)return NULL;
		result = pa;
		return result;
	}
};

int main(){
	Solution s;
	ListNode *ha, *hb;
	vector<ListNode> lista, listb;
	ha = NULL;
	hb = NULL;
	s.getIntersectionNode(ha,hb);
	return 1;
}
