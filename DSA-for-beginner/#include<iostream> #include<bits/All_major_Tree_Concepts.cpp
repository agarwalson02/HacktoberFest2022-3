#include<iostream>
#include<bits/stdc++.h>
#define vi vector<itn>
#define vvi vector<vi>
#define rep(i,n) for(int i=0;i<n;i++)
#define repi(i,a,b) for(int i=a;i<b;i++)

using namespace std;
struct node{
public:
  int data;
  node* left;
  node* right;

  node(int val){
    data=val;
    left=NULL;
    right=NULL;
  }
};
void preorder(node* root){
  if(root){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
  else return;
}
void inorder(node* root){
  if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
  else return;
}
void postorder(node* root){
  if(root){
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
  else return;
}
void level_order(node* root){
  if(!root) return;
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* temp=q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left)
      q.push(temp->left);
    if(temp->right)
      q.push(temp->right);
  }
}
int max_ele(node* root){
  int root_val,right,left,max=INT_MIN;
  if(root){
    root_val=root->data;
    left=max_ele(root->left);
    right=max_ele(root->right);
    if(left>right) max=left;
    else max=right;
    if(root_val>max) max=root_val;
  }
  return max;
}
int max_ele_itr(node* root){
  node* temp;
  queue<node*> q;
  q.push(root);
  int max=INT_MIN;
  while(!q.empty()){
    temp=q.front();
    q.pop();
    if(temp->data>max) max=temp->data;
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  return max;
}
int ele_search(node* root,int val){
    if(!root) return 0;
    else{
      if(root->data==val) return 1;
    }
    return ele_search(root->left,val) || ele_search(root->right,val);
    return 0;
}
int size_itr(node* root){
  if(!root) return 0;
  queue<node*> q;
  node* temp=root;
  q.push(root);
  int count=0;
  while(!q.empty()){
    temp=q.front();
    q.pop();
    count++;
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  return count;

}
int size(node* root){
  if(!root) return 0;
  return (size(root->left)+1+size(root->right));
}
int height(node* root){
  if(!root) return 0;
  int lh=0,rh=0;
  lh=height(root->left);
  rh=height(root->right);
  if(lh>rh) return (lh+1);
  else return (rh+1);
}
int full_node(node* root){
  if(!root) return 0;
  else if(root->left && root->right) return 1;
  return (1+ full_node(root->left) + full_node(root->right));
}
int full_node_itr(node* root){
  queue<node*>q;
  if(!root) return 0;
  node* temp;
  int count=0;
  q.push(root);
  while(!q.empty()){
    temp=q.front();
    q.pop();
    if(temp->right && temp->left) count++;
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  return count;
}
int half_nodes(node* root){
  node* temp;
  queue<node*> q;
  int count=0;
  q.push(root);
  while(!q.empty()){
    temp=q.front();
    q.pop();
    if((!temp->left && temp->right)||(!temp->right && temp->left)) count++;
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  return count;
}
int identical(node* root1,node* root2){
  if(!root1 && !root2) return 1;
  if(!root1 || root2) return 0;
return( root1->data== root2->data && identical(root1->left,root2->left) &&
      identical(root1->right,root2->right));
}
int level_max_sum(node* root){
  if(!root) return 0;
  node* temp;
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  int lvl=0,max_lvl=0,sum=0,cur_sum=0;
  while(!q.empty()){
    temp=q.front();
    q.pop();
    if(temp==NULL){
      if(cur_sum>sum){
        sum=cur_sum;
        max_lvl=lvl;
      }
      cur_sum=0;
      if(!q.empty()) q.push(NULL);
      lvl++;
    }
    else{
      cur_sum+=temp->data;
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
  }
  return max_lvl;
}
int print_arr(int arr[],int len){
  rep(i,len){
    cout<<arr[i]<<"->";
  }
}

void print_path(node* root,int path[],int plen){
  if(!root) return;
  path[plen]=root->data;
  plen++;
  if(!root->left && !root->right) print_arr(path,plen);
  else{
    print_path(root->left,path,plen);
    print_path(root->right,path,plen);
  }
}

int path_exsist(node* root,int sum){
  if(!root) return sum==0;
  else{
    int remain_sum=sum-root->data;
    if((root->left && root->right)||(!root->left && !root->right))
      return path_exsist(root->left,remain_sum)|| path_exsist(root->right,remain_sum);
    else if(root->left)
      return path_exsist(root->left,remain_sum);
    else return path_exsist(root->right,remain_sum);
  }
}

int sum_tree(node* root){
  if(!root) return 0;
  return(root->data+sum_tree(root->left)+sum_tree(root->right));
}

int sum_tree_itr(node* root){
  queue<node*> q;

  node* temp;
  q.push(root);
  int sum=0;
     while(!q.empty()){
    temp=q.front();
    q.pop();
    sum+=temp->data;
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
  return sum;
}

node* mirror_form(node* root){
  node* temp;
  if(root){
    mirror_form(root->left);
    mirror_form(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
  }
  return root;
}

int are_mirror_tree(node* root1,node* root2){
  if(!root1 && !root2) return 1;
  if(!root1 || !root2) return 0;
  if(root1->data!=root2->data) return 0;
  else return( are_mirror_tree(root1->left, root2->right) &&
                are_mirror_tree(root1->right, root2->left));
}

node* LCA(node* root,int a,int b){
  if(!root) return NULL;
  node* left,*right;
  if(root->data==a || root->data==b) return root;
  left=LCA(root->left,a,b);
  right=LCA(root->right,a,b);
  if(left && right) return root;
  else return(left?left:right);
}

int print_all_ancestor(node* root,int a){
  if(!root) return 0;
  if(root->left->data==a || root->right->data==a ||
    print_all_ancestor(root->left,a) ||print_all_ancestor(root->right,a)){
    cout<<root->data<<" ";
    return 1;
  }
  return 0;
}
int main(){
  node* root=new node(1);
  root->left=new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);
  preorder(root);
  cout<<"\n";
  postorder(root);
  cout<<"\n";
  inorder(root);
  cout<<"\n";
  level_order(root);
  cout<<"\n";
  cout<<"Max element is "<<max_ele(root)<<"\n";
  cout<<"Max element using iterative method "<<max_ele_itr(root);
  cout<<"\nSize of tree is "<<size(root);
  cout<<"\nSize of tree using iterative is "<<size_itr(root);
  cout<<"\nNo. of full nodes are "<<full_node(root);
  cout<<"\nNo. of full nodes are "<<full_node_itr(root);
  cout<<"\nNO. of half nodes are "<<half_nodes(root);
  node* root2=new node(1);
  root2->left=new node(2);
  root2->right=new node(3);
  root2->left->left=new node(4);
  root2->left->right=new node(5);
  cout<<"\nAre 2 trees identical "<<identical(root,root2);
  cout<<"\nSo level with max sum is "<<level_max_sum(root);
  cout<<"\nDo path with sum 8 exsist in tree "<<path_exsist(root,8);
  cout<<"\nSum of tree is "<<sum_tree(root);
  cout<<"\nSum of tree using iterative method is "<<sum_tree_itr(root);
  node* mirror_node=mirror_form(root);
  cout<<"\nChecking are mirror trees "<<are_mirror_tree(root,mirror_node);

  node* LCA_node=LCA(root,4,5);
  cout<<"\nLeast Comman Ancestor for 4 and 5 are "<<LCA_node->data;
  cout<<"\nAll ancestors of 5 are "<<print_all_ancestor(root,5);



}
