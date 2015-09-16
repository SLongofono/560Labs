#include <iostream>
#include <fstream>
#include <queue>
#include <array>
#include "BinaryTree.h"
#include "Node.h"

int main()
{
  BinaryTree* orig = new BinaryTree();
  orig->build();
  orig->count();
  orig->printTree();
  orig->largest();

return(0);
}
