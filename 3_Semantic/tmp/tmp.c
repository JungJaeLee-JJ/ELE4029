
void print_FuncTab(FILE * listing)
{ int sc_idx, bk_idx, param_sc_idx, param_bk_idx;
  fprintf(listing,"< Function Table >\n");
  fprintf(listing,"Function Name  Scope Name  Return Type  Parameter Name  Parameter Type\n");
  fprintf(listing,"-------------  ----------  -----------  --------------  --------------\n");

  for (sc_idx = 0; sc_idx < scope_idx; sc_idx++)
  { ScopeList nowSC = scopes[sc_idx];
    BucketList * l = nowSC->bucket;

    for (bk_idx = 0; bk_idx < MAX_BUCKET; bk_idx++)
    { if(l[bk_idx] != NULL)
      { BucketList nowBK = l[bk_idx];
        TreeNode * node = nowBK->node;

        while(nowBK != NULL)
        { switch (node->nodekind)
          { case DeclK:
              if(node->kind.decl == FunK)  /* Function print */
              { fprintf(listing,"%-15s",nowBK->name);
                fprintf(listing,"%-12s",nowSC->name);
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

                int no_param = TRUE;
                for (param_sc_idx = 0; param_sc_idx < scope_idx; param_sc_idx++)
                { ScopeList paramScope = scopes[param_sc_idx];
                  if (strcmp(paramScope->name, nowBK->name) != 0)
                    continue;
                  BucketList * paramhashTable = paramScope->bucket;                  //printf("c\n");

                  for (param_bk_idx = 0; param_bk_idx < MAX_BUCKET; param_bk_idx++)
                  { if(paramhashTable[param_bk_idx] != NULL)
                    { BucketList pbl = paramhashTable[param_bk_idx];
                      TreeNode * pnode = pbl->node;

                      while(pbl != NULL)
                      { switch (pnode->nodekind)
                        { case ParamK:
                            no_param = FALSE;
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
                if (no_param)
                { fprintf(listing,"%-16s","");
                  if (strcmp(nowBK->name, "output") != 0)
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
          nowBK = nowBK->next;
        }
      }
    }
  }
}
