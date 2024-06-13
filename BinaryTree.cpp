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

        void search (string element, Node*& parent, Node*& currentNode)
        {
            //this function searches the currentNode of the specified Node aas well as the current Node of its parent

            currentNode= ROOT;
            parent = NULL;
            while ((currentNode!=NULL) && (currentNode->info != element))
            {
                parent = currentNode;
                if (element < currentNode->info)
                    currentNode =currentNode-> leftchild;
                else
                    currentNode = currentNode->rightchild;
            }
        }

        void inorder (Node* ptr)
        {
            if (ROOT == NULL)
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr!= NULL)
            {
                inorder (ptr->leftchild);
                cout << ptr-> info <<" ";
                inorder (ptr->rightchild);
            }
        }

        void preorder (Node* ptr)
        {
            if (ROOT == NULL)
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr!= NULL)
            {
                cout << ptr-> info <<" ";
                preorder (ptr->leftchild);
                preorder (ptr->rightchild);
            }
        }

        void postorder (Node* ptr)
        {
            if (ROOT == NULL)
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr!= NULL)
            {
                postorder (ptr->leftchild);
                postorder (ptr->rightchild);
                cout << ptr-> info <<" ";
            }
        }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. implementasi insert operation"<< endl;
        cout << "2. perform inorder operation"<< endl;
        cout << "3. perform preorder operation"<< endl;
        cout << "4. perform postorder operation"<< endl;
        cout << "5. exit"<< endl;
        cout << "\nEnter your choce (1-5):";
        char ch;
        cin>> ch;
        cout << endl;

        switch(ch)
        {
        case '1':
        {
            cout << "enter a word:";
            string word;
            cin >> word;
            x.insert (word);
            break;
        }
        case'2':
        {
            x. inorder(x.ROOT);
            break;
        }
        case'3':
        {
            x.preorder(x.ROOT);
            break;
        }
        case'4':
        {
            x.postorder(x.ROOT);
            break;
        }
        case '5':
        {
            return 0;
        }
        default:
        {
            cout << "invalid option" << endl;
            break;
        }
        
        }
    }
}