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

/* 스코프 최대 갯수 */
ScopeList * scope_list_for_print[MAX_SC];
extern int scope_index;


static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % MAX_BUCKET;
    ++i;
  }
  return temp;
}


void st_insert( ScopeList * scope, char * name, TreeNode * node, int lineno, int loc ){ 
  int h = hash(name);
  ScopeList nowSC = *scope;
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

    /* 변수 및 함수 index */
    nowSC->memidx++;
  }
  /* 이미 선언된 경우 line number만 추가 */
  else 
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( ScopeList * scope, char * name ){ 
  int h = hash(name);
  ScopeList nowSC = *scope;
  while (nowSC != NULL){
    BucketList l =  nowSC->bucket[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
    if (l != NULL) return l->memloc;
    nowSC = nowSC -> parent;
  }
  return -1; 
}

BucketList bk_lookup ( ScopeList * scope, char * name ){ 
  int h = hash(name);
  ScopeList nowSC = *scope;
  while (nowSC != NULL){
    BucketList l =  nowSC->bucket[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
    if (l != NULL) return l;
    nowSC = nowSC -> parent;
  }
  return NULL; 
}

ScopeList scope_create ( ScopeList * scope, char * name){
  ScopeList nowSC = *scope;
  
  /* 스코프 생성 */
  ScopeList newSC;
  newSC = (ScopeList)malloc(sizeof(struct ScopeListRec));
  newSC->name = name;

  /* 지역 변수 및 함수 선언 */
  newSC->memidx = 0;

  /* 스코프 주소값 등록 */
  scope_list_for_print[scope_index] = newSC;
  scope_index++;

  /* 부모 스코프가 없는 경우 (Global 스코프인 경우) */
  if(scope == NULL){
    newSC->depth = 0;
    newSC->parent = NULL;
  }
  else{
    ScopeList nowSC = (ScopeList) scope;
    newSC->depth = nowSC->depth + 1;
    nowSC->parent = nowSC;
  }
  return newSC;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing){ 
  int sc_idx,bk_idx;

  fprintf(listing,"Name           Type           Location  Scope      Line Numbers\n");
  fprintf(listing,"-------------  -------------  --------  ---------- ------------\n");

  for(sc_idx = 0; sc_idx < scope_index; sc_idx++){

    ScopeList nowSC = scope_list_for_print[sc_idx];
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
          fprintf(listing,"%-10d",nowBK->memloc);
          fprintf(listing,"%-12s",nowSC->name);
          LineList linelist = nowBK->lines;
          while(linelist != NULL){ 
            fprintf(listing,"%4d",linelist->lineno);
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

  for (sc_idx = 0; sc_idx < scope_index; sc_idx++){ 
  
    ScopeList nowSC = scope_list_for_print[sc_idx];
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
             /* 선언 일 때 */
            case DeclK:

              /* 함수만 출력 */
              if (node->kind.decl != FunK) continue;

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
              for(param_sc_idx = 0; param_sc_idx < scope_index; param_sc_idx++){
                ScopeList paramSC = scope_list_for_print[param_sc_idx];
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
                          no_param = 1;
                          fprintf(listing,"\n");
                          fprintf(listing,"%-40s","");
                          fprintf(listing,"%-16s",paramBK->name);
                          switch (param_node->nodekind)
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
                      BucketList paramBK = paramBK->next;
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
  fprintf(listing,"   ID Name      ID Type    Data Type \n");
  fprintf(listing,"-------------  ---------  -----------\n");

  for(sc_idx = 0; sc_idx < scope_index; sc_idx++){

    ScopeList nowSC = scope_list_for_print[sc_idx];

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
  fprintf(listing,"  Scope Name    Nested Level     ID Name      Data Type \n");
  fprintf(listing,"--------------  ------------  -------------  -----------\n");


  for(sc_idx = 0; sc_idx < scope_index; sc_idx++){

    ScopeList nowSC = scope_list_for_print[sc_idx];

    /* globa만 확인 */
    if(strcmp(nowSC->name, "global") != 0) continue;

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

