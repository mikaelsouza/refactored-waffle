#include <iostream>
#include <vector>

std::vector<int> values;

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


void print_infix(Node *node){
    if(node == NULL){
        return;
    }
    print_infix(node->leftChild);
    values.push_back(node->value);
    print_infix(node->rightChild);
}


void print_prefix(Node *node){
    if(node == NULL){
        return;
    }
    values.push_back(node->value);
    print_prefix(node->leftChild);
    print_prefix(node->rightChild);
}

void print_postfix(Node *node){
    if(node == NULL){
        return;
    }
    print_postfix(node->leftChild);
    print_postfix(node->rightChild);
    values.push_back(node->value);
}



int main(){

    int qnt_casos;
    int qnt_nos;
    int aux;
    int contador_casos = 0;
    std::cin >> qnt_casos;
    int i;

    while(contador_casos < qnt_casos){
        contador_casos += 1;

        BinaryTree bt = BinaryTree();
        std::cin >> qnt_nos;

        while(qnt_nos--){
            std::cin >> aux;
            bt.insertElement(aux);
        }
        std::cout << "Case " << contador_casos << ":" <<std::endl;
        values.clear();
        std::cout << "Pre.: ";
        print_prefix(bt.root);
        for(i = 0; i < values.size() - 1; i++){
            std::cout << values[i] << " ";
        }
        std::cout << values[i];
        std::cout << std::endl;

        values.clear();
        std::cout << "In..: ";
        print_infix(bt.root);
        for(i = 0; i < values.size() - 1; i++){
            std::cout << values[i] << " ";
        }
        std::cout << values[i];
        std::cout << std::endl;

        values.clear();
        std::cout << "Post: ";
        print_postfix(bt.root);
        for(i = 0; i < values.size() - 1; i++){
            std::cout << values[i] << " ";
        }
        std::cout << values[i];
        std::cout << std::endl << std::endl;
    }

}
