
Hash::Hash(int p){
  table = new LinkedList*[p];
}


//insert changed for application with linked lists
void Hash::insert(int x){
  if(contains(x)==false){
    std::cout<<"num: "<<num<<std::endl;
    load = num/prime;
    std::cout<<"load: "<<load<<std::endl;
    if(load > 1){
      rehash();
      int i = hash(x);
      Container* temp = table[i];
      while(temp->next != nullptr){
        temp = temp->next;
      }
      temp->next = new Container(nullptr, x);
      num++;
      std::cout<<x<<" goes in index "<<i<<std::endl;
    }
    else{
     std::cout<<"inserting"<<std::endl;
     int i = hash(x);
     std::cout<<"inserting"<<std::endl;
     Container* temp = table[i];
     std::cout<<"assigned temp"<<std::endl;
     while(temp->next != nullptr){
       std::cout<<"going to end of list"<<std::endl;
       temp = temp->next;
     }
     temp->next = new Container(nullptr, x);
     std::cout<<"assigned temp next"<<std::endl;
     num++;
     std::cout<<x<<" goes in index "<<i<<std::endl;
    }
  }
  else{
    return;
  }
}

//complete hash function with linked lists...seems a bit too easy
int Hash::hash(int x){
  std::cout<<"hashing"<<x<<std::endl;
  int i = x % prime;
  return(i);
}

//print function completed to include linked list
void Hash::print(){
  Container* temp;
  for(int i = 0; i<prime; i++){
    std::cout<<i<<":    ";
    temp = table[i];
    while(temp->next!= nullptr){
      std::cout<<temp->value<<" ";
      temp = temp->next;
    }
  }
}


//new remove function
void Hash::remove(int x){
  Container* temp;
  Container* tempn;
  if(contains(x) == true){
    for(int i = 0; i<prime; i++){
      std::cout<<i<<":    ";
      temp = table[i];
      tempn = table[i]->next;
      //if first value in linked list == x
      if(temp->value == x){
          while(temp->next!=nullptr){
            temp = temp->next;
          }
          return;
      }
      //else, look through the list
      while(tempn->next!= nullptr){
        if(tempn->value != x){
        temp = temp->next;
        tempn = tempn->next;
        }
        //when you find the value...
        else if(tempn->value == x){
          //if value is at the end of the list, delete the value
          if(tempn->next == nullptr){
            delete tempn;
            num--;
            return;
          }
          //otherwise, reassign pointers
          else{
            temp->next = tempn->next;
            delete tempn;
            num--;
          }
        }
      }
    }
  }
  else{
    return;
  }
}

int Hash::findprime(int x){
  int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};
  int num = 2 * x;
  for(int i = 0; i<12; i++){
    if(num < primes[i]){
      return primes[i];
    }
    else{
    }
  }
}

//optimized for linked list
// use hash function to find exact cell number is in and then go down chain
bool Hash::contains(int x){
  std::cout<<"checking"<<std::endl;
  int i = x % prime;
  Container* temp = table[i];
  while(temp != nullptr){
    if(temp->value == x){
      return true;
    }
    else{
      temp = temp->next;
    }
  }
  if(temp == nullptr){
        std::cout<<"value not in table\n";
        return false;
  }
}

//changed for linked lists...i think
int Hash::rehash(){
  std::cout<<"rehashing"<<std::endl;
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
    //check to see if value worth copying
      if(temp[i]->size() > 0){
        Container* pre = temp[i]->m_front;
        //go through every item in linked list and reinsert it in newly created table
        while(pre->next != nullptr){
          insert(pre->value);
          pre = pre->next;
        }
      }
    }
}
/*
int Hash::remove(x){

}
*/
