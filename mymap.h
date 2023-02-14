// mymap.h
// This is the header file that contains all the function in relation to a
// threaded self-balancing binary search tree
//
//  
//  Copyright © 2022 Mark Cirineo. All rights reserved.
// System: MacOSX, Visual Studio 
//
// 
#pragma once

#include <iostream>
#include <sstream>
#include <stack> 
#include <vector>

using namespace std;

template <typename keyType, typename valueType>
class mymap {
 private:
  struct NODE {
    keyType key;      // used to build BST
    valueType value;  // stored data for the map
    NODE* left;       // links to left child
    NODE* right;      // links to right child
    int nL;           // number of nodes in left subtree
    int nR;           // number of nodes in right subtree
    bool isThreaded;
  };
  NODE* root;  // pointer to root node of the BST
  int size;    // # of key/value pairs in the mymap

  //
  // iterator:
  // This iterator is used so that mymap will work with a foreach loop.
  //
  struct iterator {
   private:
    NODE* curr;  // points to current in-order node for begin/end

   public:
    iterator(NODE* node) { 
      curr = node; 
    }

    keyType operator*() { 
      return curr->key; 
    }

    bool operator==(const iterator& rhs) { 
      return curr == rhs.curr; 
    }

    bool operator!=(const iterator& rhs) { 
      return curr != rhs.curr; 
    }

    bool isDefault() { 
      return !curr; 
    }

    //
    // operator++:
    //
    // This function should advance curr to the next in-order node.
    // O(logN)
    //
    iterator operator++() {
      NODE* next;
      if (this->curr->isThreaded) {
        this->curr = this->curr->right;
      } else {
        next = this->curr->right;
        this->curr = next;
        while (next != nullptr) {
          this->curr = next;
          next = next->left;
        }
      }

      return iterator(this->curr);  // TODO: Update this return.
    }
  };

  // inOrder
  // in-order recursive function used for toString
  void inOrder(struct NODE* node, stringstream& ss) {
    if (node == nullptr) return;

    inOrder(node->left, ss);

    ss << "key: " << node->key << " value: " << node->value << "\n";

    NODE* next = (node->isThreaded) ? nullptr : node->right;

    inOrder(next, ss);
  }

  // inOrderVector
  // in-order recursive function to build a vector that contains the key and
  // value for all of the nodes connected to the given node Called by toVector
  // function
  void inOrderVector(struct NODE* node, vector<pair<keyType, valueType>>& vec) {
    if (node == nullptr) return;

    inOrderVector(node->left, vec);

    vec.emplace_back(node->key, node->value);

    NODE* next = (node->isThreaded) ? nullptr : node->right;

    inOrderVector(next, vec);
  }

  // inOrderBalance
  // pre-order recursive function used for checkBalance function
  void inOrderBalance(struct NODE* node, stringstream& ss) {
    if (node == nullptr) return;

    ss << "key: " << node->key << ", nL: " << node->nL << ", nR: " << node->nR
       << "\n";

    inOrderBalance(node->left, ss);

    inOrderBalance(node->isThreaded ? nullptr : node->right, ss);
  }

  // buildVector
  // in-order recursive function that is used to create a vector that contains
  // all of the nodes connected to a given node
  void buildVector(struct NODE* node, vector<struct NODE*>& nodes) {
    if (node == nullptr) return;
    buildVector(node->left, nodes);
    nodes.emplace_back(node);
    buildVector((node->isThreaded) ? nullptr : node->right, nodes);
  }

  // balancing
  // Recursive function that handles balancing
  void balancing(NODE* root, int begin, int end, vector<struct NODE*>& nodes,
                 stack<NODE*>& nodes_toUpdate) {
    // base case
    if (end < begin || begin > end) {
      return;
    }

    int mid = (begin + end) / 2;
    // if root is nullptr then the root for this map is this node
    if (root == nullptr) {
      this->root = nodes[mid];
      // resetting all the parameters for this node
      this->root->isThreaded = false;
      this->root->left = nullptr;
      this->root->right = nullptr;
      this->root->nL = 0;
      this->root->nR = 0;
    } else if (nodes[mid]->key < root->key) {
      root->left = nodes[mid];
      nodes_toUpdate.push(root);  // keeping tract of nodes that havce to update nL and nR
      nodes[mid]->right = root;
      // resetting all the parameters for this node
      nodes[mid]->left = nullptr;
      nodes[mid]->nL = nodes[mid]->nR = 0;
      nodes[mid]->isThreaded = true;
    } else {
      NODE* thread = root->isThreaded ? nullptr : root->right;
      root->isThreaded = false;
      root->right = nodes[mid];
      nodes_toUpdate.push(root);  // keeping track of nodes that have to update nL and nR
      nodes[mid]->right = thread;
      nodes[mid]->isThreaded = (thread == nullptr) ? false : true;
      // resetting all the parameters for this node
      nodes[mid]->left = nullptr;
      nodes[mid]->nL = nodes[mid]->nR = 0;
    }
    balancing(nodes[mid], begin, mid - 1, nodes, nodes_toUpdate);
    balancing(nodes[mid], mid + 1, end, nodes, nodes_toUpdate);
  }

