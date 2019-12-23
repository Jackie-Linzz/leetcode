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
    if(root == nullptr) return;
    stack<Node *> s;
    Node * head = root;
    s.push(head);
    while(!s.empty()) {
        head = s.top();
        s.pop();
        cout << head->getData() << " ";
        Node * right = head->getRight();
        if (right) s.push(right);
        Node * left = head->getLeft();
        if (left) s.push(left); 
    }
    cout << endl;
    return; 
}

void inOrder(Node * root) {
    if(root == nullptr) return;
    stack<Node *> s;
    Node * head = root;
    
    while(head != nullptr || !s.empty()) {
        if(head != nullptr) {
            s.push(head);
            head = head->getLeft();
        } else {
            head = s.top();
            s.pop();
            cout << head->getData() << " ";
            head = head->getRight();
        }
    }
    cout << endl;
    return;
}

void postOrder(Node * root) {
    if(root == nullptr) return;
    stack<Node *> s1, s2;
    Node * head = root;
    s1.push(head);
    while(!s1.empty()) {
        head = s1.top();
        s1.pop();
        s2.push(head);
        Node * left = head->getLeft();
        Node * right = head->getRight();
        if(left) s1.push(left);
        if(right) s1.push(right);
    }
    while(!s2.empty()) {
        head = s2.top();
        s2.pop();
        cout << head->getData() << " ";
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
