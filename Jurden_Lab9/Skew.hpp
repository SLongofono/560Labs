Skew::Skew()
{
  root = nullptr;
}

SNode* Skew::merge(SNode* h1, SNode* h2)
{
  //cout<<"merging "<<endl;
  if(h1 == nullptr)
  {
    //cout<<"h1 is null returning "<<h2->value<<endl;
    return h2;
  }
  else if(h2 == nullptr)
  {
    //cout<<"h2 is null returning "<<h1->value<<endl;
    return h1;
  }
  else if(h1->value > h2->value)
  {
    std::swap(h1, h2);
  }
  SNode* temp = h1->right;
  h1->right = h1->left;
  h1->left = merge(temp, h2);
  return h1;
}

void Skew::deleteMin(Skew* h)
{
  SNode* h1 = h->root->left;
  SNode* h2 = h->root->right;
  delete h->root;
  merge(h1, h2);
}

void Skew::insert(int x, SNode*& h)
{
  //cout<<"inserting "<<x<<endl;
  SNode* r = new SNode();
  r->value = x;
  h = merge(h,r);
}


void Skew::print(SNode* subtree, Order order)
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

void Skew::print(SNode* subtree, Order order, std::queue<SNode*> q)
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
		SNode* x = q.front();
		std::cout << x->value << " ";
    q.pop();
		while(q.front() != nullptr)
		{
		print(q.front(), LEVEL_ORDER, q);
		}
	}
}
