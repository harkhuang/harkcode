#include<stdlib.h>
#include<stdio.h>
struct tree                //声明树的结构
{
     struct tree *left;
     int data;
     struct tree *right;
};

typedef struct tree treenode;
typedef treenode *b_tree;             //声明二叉树链表

//插入二叉树的节点
b_tree insert_node(b_tree root,int node)
{
     b_tree newnode;
     b_tree currentnode;
     b_tree parentnode;
     
     newnode=(b_tree)malloc(sizeof(treenode));     //建立新节点的内存空间
     newnode->data=node;
     newnode->right=NULL;
     newnode->left=NULL;

     if(root=NULL)
          return newnode;
     else
     {   currentnode=root;
          while(currentnode!=NULL)
          {   parentnode=currentnode;
               if( currentnode->data>node)
                    currentnode=currentnode->left;
               else   currentnode=currentnode->right;
          }
          if(parentnode->data>node)
               parentnode->left=newnode;
          else  parentnode->right=newnode;
     }
     return root;
}

// 建立二叉树
b_tree create_btree(int *data,int len)
{
     b_tree root=NULL;
     int i;

     for(i=0;i<len;i++)
          root=insert_node(root,data[i]);
     return root;
}

//二叉树中序遍历
void inorder(b_tree point)
{
     if(point!=NULL)
     {
          inorder(point->left);
          printf("%d",point->data);
          inorder(point->right);
     }
}

//主程序
void main( )
{
     b_tree root=NULL;
     int i,index;
     int value;
     int nodelist[20];
     printf("\n pleaase input the elements of binary tree(exit for 0 ):\n");
     index=0;

     //读取数值存到数组中
     scanf("%d",&value);
     
     while(value!=0)
     {
          nodelist[index]=value;
          index=index+1;
          scanf("%d",&value);
     }
     //建立二叉树
     root=create_btree(nodelist,index);

     //中序遍历二叉树
     printf("\nThe inorder traversal result is :");
     inorder(root);
     printf("\n");
}

 

 
 

 

 
