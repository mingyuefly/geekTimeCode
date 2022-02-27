//
//  main.cpp
//  BinarySearchTree
//
//  Created by mingyue on 2022/2/14.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct Comparable {
public:
    Comparable() {
        
    }
    Comparable(int value) {
        this->value = value;
    }
    int value;
    int compareTo(Comparable a) {
        return value - a.value;
    }
    ~Comparable() {
        cout << "~Comparable()" << endl;
    }
}Comparable;

typedef struct Node {
public:
    Node() {
        
    }
    Node(Comparable key, int value, int N) {
        this->key = key;
        this->value = value;
        this->N = N;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~Node() {
        cout << "~Node()" << endl;
        delete left;
        delete right;
    }
    Comparable key;
    int value;
    Node * left;
    Node * right;
    int N;
private:
}Node;

class BinarySearchTree {
public:
    BinarySearchTree() {
        
    }
    ~BinarySearchTree() {
        cout << "~BinarySearchTree()" << endl;
        delete root;
    }
    int size() {
        return size(root);
    }
    int get(Comparable key) {
        return get(root, key);
    }
    void put(Comparable key, int value) {
        root = put(root, key, value);
    }
    Comparable min() {
        return min(root)->key;
    }
    Comparable floor(Comparable key) {
        Node * x = floor(root, key);
        if (x == nullptr) {
            return Comparable(-1);
        }
        return x->key;
    }
    Comparable select(int k) {
        return select(root, k)->key;
    }
    int rank(Comparable key) {
        return rank(key, root);
    }
    void deleteMin() {
//        deleteMin(root);
        Node * t = min(root);
        root = deleteMin(root);
        t->right = nullptr;
        delete t;
    }
    void deleteKey(Comparable key) {
        root = deleteKey(root, key);
    }
    void show() {
        show(root);
    }
private:
    Node *root;
    int size(Node * x) {
        if (x == nullptr) {
            return 0;
        } else {
            return x->N;
        }
    }
    int get(Node * x, Comparable key) {
        if (x == nullptr) {
            return -1;
        }
        int cmp = key.compareTo(x->key);
        if (cmp < 0) {
            return get(x->left, key);
        } else if (cmp > 0) {
            return get(x->right, key);
        } else {
            return x->value;
        }
    }
    Node * put(Node * x, Comparable key, int value) {
        if (x == nullptr) {
            return new Node(key, value, 1);
        }
        int cmp = key.compareTo(x->key);
        if (cmp < 0) {
            x->left = put(x->left, key, value);
        } else if (cmp > 0) {
            x->right = put(x->right, key, value);
        } else {
            x->value = value;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    Node * min(Node * x) {
        if (x->left == nullptr) {
            return x;
        }
        return min(x->left);
    }
    Node * floor(Node * x, Comparable key) {
        if (x == nullptr) {
            return nullptr;
        }
        if (key.compareTo(x->key) == 0) {
            return x;
        }
        if (key.compareTo(x->key) < 0) {
            return floor(x->left, key);
        }
        Node * t = floor(x->right, key);
        if (t != nullptr) {
            return t;
        } else {
            return x;
        }
    }
    Node * select(Node * x, int k) {
        if (x == nullptr) {
            return nullptr;
        }
        int t = size(x->left);
        if (t > k) {
            return select(x->left, k);
        } else if (t < k) {
            return select(x->right, k - t - 1);
        } else {
            return x;
        }
    }
    int rank(Comparable key, Node * x) {
        if (x == nullptr) {
            return 0;
        }
        int cmp = key.compareTo(x->key);
        if (cmp < 0) {
            return rank(key, x->left);
        } else if (cmp > 0) {
            return 1 + size(x->left) + rank(key, x->right);
        } else {
            return 1 + size(x->left);
        }
    }
    Node * deleteMin(Node * x) {
        if (x->left == nullptr) {
            return x->right;
        }
        x->left = deleteMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    Node * deleteKey(Node * x, Comparable key) {
        if (x == nullptr) {
            return nullptr;
        }
        int cmp = key.compareTo(x->key);
        if (cmp < 0) {
            x->left = deleteKey(x->left, key);
        } else if (cmp > 0) {
            x->right = deleteKey(x->right, key);
        } else {
            if (x->right == nullptr) {
                return x->left;
            }
            if (x->left == nullptr) {
                return x->right;
            }
            Node * t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
            t->left = nullptr;
            t->right = nullptr;
            delete t;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    void show(Node * x) {
        if (x == nullptr) {
            return;
        }
        show(x->left);
        cout << x->key.value << ":" << x->value << endl;
        show(x->right);
    }
};

int main(int argc, const char * argv[]) {
    
    BinarySearchTree bst = BinarySearchTree();
    
    Comparable key0 = Comparable();
    key0.value = 18;
    Comparable key1 = Comparable();
    key1.value = 23;
    Comparable key2 = Comparable();
    key2.value = 4;
    Comparable key3 = Comparable();
    key3.value = 17;
    Comparable key4 = Comparable();
    key4.value = 0;
    Comparable key5 = Comparable();
    key5.value = 2;
    Comparable key6 = Comparable();
    key6.value = 12;
    Comparable key7 = Comparable();
    key7.value = 11;
    Comparable key8 = Comparable();
    key8.value = 15;
    
    bst.put(key0, 100);
    bst.put(key1, 101);
    bst.put(key2, 102);
    bst.put(key3, 103);
    bst.put(key4, 104);
    bst.put(key5, 105);
    bst.put(key6, 106);
    bst.put(key7, 107);
    bst.put(key8, 108);
    
    bst.show();
    
    cout << bst.get(key5) << endl;
    
    bst.put(key6, 116);
    bst.show();
    
    cout << bst.min().value << endl;
    cout << bst.floor(key6).value << endl;
    
    Comparable key9 = Comparable();
    key9.value = 13;
    cout << bst.floor(key9).value << endl;
    
    cout << bst.select(3).value << endl;
    
    cout << bst.rank(16) << endl;
    
    bst.deleteMin();
    bst.show();
    
    bst.deleteKey(key6);
    bst.show();
 
    return 0;
}
