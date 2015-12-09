Node::Node(){
  this->left = nullptr;
  this->right = nullptr;
  for(int i = 0; i < 2; i++)
  {
    this->edge[i] = -1;
  }
  this->value = 0;
}
