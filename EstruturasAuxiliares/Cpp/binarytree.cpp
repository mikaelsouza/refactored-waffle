#include <iostream>

class Node{
public:
    int value;
    Node *rightChild;
    Node *leftChild;

    Node(int value){
        this->value = value;
        this->rightChild = NULL;
        this->leftChild = NULL;
    }
};

class BinaryTree{

public:
    Node *root;

    BinaryTree(){
        this->root = NULL;
    }

    ~BinaryTree(){
        deleteNode(this->root);
    }

    void deleteNode(Node *node){
        if(node != NULL){
            deleteNode(node->leftChild);
            deleteNode(node->rightChild);
            delete node;
        }
    }

    void insertElement(int value){
        Node *newNode = new Node(value);
        if(this->root == NULL){
            this->root = newNode;
        } else {
            Node *auxNode = this->root;
            Node *previous;

            while(auxNode != NULL){
                previous = auxNode;
                if(value > auxNode->value){
                    auxNode = auxNode->rightChild;
                    if(auxNode == NULL){
                        previous->rightChild = newNode;
                    }
                } else {
                    auxNode = auxNode->leftChild;
                    if(auxNode == NULL){
                        previous->leftChild = newNode;
                    }
                }
            }
        }
    }
    void printNodesInfix(){
        infixRecursive(this->root);
    }
    void infixRecursive(Node *node){
        if(node != NULL){
            infixRecursive(node->leftChild);
            std::cout << node->value << std::endl;
            infixRecursive(node->rightChild);
        }
    }
};
