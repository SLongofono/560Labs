Tree::Tree(){
 graphs = new Graph[numG];
}
Tree::Tree(int num){
  graphs = new Graph[num];
}
/*
Graph* Tree::Kruskal(Graph* g){
  int size = g->size;
  int marked[size][size];
  int cycle[size];
  int** cedge = g->edges;
  int count = 0;
  int edge = countEdge(g);
  while((count < ((size*size)-1)) && (edge > 0))
  {
    int min;
    int k = -1;
    int l = -1;
    for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
      {
        if(cedge[i][j] != 0 && marked[i][j] != 1)
        {
          if(min == 0 || (min > cedge[i][j]))
          {
            min = cedge[i][j];
            k = i;
            l = j;
          }
        }
      }
    }
    cedge[k][l] = 0;
    marked[k][l] = 1;
    marked[l][k] = 1;
    edge--;
    count++;
  }
  if(count==(size*size)-1))
  {

  }
}
*/
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

Graph* buildGraph(int size, ifstream& infile){
  Graph* g = new Graph();
  g->size = size;
  for(int i = 0; i < size; i ++)
  {
    for(int j = 0; j < size; j++)
    {
      infile >> g->edges[i][j];
    }
  }
  return g;
}

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
