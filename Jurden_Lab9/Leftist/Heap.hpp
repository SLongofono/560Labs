Heap::Heap()
{
  root = nullptr;
}

Node* Heap::merge(Node* h1, Node* h2)
{
  cout<<"merging "<<endl;
  if(h1 == nullptr)
  {
    cout<<"h1 is null returning "<<h2->value<<endl;
    return h2;
  }
  else if(h2 == nullptr)
  {
    cout<<"h2 is null returning "<<h1->value<<endl;
    return h1;
  }
  else if(h1->value > h2->value)
  {
    std::swap(h1, h2);
  }
  h1->right =  merge(h1->right, h2);
  setRanks(h1);
  if(h1->left == nullptr)
  {
      std::swap(h1->left, h1->right);
  }
  else if(h1->left->getRank() < h1->right->getRank())
  {
    std::swap(h1->left, h1->right);
  }
  cout<<"returning "<<h1->value<<endl;
  return h1;
}

void Heap::deleteMin(Node* h)
{
  Node* h1 = h->left;
  Node* h2 = h->right;
  Node* temp = root;
  root = merge(h1, h2);
  delete temp;
}

void Heap::insert(int x, Node*& h)
{
  cout<<"inserting "<<x<<endl;
  Node* r = new Node();
  r->value = x;
  h = merge(h,r);
}

int Heap::adjustRank(Node* r)
{
  if(r->left == nullptr || r->right == nullptr)
  {
    return 1;
  }
  else
  {
    return std::min(1 + r->left->getRank(), 1+r->right->getRank());
  }
}

void Heap::setRanks(Node* h)
{
  if(h == nullptr)
  {
    return;
  }
  else
  {
    h->setRank(adjustRank(h));
    setRanks(h->left);
    setRanks(h->right);
  }
}

void Heap::print(Node* subtree, Order order)
{
	if(subtree==nullptr)
	{
		return;
	}
	if(order == PRE_ORDER)
	{
		std::cout<<subtree->value<<", ";
		print(subtree->left, order);
		print(subtree->right, order);
	}
	if(order == IN_ORDER)
	{
		print(subtree->left, order);
		std::cout<<subtree->value<<", ";
		print(subtree->right, order );
	}
}

void Heap::print(Node* subtree, Order order, std::queue<Node*> q)
{
	if (order == LEVEL_ORDER)
	{
    q.push(subtree);
		while(q.front() != nullptr)
		{
      int lcount = q.size();
      while(lcount > 0)
      {
        Node* x = q.front();
        std::cout << x->value << " ";
        q.pop();
        if(x->left!= nullptr)
    		{
    			q.push(x->left);
    		}
    		if(x->right!= nullptr)
    		{
    			q.push(x->right);
    		}
        lcount--;
      }
      cout << '\n';
		}
	}
}
