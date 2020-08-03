struct node {
    int val;
    node *next;
};

node *sort(struct node *first) {
    struct node *tmp = NULL;
    struct node *help = NULL;

    for (tmp = first; tmp != NULL; tmp = tmp->next)
        for (help = tmp; help != NULL; help = help->next)
            if (help->val < tmp->val) {
                int key = help->val;
                help->val = tmp->val;
                tmp->val = key;
            }
    return first;
}