#include <iostream>
#include <stack>
using namespace std;
class Node {

    int  data;
    Node * left;
    Node * right;
public:
    Node(int data, Node* left, Node* right)
        :data(data), left(left), right(right)
        {}
    Node(int data)
        :data(data), left(nullptr), right(nullptr)
        {}
    void setData(int data) {
        this->data = data;
    }
    int getData() {
        return data;
    }
    void setLeft(Node* left) {
        this->left = left;
    }
    Node* getLeft() {
        return left;
    }
    void setRight(Node* right) {
        this->right = right;
    }
    Node* getRight() {
        return right;
    }
    virtual ~Node() {
        if(left) delete left;
        if(right) delete right;
    }
    
};
/*
      1
    2   3
 4   5 6  7
8
 */

Node* buildTree() {
    Node * n8 = new Node(8);
    Node * n4 = new Node(4, n8, nullptr);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    Node * n7 = new Node(7);
    Node * n2 = new Node(2, n4, n5);
    Node * n3 = new Node(3, n6, n7);
    Node * n1 = new Node(1, n2, n3);
    return n1;
}

void preOrder(Node * root) {
    stack<Node *> s;
    if(root == nullptr) return;
    //s.push(root);
    Node * t = root;
    while(t || !s.empty()) {
        while(t != nullptr) {
            cout << " " << t->getData();
            s.push(t);
            t = t->getLeft();
        }
        if(!s.empty()) {
            t = s.top();
            s.pop();
            t = t->getRight();
        }
        
    }
    cout << endl;
    return;
}

void inOrder(Node * root) {
    stack<Node *> s;
    if(root == nullptr) return;
    //s.push(root);
    Node * t = root;
    while(t || !s.empty()) {
        while(t != nullptr) {
            s.push(t);
            t = t->getLeft();
        }
        if(!s.empty()) {
            t = s.top();
            cout << " " << t->getData();
            s.pop();
            t = t->getRight();
        }
        
    }
    cout << endl;
    return;
}

void postOrder(Node * root) {
    stack<Node*> s;
    if(root == nullptr) return;
    Node * t = root;
    Node * p = nullptr;
    while(t) {
        s.push(t);
        t = t->getLeft();
    }
    while(!s.empty()) {
        t = s.top();
        s.pop();
        if(t->getRight() == p || t->getRight() == nullptr) {
            cout << " " << t->getData();
            p = t;
        } else {
            s.push(t);
            t = t->getRight();
            while(t) {
                s.push(t);
                t = t->getRight();
            }
        }
        
    }
    cout << endl;
    return;
}

int main() {
    Node * root = buildTree();
    
    cout << "preorder:" << endl;
    preOrder(root);
    cout << "finish" << endl;
    
    cout << "inorder:" << endl;
    inOrder(root);
    cout << "finish" << endl;

    cout << "postorder" << endl;
    postOrder(root);
    cout << "finish" << endl;
    
    delete root;
    return 0;
}
