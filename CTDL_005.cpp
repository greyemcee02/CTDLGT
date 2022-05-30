#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class List{
	private:
		Node *first;
	public:
		List(){
			first = NULL;
		}
		Node *newNode(int value){
			Node *tmp = new Node();
			tmp->data = value;
			tmp->next = NULL;
			return tmp;
		}
		void push(int value){
			Node *p = newNode(value);
			if(first == NULL){
				first = p;
				first->next = NULL;
			}
			else{
				Node *tmp = first;
				while(tmp->next != NULL){
					tmp = tmp->next;
				}
				tmp->next = p;
				tmp = NULL;
				p = NULL;
			}
		}
		void out(){
			Node *tmp = first;
			while(tmp != NULL){
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
		}
		void Delete(int value){
			while(first != NULL && first->data == value){
				Node *tmp = first;
				first = tmp->next;
				delete(tmp);
				tmp = NULL;
			}
			Node *p = first;
			while(p != NULL){
				if(p->data == value){
					Node *tmp1 = p;
					Node *tmp = first;
					while(tmp->next != p){
						tmp = tmp->next;
					}
					tmp->next = p->next;
					p = tmp->next;
					delete(tmp1);
					tmp1 = NULL;
					tmp = NULL;
				}
				else p = p->next;
			}
		}
};

int main() {
	int n;
	cin >> n;
	int tmp;
	List list;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		list.push(tmp);
	}
	cin >> tmp;
	list.Delete(tmp);
	list.out();
	
	return 0;
}
