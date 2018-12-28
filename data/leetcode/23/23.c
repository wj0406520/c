#include <stdio.h>
#include <math.h>

#define ID 23 //完成
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

	if(listsSize==0){
		return NULL;
	}
	// printf("%p\n", lists);
	struct ListNode *n;
	struct ListNode *t;
	struct ListNode *r;
	int s;
	int h;
	int m;
	int end[listsSize];
	t = NULL;
	s = 0;
	m = 0;
	end[0]=1;
	for (int i = 0; i < listsSize; ++i)
	{
		end[i]=1;
		if(lists[i]==NULL){
			end[i] = 0;
			continue;
		}
		struct ListNode *l = lists[i];
		h = l->val;
		if(h<s || t==NULL){
			s = l->val;
			t = l;
			m = i;
		}
		// printf("%p\n", *lists);
	}
	n = t;
	r = n;

	if(lists[m]==NULL){
		return NULL;
	}

	if(lists[m]->next == NULL){
		end[m] = 0;
	}else{
		lists[m] = lists[m]->next;
	}
	// printf("%d\n", lists[0]->val);
	// printf("%d\n", lists[1]->val);
	// printf("%d\n", lists[2]->val);

	while(true){
		t = NULL;
		s = 0;
		m = 0;
		int e = 0;
		for (int i = 0; i < listsSize; ++i)
		{
			if(end[i]==0){
				continue;
			}
			struct ListNode *l = lists[i];
			h = l->val;
			if(h<s || t==NULL){
				s = l->val;
				t = l;
				m = i;
			}
			e = 1;
		}
		if(e==0){
			break;
		}
		// printf("%d\n", t->val);
		n->next = t;
		n = n->next;
		if(lists[m]->next == NULL){
			// printf("%daaaa%d\n", m,lists[m]->val);
			end[m] = 0;
		}else{
			lists[m] = lists[m]->next;
		}
		// printf("%d\n", lists[m]->val);
		// break;
	}
	return r;
};
int main()
{
	// [
	//   1->4->5,
	//   1->3->4,
	//   2->6
	// ]
	// int a = 1410065408;
	struct ListNode l1;
	struct ListNode l2;
	struct ListNode l3;
	l1.val = 1;
	l2.val = 4;
	l3.val = 5;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = NULL;

	struct ListNode y1;
	struct ListNode y2;
	struct ListNode y3;
	y1.val = 0;
	y2.val = 3;
	y3.val = 7;
	y1.next = &y2;
	y2.next = &y3;
	y3.next = NULL;

	struct ListNode f1;
	struct ListNode f2;
	f1.val = 2;
	f2.val = 6;
	f1.next = &f2;
	f2.next = NULL;


	struct ListNode *names[] =
	{
		&l1,&y1,&f1
	};


	// printf("%p\n", &l1);
	//printf("%p\n", &l2);
	//printf("%p\n", &l3);

	//printf("%p\n", &y1);
	//printf("%p\n", &y2);
	//printf("%p\n", &y3);

	// printf("%p\n", &f1);
	//printf("%p\n", &f2);

	struct ListNode *a = mergeKLists(names,3);
	while(a->next!=NULL){
		// printf("%d\n", a->val);
		a = a->next;
	}
}