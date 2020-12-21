/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* 12.12 TreeNode 자료형을 사용하기 위해 추가 */
#include "globals.h"


#define SHIFT 4

/* 스코프 배열 */
ScopeList scopes[MAX_SC];
int scope_idx = 0;

/* 스코프 스택 */
ScopeList stack[MAX_SC];
int stack_idx = 0;

/* 스코프 위치 */
int loc_arr[MAX_SC];


static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % MAX_BUCKET;
    ++i;
  }
  return temp;
}


void st_insert( char * name, TreeNode * node, int lineno, int loc ){ 
  //printf("insert %s at lineno %d\n",name,lineno);
  int h = hash(name);
  ScopeList nowSC = now_scope();
  BucketList l =  nowSC->bucket[h];

 /* Bucket list 순회 */
  while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;

  /* 선언되지 않은경우 해당 변수를 테이블에 삽입 */
  if (l == NULL) { 
    l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->node = node;
    
    /* line number 추가 */
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;

    /* 맨 앞에 삽입 */
    l->next = nowSC->bucket[h];
    nowSC->bucket[h] = l;   
  }
} 

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name ){ 

  int h = hash(name);
  ScopeList nowSC = now_scope();

  while(nowSC != NULL){ 

    BucketList l = nowSC->bucket[h];

    while((l != NULL) && (strcmp(name,l->name) != 0) ) l = l->next;

    /* 찾았을 때 */
    if(l != NULL) return l->memloc;
    
    nowSC = nowSC->parent;
  }
  return -1;
}

void line_add( char * name, int lineno ){ 

  int h = hash(name);
  ScopeList nowSC = now_scope();

  while(nowSC != NULL){ 
    
    BucketList l = nowSC->bucket[h];

    while((l != NULL) && (strcmp(name,l->name) != 0) ) l = l->next;

    if(l != NULL){
       LineList ll = l->lines;
      /* 마지막 line 찾기 */
      while(ll->next != NULL) ll = ll->next;

      /* 마지막 line에서 line 1개를 더 추가*/
      ll->next = (LineList) malloc(sizeof(struct LineListRec));
      ll->next->lineno = lineno;
      ll->next->next = NULL;

    }
    nowSC = nowSC->parent;
  }
}

