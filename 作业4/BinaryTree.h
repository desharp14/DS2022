#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

#include <algorithm>

using namespace std;

//Node
template < typename Comparable >
  class Node {
    private:
      Comparable element;
    Node * left;
    Node * right;

    public:
      //Construct node
      Node() {};
    //Get the _val from the node
    virtual Comparable getelement() const {
      return element;
    }
    //Assign _val to the element
    virtual void setelement(const Comparable _val) {
      element = _val;
    }
  };

//BinaryTree
template < typename Comparable >
  class BinaryTree {
    private:
      class BinaryTreeNode: public Node < Comparable > {};
    BinaryTreeNode * root;

    public:
      //Constructor
      BinaryTree(): root {
        nullptr
      } {}
    //Destructor
    virtual~BinaryTree() {}
    //Insert _val to the tree.
    virtual void insert(const Comparable & _val) {}
    //Find the smallest item in the tree
    virtual
    const Comparable & findMin() const = 0;
    //Find the smallest item in the tree
    virtual
    const Comparable & findMax() const = 0;
    //Remove _val from the tree
    virtual void remove(const Comparable & _val) {}
  };

//BinarySearchTree
template < typename Comparable >
  class BinarySearchTree {
    private:
      class BinarySearchTreeNode: public Node < Comparable > {};
    BinarySearchTreeNode * root;

    public:
      //Constructor
      BinarySearchTree(): root {
        nullptr
      } {}
    //Destructor
    virtual~BinarySearchTree() {}
    //Insert _val to the tree
    virtual void insert(const Comparable & _val) {}
    //Find the smallest item in the tree
    virtual
    const Comparable & findMin() const = 0;
    //Find the smallest item in the tree
    virtual
    const Comparable & findMax() const = 0;
    //Remove _val from the tree
    virtual void remove(const Comparable & _val) {}
  };

//AvlTree
template < typename Comparable >
  class AvlTree: public BinaryTree < Comparable > {
    private: class AvlNode: public Node < Comparable > {
      //Height of each node
      int height;
    };
    //Root node
    AvlNode * root;

    public:
      //Constructor 
      AvlTree(): root {
        nullptr
      } {}
    //Destructor
    virtual~AvlTree() {}
    //Insert _val to the tree
    virtual void insert(const Comparable & _val) {}
    //Rotate binary tree node
    virtual void rotate(const Comparable * & t) {}
    //Balance the tree
    virtual void balance(AvlNode * & t) {}
    //Return the height of node
    virtual int height(AvlNode * t) const = 0
    //Remove _val from the tree
    virtual void remove(const Comparable & _val) {}
  };

#endif