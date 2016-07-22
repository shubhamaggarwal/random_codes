void rev(nd* cur,nd* pre,nd** head)
{
  if(cur==NULL) return;
  nd* next=cur->nxt;
  *head=cur;
  cur->nxt=pre;
  pre=cur;
  rev(next,pre,head);
}
rev(head,NULL,&head);
