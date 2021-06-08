#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


namespace ariel{

    template<class T> 

    class BinaryTree{

        protected:
        class Node{

            T val;
            Node *left, *right;

            Node(T value):val(value), left(nullptr), right(nullptr){}

            Node(Node &other):val(other.val), left(nullptr), right(nullptr){ 
                if(other.left!=nullptr){
                    this->left=new Node(*other.left);
                }
                if(other.right!=nullptr){
                    this->right=new Node(*other.right);
                }
            }

            Node(Node &&other) noexcept{
                this->val=other.val;
                this->left=other.left;
                this->right=other.right;
                other.left=other.right = nullptr;
            }

            Node &operator=(Node other){
                if(this==other){
                    return *this;
                }
                if(left!=nullptr){
                    delete left;
                }
                if(right!=nullptr){
                    delete right;
                }
                left=new Node(*other.left);
                right=new Node(*other.right);
                return *this;
            }

            Node &operator=(Node &&other) noexcept{
                if(left!=nullptr){
                    delete left;
                }
                if(right!=nullptr){
                    delete right;
                }
                this->left=other.left;
                this->right=other.right;
                this->val=other.val;
                other.left=other.right=nullptr;
                return *this;
            }

            ~Node(){
                if(this->left!=nullptr){
                    delete(this->left);
                }
                if(this->right!=nullptr){
                    delete(this->right);
                }
            }
            friend class BinaryTree;
        };


        private:
        Node *root;

        public:
        BinaryTree():root(nullptr){}

        BinaryTree(const BinaryTree &other):root(new Node(*other.root)){}

        BinaryTree &operator=(BinaryTree other){
            if(this==&other){
                return *this;
            }
            delete(this->root);
            root=new Node(*other.root);
            return *this;
        }

        BinaryTree &operator=(BinaryTree &&other) noexcept{
            delete(this->root);
            root=other.root;
            other.root=nullptr;
            return *this;
        }

        BinaryTree(BinaryTree &&other) noexcept{
            root=other.root;
            other.root=nullptr;
        }

        ~BinaryTree(){
            if(this->root!=nullptr){
                delete root;
            }
        }

        BinaryTree<T> &add_root(T value){
            if(root==nullptr){
                root=new Node(value);
            }
            root->val=value;
            return *this;
        }

        Node *search_node(Node *n ,T value){
            if(n==nullptr || n->val==value){ 
                return n;
            }
            //search in the left subtree
            Node *ans=search_node(n->left, value);
            if(ans==nullptr){
                return search_node(n->right, value); //search in the right subtree
            }
            return ans;
        }

        BinaryTree<T> &add_left(T parent, T left_son){
            Node *n=search_node(root, parent);
            if(n==nullptr){
                throw invalid_argument{"Error: node doesn't exist"};
            }
            if(n->left!=nullptr){
                n->left->val=left_son;
                return *this;
            }
            n->left=new Node(left_son);
            return *this;
        }

        BinaryTree<T> &add_right(T parent, T right_son){
            Node *n=search_node(root, parent);
            if(n==nullptr){
                throw invalid_argument{"Error: node doesn't exist"};
            }
            if(n->right!=nullptr){
                n->right->val=right_son;
                return *this;
            }
            n->right=new Node(right_son);
            return *this;
        }

        
        //left->root->right
        class in_order{  

            private:
            Node *node;
            stack<Node *> s;
            queue<Node *> q;

            public:
            in_order(Node *ptr=nullptr):node(ptr){
                if(node==nullptr){
                    return;
                }
 
                while(node!=nullptr || s.empty()==false){
                    //reach the left most node of the curr node 
                    while(node!=nullptr){
                        s.push(node);
                        node=node->left;
                    }
            
                    //curr node is NULL
                    node=s.top();
                    q.push(node);
                    s.pop();

                    //we have visited the node & its left subtree. Now, it's right subtree's turn 
                    node=node->right;
                }
                q.push(nullptr);
                node=q.front();
                q.pop();
            }

            T &operator *() const{
                return node->val;
            }
            
            T *operator ->() const{ 
                return &(node->val);
            }

