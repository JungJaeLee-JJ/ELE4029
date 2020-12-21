/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util.h"

/* counter for variable memory locations */
static int location = 0;
static ScopeList globalSC = NULL;
static char * funcName;
static int inScopeBefore = FALSE;

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Error: Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

static void symbolError(TreeNode * t, char * message)
{ fprintf(listing,"Error: Symbol error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

static void undeclaredError(TreeNode * t)
{ if (t->kind.exp == CallK)
    fprintf(listing,"Error: Undeclared Function \"%s\" at line %d\n",t->attr.name,t->lineno);
  else if (t->kind.exp == IdK || t->kind.exp == ArrIdK)
    fprintf(listing,"Error: Undeclared Variable \"%s\" at line %d\n",t->attr.name,t->lineno);
  Error = TRUE;
}

static void redefinedError(TreeNode * t)
{ if (t->kind.decl == FunK)
    fprintf(listing,"Error: Redefined Function \"%s\" at line %d\n",t->attr.name,t->lineno);
  else if (t->kind.decl == VarK)
    fprintf(listing,"Error: Redefined Variable \"%s\" at line %d\n",t->attr.name,t->lineno);
  else if (t->kind.decl == ArrVarK)
    fprintf(listing,"Error: Redefined Variable \"%s\" at line %d\n",t->attr.arr.name,t->lineno);
  Error = TRUE;
}

static void funcDeclNotGlobal(TreeNode * t)
{ fprintf(listing,"Error: Function Definition is not allowed at line %d (name : %s)\n",t->lineno,t->attr.name);
  Error = TRUE;
}

static void voidVarError(TreeNode * t, char * name)
{ fprintf(listing,"Error: Variable Type cannot be Void at line %d (name : %s)\n",t->lineno,name);
  Error = TRUE;
}


static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t )
{ switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case CompK:
          if (inScopeBefore)
            inScopeBefore = FALSE;
          else
          { ScopeList scope = scope_create(funcName);
            scope_add(scope);
            location++;
          }
          t->scope = sc_top();
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case IdK:
        case ArrIdK:
        case CallK:
          /* not yet in table, undeclared error */
          if (st_lookup(t->attr.name) == -1)
            undeclaredError(t);
          /* already in table, so ignore location, 
             add line number of use only */ 
          else
            st_add_lineno(t->attr.name, t->lineno);
          break;
        default:
          break;
      }
      break;
    case DeclK:
      switch (t->kind.decl)
      { case FunK:
          funcName = t->attr.name;
          if (st_lookup_top(t->attr.name) >= 0)
          { redefinedError(t);
            break;
          }
          if (sc_top() != globalSC)
          { funcDeclNotGlobal(t);
            break;
          }
          st_insert(funcName, t, t->lineno, loc_add());
          scope_add(scope_create(funcName));
          inScopeBefore = TRUE;

          switch (t->child[0]->attr.type)
          { case INT:
              t->type = Integer;
              break;
            case VOID:
            default:
              t->type = Void;
              break;
          }        
          break;
        case VarK:
        case ArrVarK:
          { char * name;            
            if (t->kind.decl == VarK)
            { name = t->attr.name;
              t->type = Integer;
            }
            else
            { name = t->attr.arr.name;
              t->type = ArrayInteger;
            }
            
            if (st_lookup_top(name) < 0){
              st_insert(name, t, t->lineno, loc_add());
            }
            else 
              redefinedError(t);
          }
          break;
        default:
          break;
      }
      break;
    case ParamK:
        if (t->child[0]->attr.type == VOID)
        { break;
        }

        if (st_lookup(t->attr.name) == -1)
        { st_insert(t->attr.name, t, t->lineno, loc_add());
          if(t->kind.param == SingleParamK)
            t->type = Integer;
          else
            t->type = ArrayInteger;
        }
        break;
    default:
      break;
  }
}

static void backToParent(TreeNode * t){ 
  if (t->nodekind == StmtK && t->kind.stmt == CompK) scope_sub();
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree){ 

  /* 12.12 global scope 생성  */


  globalSC = scope_create("global");
  scope_add(globalSC);

  TreeNode * function;
  TreeNode * type;
  TreeNode * parameter;
  TreeNode * parameter_child;
  TreeNode * comp;

  /* input() */
  function = newDeclNode(FunK);
  type = newDeclNode(TypeK);
  comp = newStmtNode(CompK);
  type->attr.type = INT;


  comp->child[0] = NULL;
  comp->child[1] = NULL;

  function->type = Integer;
  function->lineno = 0;
  function->attr.name = "input";
  function->child[0] = type;
  function->child[1] = NULL;
  function->child[2] = comp; 



  st_insert("input",function,0,loc_add());



  /* output() */
  function = newDeclNode(FunK);
  type = newDeclNode(TypeK);
  parameter = newParamNode(SingleParamK);
  parameter_child = newDeclNode(TypeK);
  comp = newStmtNode(CompK);
  type->attr.type = VOID;

  parameter->attr.name = "arg";
  parameter->type = Integer;
  parameter_child->attr.type = INT;
  parameter->child[0] = parameter_child;

  comp->child[0] = NULL;
  comp->child[1] = NULL;

  function->type = Void;
  function->lineno = 0;
  function->attr.name = "output";
  function->child[0] = type;
  function->child[1] = parameter;
  function->child[2] = comp; 

  st_insert("output",function,0,loc_add());


  traverse(syntaxTree,insertNode,backToParent);
  scope_sub();
}

