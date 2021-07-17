#include<bits/stdc++.h>

using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class treeNode
{
public:
	int data;
	treeNode* left;
	treeNode* right;
	treeNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~treeNode(){
		delete left;
		delete right;
	}
	
};

class List{
    public:
    int data;
    List* next;
    
    //Constructor of List Class
    List(int data)
    {
        this->data = data;
        next = NULL;
    }
};

treeNode* builtTree(){

	// cout<<"\n Enter root :";
	int rootData;
	cin>>rootData;
	treeNode* root = new treeNode(rootData);

	queue<treeNode*> node;
	node.push(root);

	while(!node.empty()){

		treeNode* ptr = node.front();
		node.pop();

		int val;
		// cout<<"\n Enter Left of "<<ptr->data<<" :";
		cin>>val;

		if( val != -1){
			ptr->left = new treeNode(val);
			node.push(ptr->left);
		}

		// cout<<"\n Enter right of "<<ptr->data<<" :";
		cin>>val;

		if(val != -1){
			ptr->right = new treeNode(val);
			node.push(ptr->right);
		}

	}

	return root;
}



vector<List*> createList(treeNode* root){
    
    vector<List*> res;
    if(!root) return res;
    
    queue<treeNode* > node;
    node.push(root);
    
    while(!node.empty()){
        
        int count  = node.size();
        List* head = NULL;
        List* last = NULL;
        
        while(count--){
            treeNode* ptr = node.front();
            List* temp = new List(ptr->data);
            node.pop();
            
            if( head == NULL){
                head = temp;
                last = temp;
            }else{
                last->next = temp;
                last = temp;
            }
            
            if(ptr->left) node.push(ptr->left);
            
            if(ptr->right) node.push(ptr->right);
        }
        res.push_back(head);
    }
    
    return res;
}

void output(List* head){
    
    List* ptr = head;
    
    while(ptr){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    
}

void Display(vector<List*> res){
    
    for(int i = 0; i< res.size() ; i++){
        output(res[i]);
        cout<<"\n";
    }
}

int main(){

	treeNode* root = builtTree();	
	cout<<"\n Level Order LinkLIst : ";
	vector<List*> head = createList(root);
	Display(head);

	return 0;
}
