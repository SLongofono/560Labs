
Hash::Hash(int p){
  table = new Container*[p];
}

void Hash::insert(int x){
  int i = hash(x);
  table[i]->value = x;
  num++;
  std::cout<<x<<" goes in index "<<i<<std::endl;
}

int Hash::hash(int x){
  std::cout<<"hashing"<<std::endl;
  int i = 0;
  int ind = (x % prime) + i;
  while(table[ind]->value != -1){
    i++;
    ind = (x % prime) + i;
  }
  return(ind);
}

/*
int Hash::remove(x){

}
*/

