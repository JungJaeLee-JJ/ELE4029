/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTAB_H_
#define _SYMTAB_H_


/* 12.12 추가 */
#include "globals.h"
#define MAX_BUCKET 100

#define MAX_SC 500

/* 12.12 symbol이 사용되는 line들을 link the list 형태로 구현 */
typedef struct LineListRec{ 
    int lineno;
    struct LineListRec * next;
} * LineList;

/* 12.12 추가 */
typedef struct BucketListRec { 
    char * name;
    TreeNode * node;  
    LineList lines;
    int memloc ;
    struct BucketListRec * next;
} * BucketList;

typedef struct ScopeListRec { 
    char * name;
    BucketList bucket[MAX_BUCKET]; /* the hash table */
    int depth;
    int memidx;
    struct ScopeListRec * parent;
} * ScopeList;
 

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, TreeNode * node, int lineno, int loc );

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup (char * name );
void st_add_lineno( char * name, int lineno );
int st_lookup_top ( char * name );

BucketList get_bucket ( char * name );

/* Stack for static scope */
ScopeList sc_create ( char * funcName );
ScopeList sc_top ( void );
void scope_sub ( void );
void scope_add ( ScopeList scope );
int addLocation ( void );

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing);
void print_SymTab(FILE * listing);
void print_FuncTab(FILE * listing);
void print_Func_globVar(FILE * listing);
void print_FuncP_N_LoclVar(FILE * listing);

#endif
