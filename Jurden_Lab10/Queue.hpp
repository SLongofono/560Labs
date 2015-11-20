Queue::Queue()
{
  this.len = 0;
}
void Queue::insert(int x)
{

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
    n3 = q3->q[i];
    //there will be 8 cases
    //q1 and q3
    if(n1 != nullptr and n3 != nullptr and n2==nullptr)
    {
      if(n1->key > n3->key)
      {
        n3->first = n1;
        q3[i+1] = n3;
        n3 = nullptr; //do we need to do delete instead?
        n1 = nullptr;
      }
      else
      {
        n1->first = n3;
        q3[i+1] = n1;
        n3 = nullptr; //do we need to do delete instead?
        n1 = nullptr;
      }
    }

    //q2 and q3
    else if(n1 != nullptr and n2 != nullptr and n3 == nullptr)
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
    //q1 and q2
    else if(n1 != nullptr and n2 != nullptr)
    //q1
    else if(n1 != nullptr and n2 != nullptr)
    //q2
    else if(n1 != nullptr and n2 != nullptr)
    //q3
    else if(n1 != nullptr and n2 != nullptr)
    //all empty
    else if(n1 != nullptr and n2 != nullptr)
    {

    }
  }
}
void Queue::levelorder()
{

}
