void delete_last(node *first) //usuwanie ostatniego elementu
{
    if (first != NULL && first->next != NULL) {
        while (first->next->next != NULL) {
            first = first->next;
        }
        delete first->next;
        first->next = NULL;
    }
}