
#include <vector>
#include <iostream>
#include <functional>
#include <memory>
#include <queue>
#include <string>


using namespace std;
// Create binary tree with preorder algorithm
// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

//Create binary tree starting with nodes
template<typename K, typename V, typename Compare = std::less<K>>
        class binary_search_tree {
            struct Node;
            using item_t = pair<K, V>;
            using shared_ptr_t = shared_ptr<Node>;
            using weak_ptr_t = weak_ptr<Node>;

            struct Node {
                pair<K, V> item;
                shared_ptr<Node> left;
                shared_ptr<Node> right;
                weak_ptr<Node> parent;

                Node(item_t item, shared_ptr_t parent) :
                        item(item), parent(parent) {}

            };

            shared_ptr_t root;
            Compare cmp;

            template<typename Callable>
            void _in_order(Node *node, Callable& fun) {
                    if(node == nullptr){
                        return;
                    }
                    _in_order(node->left.get(), fun);
                    fun(node->item);
                    _in_order(node->right.get(), fun);
            }


        public:
            binary_search_tree() = default;
            //insert
            void insert(item_t item) {
                if (root == nullptr) {
                    root = make_shared<Node>(item, nullptr);
                }
                auto current = root;
                while(current){ //existe
                    if(cmp(item.first, current->item.first)){
                        if(!current->left){ // si no existe ya un valor a la izquierda
                            current->left = make_shared<Node>(item, current);
                            break; //para terminar el while
                        }
                            else{
                                current = current->left;
                            }
                        }
                    else{
                        if(!current->right){
                            current->right = make_shared<Node>(item, current);
                            break;
                        }
                        else{
                            current = current->right;
                        }
                    }
                }
            }

            //Breadth first search (BFS)
            //https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
            template<typename Callable>
            void bfs(const Callable& fun){
                //Crear queue
                queue<shared_ptr_t> q;
                //Realizar push del root
                q.push(root);
                //Mientras el queue no este vacio
                while(!q.empty()){
                    //Obtener front
                    auto current = q.front();
                    fun(current->item);
                    //Realizar pop
                    q.pop();
                    //Agregar todos los hijos al queue del nodo extraido
                    if(current->left) q.push(current->left);
                    if (current->right) q.push(current->right);


                }
            }

            template<typename Callable>
            void in_order(const Callable& fun) {
                _in_order(root.get(),fun);

            }

        };

int main(){
    binary_search_tree<int,string> bst;
    bst.insert({40,"B"});
    bst.insert({20,"A"});
    bst.insert({10,"A"});
    bst.insert({30,"A"});
    bst.insert({50,"A"});
    bst.insert({60,"A"});

    bst.in_order([](auto item){
        cout << item.first << "  " << item.second << endl;
    });

    cout << "BFS" << endl;
    bst.bfs([](auto item){
        cout << item.first << "  " << item.second << endl;
    });

    return 0;
}