  // updateSizes
  // This function is used to update the nL and nR values for all of the nodes
  // in the given satck This function also checks if the node is broken and if
  // it is then calls the balancing function
  void updateSizes(stack<NODE*>& nodes, bool toBalance) {
    stack<NODE*> nodesToRebalance;
    int j = nodes.size();
    for (int i = 0; i < j; i++) {
      if (nodes.top()->left == nullptr) {
        nodes.top()->nL = 0;
      } else {
        nodes.top()->nL = nodes.top()->left->nL + nodes.top()->left->nR + 1;
      }
      if (nodes.top()->isThreaded || nodes.top()->right == nullptr) {
        nodes.top()->nR = 0;
      } else {
        nodes.top()->nR = nodes.top()->right->nR + nodes.top()->right->nL + 1;
      }
      // check if the node is broken
      if ((max(nodes.top()->nL, nodes.top()->nR) >
           2 * min(nodes.top()->nL, nodes.top()->nR) + 1) &&
          toBalance) {
        // If the vector has nodes in it then remove them
        if (nodesToRebalance.size() > 0) {
          nodesToRebalance.pop();
          nodesToRebalance.pop();
        }
        // insert the node that is broken
        nodesToRebalance.push(nodes.top());
        // remove the node from the stack
        nodes.pop();
        // push the root node to the broken node into the vector
        nodesToRebalance.push((nodes.size() > 0) ? nodes.top() : nullptr);
      } else
        nodes.pop();
    }
    // if there are nodes in the vector then there needs to be rebalancing
    if (nodesToRebalance.size() > 0) {
      stack<NODE*> nodestoUpdate;
      NODE* root = nodesToRebalance.top();
      nodesToRebalance.pop();
      NODE* curr = nodesToRebalance.top();
      nodesToRebalance.pop();
      vector<struct NODE*> Nodes;
      // build vector containing all of the nodes connected to the broken node
      // in in-order
      buildVector(curr, Nodes);
      // balance the subtree
      balancing(root, 0, Nodes.size() - 1, Nodes, nodestoUpdate);
      // update the nL and nR values of all the nodes that were changed
      updateSizes(nodestoUpdate, false);
    }
    return;
  }

  // insertNode
  // inserts the node into the tree
  void insertNode(keyType key, valueType value, NODE* prev, stack<NODE*>& nodes,
                  bool toBalance) {
    NODE* thread;

    NODE* node = new NODE();
    node->key = key;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->isThreaded = false;
    node->nL = 0;
    node->nR = 0;

    if (prev == nullptr) {
      root = node;
      size++;
      return;
    } else if (key < prev->key) {
      thread = prev;
      prev->left = node;
      node->right = thread;
      node->isThreaded = true;
    } else {
      thread = prev->right;
      prev->isThreaded = false;
      prev->right = node;
      node->right = thread;
      if (thread != nullptr) node->isThreaded = true;
    }

    size++;
    if (prev != nullptr) {
      updateSizes(nodes, toBalance);
    }
  }

  // insert
  // This function traverses to the point where insertion needs to happen
  void insert(keyType key, valueType value, bool toBalance) {
    NODE* prev = nullptr;
    NODE* curr = root;
    stack<NODE*> nodes;

    while (curr != nullptr) {
      if (curr->key == key) {
        curr->value = value;
        return;
      }

      else if (key < curr->key) {
        prev = curr;
        curr = curr->left;
        nodes.push(prev);
      }

      else {
        prev = curr;
        nodes.push(prev);
        curr = (curr->isThreaded) ? nullptr : curr->right;
      }
    }
    insertNode(key, value, prev, nodes, toBalance);
  }

  // deleteTree
  // post-oorder recursive function to delete the tree
  void deleteTree(NODE* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree((node->isThreaded) ? nullptr : node->right);
    delete node;
  }

  // treeCopy
  // pre-order recursive function to create a copy of a tree
  void treeCopy(NODE* temp) {
    if (temp == nullptr)
      return;
    else {
      insert(temp->key, temp->value, false);
      treeCopy(temp->left);
      treeCopy((temp->isThreaded) ? nullptr : temp->right);
    }
  }

