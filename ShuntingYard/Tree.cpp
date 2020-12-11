//Created by Vatsal Parikh
//Date: 12/1/20
//.cpp file for tree class

//imports
#include "Tree.h"

//constructor requires a char*
Tree::Tree(Node* q) {
  
  //set expression to e and create new list
  qh = q;
  stack = new List();
}

//builds tree
Node* Tree::build() {
  while (qh != NULL) {

    //if an operator pop twice and then push subtree into stack
    if (qh->getNum() == -1) {                                                                                                               
      Node* n = new Node();                                                                                                         
      n->setNum(-1);                                                                                                                
      n->setPrecedence(2);                                                                                                          
      n->setAssociate(1);                                                                                                           
      n->setRight(stack->pop());                                                                                                                         
      n->setLeft(stack->pop());      
      stack->push(n, true);                                                                                                         
    }
    else if (qh->getNum() == -2) {                                                                                                                        
      Node* n = new Node();                                                                                                                               
      n->setNum(-2);                                                                                                                                      
      n->setPrecedence(2);                                                                                                                                
      n->setAssociate(1);                                                                                                                                 
      n->setRight(stack->pop());                                                                                                                          
      n->setLeft(stack->pop());                                                                                                                           
      stack->push(n, true);                                                                                                                               
    }
    else if (qh->getNum() == -3) {                                                                                                                    
      Node* n = new Node();                                                                                                                               
      n->setNum(-3);                                                                                                                                      
      n->setPrecedence(3);                                                                                                                                
      n->setAssociate(1);                                                                                                                                 
      n->setRight(stack->pop());                                                                                                                          
      n->setLeft(stack->pop());                                                                                                                           
      stack->push(n, true);                                                                                                                               
    }                                                                                                                                                    
    else if (qh->getNum() == -4) {                                                                                                                   
      Node* n = new Node();                                 
      n->setNum(-4);                                                                                                                                      
      n->setPrecedence(3);                                                                                                                                
      n->setAssociate(1);                                                                                                                                 
      n->setRight(stack->pop());                                                                                                                          
      n->setLeft(stack->pop());                                                                                                                           
      stack->push(n, true);                                                                                                                               
    }
    else if (qh->getNum() == -5) {                                                                                         
      Node* n = new Node();                                                                                               
      n->setNum(-5);                                                                                                        
      n->setPrecedence(4);                                                                                                   
      n->setAssociate(2);                                                                                                 
      n->setRight(stack->pop());                                                                                            
      n->setLeft(stack->pop());                                                                                             
      stack->push(n, true);                                                                                                  
    }
    
    //else its just a number and push it onto the stack
    else {
      Node* n = new Node();                                                                                                
      n->setNum(qh->getNum());                                                                                              
      stack->push(n, true); 
    }
    qh = qh->getNext();
  }

  return stack->peek();
  
}

//traverses tree to create infix form starts with top node
void Tree::infix(Node* n) {

  //if the node isn't null
  if (n != NULL) {

    //if the node is an operator add a (
    if (n->getNum() == -1 || n->getNum() == -2 || n->getNum() == -3 ||
	n->getNum() == -4 || n->getNum() == -5) {
      cout << "( ";
    }

    //call infix on the nodes left subtree
    infix(n->getLeft());

    //figure out if its an operator or normal number and print based off that
    if (n->getNum() == -1) {
      cout << "+ ";
    }
    else if (n->getNum() == -2) {
      cout << "- ";
    }
    else if (n->getNum() == -3) {
      cout << "* ";
    }
    else if (n->getNum() == -4) {
      cout << "/ ";
    }
    else if (n->getNum() == -5) {
      cout << "^ ";
    }
    else {
      cout << n->getNum() << " ";
    }
    
    //call infix on the nodes right subtree
    infix(n->getRight());

    //if the node is an operator add a )
    if (n->getNum() == -1 || n->getNum() == -2 || n->getNum() == -3 ||                                                              
	n->getNum() == -4 || n->getNum() == -5) {
      cout << ")";
    }
  }
}

//traverses tree to create postfix form starts with top node
void Tree::postfix(Node* n) {

  //if the node isn't null
  if (n != NULL) {

    //call postfix on the left subtree
    postfix(n->getLeft());

    //call postfix on the right subtree
    postfix(n->getRight());

    //figure out if its an operator or normal number and print based off that
    if (n->getNum() == -1) {                                                                                                                              
      cout << "+ ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -2) {                                                                                                                         
      cout << "- ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -3) {                                                                                                                         
      cout << "* ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -4) {                                                                                                                         
      cout << "/ ";                                                                                                                                      
    }                                                                                                                                                     
    else if (n->getNum() == -5) {                                                                                                                         
      cout << "^ ";                                                                                                                                       
    }                                                                                                                                                     
    else {                                                                                                                                                
      cout << n->getNum() << " ";                                                                                                                         
    }              
  }
}

//traverses tree to create prefix form starts with top node
void Tree::prefix(Node* n) {

  //if the node isn't null
  if (n != NULL) {

    //figure out if its an operator or normal number and print based off that
    if (n->getNum() == -1) {                                                                                                                              
      cout << "+ ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -2) {                                                                                                                         
      cout << "- ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -3) {                                                                                                                         
      cout << "* ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -4) {                                                                                                                         
      cout << "/ ";                                                                                                                                       
    }                                                                                                                                                     
    else if (n->getNum() == -5) {                                                                                                                         
      cout << "^ ";                                                                                                                                       
    }                                                                                                                                                     
    else {                                                                                                                                                
      cout << n->getNum() << " ";                                                                                                                         
    }

    //call prefix on the left subtree
    prefix(n->getLeft());

    //call prefix on the right subree
    prefix(n->getRight());
  }
}
