Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* mergeTwoLL(Node* left,Node* right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        Node* ansHead = new Node(-1);
        Node* ans = ansHead;
        
        while(left!=NULL && right !=NULL){
            if(left->data < right->data){
                ans->next = left;
                ans = left;
                left = left->next;
            }
            else{
                ans->next = right;
                ans = right;
                right = right->next;
            }
        }
        
        while(left != NULL){
            ans->next = left;
            ans = left;
            left = left->next;
        }
        while(right != NULL){
            ans->next = right;
            ans = right;
            right = right->next;
        }
        return ansHead->next;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL) return head;
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* ans = mergeTwoLL(left,right);
        
        return ans;
        
    }