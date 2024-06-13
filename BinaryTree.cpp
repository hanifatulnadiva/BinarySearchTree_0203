#include<iostream>
#include<string>
using namespace std;

class Node {
    public:
        string info;
        Node* leftchild;
        Node* rightchild;

        Node(string i, Node* l, Node*r){
            info=i;
            leftchild= l;
            rightchild=r;
        }

};

class BinaryTree
{
    public:
        Node* ROOT;
        BinaryTree()
        {
            ROOT = nullptr;
        }

        void insert(string element)
        {
            Node* newNode = new Node(element, nullptr, nullptr); // alocate memory for the new node
            newNode ->info = element; // assign value to the data field of the new node
            newNode->leftchild = nullptr;//make the leftchild of the new node poin the null
            newNode->rightchild= nullptr;   //make the rightchild of the new node poin the null

            Node* parent = nullptr;
            Node* currentNode = nullptr;

            search (element, parent, currentNode); // locate the node which will be the parent of the node to be indert

            if(parent == nullptr)// if the parent is Null (tree is empty)
            {
                ROOT = newNode; //mark the new node as root
                return; // exit
            }
            if(element < parent->info) //if the value in the data field of the new node is less then that of the
            {
                parent->leftchild = newNode; // make the left child of the parent point too the new Node 
            }
            else if (element > parent->info) // if the value in the data field of the new node id greather than
            {
                parent->rightchild=newNode; //make the right child of the parent point to the new node 
            }
        }

};