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
 merge()
}

void Queue::deletemin()
{

}
Queue* Queue::merge(Queue* queue1, Queue* queue2)
{
  Node* q1[] = queue1->q;
  Node* q2[] = queue2->q;

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
      n1->first = n3;
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
      n1->first = n2;
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
      n2->first = n3;
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
  return queue3;
}
void Queue::levelorder()
{

}

void Queue::swap(Node* &node1, Node* &node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;
}
