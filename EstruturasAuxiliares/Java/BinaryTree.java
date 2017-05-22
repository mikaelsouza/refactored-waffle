/**
 * Created by mikael on 21/05/17.
 */
public class BinaryTree {

    Node root;

    BinaryTree(){
         root = null;
    }

    public void insertElement(int value){
        Node newNode = new Node(value);

        if(this.root == null){
            this.root = newNode;
        } else {
            Node auxNode = this.root;
            Node previous;

            while(auxNode != null){
                previous = auxNode;
                if(value > auxNode.value){
                    auxNode = auxNode.rightChild;
                    if(auxNode == null){
                        previous.rightChild = newNode;
                    }
                } else{
                    auxNode = auxNode.leftChild;
                    if(auxNode == null){
                        previous.leftChild = newNode;
                    }
                }
            }
        }
    }

    public void printNodesInfix(){
        infixRecursive(this.root);
    }

    private void infixRecursive(Node node){
        if(node != null){
            infixRecursive(node.leftChild);
            System.out.println(node.value);
            infixRecursive(node.rightChild);
        }
    }

}

