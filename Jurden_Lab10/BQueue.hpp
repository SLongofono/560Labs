#include "BQueue.h"

BQueue::BQueue()
{

  for(int i =0; i<10; i++)
  {
    q[i] = nullptr;
  }
}
void BQueue::insert(int x)
{
 BQueue* q2 = new BQueue();
 Node* qu2 = new Node(0, x, nullptr, nullptr, nullptr);
 q2->q[0] = qu2;
 merge(this->q, q2)
}
/*
void BQueue::deletemin()
{
  Node* min = findMin(q[0]);
  for(int i = 1; i < 10; i ++)
  {
    Node* temp = findMin(q[i]);
    if(min->key < temp->key)
    {
      min = temp;
    }
    delete temp;
  }
  //now that min is found, we must delete it.
  Node* t1 = min->first;
  if(t1 == nullptr)
  {
    if()
  }
  else if(t1->right == nullptr)//has first node
  {

  }
  else{ //min first has siblings

  }
}

Node* BQueue::findMin(Node* root)
{

}
*/
Node** BQueue::merge(Node** q1, Node** q2)
{
  BQueue* queue3 = new BQueue();
  Node* q3[] = queue3->q;
  for(int i = 0; i <10; i++)
  {
    n1 = q1[i];
    n2 = q2[i];
    n3 = q3[i];
    //there will be 8 cases
    //q1 && q3
    if(n1 != nullptr && n3 != nullptr && n2==nullptr)
    {
      if(n1->key > n3->key)
      {
        swap(n1, n3)
      }
      combineTree(n1, n3);
      q3[i+1] = n1;
      n3 = nullptr; //do we need to do delete instead?
      n1 = nullptr;
    }

    //q2 && q3
    else if(n1 != nullptr && n2 != nullptr && n3 == nullptr)
    {
      if(n1->key > n2->key)
      {
        swap(n1, n2);
      }
      combineTree(n1, n2);
      q3[i+1] = n1;
      n2 = nullptr; //do we need to do delete instead?
      n1 = nullptr;
    }
    //q1 && q2
    else if(n2 != nullptr && n3 != nullptr && n1 == nullptr)
    {
      if(n2->key > n3->key)
      {
        swap(n3, n2);
      }
      combineTree(n2, n3);
      q3[i+1] = n2;
      n2 = nullptr; //do we need to do delete instead?
      n3 = nullptr;
    }
    //q1
    else if(n1 != nullptr && n2 == nullptr && n3 == nullptr)
    {
      q3[i] = n1;
      n1 = nullptr;
    }
    //q2
    else if(n1 == nullptr && n2 != nullptr && n3 == nullptr)
    {
      q3[i] = n2;
      n2 = nullptr;
    }
    //q3
    else if(n1 == nullptr && n2 == nullptr n3 != nullptr)
    {
      //do nothing
    }
    //all empty
    else if(n1 == nullptr && n2 == nullptr && n3 == nullptr)
    {
      //do nothing
    }

  }
  return q3;
}
void BQueue::levelorderBQueue()
{
  for(int i = 0; i<10; i++)
  {
    if(q[i] != nullptr)
    {
      std::queue pq;
      pq.push(q[i]);
      levelorder(q[i], pq, q[i]->order);
      cout<<"-------\n"<<endl;
    }
  }
}

void BQueue::levelorder(Node* node, std::queue<Node*> pq, int o)
{
  int nexto = 0;
  int order = o;
  while(!pq.empty())
  {
    for(int i = 0; i < order; i++)
    {
      Node* temp = pq.front();
      if(temp->first ==nullptr)
      {
        cout<<node->key<<" ";
        pq.pop();
      }
      else{
        pq.push(temp->first);
        nexto = nexto + temp->first->order;
        while(temp->right != nullptr)
        {
          nexto = nexto+ temp->right->order;
          pq.push(temp->right);
          temp = temp->right;
        }
        cout<<node->key<<" ";
        pq.pop();
      }
    }
    order = nexto;
    nexto = 0;
    cout << "\n";
  }

}
void BQueue::combineTree(Node* &r1, Node* &r2)
{
  r1->order++;
  if(r1->first == nullptr)
  {
    r1->first = r2;
  }
  if(r1->first->right == nullptr)
  {
    r1->first->right = r2;
    r2->left = r1->first;
    r1->order++;
  }
  else{
    Node* tempR = r1->first;
    while(tempR->right != nullptr){
      tempR = tempR->right;
    }
    tempR->right = r2;
  }
}

void BQueue::swap(Node* &node1, Node* &node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;
}
