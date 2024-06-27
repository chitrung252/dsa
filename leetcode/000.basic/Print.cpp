void print(ListNode *head) {
    if (head == nullptr) {
        cout << "\nArray is empty";
    }
    ListNode *node = head;
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}