int countLen(Node* head){
     if(head==NULL)return 0;
     Node* temp=head;
     int cnt=0;
     while(temp!=NULL){
           cnt++;
            temp=temp->next;
     }
     return cnt;
}
Node* removeKthNode(Node* head, int K)
{
    if(head==NULL)return NULL;
      int len=countLen(head);
      if(len==K){
    Node* node =head;
    head=head->next;
    delete node;
    return head; 
      }else{
      Node* temp=head;
      int cnt=1;
      while(cnt<(len-K)){
            temp=temp->next;
            cnt++;
      }
        Node* t =temp->next;
        temp->next=temp->next->next;
        delete t;
        return head;
      }
}