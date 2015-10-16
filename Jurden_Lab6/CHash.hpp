
CHash::CHash(int p){
  table = new CContainer*[p];
  this->prime = p;
}

void CHash::Cinsert(int long x){
  if(contains(x)==false){
     int i = chash(x);
     table[i] = new CContainer(false, x);
  }
  else{
    return;
  }
}

int CHash::chash(int long x){
    int i = 0;
    int ind = (x % prime) + i;
    while(table[ind]->getValue() != -1){
      i++;
      ind = ((x+i) % prime);
    }
    return(ind);
}

bool CHash::contains(int long x){
  int i = 0;
  int ind = (x % prime) + i;
  while(table[ind]->getValue() != -1){
    if(table[ind]->getValue() == x)
    {
      return true;
    }
    else
    {
      i++;
      ind = ((x+i) % prime);
    }
  }
  return false;
}
