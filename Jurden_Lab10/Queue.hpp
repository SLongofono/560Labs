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
  Node* q3[] = queue3->queue;
  int size = std::max(queue1->len, queue2->len);
  for(int i = 0; i <size; i++)
  {
    qu1 = q1[i];
    qu2 = q2[i];
    qu3 = q3->queue[i];
    //there will be 8 cases
    //q1 and q3
    if(qu1 != nullptr and qu3 != nullptr)
    {
      
    }

    //q2 and q3
    else if(qu1 != nullptr and qu2 != nullptr)
    //q1 and q2
    else if(qu1 != nullptr and qu2 != nullptr)
    //q1
    else if(qu1 != nullptr and qu2 != nullptr)
    //q2
    else if(qu1 != nullptr and qu2 != nullptr)
    //q3
    else if(qu1 != nullptr and qu2 != nullptr)
    //all empty
    else if(qu1 != nullptr and qu2 != nullptr)
    {

    }
  }
}
void Queue::levelorder()
{

}
