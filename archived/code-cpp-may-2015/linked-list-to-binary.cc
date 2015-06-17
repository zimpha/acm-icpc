long long getNumber(Node *head) {
    long long ret = 0;
    for (Node *p = head; p != nullptr; p = p->next) {
        ret = ret * 2 + p->data;
    }
    return ret;
}
