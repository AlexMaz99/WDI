void delete_second(node *first) //usuwanie co drugiego elementu
{
    int i = 1;
    while (first != NULL && first->next != NULL) {
        i++;
        if (i % 2 == 0) {
            if (first->next->next != NULL) {
                node *p = first->next;
                first->next = first->next->next;
                delete p;
                i++;
            } else {
                delete first->next;
                first->next = NULL;
            }
        }
        first = first->next;
    }
}