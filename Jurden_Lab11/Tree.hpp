Tree::Tree(){
  //graphs = new Graph*[this->numG];
}

//use union find and skew tree
Graph* Tree::Kruskal(Graph* g){
  Skew* C = new Skew();
  Set* Cyc = new Set(g->size);


}


Graph* Tree::Prims(Graph* g){

}

void Tree::printGraph(Graph* g){
  int size = g->size;
  for(int i = 0; i < size; i ++)
  {
    for(int j = 0; j < size; j++)
    {
      std::cout<<g->edges[i][j]<<" ";
    }
    std::cout<<"\n";
  }
}
/*
Graph* buildGraph(int size, ifstream infile){
  Graph* g = new Graph(size);
  for(int i = 0; i < size; i ++)
  {
    for(int j = 0; j < size; j++)
    {
      infile >> g->edges[i][j];
    }
  }
  return g;
}
*/
int Tree::countEdge(Graph* g){
  int size = g->size;
  int count = 0;
  for(int i = 0; i < size; i++){
    for(int j =0; j<size; j++){
      if(g->edges[i][j] != 0)
      {
        count++;
      }
    }
  }
  return count;
}

int Tree::calcCost(Graph* g)
{

}
