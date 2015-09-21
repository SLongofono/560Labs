
Hash::Hash(int p){
  table = new Container*[p];
}

void Hash::insert(int x){
  if(contains(x)==false){
    std::cout<<"inserting"<<std::endl;
    int i = hash(x);
    table[i]->value = x;
    num++;
    load = num/prime;
    if(load > .5){
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
          int ind = (x % old) + j;
          while(temp[ind]->value != -1){
            i++;
            ind = (x % old) + i;
          }
          temp[ind] = table[i];
          num++;
        }
      }
      table = temp; 
    }
    std::cout<<load<<" goes in index "<<i<<std::endl;
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
    ind = (x % prime) + i;
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
      return num;
    }
    else{

    }
  }
}

bool Hash::contains(int x){
  for(int i = 0; i<prime; i++){
    if(Hash::table[i]->value == x){
      return true;
    }
    else{
      return false;
    }
  }
}
/*
int Hash::remove(x){

}
*/

