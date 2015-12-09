Tree::Tree(){
  //graphs = new Graph*[this->numG];
}

//use union find and skew tree
Graph* Tree::Kruskal(Graph* g){
  Skew* C = new Skew();
  Set* Cyc = new Set(g->size);
  int final[g->size][g->size];
  int n = g->size * g->size;
  int count = 0;
  for(int i = 0; i < g->size; i++)
  {
    for(int j = 0; j < g->size; j++)
    {
      final[i][j] = 0;
      if(g->edges[i][j] != 0)
      {
        int cost = g->edges[i][j];
        g->edges[j][i] = 0;
        Node* n = new Node();
        n->edge[0] = i;
        n->edge[1] = j;
        n->value = cost;
        C->insert(n, C->root);
      }
    }
  }
  while(C->root != nullptr && count <n-1)
  {
    Node* x = C->root;
    C->deleteMin(C->root);
    int v = x->edge[0];
    int w = x->edge[1];
    int fv = Cyc->find(x->edge[0]);
    int fw = Cyc->find(x->edge[1]);
    if(fv != fw)
    {
      final[v][w] == 1;
      final[w][v] == 1;
      Cyc->Sunion(v, w);
    }
  }
//to get upper triangular, use for loops with j = i+1, j<size
  if(count == n-1)
  {
    Graph* f = new Graph(g->size);
    for(int i = 0; i < f->size; i++)
    {
      for(int j = 0; j < f->size; j++)
      {
        f->edges[i][j] = final[i][j];
      }
    }
    printGraph(f);
    printGraph(g);
  }
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
