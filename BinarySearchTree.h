//
// Created by tim-berners-bai on 17-5-23.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

// 如果找到 target，返回相应的索引
// 如果没有找到 target，返回 -1
template <typename T>
int binarySearch(T arr[], int n, T target) {

    // 在 arr[l...r] 之中查找 target
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

template <typename Key, typename Value>
class BinarySearchTree {

private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            left = NULL;
            right = NULL;
        }

        Node(Node* node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node* root;
    int count;

public:
    BinarySearchTree() {
        root = NULL;
        count = 0;
    }

    ~BinarySearchTree(){
        destory(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    Value* search(Key key) {
        return search(root, key);
    }

    void perOrder() {
        perOrder(root);
    }

    void inOrder( ) {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

    void levelOrder() {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->key << endl;

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }

    Key minimum() {
        assert(count != 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }

    Key maximum() {
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    void removeMin() {
        if (root)
            root = removeMin(root);
    }

    void removeMax() {
        if (root)
            root = removeMax(root);
    }

    void removeNode(Key key) {
        root = removeNode(root, key);
    }

    // 寻找key的floor值
    // 如果不存在key的floor值(key比BST中的最小值还小), 返回NULL
    Key* floor(Key key){

        if( count == 0 || key < minimum() )
            return NULL;

        Node *floorNode = floor(root, key);
        return &(floorNode->key);
    }

    // 寻找key的ceil值
    // 如果不存在key的ceil值(key比BST中的最大值还大), 返回NULL
    Key* ceil(Key key){

        if( count == 0 || key > maximum() )
            return NULL;

        Node *ceilNode = ceil(root, key);
        return &(ceilNode->key);
    }

private:
    Node* insert(Node* node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if (key == node->key) {
            node->value = value;
        } else if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    bool contain(Node* node, Key key) {
        if (node == NULL) {
            return false;
        }
        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }

    Value* search(Node* node, Key key) {
        if (node == NULL)
            return NULL;
        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    void perOrder(Node* node) {
        if (node != NULL) {
            cout << node->key << endl;
            perOrder(node->left);
            perOrder(node->right);
        }
    }

    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
    }

    void destory(Node* node) {
        if (node != NULL) {
            destory(node->left);
            destory(node->right);

            delete node;
            count--;
        }
    }

    Node* minimum(Node* node) {
        if (node->left == NULL) {
            return node;
        }
        return minimum(node->left);
    }

    Node* maximum(Node* node) {
        if (node->right == NULL) {
            return node;
        }
        return maximum(node->right);
    }

    Node* removeMin(Node* node) {
        if (node->left == NULL)  {
            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node) {
        if (node->right == NULL) {
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node* removeNode(Node* node, Key key) {
        if (node == NULL)
            return NULL;
        if (key < node->key) {
            node->left = removeNode(node->left, key);
            return node;
        }
        else if (key > node->key) {
            node->right = removeNode(node->right, key);
            return node;
        }
        else {
            if (node->left == NULL) {
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            else if (node->right == NULL) {
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            else {
                Node* successor = new Node(minimum(node->right));
                count++;
                successor->right = removeMin(node->right);
                successor->left = node->left;
                delete node;
                count--;
                return successor;
            }
        }
    }

    // 在以node为根的二叉搜索树中, 寻找key的floor值所处的节点
    Node* floor(Node* node, Key key){

        if( node == NULL )
            return NULL;

        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的floor节点
        if( node->key == key )
            return node;

        // 如果node的key值比要寻找的key值大
        // 则要寻找的key的floor节点一定在node的左子树中
        if( node->key > key )
            return floor( node->left , key );

        // 如果node->key < key
        // 则node有可能是key的floor节点, 也有可能不是(存在比node->key大但是小于key的其余节点)
        // 需要尝试向node的右子树寻找一下
        Node* tempNode = floor( node->right , key );
        if( tempNode != NULL )
            return tempNode;

        return node;
    }

    // 在以node为根的二叉搜索树中, 寻找key的ceil值所处的节点
    Node* ceil(Node* node, Key key){

        if( node == NULL )
            return NULL;

        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的ceil节点
        if( node->key == key )
            return node;

        // 如果node的key值比要寻找的key值小
        // 则要寻找的key的ceil节点一定在node的右子树中
        if( node->key < key )
            return ceil( node->right , key );

        // 如果node->key > key
        // 则node有可能是key的ceil节点, 也有可能不是(存在比node->key小但是大于key的其余节点)
        // 需要尝试向node的左子树寻找一下
        Node* tempNode = ceil( node->left , key );
        if( tempNode != NULL )
            return tempNode;

        return node;
    }

};


#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