 public:
  //
  // default constructor:
  //
  // Creates an empty mymap.
  // Time complexity: O(1)
  //
  mymap() {
    root = nullptr;
    size = 0;
  }

  //
  // copy constructor:
  //
  // Constructs a new mymap which is a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(nlogn), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap(const mymap& other) {
    this->root = nullptr;
    this->size = 0;

    treeCopy(other.root);
  }

  //
  // operator=:
  //
  // Clears "this" mymap and then makes a copy of the "other" mymap.
  // Sets all member variables appropriately.
  // Time complexity: O(nlogn), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  mymap& operator=(const mymap& other) {
    this->clear();
    treeCopy(other.root);
    return *this;
  }

  // clear:
  //
  // Frees the memory associated with the mymap; can be used for testing.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  void clear() {
    NODE* node = root;
    deleteTree(node);
    size = 0;
    root = nullptr;
  }

  //
  // destructor:
  //
  // Frees the memory associated with the mymap.
  // Time complexity: O(n), where n is total number of nodes in threaded,
  // self-balancing BST.
  //
  ~mymap() { 
    this->clear(); 
  }

  //
  // put:
  //
  // Inserts the key/value into the threaded, self-balancing BST based on
  // the key.
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-tree that needs to be re-balanced.
  // Space complexity: O(1)
  //
  void put(keyType key, valueType value) { 
    insert(key, value, true);
  
 }

  //
  // contains:
  // Returns true if the key is in mymap, return false if not.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  bool contains(keyType key) {
    NODE* curr = root;
    while (curr != nullptr) {
      if (curr->key == key) return true;

      if (key < curr->key)
        curr = curr->left;

      else
        curr = (curr->isThreaded) ? nullptr : curr->right;
    }
    return false;
  }

  //
  // get:
  //
  // Returns the value for the given key; if the key is not found, the
  // default value, valueType(), is returned (but not added to mymap).
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  valueType get(keyType key) {
    NODE* curr = root;
    while (curr != nullptr) {
      if (curr->key == key)
        return curr->value;

      else if (key < curr->key)
        curr = curr->left;

      else
        curr = (curr->isThreaded) ? nullptr : curr->right;
    }
    return valueType();
  }

  //
  // operator[]:
  //
  // Returns the value for the given key; if the key is not found,
  // the default value, valueType(), is returned (and the resulting new
  // key/value pair is inserted into the map).
  // Time complexity: O(logn + mlogm), where n is total number of nodes in the
  // threaded, self-balancing BST and m is the number of nodes in the
  // sub-trees that need to be re-balanced.
  // Space complexity: O(1)
  //
  valueType operator[](keyType key) {
    NODE* prev = nullptr;
    NODE* curr = root;
    stack<NODE*> nodes;

    while (curr != nullptr) {
      if (curr->key == key) {
        return curr->value;
      }

      else if (key < curr->key) {
        prev = curr;
        curr = curr->left;
        nodes.push(prev);
      }

      else {
        prev = curr;
        nodes.push(prev);
        curr = (curr->isThreaded) ? nullptr : curr->right;
      }
    }

    insertNode(key, valueType(), prev, nodes, true);
    return valueType();
  }

  //
  // Size:
  //
  // Returns the # of key/value pairs in the mymap, 0 if empty.
  // O(1)
  //
  int Size() { return size; }

  //
  // begin:
  //
  // returns an iterator to the first in order NODE.
  // Time complexity: O(logn), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  iterator begin() {
    iterator itr(nullptr);
    NODE* next;
    next = root;
    while (next != nullptr) {
      itr = next;
      next = next->left;
    }

    return itr;
  }

  //
  // end:
  //
  // returns an iterator to the last in order NODE.
  // this function is given to you.
  //
  // Time Complexity: O(1)
  //
  iterator end() { return iterator(nullptr); }

  //
  // toString:
  //
  // Returns a string of the entire mymap, in order.
  // Format for 8/80, 15/150, 20/200:
  // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  string toString() {
    NODE* node = root;
    stringstream ss;
    inOrder(node, ss);
    string str = ss.str();
    return str;
  }

  //
  // toVector:
  //
  // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
  // {{8, 80}, {15, 150}, {20, 200}}
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  vector<pair<keyType, valueType>> toVector() {
    vector<pair<keyType, valueType>> vec;
    inOrderVector(root, vec);
    return vec;
  }

  //
  // checkBalance:
  //
  // Returns a string of mymap that verifies that the tree is properly
  // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
  // function should return a string in this format (in pre-order):
  // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
  // Time complexity: O(n), where n is total number of nodes in the
  // threaded, self-balancing BST
  //
  string checkBalance() {
    NODE* node = root;
    stringstream ss;
    inOrderBalance(node, ss);
    string str = ss.str();
    return str;
  }
};