int st_lookup_now_scope ( char * name ){ 
  
  int h = hash(name);
  ScopeList nowSC = now_scope();
  BucketList l = nowSC->bucket[h];
  while((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
  if(l != NULL) return l->memloc;
  return -1;
}

BucketList bk_lookup ( char * name ){ 
  
  int h = hash(name);
  ScopeList nowSC = now_scope();

  while(nowSC != NULL){ 
    BucketList l = nowSC->bucket[h];

    while((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;

    /* 찾았을 때 */
    if(l != NULL)  return l;

    nowSC = nowSC->parent;
  }
  return NULL;
}

ScopeList scope_create (char * name){
  
  /* 스코프 생성 */
  ScopeList newSC;
  newSC = (ScopeList)malloc(sizeof(struct ScopeListRec));
  newSC->name = name;

  /* depth는 현재 stack에 쌓여있는 스코프의 수가 된다.*/
  newSC->depth = stack_idx;
  /* 새로운 스코프의 부모는 현재 스택의 맨 위에 있는 스코프이다. */
  newSC->parent = now_scope();

  /* 스코프 주소값 등록 */
  scopes[scope_idx++] = newSC;

 
  return newSC;
}



// 스코프 스택에 추가
void scope_add(ScopeList scope){
  stack[stack_idx] = scope;
  loc_arr[stack_idx++] = 0;
}

// 스코프 스택에서 제거
void scope_sub(){
  if(stack_idx>0) {
    stack_idx--;
  }
}

ScopeList now_scope(){
  if(stack_idx>0){
    return stack[stack_idx-1];
  }
  return NULL;
}



int loc_add ( void ){ 
  return loc_arr[stack_idx - 1]++;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */

void printSymTab(FILE * listing){ 
  int sc_idx,bk_idx;

  fprintf(listing,"Name           Type           Location       Scope          Line Numbers\n");
  fprintf(listing,"-------------  -------------  -------------  -------------  ------------- \n");

  for(sc_idx = 0; sc_idx < scope_idx; sc_idx++){

    ScopeList nowSC = scopes[sc_idx];
    BucketList * l =  nowSC->bucket;  

    /* 해당 심볼 테이블 내의 모든 버킷 순회 */
    for(bk_idx =0; bk_idx < MAX_BUCKET; bk_idx++){ 
      
      if (l[bk_idx] != NULL){ 
    
        BucketList nowBK = l[bk_idx];

        /* 같은 버켓에 존재하는 symbol 순회 */
        while (nowBK != NULL){
           /* 심볼 이름 출력 */
          fprintf(listing,"%-15s",nowBK->name);
  
          TreeNode * node = nowBK->node;
          /* 타입 출력 */
          switch (node->type)
          {
            case Void:
              fprintf(listing,"%-15s","Void");
              break;
            case Integer:
              fprintf(listing,"%-15s","Integer");
              break;
            default:
              break;
          }

          /* 나머지 출력 */
          fprintf(listing,"%-15d",nowBK->memloc);
          fprintf(listing,"%-15s",nowSC->name);
          LineList linelist = nowBK->lines;
          while(linelist != NULL){ 
            fprintf(listing,"%15d",linelist->lineno);
            linelist = linelist->next;
          }
          fprintf(listing,"\n");

          nowBK = nowBK->next;
        }
      }
    }
  }
} /* printSymTab */



void print_Function_Table (FILE * listing){ 
  int sc_idx,bk_idx,param_sc_idx,param_bk_idx;

  fprintf(listing,"< Function Table >\n");
  fprintf(listing,"Function Name  Scope Name  Return Type  Parameter Name  Parameter Type\n");
  fprintf(listing,"-------------  ----------  -----------  --------------  --------------\n");

  for (sc_idx = 0; sc_idx < scope_idx; sc_idx++){ 
  
    ScopeList nowSC = scopes[sc_idx];
    BucketList * l =  nowSC->bucket;  


        /* 해당 심볼 테이블 내의 모든 버킷 순회 */
    for(bk_idx =0; bk_idx < MAX_BUCKET; bk_idx++){ 
      
      if (l[bk_idx] != NULL){ 
    
        BucketList nowBK = l[bk_idx];
        TreeNode * node = nowBK->node;

        /* 같은 버켓에 존재하는 symbol 순회 */
        while (nowBK != NULL){
  
          switch (node->nodekind)
          {
             /* 선언 일 때 */
            case DeclK:

              /* 함수만 출력 */
              if (node->kind.decl == FunK) {

                fprintf(listing,"%-15s",nowBK->name);
                fprintf(listing,"%-12s",nowSC->name);

                /* return type */
                switch (node->type)
                {
                  case Void:
                    fprintf(listing,"%-13s","Void");
                    break;
                  case Integer:
                    fprintf(listing,"%-13s","Integer");
                    break;
                  default:
                    break;
                }
              
                /* 파라미터 찾기 */
                int no_param = 1;
                for(param_sc_idx = 0; param_sc_idx < scope_idx; param_sc_idx++){
                  ScopeList paramSC = scopes[param_sc_idx];
                  if (strcmp(paramSC->name, nowBK->name) != 0) continue;
                  BucketList * param_l =  paramSC->bucket;  

                  /* 버켓들 순회 */
                  for(param_bk_idx = 0; param_bk_idx < MAX_BUCKET;param_bk_idx++){

                    if (param_l[param_bk_idx] != NULL){
                        BucketList paramBK = param_l[param_bk_idx];
                        TreeNode * param_node = paramBK->node;

                      /* 1개 버켓 순회 */
                      while (paramBK != NULL){
                        switch (param_node->nodekind)
                        {
                          case ParamK:
                            no_param = 0;
                            fprintf(listing,"\n");
                            fprintf(listing,"%-40s","");
                            fprintf(listing,"%-16s",paramBK->name);
                            switch (param_node->type)
                            {
                              case Integer:
                                fprintf(listing,"%-14s","Integer");
                                break;
                              case ArrayInteger:
                                fprintf(listing,"%-14s","ArrayInteger");
                                break;
                              default:
                                break;
                            }
                            break;
                          default:
                            break;
                        }
                        paramBK = paramBK->next;
                      }
                    }
                  }
                break;
              }
              if(no_param){
                fprintf(listing,"%-16s","");
                if (strcmp(nowBK->name, "output") != 0) fprintf(listing,"%-14s","Void");
                else  fprintf(listing,"\n%-56s%-14s","","Integer");
              }

              fprintf(listing,"\n");
            }
            break;
          default:
            break;
          }
          nowBK = nowBK->next;
        }
      }
    }
  }
}



void print_Function_and_GlobalVariables(FILE * listing){ 
  
  int sc_idx,bk_idx;

  fprintf(listing,"< Function and Global Variables >\n");
  fprintf(listing,"ID Name        ID Type    Data Type \n");
  fprintf(listing,"-------------  ---------  -----------\n");

  for(sc_idx = 0; sc_idx < scope_idx; sc_idx++){

    ScopeList nowSC = scopes[sc_idx];

    /* globa만 확인 */
    if(strcmp(nowSC->name, "global") != 0) continue;

    BucketList * l =  nowSC->bucket;  

    /* 해당 심볼 테이블 내의 모든 버킷 순회 */
    for(bk_idx =0; bk_idx < MAX_BUCKET; bk_idx++){ 
      
      if (l[bk_idx] != NULL){ 
    
        BucketList nowBK = l[bk_idx];
        /* 같은 버켓에 존재하는 symbol 순회 */
        while (nowBK != NULL){
          TreeNode * node = nowBK->node;
          switch (node->nodekind)
          { 
            case DeclK:
              fprintf(listing,"%-15s",nowBK->name);
              switch (node->kind.decl)
              { 
                case FunK:
                  fprintf(listing,"%-11s","Function");
                  switch (node->type)
                  { 
                    case Void:
                      fprintf(listing,"%-11s","Void");
                      break;
                    case Integer:
                      fprintf(listing,"%-11s","Integer");
                      break;
                    default:
                      break;
                  }
                  break;
                case VarK:
                  fprintf(listing,"%-11s","Variable");
                  switch (node->type)
                  { 
                    case Void:
                      fprintf(listing,"%-11s","Void");
                      break;
                    case Integer:
                      fprintf(listing,"%-11s","Integer");
                      break;
                    default:
                      break;
                  }
                  break;
                case ArrVarK:
                  fprintf(listing,"%-11s","Variable");
                  fprintf(listing,"%-15s","ArrayInteger");
                  break;
                default:
                  break;
              }
              fprintf(listing,"\n");
              break;              
            default:
              break;
          }
          nowBK = nowBK->next;
        }
      }
    }
  }
}


void print_FunctionParameter_and_LocalVariables (FILE * listing){ 
  
  int sc_idx,bk_idx;

  fprintf(listing,"< Function Parameter and Local Variables >\n");
  fprintf(listing,"Scope Name      Nested Level  ID Name        Data Type \n");
  fprintf(listing,"--------------  ------------  -------------  -----------\n");


  for(sc_idx = 0; sc_idx < scope_idx; sc_idx++){

    ScopeList nowSC = scopes[sc_idx];

    /* globa만 확인 */
    if(strcmp(nowSC->name, "global") == 0) continue;

    BucketList * l =  nowSC->bucket;  

    int no_param = 1;

    /* 해당 심볼 테이블 내의 모든 버킷 순회 */
    for(bk_idx =0; bk_idx < MAX_BUCKET; bk_idx++){ 
      
      if (l[bk_idx] != NULL){ 
    
        BucketList nowBK = l[bk_idx];
        /* 같은 버켓에 존재하는 symbol 순회 */
        while (nowBK != NULL){
          TreeNode * node = nowBK->node;
        
          switch (node->nodekind)
          { 
            case DeclK:

              no_param = 0;
              fprintf(listing,"%-16s",nowSC->name);
              fprintf(listing,"%-14d",nowSC->depth);

              switch (node->kind.decl)
              { 
                case VarK:
                  switch (node->type)
                  { 
                    case Void:
                      fprintf(listing,"%-15s",node->attr.name);
                      fprintf(listing,"%-11s","Void");
                      break;
                    case Integer:
                      fprintf(listing,"%-15s",node->attr.name);
                      fprintf(listing,"%-11s","Integer");
                      break;
                    default:
                      break;
                  }
                  break;
                case ArrVarK:
                  fprintf(listing,"%-15s",node->attr.arr.name);
                  fprintf(listing,"%-11s","ArrayInteger");
                  break;
                default:
                  break;
              }
              fprintf(listing,"\n");
              break;              
            case ParamK:
              no_param = 0;
              fprintf(listing,"%-16s",nowSC->name);
              fprintf(listing,"%-14d",nowSC->depth);
              switch (node->kind.param)
              { case ArrParamK:
                  fprintf(listing,"%-15s",node->attr.name);
                  fprintf(listing,"%-11s","ArrayInteger");
                  break;
                case SingleParamK:
                  fprintf(listing,"%-15s",node->attr.name);
                  fprintf(listing,"%-11s","Integer");
                  break;
                default:
                  break;
              }
              fprintf(listing,"\n");
              break;
            default:
              break;
          }
          nowBK = nowBK->next;
        }
      }
    }
    if (!no_param) fprintf(listing,"\n");
  }
}

