
#include <vector>
#include <iostream>
#include <functional>
#include <memory>
#include <queue>


using namespace std;
// Create binary tree with preorder algorithm
// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

//Create binary tree starting with nodes
template<typename K, typename V, typename Compare = std::less<K>>
        class binary_search_tree{
            struct Node;
            using item_t = pair<K, V>;
            using shared_ptr = shared_ptr<Node>;

            struct Node{
                pair<K, V> item;
                shared_ptr<Node> left;
                shared_ptr<Node> right;
                weak_ptr<Node> parent;

               Node(pair<K, V> item, weak_ptr<Node> parent):
                item(item), parent(parent){}

            };

            shared_ptr root;
            Compare cmp;
        public:
            binary_search_tree() = default;
            //insert
            void insert(const item_t& item) {
                if (!root) {
                    root = make_shared<Node>(item, nullptr);
                }
                auto current = root;

                while(current){ //existe
                    if(cmp(item.first, current->item.first)){
                        if(current->left == false){ // si no existe ya un valor a la izquierda
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
                    fun(current);
                    //Realizar pop
                    q.pop();
                    //Agregar todos los hijos al queue del nodo extraido
                    if(current->left) q.push(current->left);
                    if (current->right) q.push(current->right);


                }
            }


        };