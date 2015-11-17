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
  Node* temp = h1->right;
  h1->right = h1->left;
  h1->left = merge(temp, h2);
  return h1;
}

void Heap::deleteMin(Heap* h)
{
  Node* h1 = h->root->left;
  Node* h2 = h->root->right;
  delete h->root;
  merge(h1, h2);
}

void Heap::insert(int x, Node*& h)
{
  cout<<"inserting "<<x<<endl;
  Node* r = new Node();
  r->value = x;
  h = merge(h,r);
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
		if(subtree->left!= nullptr)
		{
			q.push(subtree->left);
		}
		if(subtree->right!= nullptr)
		{
			q.push(subtree->right);
		}
		Node* x = q.front();
		std::cout << x->value << " ";
    q.pop();
		while(q.front() != nullptr)
		{
		print(q.front(), LEVEL_ORDER, q);
		}
	}
}
