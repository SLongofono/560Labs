Hash::Hash(int p){
  table = new LinkedList*[p];
  this->prime = p;
}


//insert changed for application with linked lists using linked array
void Hash::insert(long int x){
  if(contains(x)==false){
     int i = hash(x);
     table[i]->add(x);
  }
  else{
    return;
  }
}

//complete hash function with linked lists...seems a bit too easy
int Hash::hash(long int x){
  //std::cout<<"hashing"<<x<<std::endl;
  int i = x % prime;
  return(i);
}


//new contains function for linked lists
bool Hash::contains(long int x){
  int ind = x % prime;
  if(table[ind]->isEmpty() == true){
    return false;
  }
  else if(table[ind]->find(x) != nullptr){
    return true;
  }
  else{
    return false;
  }
}

