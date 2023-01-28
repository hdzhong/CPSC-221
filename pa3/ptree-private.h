/*
*  File:        ptree-private.h
*  Description: Private functions for the PTree class
*  Date:        2022-03-06 03:30
*
*               DECLARE YOUR PTREE PRIVATE MEMBER FUNCTIONS HERE
*/

#ifndef _PTREE_PRIVATE_H_
#define _PTREE_PRIVATE_H_

/////////////////////////////////////////////////
// DEFINE YOUR PRIVATE MEMBER FUNCTIONS HERE
//
// Just write the function signatures.
//
// Example:
//
// Node* MyHelperFunction(int arg_a, bool arg_b);
//
/////////////////////////////////////////////////

void renderHelper(Node* curr, PNG& im) const;
Node * copyHelper(Node* orig);
void clearHelper(Node * curr);
int sizeHelper(const Node * curr) const;
int numLeavesHelper(const Node * curr) const;
void flipHorizontalHelper(Node*& curr, unsigned width);
void flipVerticalHelper(Node*& curr, unsigned height);
void pruneHelper(double tol, Node * curr);
int pruneCounter(double tol, HSLAPixel avg, Node * curr);

#endif