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
  std::cout<<"original heap:"<<std::endl;
  levelOrder();
  int index = size-1;
  for(int i = int(floor((index-1)/2)); i>=0; i--)
  {
    std::cout<<"i = "<<i<<std::endl;
    trickleDown(i);
    levelOrder();
    std::cout<<"\n"<<std::endl;
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
  for(int i = 0; i <= size; i ++)
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
  if(int(floor(log2(i+1)))%2 == 0)
  {
    std::cout<<"min the level is: "<<int(floor(log2(i+1)))<<std::endl;
    trickleDownMin(i);
  }
  else
  {
    std::cout<<"max the level is: "<<int(floor(log2(i+1)))<<std::endl;
    trickleDownMax(i);
  }
}
//we have a problem where we arent looking at every grandchild of c....
void Heap::trickleDownMin(int i)
{
  int c = 2*i+1;
  int g = 2*c+1;
  if(c < size)
  {
    int mc = findMin(i);
    int mg = findMin(c);
    if(c+1 < size)
    {
      int mg = std::min(heap[findMin(c)], heap[findMin(c+1)]);
    }
      if(g < size)
      {
        if(heap[mg] < heap[mc])
        {
          if(heap[mg] < heap[i])
          {
            swap(mg, i);
            if(heap[mg]>heap[parent(mg)])
            {
              swap(mg, parent(mg));
            }
            trickleDownMin(mg);
          }
        }
      }
    else
    {
      std::cout<<"grandchild doesnt exist"<<std::endl;
      if(heap[mc]<heap[i])
      {
        swap(mc, i);
      }
    }
  }
}

void Heap::trickleDownMax(int i)
{
  int c = 2*i+1;
  int g = 2*c+1;
  if(c < size)
  {
    int mc = findMax(i);
    int mg = findMax(c);
    if(c+1 < size)
    {
      int mg = std::max(heap[findMax(c)], heap[findMax(c+1)]);
    }
    if(g < size)
    {
      if(heap[mg] > heap[mc])
      {
        if(heap[mg] > heap[i])
        {
          swap(mg, i);
          if(heap[mg]<heap[parent(mg)])
          {
            swap(mg, parent(mg));
          }
          trickleDownMax(mg);
        }
      }
    }
    else
    {
      std::cout<<"grandchild doesnt exist"<<std::endl;
      if(heap[mc]>heap[i])
      {
        swap(mc, i);
      }
    }
  }
}

void Heap::bubbleUp(int i)
{
  if(int(floor(log2(i)))%2 == 0) //i is on a min level
  {
    if((parent(i) >= 0) && (heap[i] > heap[parent(i)])) //i has parent and i > parent
    {
      swap(i, parent(i));
      bubbleUpMax(parent(i));
    }
    else
    {
      bubbleUpMin(i);
    }
  }
  else //i is on a max level
  {
    if((floor((i-1)/2) >= 0) && (heap[i] < heap[parent(i)]))
    {
      swap(i, parent(i));
      bubbleUpMin(parent(i));
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
  std::cout<<"swapping: "<<heap[c]<<" and "<<heap[p]<<std::endl;
  int temp = 0;
  temp = heap[p];
  heap[p] = heap[c];
  heap[c] = temp;
  std::cout<<heap[c]<<" is at index "<<c<<" and "<<heap[p]<<" is at index "<<p<<std::endl;
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
  std::cout<<"the min of "<<heap[par]<<" is "<<heap[cind + min]<<std::endl;
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
  std::cout<<"the max of "<<heap[p]<<" is "<<heap[cind + max]<<std::endl;
  return (cind + max);
}

//need to modify deletemax and min - THESE DO NOT WORK!!!
void Heap::deleteMax()
{
  int max = findMax(0);
  swap(max, (size-1));
  heap[size-1] = 0;
  size--;
  trickleDown(max);
}
//DOESNT WORK!!!
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
  return(floor(((floor((i-1)/2))-1)/2));
}

int Heap::parent(int i)
{
  return(floor(i-1)/2);
}
