
Heap::Heap()
{
  this->size = 0;
}

void Heap::heapify()
{
  int i = floor((size-2)/5);
  std::cout<<"i = "<<i<<std::endl;
  while(i>=0)
  {
    std::cout<<"i = "<<i<<std::endl;
    trickleDown(i);
    i--;
  }
}

void Heap::insert(int x)
{
  heap[size] = x;
  size++;
  bubbleUp(size-1);
}

//figure out how to break lines....this isnt right

void Heap::levelOrder()
{
  for(int i = 0; i < size; i ++)
  {
    if(i%5 == 0)
    {
      std::cout<<heap[i];
      
    }
  }
}

void Heap::trickleDown(int p)
{
  int c = (5*p)+1;
  if(heap[c] == NULL)
  {
    return;
  }
  else
  {
    int min = findMin(p);
    if(heap[min]<heap[p])
    {
      std::cout<<"swapping"<<heap[p]<<" and "<<heap[min]<<std::endl;
      swap(p, min);
      trickleDown(min);
    }
  }
}

void Heap::bubbleUp(int i)
{
  int p = floor((i-1)/5);
  if(heap[p]<heap[i])
  {
    return;
  }
  else
  {
    if(heap[i]<heap[p])
    {
      swap(i, p);
      bubbleUp(p);
    }
  }
}

void Heap::swap(int p, int c)
{
  int temp = 0;
  temp = heap[p];
  heap[p] = heap[c];
  heap[c] = temp;
}

//returns the index of the child with the smallest value given a parent index
int Heap::findMin(int par)
{
  int min = 1;
  int cind = 5*par;
  for(int i = 1; i <=5; i++)
  {
    if(heap[cind+i]<heap[cind+min])
    {
      min = i;
    }
  }
  return (cind + min);
}
//returns the index of the child with the largest value given a parent index
int Heap::findMax(int par)
{

}
