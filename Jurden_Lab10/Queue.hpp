Queue::Queue()
{
  this.len = 0;
  for(int i =0; i<10; i++)
  {
    q[i] = nullptr;
  }
}
void Queue::insert(int x)
{
 Queue* q2 = new Queue();
 Node* qu2 = new Node(0, x, nullptr, nullptr, nullptr);
 q2->q[0] = qu2;
 merge(this.q, q2)
}

void Queue::deletemin()
{

}
Node** Queue::merge(Node** q1, Node** q2)
{
  Queue* queue3 = new Queue();
  queue3-> len = 0;
  Node* q3[] = queue3->q;
  int size = std::max(queue1->len, queue2->len);
  for(int i = 0; i <size; i++)
  {
    n1 = q1[i];
    n2 = q2[i];
    n3 = q3[i];
    //there will be 8 cases
    //q1 && q3
    if(n1 != nullptr && n3 != nullptr && n2==nullptr)
    {
      if(n1->key > n3->key)
      {
        swap(n1, n3)
      }
      combineTree(n1, n3);
      q3[i+1] = n1;
      n3 = nullptr; //do we need to do delete instead?
      n1 = nullptr;
    }

    //q2 && q3
    else if(n1 != nullptr && n2 != nullptr && n3 == nullptr)
    {
      if(n1->key > n2->key)
      {
        swap(n1, n2);
      }
      combineTree(n1, n2);
      q3[i+1] = n1;
      n2 = nullptr; //do we need to do delete instead?
      n1 = nullptr;
    }
    //q1 && q2
    else if(n2 != nullptr && n3 != nullptr && n1 == nullptr)
    {
      if(n2->key > n3->key)
      {
        swap(n3, n2);
      }
      combineTree(n2, n3);
      q3[i+1] = n2;
      n2 = nullptr; //do we need to do delete instead?
      n3 = nullptr;
    }
    //q1
    else if(n1 != nullptr && n2 == nullptr && n3 == nullptr)
    {
      q3[i] = n1;
      n1 = nullptr;
    }
    //q2
    else if(n1 == nullptr && n2 != nullptr && n3 == nullptr)
    {
      q3[i] = n2;
      n2 = nullptr;
    }
    //q3
    else if(n1 == nullptr && n2 == nullptr n3 != nullptr)
    {
      //do nothing
    }
    //all empty
    else if(n1 == nullptr && n2 == nullptr && n3 == nullptr)
    {
      //do nothing
    }

  }
  return q3;
}
void Queue::levelorderQueue()
{
  
}

void Queue::levelorder(Node* node)
{

}
void Queue::combineTree(Node* &r1, Node* &r2)
{
  r1->order++;
  if(r1->first == nullptr)
  {
    r1->first = r2;
  }
  if(r1->first->right == nullptr)
  {
    r1->first->right = r2;
    r2->left = r1->first;
    r1->order++;
  }
  else{
    Node* tempR = r1->first;
    while(tempR->right != nullptr){
      tempR = tempR->right;
    }
    tempR->right = r2;
  }
}

void Queue::swap(Node* &node1, Node* &node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;
}
