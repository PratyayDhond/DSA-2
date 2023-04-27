#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x,y) ((x>y)?x:y)

void init(bst* t){
    *t=NULL;
}

void Adjustbf(bst* root){
   if ((*root) != NULL) {
         if (((*root)->left != NULL) && ((*root)->right != NULL)) {
                 (*root)->height = max((*root)->left->height, (*root)->right->height) + 1 ;          
         }
         else if ((*root)->left != NULL) {
             (*root)->height = (*root)->left->height + 1 ;
         }
         else if ((*root)->right != NULL) {
             (*root)->height = (*root)->right->height + 1;
         }
         else {
             (*root)->height = 1;
         }
    }
}

node* ll_rotation(node* imbal){
  
   

        node* temp=imbal->left;
        imbal->left=temp->right;
        if(temp->right!=NULL){
           temp->right->parent=imbal;
            
        }
        temp->right=imbal;
       
        temp->parent=imbal->parent;
        imbal->parent=temp;

        if((temp)->parent!=NULL){
            if(strcmp(imbal->data,temp->parent->data)<0){
                temp->parent->left=temp;
            }
            else{
                temp->parent->right=temp;
            }
        }
       
        imbal=temp;
        
        Adjustbf(&imbal->right);
        Adjustbf(&imbal->left);
        Adjustbf(&imbal);
        Adjustbf(&imbal->parent);
    

    
   return imbal;

}

node* rr_rotation(node* imbal){
   
        node* temp=(imbal)->right;
        imbal->right=temp->left;
        if(temp->left!=NULL){
            temp->left->parent=imbal;
        }
        temp->left=imbal;
        temp->parent=imbal->parent;
        imbal->parent=temp;
        if(temp->parent!=NULL){
            if(strcmp(imbal->data,temp->parent->data)<0){
                temp->parent->left=temp;
            }
            else{
                temp->parent->right=temp;
            }
        }
        imbal=temp;
       
       Adjustbf(&imbal->left);
       Adjustbf(&imbal->right);
       Adjustbf(&imbal);
       Adjustbf(&imbal->parent);
       return imbal;

    
}

node* lr_rotation(node* imbal){
    
    imbal->left=rr_rotation(imbal->left);
    return ll_rotation(imbal);
}
node* rl_rotation(node* imbal){
    
    imbal->right=ll_rotation(imbal->right);
    return rr_rotation(imbal);
   

}

void insert(bst* t,bst parent,char* data){
    node *p=*t;
    node* nn=NULL;
    
   if(*t==NULL){
       
        nn=(node*)malloc(sizeof(node));
        nn->data=(char*)malloc(sizeof(char)*20);
        nn->left=NULL;
        nn->right=NULL;
        nn->parent=parent;
        strcpy(nn->data,data);
        //nn->data=data;
        nn->height=1;
        *t=nn;
       
        return;
    }

    if(*t!=NULL){
        
        if(strcmp((*t)->data,data)>0){
            insert(&(*t)->left,*t,data);
            Adjustbf(t);
            int left_height=0;
            int right_height=0;
            if((*t)->left!=NULL){
                left_height=(*t)->left->height;
            }
            if((*t)->right!=NULL){
                right_height=(*t)->right->height;
            }

            if(left_height-right_height > 1){
                if((*t)->left!=NULL && (*t)->left->data>data){
                    *t=ll_rotation(*t);
                }
                else{
                    *t=lr_rotation(*t);
                }
            }
        }
        else if(strcmp((*t)->data,data)<0){
          
            insert(&(*t)->right,*t,data);
            Adjustbf(t);
            int left_height=0;
            int right_height=0;
            if((*t)->left!=NULL){
                left_height=(*t)->left->height;
            }
            if((*t)->right!=NULL){
                right_height=(*t)->right->height;
            }
           
            if(right_height-left_height > 1){
                
                if((*t)->right!=NULL && strcmp((*t)->right->data,data)>0){
                   
                   *t=rl_rotation(*t);
            }
            else{
                   
                    *t=rr_rotation(*t);
                }
        }
    }
    
    }
}

node* inorder_before(bst t){
	node *p;
	p=t;
	while(p!=NULL && p->right!=NULL){
		p=p->right;
	}
	return p;
}

node* inorder_after(bst t){
	node *p;
	p=t;
	while(p!=NULL && p->left!=NULL){
		p=p->left;
	}
	return p;
}

int height(bst t){
	node *p;
	p=t;
	if(p==NULL){
		return 0;
	}
	int x=height(p->left);
	int y=height(p->right);
	if(x>y){
		return x+1;

		
	}
	else{
		return y+1;
	}
}


int BalanceFactor(bst p){

    if(p==NULL){
        return 0;
    }
    if(p->left==NULL && p->right==NULL){
        return 0;
    }
    else if (p->left==NULL && p->right!=NULL){
        return 0-height(p->right);
    }
    else{
        return height(p->left)-height(p->right);
    }
}



node* Delete(bst *t,char* data){
    
    node* p;
    p=*t;
  
    node *q=NULL;


    if(p==NULL){
    	return NULL;
	}
	if(p->left==NULL && p->right==NULL){
		if(p==*t){
			*t=NULL;
	
		}
		free(p);
		return NULL;
		
	}
	else {
		if(strcmp(p->data,data)>0){
			p->left=Delete(&p->left,data);
            
		}
		else if(strcmp(p->data,data)<0){
			p->right=Delete(&p->right,data);
		}
		else {
           
			if(height(p->left)>height(p->right)){
               
				q=inorder_before(p->left);
                strcpy(p->data,q->data);
                
				p->left=Delete(&p->left,q->data);
			}
			else {
				q=inorder_after(p->right);
                
				//p->data=q->data;
                strcpy(p->data,q->data);
                 
                   //printf("q: %s\n",p->data);
				p->right=Delete(&p->right,q->data);
			}
		}
        Adjustbf(&(p));
        Adjustbf(&(p->parent));


          if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1) {  // L1 Rotation
        *t = ll_rotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1){  // L-1 Rotation
        *t = lr_rotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1){  // R-1 Rotation
        *t = rr_rotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1){  // R1 Rotation
        *t =  rl_rotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 0){  // L0 Rotation
        *t = ll_rotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 0){  // R0 Rotation
        *t = rr_rotation(p);
    }
     
    return *t;



	}

	
}


void traverse(bst t){
    int count=0;
    if(t!=NULL){
        traverse(t->left);
       
        traverse(t->right);
         printf(" %s\n",t->data);
        //printf("%d ",t->height);
    }
    
}

void destroyTree(bst *t){
	node *p=*t;
	if(*t==NULL){
		return;
	}
	destroyTree(&p->left);
	destroyTree(&p->right);
	printf("%s\n",p->data);
	free(p);
	
}