            in_order &operator ++ (){ //++i
                if(!q.empty()){
                    this->node=q.front();
                    q.pop();
                }
                return *this;
            }

            in_order operator ++ (int){ //i++
                in_order tmp=*this;
                this->node=q.front();
                q.pop();
                return tmp;
            }
            
            bool operator == (const in_order &other) const{
                return node==other.node;
            }			

            bool operator != (const in_order &other) const{
                return node!=other.node;
            }
        };

        //root->left->right
        class pre_order{

            private:
            Node *node;
            stack<Node*> s;
            queue<Node*> q;

            public:
            pre_order(Node *ptr=nullptr):node(ptr){
                if(node==nullptr){
                    return;
                }

                s.push(node);
              
                while(s.empty()==false){
                    node=s.top();
                    q.push(node);
                    s.pop();
            
                    //push the right & left children of the node to the stack
                    if(node->right){
                        s.push(node->right);
                    }
                    if(node->left){
                        s.push(node->left);
                    }
                }
                q.push(nullptr);
                node=q.front();
                q.pop();
            }

            T &operator *() const{
                return node->val;
            }

            T *operator ->() const{ 
                return &(node->val);
            }

            pre_order &operator ++ (){ //++i
                if(!q.empty()){
                    this->node=q.front();
                    q.pop();
                }
                return *this;
            }

            pre_order operator ++ (int){ //i++
                pre_order tmp=*this;
                this->node=q.front();
                q.pop();
			    return tmp;
            }

            bool operator == (const pre_order &other) const{
                return node==other.node;
            }			

            bool operator != (const pre_order &other) const{
                return node!=other.node;
            }
        };


        //left->right->root
        class post_order{

            private:
            Node *node;
            stack<Node *> s1, s2;
            queue<Node *> q;

            public:
            post_order(Node *ptr=nullptr):node(ptr){
                if(node==nullptr){
                    return;
                }

                //push root to s1
                s1.push(node);
            
                while(!s1.empty()){
                    //pop an item from s1 & push it to s2
                    node=s1.top();
                    s1.pop();
                    s2.push(node);
            
                    //push left & right children to s1
                    if(node->left){
                        s1.push(node->left);
                    }
                    if(node->right){
                        s1.push(node->right);
                    }
                }
            
                //push all elements of s2 to q
                while(!s2.empty()) {
                    node = s2.top();
                    q.push(node);
                    s2.pop();
                }
                q.push(nullptr);
                node=q.front();
                q.pop();
            }

            T &operator *() const{
                return node->val;
            }

            T *operator ->() const{ 
                return &(node->val);
            }

            post_order &operator ++ (){ //++i
                if(!q.empty()){
                    this->node=q.front();
                    q.pop();
                }
                return *this;
            }

            post_order operator ++ (int){ //i++
                post_order tmp=*this;
                node=q.front();
                q.pop();
                return tmp;
            }

            bool operator == (const post_order &other) const{
                return node==other.node;
            }			

            bool operator != (const post_order &other) const{
                return node!=other.node;
            }
        };


        in_order begin_inorder(){
            return in_order(root);
        }

        in_order end_inorder(){
            return (nullptr);
        }

        in_order begin() const{
            return in_order(root);
        }

        in_order end() const{
            return (nullptr);
        }

        pre_order begin_preorder() const{
            return pre_order(root);   
        }

        pre_order end_preorder() const{
            return (nullptr);
        }

        post_order begin_postorder() const{
            return post_order(root);
        }

        post_order end_postorder() const{
            return (nullptr);
        }
    
        friend std::ostream &operator<<(std::ostream &out, const BinaryTree &bt){
            out << "\nMy binary tree:\n" << endl;
            bt.show("", bt.root, true);
            return out; 
        }
       
        void show(const string &prefix, const Node *node, bool isLeft) const{
            if(node!=nullptr){
                cout << (isLeft ? prefix+"├──" : prefix+"└──" );
                cout << node->val << endl;

                show(prefix + (isLeft ? "│   " : "    "), node->right, true);
                show(prefix + (isLeft ? "│   " : "    "), node->left, false);
            }
        }
    };
}