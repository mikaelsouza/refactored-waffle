#include <iostream>
#include <queue>

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

  void deleteNode(Node *node){
      if(node != NULL){
          deleteNode(node->leftChild);
          deleteNode(node->rightChild);
          delete node;
      }
  }

public:
    Node *root;

    BinaryTree(){
        this->root = NULL;
    }

    ~BinaryTree(){
        deleteNode(this->root);
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
};

void printLevels(Node *node, std::queue<Node*> &fila){

    if(node != NULL){
        if(node->leftChild != NULL){
            fila.push(node->leftChild);
        }
        if(node->rightChild != NULL){
            fila.push(node->rightChild);
        }
        if(fila.size() == 1){
            std::cout << fila.front()->value << std::endl;
            fila.pop();
        } else {
            std::cout << fila.front()->value << " ";
            fila.pop();
        }
    }
    if(fila.size() > 0){
        printLevels(fila.front(), fila);
    }
}

std::queue<Node*> fila;

int main(){

    int qnt_casos;
    int qnt_entradas;
    int aux;
    int v = 1;
    std::cin >> qnt_casos;

    while(qnt_casos > 0){
        BinaryTree bt = BinaryTree();
        std::cin >> qnt_entradas;
        while(qnt_entradas > 0){
            std::cin >> aux;
            bt.insertElement(aux);
            qnt_entradas -= 1;
        }

        std::cout << "Case " << v << ":" << std::endl;
        fila.push(bt.root);
        printLevels(bt.root, fila);
        std::cout << std::endl;
        v += 1;
        qnt_casos -= 1;

    }
}
