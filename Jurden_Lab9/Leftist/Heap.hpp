Heap::Heap()
{
  root = new Node();
  left = new Heap();
  right = new Heap();
}

Heap* Heap::merge(Heap* h1, Heap* h2)
{
  cout<<"merging"<<endl;
  if(h1->root == nullptr)
  {
    return h2;
  }
  else if(h2->root == nullptr)
  {
    return h1;
  }
  else if(h1->root->getValue() > h2->root->getValue())
  {
    swap(h1, h2);
  }
  h1->right =  merge(h1->right, h2);
  setRanks(h1);
  if(h1->left->root->getRank() < h1->right->root->getRank())
  {
    swap(h1->left, h1->right);
  }
  return h1;
}

void Heap::deleteMin(Heap* h)
{
  Heap* h1 = h->left;
  Heap* h2 = h->right;
  delete h->root;
  merge(h1, h2);
}

void Heap::insert(int x, Heap* h)
{
  cout<<"inserting"<<endl;
  Heap* h1 = new Heap();
  Node* r = new Node();
  h1->root = r;
  h1->root->setValue(x);
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

int Heap::adjustRank(Heap* r)
{
  if(r->left == nullptr || r->right == nullptr)
  {
    return 1;
  }
  else
  {
    return std::min(1 + adjustRank(r->left), 1+adjustRank(r->right));
  }
}

void Heap::setRanks(Heap* h)
{
  if(h == nullptr)
  {
    return;
  }
  else
  {
    h->root->setRank(adjustRank(h));
    setRanks(h->left);
    setRanks(h->right);
  }
}

void Heap::print(Heap* subtree, Order order)
{
	if(subtree==nullptr)
	{
		return;
	}
	if(order == PRE_ORDER)
	{
		std::cout<<subtree->root->getValue()<<", ";
		print(subtree->left, order);
		print(subtree->right, order);
	}
	if(order == IN_ORDER)
	{
		print(subtree->left, order);
		std::cout<<subtree->root->getValue()<<", ";
		print(subtree->right, order );
	}
}

void Heap::print(Node* subtree, Order order, std::queue<Node*> q)
{
	if (order == LEVEL_ORDER)
	{
		if(subtree->getLeft()!= nullptr)
		{
			q.push(subtree->getLeft());
		}
		if(subtree->getRight()!= nullptr)
		{
			q.push(subtree->getRight());
		}
		Node* x = q.front();
		std::cout << x->getValue() << " ";
    q.pop();
		while(q.front() != nullptr)
		{
		print(q.front(), LEVEL_ORDER, q);
		}
	}
}
