/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
void bubbleDown(vector<ListNode*>& lists){
    size_t size = lists.size();
    int index = 0;
    while (true) {
        size_t leftChild = 2 * index + 1;
        size_t rightChild = 2 * index + 2;
        size_t smallest = index;

        // Check if left child exists and is smaller than current smallest
        if (leftChild < size && lists[leftChild] && lists[leftChild]->val < lists[smallest]->val) {
            smallest = leftChild;
        }

        // Check if right child exists and is smaller than current smallest
        if (rightChild < size && lists[rightChild] && lists[rightChild]->val < lists[smallest]->val) {
            smallest = rightChild;
        }

        // If the smallest is still the parent, the heap property is restored
        if (smallest == index) {
            break;
        }

        // Swap and continue down the tree
        std::swap(lists[index], lists[smallest]);
        index = smallest; 
    }
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode* dumH = new ListNode(-1);
        ListNode* head = dumH;
        auto cmp = [](const ListNode* a, const ListNode* b) {
            if(!a || !b) {
                return false;
            }
            return a->val > b->val; 
        };
        make_heap(lists.begin(), lists.end(), cmp);
        while(!lists.empty()){
            ListNode* top = lists.front();
            if(!top){
                pop_heap(lists.begin(), lists.end(), cmp);           
                lists.pop_back();
                continue;
            }
            if(top->next) {
                lists.front() = top->next;
                bubbleDown(lists);
            }
            else{
                pop_heap(lists.begin(), lists.end(), cmp);           
                lists.pop_back();
            }
            head->next = top;
            head = top;
        }
        return dumH->next;
    }
};
