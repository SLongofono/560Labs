//when adding a new number to the heap:
//check if on the right level (min/max level)
//check against the grandparents after swap

//we can reuse most of the methods, but change trickledown and bubbleup
//to determine the level, we take



Heap::Heap()
{
  this->size = 0;
}

void Heap::heapify()
{
  int i = floor((size-2)/2);
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


void Heap::levelOrder()
{
  int enter = 0;
  int line = enter*2;
  for(int i = 0; i < size; i ++)
  {
    if(heap[i] != 0)
    {
      if(i == line)
      {
        std::cout<<heap[i]<<" "<<std::endl;
        enter++;
        line = line + enter*2;
      }
      else if((i >= 4) && (i!=line) && (i%2 == 0))
      {
        std::cout<<heap[i]<<" - ";
      }
      else{
        std::cout<<heap[i]<<" ";
      }
    }
  }
}
//new trickledown
void Heap::trickleDown(int i)
{
  if(floor(lg(i))%2 == 0)
  {
    trickleDownMin(i);
  }
  else
  {
    trickleDownMax(i);
  }
}

void Heap::trickleDownMin(int i)
{
  int c = heap[2i+1];
  int g = heap[2(2i+1)+1];
  if(c != 0)
  {
    int mc = findMin(i);
    int mg = findMin(c);
    if(heap[mg] < heap[mc])
    {
      if(heap[mg] < heap[i])
      {
        swap(mg, i);
        if(heap[mg]>heap[floor((mg-1)/2)])
        {
          swap(mg, floor((mg-1)/2));
        }
        trickleDownMin(mg);
      }
    }
    else
    {
      if(heap[mc]<heap[i)
      {
        swap(mc, i);
      }
    }
  }
}

void Heap::trickleDownMax(int i)
{
  int c = heap[2i+1];
  int g = heap[2(2i+1)+1];
  if(c != 0)
  {
    int mc = findMax(i);
    int mg = findMax(c);
    if(heap[mg] > heap[mc])
    {
      if(heap[mg] > heap[i])//max value is a grandchild of i
      {
        swap(mg, i);
        if(heap[mg]<heap[floor((mg-1)/2)])//check with the parent
        {
          swap(mg, floor((mg-1)/2));
        }
        trickleDownMax(mg);//call recursively
      }
    }
    else //max value is a child of i
    {
      if(heap[mc]>heap[i)
      {
        swap(mc, i);
      }
    }
  }
}


void Heap::bubbleUp(int i)
{
  if(floor(lg(i))%2 == 0) //i is on a min level
  {
    if((floor((i-1)/2) >= 0) && (heap[i] > heap[floor((i-1)/2)])) //i has parent and i > parent
    {
      swap(i, floor((i-1)/2));
      bubbleUpMax(floor((i-1)/2));
    }
    else
    {
      bubbleUpMin(i);
    }
  }
  else //i is on a max level
  {
    if((floor((i-1)/2) >= 0) && (heap[i] < heap[floor((i-1)/2)]))
    {
      swap(i, floor((i-1)/2));
      bubbleUpMin(floor((i-1)/2));
    }
    else
    {
      bubbleUpMax(i);
    }
  }
}

void Heap::bubbleUpMin(int i)
{
  int g = grandparent(i);
  if(g >= 0)
  {
    if(heap[i] < heap[g])
    {
      swap(i, g);
      bubbleUpMin(g);
    }
  }
}

void Heap::bubbleUpMax(int i)
{
  int g = grandparent(i);
  if(g >= 0)
  {
    if(heap[i] > heap[g])
    {
      swap(i, g);
      bubbleUpMax(g);
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
  int cind = 2*par;
  for(int i = 1; i <=2; i++)
  {
    if((heap[cind+i]<heap[cind+min]) && (heap[cind+ i]!=0))
    {
      min = i;
    }
  }
  return (cind + min);
}

//returns the index of the node with the largest value.
int Heap::findMax(int p)
{
  int max = 1;
  int cind = 2*p;
  for(int i = 1; i <=2; i++)
  {
    if((heap[cind+i]>heap[cind+max]) && (heap[cind+ i]!=0))
    {
      max = i;
    }
  }
  return (cind + max);
}

void Heap::deleteMax()
{
  int max = findMax();
  swap(max, (size-1));
  heap[size-1] = 0;
  size--;
}

void Heap::deleteMin()
{
  swap(0, size-1);
  heap[size-1] = 0;
  size--;
  trickleDown(0);
}

int Heap::find(int x)
{
  for(int i = 0; i < size; i++)
  {
    if(heap[i] == x)
    {
      return i;
    }
  }
  return -1;
}

int Heap::grandparent(int i)
{
  return(floor(((floor((i-1)/5))-1)/5))
}
