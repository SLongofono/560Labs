
Heap::Heap()
{
  this->size = 0;
}

void Heap::heapify()
{
  for(int i = (size-1); i >= 0; i--)
  {
    int par = floor((i-1)/5);
    if(heap[i] < heap[par])
    {
      int temp = 0;
      temp = heap[i];
      heap[i] = heap[par];
      heap[par] = temp;
    }
  }
}


void Heap::levelOrder()
{
  for(int i = 0; i < size; i++)
  {
    std::cout<<heap[i]<<" ";
  }
}
