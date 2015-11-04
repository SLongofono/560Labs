Heap::Heap()
{
  root = nullptr;
}

Heap* Heap::merge(Heap* h1, Heap* h2)
{
  if(h1 == nullptr)
  {
    return h2;
  }
  else if(h2 == nullptr)
  {
    return h1;
  }
  else if(h1->root->getValue() > h2->root->getValue())
  {
    swap(h1, h2);
  }
  h1->getRight() =  merge(h1->getRight(), h2);
  adjustRank(h1->root);
  if(h1->getLeft()->getRank() < h1->getRight()->getRank())
  {
    swap(h1->getLeft(), h1->getRight());
  }
  return h1;
}

void Heap::deleteMin(Heap* h)
{
  Heap* h1, h2;
  h1->root = h->lchild;
  h2->root = h->rchild;
  delete h->root;
  merge(h1, h2);
}

void Heap::insert(Node* x, Heap* h)
{
  Heap* h1 = new Heap();
  h1->root = x;
  merge(h1, h);
}

void Heap::swap(Heap* h1, Heap* h2)
{
  Heap* temp = nullptr;
  h1 = temp;
  h1 = h2;
  h2 = temp;
  delete temp;
}

int Heap::adjustRank(Node* root)
{
  if(root->getLeft() == nullptr || root->getRight() == nullptr)
  {
    return 1;
  }
  else
  {
    return min(1 + adjustRank(root->getLeft()), 1+adjustRank(root->getRight()));
  }
}
