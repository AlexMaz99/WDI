#include <iostream>
#include <cmath>

using namespace std;


struct node {
    int w;
    node *right;
    node *left;
};

int leaves(node *root) // funkcja zwracajaca liczbe lisci w drzewie
{
    if (root == NULL) return 0;
    if (root->right == NULL && root->left == NULL) return 1;
    return leaves(root->right) + leaves(root->left);
}

/*napisz funkcje wypisujaca zawartosc drzewa*/

void print_tree(node *root) {
    if (root == NULL) return;
    if (root->left != NULL) {
        print_tree(root->left);
    }
    cout << root->val << endl;
    if (root->right != NULL) {
        print_tree(root->right);
    }
}

/*funkcja wypisujaca liczbe elementow w drzewie*/

int size(node *root, int &counter) {
    if (root == NULL) return;
    counter++;
    size(root->left, counter);
    size(root->right, counter);
}

/*funkcja zwracajaca wysokosc drzewa*/

int height(node *root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}


// funkcja zwracajaca liczbe wezlow na n-tym poziomie
int node_count(node *root, int lvl, int n) {
    if (root == NULL) return 0;
    if (lvl == n) return 1;
    return node_count(root->left, lvl + 1, n) + node_count(root->right, lvl + 1, n);
}

//funkcja usuwajaca drzewo

void delete_tree(node *&root) {
    if (root != NULL) {
        delete_tree(root->right);
        delete_tree(root->left);
        delete root;
        root = NULL;
    }
}

/*Drzewo bst - elementy po lewej stronie sa mniejsze niz elementy po prawej stronie
    dla drzewa bst napisz funkcje:
    a) sprawdzajaca czy element jest w drzewie
    b) wstawiajaca element do drzewa*/

bool bst_exist(node *root, int el) {
    if (root == NULL) return false;
    if (root->val == el) return true;
    if (root->val < el) {
        bst_exist(root->left, el);
    } else {
        bst_exist(root->right, el);
    }
}


int main() {

}