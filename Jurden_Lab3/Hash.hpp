
Hash::Hash(int p){
  table = new Container*[p];
}

void Hash::insert(int x){
  if(contains(x)==false){
    std::cout<<"num: "<<num<<std::endl;
    load = num/prime;
    std::cout<<"load: "<<load<<std::endl;
    if(load > .5){
      rehash(x);
      int i = hash(x);
      table[i]->value = x; 
      std::cout<<x<<" goes in index "<<i<<std::endl;
    }
    else{
     std::cout<<"inserting"<<std::endl;
     int i = hash(x);
     table[i]->value = x;
     num++; 
     std::cout<<x<<" goes in index "<<i<<std::endl;
    }
  }
  else{
    return;
  }
}

int Hash::hash(int x){
  std::cout<<"hashing"<<std::endl;
  int i = 0;
  int ind = (x % prime) + i;
  while(table[ind]->value != -1){
    i++;
    ind = ((x+i) % prime);
  }
  return(ind);
}

void Hash::print(){
  for(int i = 0; i<prime; i++){
    std::cout<<"i: "<<table[i]->value<<" flag = "<<table[i]->flag<<std::endl;
  }
}

void Hash::remove(int x){
  int i = 0;
  int ind = 0;
  while(table[ind]->value != x){
    ind = (x % prime) + i;
    i++;
  }
  table[ind]->value = -1;
  table[ind]->flag = true;
  num--;
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

bool Hash::contains(int x){
  std::cout<<"checking"<<std::endl;
  for(int i = 0; i<prime; i++){
    if(Hash::table[i]->value == x){
      return true;
    }
    else{
      return false;
    }
  }
}

int Hash::rehash(int x){
  std::cout<<"rehashing"<<std::endl;
  num = 0;
  int old = prime;
  prime = findprime(old);
  Container** temp = new Container*[prime];
  //make temp with blank cntainers
  for(int i = 0; i< prime; i++){
    temp[i] = new Container(false, -1);
  } 
  //rehash table into temp
  for(int i = 0; i<old; i++){
    if(table[i]->value != 1){
      int j = 0;
      int ind = ((x+ j) % old) ;
      while(temp[ind]->value != -1){
        j++;
        ind = ((x+j) % old);
      }
      temp[ind] = table[i];
      num++;
    }
  }
  table = temp; 
}
/*
int Hash::remove(x){

}
*/

