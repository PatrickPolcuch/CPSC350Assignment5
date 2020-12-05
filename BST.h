//BST.h
#include <iostream>
#include <cstddef>//have to use this to use NULL

using namespace std;

template <class type>

class TreeNode{
public:
  TreeNode(type *v){
    left = NULL;
    right = NULL;
    value = v;
  }
  ~TreeNode(){
    delete left;
    delete right;
    //delete value;
  }

  type *value;
  TreeNode<type> *left;
  TreeNode<type> *right;
};

template <class type>

class BST{
  private:
    TreeNode <type>*root;
  public:
    BST(){
      root = NULL;
    }
    ~BST(){
      delete root;
    }

    void insertNode(type *v){
      TreeNode<type> *node = new TreeNode<type>(v);

      if(isEmpty()){
        //Empty Tree
        root = node;
      }
      else{
        //not an empty tree

        TreeNode<type> *parent = NULL;
        TreeNode<type> *current = root;

        while(true){
          parent = current;

          if(v < current->value){
            //go left
            current = current ->left;
            if(current == NULL){
              //found insertion point
              parent-> left = node;
              break;
            }
          }
          else{
            //go right

            current = current->right;
            if(current == NULL){
              //found insertion point
              parent->right = node;
              break;
            }
          }
        }
      }
    }
    bool searchNode(int v){

      if(isEmpty()){
        return false;
      }else{
        //tree is not empty, let's go look for the value

        TreeNode<type> *current = root;

        while(current->value->ID != v){
          if(v<current->value->ID){
            current = current->left;
          }else{
            current = current->right;
          }

          if(current == NULL){
            //we did not find it
            return false;
          }
        }
        return true;
      }
    }
    type* returnNode(int v){

      if(isEmpty()){
        return NULL;
      }else{
        //tree is not empty, let's go look for the value

        TreeNode<type> *current = root;

        while(current->value->ID != v){
          if(v<current->value->ID){
            current = current->left;
          }else{
            current = current->right;
          }

          if(current == NULL){
            //we did not find it
            return NULL;
          }
        }
        return current->value;
      }
    }
    bool deleteNode(type *v){
      if(isEmpty()){
        return false;
      }

      TreeNode<type> *parent = NULL;
      TreeNode<type> *current = root;
      bool isLeftNode = true;

      //usual code to find a node
      while(current->value != v){
        parent = current;

        if(v<current->value){
          //go left
          isLeftNode = true;
          current = current->left;
        }
        else{
          isLeftNode = false;
          current = current->right;
        }

        if(current == NULL){
          //value does not exist
          return false;
        }
      }
      //if we make it here, then we found it, now lets proceed to delete

      //case: node to be deleted has no chirldren, AKA leaf node
      if(current->left == NULL && current->right == NULL){
        if(current == root){
          root = NULL;
        } else if(isLeftNode){
          parent->left = NULL;
        } else{
          parent->right = NULL;
        }
      }

      //case: node to be deleted has one child. determine whether child is left or right

      if(current->right == NULL){
        //node has left child, no right child
        if(current == root){
          root = current->left;
        } else if(isLeftNode){
          parent->left = current->left;
        } else{
          parent->right = current->left;
        }
      }else if(current->left == NULL){
        //node has right child, no left child
        if(current == root){
          root = current->right;
        } else if(isLeftNode){
          parent->left = current->right;
        } else{
          parent->right = current->right;
        }
      }else{
        //node to be deleted has two chirldren. we need to find the successor in this case

        TreeNode<type> *successor = getSucessor(current);//current is the node to be deleted

        if(current == root){
          root = successor;
        } else if(isLeftNode){
          parent->left = successor;
        } else{
          parent->right = successor;
        }

        successor->left = current->left;
      }
      //do we delete(garbage collect) the tree in the delete function for the deconstructor????
      return true;
    }

    bool isEmpty(){
      return (root == NULL);
    }
    void printTree(){
      recPrint(root);
    }
    void recPrint(TreeNode<type> *node){
      if(node != NULL){
        recPrint(node->left);
        cout<<node->value->toString()<<endl;
        recPrint(node->right);
      }
    }
    string printTreeRand(){///returns the tree printed out of order so when we add these nodes to the tree again it's closer to balanced
      return recPrintRand(root);
    }
    string recPrintRand(TreeNode<type> *node){
      string ret = "";
      if(node != NULL){
        if((rand()%3)==0){
          ret += recPrintRand(node->left);
          ret += node->value->toString();
          ret += recPrintRand(node->right);
        } else if((rand()%3)==0){
          ret += node->value->toString();
          ret += recPrintRand(node->right);
          ret += recPrintRand(node->left);
        } else{
          ret += recPrintRand(node->right);
          ret += recPrintRand(node->left);
          ret += node->value->toString();
        }
      }
      return ret;
    }

    TreeNode<type>* getSucessor(TreeNode<type> *d){//returns the successor of the node to be deleted, d
      TreeNode<type> *sp = d;
      TreeNode<type> *successor = d;
      TreeNode<type> *current = d->right;

      while(current !=NULL){
        sp = successor;
        successor = current;
        current = current->left;
      }

      if(successor !=d->right){
        //descendant of the right chirld
        sp->left = successor->right;
        successor->right = d->right;
      }
      return successor;
    }
};
