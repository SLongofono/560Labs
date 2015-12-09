Set::Set(int size){
  for(int i = 0; i<size; i++)
  {
    this->arr[i] = -1;
  }
}
void Set::union(int x, int y)
{
  r1 = find(x);
  r2 = find(y);
  if(r1 != r2)
  {
    arr[r1] = r2;
  }
}

int Set::find(int v)
{
  if(array[v] == -1)
  {
    return v;
  }
  while(arr[v] != -1)
  {
    v = arr[v];
    return v;
  }
}
