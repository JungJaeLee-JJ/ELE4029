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
ScopeList scopes[MAX_SC];
int scope_idx = 0;

ScopeList stack[MAX_SC];
int stack_idx = 0;

int loc_arr[MAX_SC];


/* the hash function */
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
  ScopeList nowSC = sc_top();
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
int st_lookup ( char * name )
{ BucketList l = get_bucket(name);
  if(l != NULL) return l->memloc;
  return -1;
}

void st_add_lineno( char * name, int lineno )
{ BucketList bl = get_bucket(name);
  LineList ll = bl->lines;
  while(ll->next != NULL)
    ll = ll->next;
  ll->next = (LineList) malloc(sizeof(struct LineListRec));
  ll->next->lineno = lineno;
  ll->next->next = NULL;
}

int st_lookup_top ( char * name )
{ int h = hash(name);
  ScopeList nowScope = sc_top();
  //while(nowScope != NULL)
   BucketList l = nowScope->bucket[h];
    while((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if(l != NULL)
      return l->memloc;
  //  nowScope = nowScope->parent;
  
  return -1;
}

BucketList get_bucket ( char * name )
{ int h = hash(name);
  ScopeList nowScope = sc_top();
  while(nowScope != NULL)
  { BucketList l = nowScope->bucket[h];
    while((l != NULL) && (strcmp(name,l->name) != 0) )
      l = l->next;
    if(l != NULL)
      return l;
    nowScope = nowScope->parent;
  }
  return NULL;
}

/* Stack for static scope */
ScopeList sc_create ( char * funcName )
{ ScopeList newScope;
  newScope = (ScopeList) malloc(sizeof(struct ScopeListRec));
  newScope->name = funcName;
  newScope->depth = stack_idx;
  newScope->parent = sc_top();
  scopes[scope_idx++] = newScope;

  return newScope;
}

ScopeList sc_top( void )
{ if(!stack_idx)
    return NULL;
  return stack[stack_idx - 1];
}

// 스코프 스택에서 제거
void scope_sub(){
  if(stack_idx>0) scope_idx--;
}


// 스코프 스택에 추가
void scope_add(ScopeList scope){
  stack[stack_idx] = scope;
  loc_arr[stack_idx++] = 0;
}


int addLocation ( void )
{ return loc_arr[stack_idx - 1]++;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */

void printSymTab(FILE * listing)
{ print_SymTab(listing);
  fprintf(listing,"\n");
  print_FuncTab(listing);
  fprintf(listing,"\n");
  print_Func_globVar(listing);
  fprintf(listing,"\n");
  print_FuncP_N_LoclVar(listing);
} /* printSymTab */

void print_SymTab(FILE * listing)
{ int i, j;
  fprintf(listing,"< Symbol Table >\n");
  fprintf(listing,"Variable Name  Variable Type  Scope Name  Location  Line Numbers\n");
  fprintf(listing,"-------------  -------------  ----------  --------  ------------\n");

  for (i = 0; i < scope_idx; i++)
  { ScopeList nowScope = scopes[i];
    BucketList * hashTable = nowScope->bucket;

    for (j = 0; j < MAX_BUCKET; j++)
    { if(hashTable[j] != NULL)
      { BucketList bl = hashTable[j];
        TreeNode * node = bl->node;

        while(bl != NULL)
        { LineList ll = bl->lines;
          fprintf(listing,"%-15s",bl->name);

          switch (node->nodekind)
          { case DeclK:
              switch (node->kind.decl)
              { case FunK:
                  fprintf(listing,"%-15s","Function");
                  break;
                case VarK:
                  switch (node->type)
                  { case Void:
                      fprintf(listing,"%-15s","Void");
                      break;
                    case Integer:
                      fprintf(listing,"%-15s","Integer");
                      break;
                    default:
                      break;
                  }
                  break;
                case ArrVarK:
                  fprintf(listing,"%-15s","IntegerArray");
                  break;
                default:
                  break;
              }
              break;
            case ParamK:
              switch (node->kind.param)
              { case ArrParamK:
                  fprintf(listing,"%-15s","IntegerArray");
                  break;
                case SingleParamK:
                  fprintf(listing,"%-15s","Integer");
                  break;
                default:
                  break;
              }
              break;
            default:
              break;
          }

          fprintf(listing,"%-12s",nowScope->name);
          fprintf(listing,"%-10d",bl->memloc);
          while(ll != NULL)
          { fprintf(listing,"%4d",ll->lineno);
            ll = ll->next;
          }
          fprintf(listing,"\n");
          
          bl = bl->next;
        }
      }
    }
  }
}

void print_FuncTab(FILE * listing)
{ int i, j, k, l;
  fprintf(listing,"< Function Table >\n");
  fprintf(listing,"Function Name  Scope Name  Return Type  Parameter Name  Parameter Type\n");
  fprintf(listing,"-------------  ----------  -----------  --------------  --------------\n");

  for (i = 0; i < scope_idx; i++)
  { ScopeList nowScope = scopes[i];
    BucketList * hashTable = nowScope->bucket;

    for (j = 0; j < MAX_BUCKET; j++)
    { if(hashTable[j] != NULL)
      { BucketList bl = hashTable[j];
        TreeNode * node = bl->node;

        while(bl != NULL)
        { switch (node->nodekind)
          { case DeclK:
              if(node->kind.decl == FunK)  /* Function print */
              { fprintf(listing,"%-15s",bl->name);
                fprintf(listing,"%-12s",nowScope->name);
                switch (node->type)
                { case Void:
                    fprintf(listing,"%-13s","Void");
                    break;
                  case Integer:
                    fprintf(listing,"%-13s","Integer");
                    break;
                  default:
                    break;
                }

                int noParam = TRUE;
                for (k = 0; k < scope_idx; k++)
                { ScopeList paramScope = scopes[k];
                  if (strcmp(paramScope->name, bl->name) != 0)
                    continue;
                  BucketList * paramhashTable = paramScope->bucket;                  //printf("c\n");

                  for (l = 0; l < MAX_BUCKET; l++)
                  { if(paramhashTable[l] != NULL)
                    { BucketList pbl = paramhashTable[l];
                      TreeNode * pnode = pbl->node;

                      while(pbl != NULL)
                      { switch (pnode->nodekind)
                        { case ParamK:
                            noParam = FALSE;
                            fprintf(listing,"\n");
                            fprintf(listing,"%-40s","");
                            fprintf(listing,"%-16s",pbl->name);
                            switch (pnode->type)
                            { case Integer:
                                fprintf(listing,"%-14s","Integer");
                                break;
                              case ArrayInteger:
                                fprintf(listing,"%-14s","IntegerArray");
                                break;
                              default:
                                break;
                            }
                            break;
                          default:
                            break;
                        }
                        pbl = pbl->next;
                      }
                    }
                  }
                  break;
                }
                if (noParam)
                { fprintf(listing,"%-16s","");
                  if (strcmp(bl->name, "output") != 0)
                    fprintf(listing,"%-14s","Void");
                  else 
                    fprintf(listing,"\n%-56s%-14s","","Integer");
                }

                fprintf(listing,"\n");
              }
              break;
            default:
              break;
          }          
          bl = bl->next;
        }
      }
    }
  }
}

void print_Func_globVar(FILE * listing)
{ int i, j;
  fprintf(listing,"< Function and Global Variables >\n");
  fprintf(listing,"   ID Name      ID Type    Data Type \n");
  fprintf(listing,"-------------  ---------  -----------\n");

  for (i = 0; i < scope_idx; i++)
  { ScopeList nowScope = scopes[i];
    if (strcmp(nowScope->name, "global") != 0)
      continue;

    BucketList * hashTable = nowScope->bucket;

    for (j = 0; j < MAX_BUCKET; j++)
    { if(hashTable[j] != NULL)
      { BucketList bl = hashTable[j];
        TreeNode * node = bl->node;

        while(bl != NULL)
        { switch (node->nodekind)
          { case DeclK:
              fprintf(listing,"%-15s",bl->name);
              switch (node->kind.decl)
              { case FunK:
                  fprintf(listing,"%-11s","Function");
                  switch (node->type)
                  { case Void:
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
                  switch (node->type)
                  { case Void:
                      fprintf(listing,"%-11s","Variable");
                      fprintf(listing,"%-11s","Void");
                      break;
                    case Integer:
                      fprintf(listing,"%-11s","Variable");
                      fprintf(listing,"%-11s","Integer");
                      break;
                    default:
                      break;
                  }
                  break;
                case ArrVarK:
                  fprintf(listing,"%-11s","Variable");
                  fprintf(listing,"%-15s","IntegerArray");
                  break;
                default:
                  break;
              }
              fprintf(listing,"\n");
              break;              
            default:
              break;
          }
          bl = bl->next;
        }
      }
    }
    break;
  }
}

void print_FuncP_N_LoclVar(FILE * listing)
{ int i, j;
  fprintf(listing,"< Function Parameter and Local Variables >\n");
  fprintf(listing,"  Scope Name    Nested Level     ID Name      Data Type \n");
  fprintf(listing,"--------------  ------------  -------------  -----------\n");

  for (i = 0; i < scope_idx; i++)
  { ScopeList nowScope = scopes[i];
    if (strcmp(nowScope->name, "global") == 0)
      continue;
    BucketList * hashTable = nowScope->bucket;
    //fprintf(listing,"%s\n",nowScope->funcName); 

    int noParamVar = TRUE;
    for (j = 0; j < MAX_BUCKET; j++)
    { if(hashTable[j] != NULL)
      { BucketList bl = hashTable[j];
        TreeNode * node = bl->node;

        while(bl != NULL)
        { switch (node->nodekind)
          { case DeclK:
              noParamVar = FALSE;
              fprintf(listing,"%-16s",nowScope->name);
              fprintf(listing,"%-14d",nowScope->depth);
              switch (node->kind.decl)
              { case VarK:
                  switch (node->type)
                  { case Void:
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
                  fprintf(listing,"%-11s","IntegerArray");
                  break;
                default:
                  break;
              }
              fprintf(listing,"\n");
              break;              
            case ParamK:
              noParamVar = FALSE;
              fprintf(listing,"%-16s",nowScope->name);
              fprintf(listing,"%-14d",nowScope->depth);
              switch (node->kind.param)
              { case ArrParamK:
                  fprintf(listing,"%-15s",node->attr.name);
                  fprintf(listing,"%-11s","IntegerArray");
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
          bl = bl->next;
        }
      }
    }
    if (!noParamVar)
      fprintf(listing,"\n");
  }
}