Graph::Graph(int size){
  this->size = size;
  edges = new int* [size];
  for(int i = 0; i < size; i++ ){
    edges[i] = new int[size];
  }
}
