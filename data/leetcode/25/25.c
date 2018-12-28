#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ID 25  //完成
/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	if(head==NULL){
		return NULL;
	}
	struct ListNode *re,*now,*past;
	struct ListNode* arr[k];
	int p;
	past = head;
	re = NULL;

	while(true){
		if(past==NULL){
			break;
		}
		p = 0;
		for (int i = 0; i < k; ++i)
		{
			if(past==NULL){
				continue;
			}
			arr[p] = past;
			past = past->next;
			++p;
		}
		if(p==k){
			for (int j = p-1; j >= 0; --j)
			{
				if(re==NULL){
					re = arr[j];
					now = re;
				}else{
					now->next = arr[j];
					now = now->next;
				}
			}
		}else{
			for (int j = 0; j < p; ++j)
			{
				if(re==NULL){
					re = arr[j];
					now = re;
				}else{
					now->next = arr[j];
					now = now->next;
				}
			}
		}
	}
	now->next = NULL;

    return re;
}
int main()
{
// [1,2,3,4,5]
// 3
	struct ListNode l1,l2,l3,l4,l5,l6;
	l1.val = 1;
	l2.val = 2;
	l3.val = 3;
	l4.val = 4;
	l5.val = 5;
	l6.val = 6;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = NULL;
	// l5.next = &l6;
	// l6.next = NULL;

	struct ListNode *a = reverseKGroup(&l1,3);
	while(a->next!=NULL){
		printf("%d\n", a->val);
		a = a->next;
	}

}