Hash::Hash(int p){
  table = new LinkedList*[p];
}


//insert changed for application with linked lists using linked array
void Hash::insert(int x){
//   std::cout<<"inserting"<<std::endl;
  if(contains(x)==false){
  //  std::cout<<"num: "<<num<<std::endl;
    load = num/prime;
  //  std::cout<<"load: "<<load<<std::endl;
    if(load > 1){
      rehash();
      int i = hash(x);
      table[i]->add(x);
      num++;
  //    std::cout<<x<<" goes in index "<<i<<std::endl;
    }
    else{
  //   std::cout<<"inserting"<<std::endl;
     int i = hash(x);
  //   std::cout<<"inserting"<<std::endl;
     table[i]->add(x);
     num++;
  //   std::cout<<x<<" goes in index "<<i<<std::endl;
    }
  }
  else{
    // std::cout<<"get out!"<<std::endl;
    return;
  }
}

//complete hash function with linked lists...seems a bit too easy
int Hash::hash(int x){
  //std::cout<<"hashing"<<x<<std::endl;
  int i = x % prime;
  return(i);
}

//print function optimized for linked lists
void Hash::print(){
  for(int i = 0; i<prime; i++){
    std::cout<<i<<":    ";
    table[i]->display();
    std::cout<<"\n";
    }
  }


//new remove function for array of linked list
void Hash::remove(int x){
  if(contains(x) == true){
    for(int i = 0; i<prime; i++){
      //we go through table and find the linked list containing x
      if(table[i]->find(x) != nullptr){
        table[i]->erase(x);
      }
    }
  }
}


int Hash::findprime(int x){
  int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
  int num = 2 * x;
  for(int i = 0; i<12; i++){
    if(num < primes[i]){
      return primes[i];
    }
  }
}


//new contains function for linked lists
bool Hash::contains(int x){
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

//rehash optimized for array of linked lists
int Hash::rehash(){
  //std::cout<<"rehashing"<<std::endl;
  num = 0;
  //save old prime and old table in other variables
  int old = prime;
  prime = findprime(old);
  LinkedList** temp = table;
  table = new LinkedList*[prime];
  //make temp with blank cntainers
  for(int i = 0; i< prime; i++){
    table[i] = new LinkedList();
  }
  //rehash temp back into table
  for(int i = 0; i<old; i++){
      if(temp[i]->m_front != nullptr){
        Container* pre = temp[i]->m_front;
        insert(pre->getValue());
        //go through every item in linked list and reinsert it in newly created table
        while(pre->getNext() != nullptr){
          pre = pre->getNext();
          insert(pre->getValue());
        }
      }
    }
}