static void beforeCheckNode(TreeNode * t)
{ switch (t->nodekind)
  { case DeclK:
      switch (t->kind.decl)
      { case FunK:
          funcName = t->attr.name;
          break;
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { case CompK:
          scope_add(t->scope);
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case CompK:
          scope_sub();
          break;
        case IfK:
        case IfEK:
          if (t->child[0] == NULL)
            typeError(t,"expected expression");
          else if (t->child[0]->type == Void)
            typeError(t->child[0],"invalid if condition type");
          break;
        case WhileK:
          if (t->child[0] == NULL)
            typeError(t,"expected expression");
          else if (t->child[0]->type == Void)
            typeError(t->child[0],"invalid loop condition type");
          break;
        case ReturnK:
        { TreeNode * retFunc = get_bucket(funcName)->node;
          if ((retFunc->type == Void && t->child[0] != NULL) ||
              (retFunc->type == Integer && 
              (t->child[0] == NULL || t->child[0]->type == Void || t->child[0]->type == ArrayInteger)))
            typeError(t,"invalid return type");
          break;
        }
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case AssignK:
          if (t->child[0]->type == Void || t->child[1]->type == Void)
            typeError(t->child[0],"invalid variable type");
          else if (t->child[0]->type == ArrayInteger && t->child[0]->child[0] == NULL)
            typeError(t->child[0],"invalid variable type");
          else if (t->child[1]->type == ArrayInteger && t->child[1]->child[0] == NULL)
            typeError(t->child[0],"invalid variable type");
          else 
            t->type = t->child[0]->type;
          break;
        case OpK:
        { ExpType lType, rType;
          TokenType op;

          lType = t->child[0]->type;
          rType = t->child[1]->type;
          op = t->attr.op;

          if(lType == ArrayInteger && t->child[0]->child[0] != NULL)
            lType = Integer;
          if(rType == ArrayInteger && t->child[1]->child[0] != NULL)
            rType = Integer;

          if (lType == Void || rType == Void)
            typeError(t,"void variable cannot be operand");
          else if (lType != rType)
            typeError(t,"operands have different type");
          else
            t->type = Integer;
          break;
        }
        case ConstK:
          t->type = Integer;
          break;
        case IdK:
        case ArrIdK:
        { BucketList l = get_bucket(t->attr.name);
          if (l == NULL)
            break;

          TreeNode * symbolNode = NULL;
          symbolNode = l->node;

          if (t->kind.exp == ArrIdK)
          { if ((symbolNode->nodekind == DeclK && symbolNode->kind.decl != ArrVarK)
                || (symbolNode->nodekind == ParamK && symbolNode->kind.param != ArrParamK))
              typeError(t, "invalid expression");
            else
              t->type = symbolNode->type;
          }
          else
            t->type = symbolNode->type;
          break;
        }
        case CallK:
        { BucketList l = get_bucket(t->attr.name);
          TreeNode * funcNode = NULL;
          TreeNode * arg;
          TreeNode * param;

          if (l == NULL)
            break;
          funcNode = l->node;
          arg = t->child[0];
          param = funcNode->child[1];

          if (funcNode->kind.decl != FunK)
          { typeError(t, "invalid expression");
            break;
          }

          while (arg != NULL)
          { if (param == NULL || arg->type == Void)
            { typeError(arg, "invalid function call");
              break;
            }
            ExpType pType = param->type;
            ExpType aType = arg->type;            
            if(aType == ArrayInteger && arg->child[0] != NULL)
              aType = Integer;

            if (pType != aType)
            { typeError(arg, "invalid function call");
              break;
            }
            else
            { arg = arg->sibling;
              param = param->sibling;
            }
          }
          if (arg == NULL && param != NULL && param->child[0]->attr.type != VOID){
            typeError(t->child[0],"invalid function call");
          }
          
          t->type = funcNode->type;
          break;
        }
        default:
          break;
      }
      break;
    case DeclK:
      switch (t->kind.decl)
      { case VarK:
        case ArrVarK:
          if (t->child[0]->attr.type == VOID)
          { char * name;            
            if (t->kind.decl == VarK)
              name = t->attr.name;
            else
              name = t->attr.arr.name;
            voidVarError(t, name);
            break;
          }
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ scope_add(globalSC);
  traverse(syntaxTree,beforeCheckNode,checkNode);
  scope_sub();
}
