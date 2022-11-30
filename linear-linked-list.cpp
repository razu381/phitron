#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* next;
    node(int n){
        val = n;
        next = NULL;
    }
};

struct duplicate_numbers{
    int arr[1000];
};

void insert_at_head(node* &head, int val){
    node* new_node = new node(val);
    node* temp = head;
    head = new_node;
    head -> next = temp;

}

void insert_at_tail(node* &head, int val){
    node* new_node = new node(val);
    if(head == NULL){
        head = new_node;
        return;
    }

    node* temp = head;
    while(temp -> next != NULL) temp = temp -> next;
    temp -> next = new_node;

}

void print_list(node* head){
    node* temp = head;

    while(temp != NULL){
        cout << temp -> val << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int find_length(node* head){
    int count = 0;
    while(head != NULL){
        head = head -> next;
        count++;
    }
    return count;
}

void insert_at_specific(node* &head, int pos, int val){
    node* new_node = new node(val);
    if(pos == 1){
        new_node -> next = head;
        head = new_node;
        return;
    }
    int count = 0;
    node* temp = head;
    while(count != pos - 2){
        temp = temp -> next;
        count++;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;


}

void search_in_unique(node* head, int value){
    int count = 1 ;

    bool found = false;
    int len = find_length(head);
    while(count <= len){
        if(head -> val == value){
            found = true;
            break;
        }
        head = head -> next;
        count++;
    }
    if(found == true){
        cout << "Number found at position: " << count << endl;
    }
    else cout << "Number not found" << endl;


}

duplicate_numbers search_in_duplicate(node* head, int key){
    int count = 1;
    int k = 1;
    duplicate_numbers t;
    node* temp = head;

    while(temp != NULL){
        if(temp -> val == key){
            t.arr[k] = count;
            k++;
        }
        temp = temp -> next;
        count++;
    }

    t.arr[0] = k;
    return t;

}


void deletion_at_head(node* &head){
    if(head == NULL) return;
    node* temp = head;
    head = head  -> next;
    delete temp;

}

void deletion_at_tail(node* &head){
    if(head == NULL) return;

    node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = NULL;
    delete(temp -> next);
}

void delete_at_specific(node* &head, int pos){
    if(head == NULL) return;
    if(pos == 1){
        node* del_node = head;
        head = head -> next;
        delete(del_node);
        return;
    }
    int count = 1;

    node* temp = head;
    while(count < pos-1){
        temp = temp -> next;
        count++;
    }

    node* del_node = temp -> next;
    temp -> next = del_node -> next;
    delete(del_node);
}

void reverse_non(node* &head){
    if(head == NULL) return;
    node* current = head;
    node* prev = NULL;
    node* next = NULL;

    while(current -> next != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    current -> next = prev;
    head = current;

}

node* reverse_recursive(node* &head){
    if(head -> next == NULL) return head;

    node* new_head = reverse_recursive(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}

int main(){
    node* head = NULL;
    int val;
   // cin >> val;

    insert_at_tail(head,5);
    insert_at_tail(head,15);
    insert_at_tail(head,25);
    insert_at_tail(head,55);
    insert_at_tail(head,555);

    print_list(head);
    head = reverse_recursive(head);
    print_list(head);

}

