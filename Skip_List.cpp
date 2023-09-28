//i tried to implement skip-list,you can check and please tell me where i can improve
class Node{
    public:
    int data;
    Node *next;
    Node *down;
    Node(int val){
        data=val;
        next=NULL;
        down=NULL;
    }
};
class Skiplist {
public:
    Node *head;
    Skiplist() {
        head=new Node(-1);
    }
    
    bool search(int num) {
        Node *current=head;
        while(current!=NULL){
            while(current->next!=NULL && current->next->data < num){
                current=current->next;
            }
            if(current->next!=NULL && current->next->data==num){
                return true;
            }
            current=current->down;
        }
       return false; 
    }
    
    void add(int num) {
        vector<Node*> pre;
        Node *current=head;
        while(current!=NULL){
            while(current->next!=NULL && current->next->data<num){
                current=current->next;
            }
            pre.push_back(current);
            current=current->down;

        }
        bool in=true;
        Node *downnode=NULL;
        while(in==true && !pre.empty()){
            Node *prev=pre.back();
            pre.pop_back();
            Node *newnode=new Node(num);
            newnode->next=prev->next;
            prev->next=newnode;
            newnode->down=downnode;
            downnode=newnode;
            if(rand()%2==0){
                in=true;
            }
            else{
                in=false;
            }
        }
        if(in==true){
            Node* newnode =new Node(num);
            Node *newhead=new Node(-1);
            newhead->down=head;
            head=newhead;
            newnode->next=newhead->next;
            newhead->next=newnode;
            newnode->down=downnode;
        }

    }
    
    bool erase(int num) {
        bool found=false;
        Node *current=head;
        while(current!=NULL){
            while(current->next!=NULL && current->next->data<num){
                current=current->next;
            }
            if(current->next!=NULL && current->next->data==num){
                Node *todelete=current->next;
                current->next=todelete->next;
                delete todelete;
                found=true;
            }
            current=current->down;
        }
        return found; 
    }
};
