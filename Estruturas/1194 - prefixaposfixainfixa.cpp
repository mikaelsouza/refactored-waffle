#include <iostream>
#include <string>

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
    std::string prefixo;
    std::string infixo;

    BinaryTree(std::string prefixo, std::string infixo){
        this->root = NULL;
        this->prefixo = prefixo;
        this->infixo = infixo;
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
    void printNodesPosfix(){
        posfixRecursive(this->root);
    }
    void posfixRecursive(Node *node){
        if(node != NULL){
            posfixRecursive(node->leftChild);
            posfixRecursive(node->rightChild);
            std::cout << this->infixo[node->value];
        }
    }
};

std::string prefixo;
std::string infixo;

int main(){

    int qnt_casos;
    int tam;

    std::cin >> qnt_casos;

    while(qnt_casos > 0){
        std::cin >> tam >> prefixo >> infixo;
        // Cria a árvore passando as strings por parâmetro para serem manipuladas
        BinaryTree b = BinaryTree(prefixo, infixo);
        // Para cada letra na string prefixo, procurar a posição dela na string
        // posfixo e adicionar a posição na árvore.
        for (auto letra : prefixo){
            int pos = infixo.find(letra);
            b.insertElement(pos);
        }
        // Após adicionar na árvore, mandar imprimir de forma posfixa os
        // as letras da string infixa utilizando a ordem posfixa da árvore
        // criada anteriormente.
        b.printNodesPosfix();
        std::cout << std::endl;
        qnt_casos -= 1;
    }
}
