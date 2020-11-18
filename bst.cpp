#include <bits/stdc++.h> 
using namespace std; 
  
//  struktur penghubung
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// fungsi untuk membuat simpul dari BST / penghubung 
struct node *newNode(int item) 
{ 
    struct node *temp =  new node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// fungsi untuk membuat preorder traversal dari BST 
void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        cout << root->key << " "; 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
  
//  fungsi untuk membuat pohon akar 
vector<struct node *> constructTrees(int start, int end) 
{ 
    vector<struct node *> list; 
  
    /*  jika start > end , akar pohon akan kosong/tidak ada */
    if (start > end) 
    { 
        list.push_back(NULL); 
        return list; 
    } 
  
    /*  mengiterasi semua nilai dari awal sampai akhir untuk membuat akar pohon kanan dan kiri secara rekursif  */
    for (int i = start; i <= end; i++) 
    { 
        /*  membuat struktur akar pohon kiri   */
        vector<struct node *> leftSubtree  = constructTrees(start, i - 1); 
  
        /*  membuat struktur akar pohon kanan  */
        vector<struct node *> rightSubtree = constructTrees(i + 1, end); 
  
        /*  loop smua dari kanan ke kiri dan gabungkan ke akar  */
        for (int j = 0; j < leftSubtree.size(); j++) 
        { 
            struct node* left = leftSubtree[j]; 
            for (int k = 0; k < rightSubtree.size(); k++) 
            { 
                struct node * right = rightSubtree[k]; 
                struct node * node = newNode(i);// value i sebagai akar 
                node->left = left;              // menghubungkan akar pohon kiri 
                node->right = right;            // menghubungkan akar pohon kanan
                list.push_back(node);           // masukkan kedalam list
            } 
        } 
    } 
    return list; 
} 
  
// Menjalankan Program
int main() 
{ 
	int t;
	cin >> t;
	for(int x = 0; x < t; x++){
		int n;
		cin >> n;
    // Menghitung semua kemungkinan BST
    	vector<struct node *> totalTreesFrom1toN = constructTrees(1, n); 
		cout << "Case #" << x+1 << ":" << "\n";
    	for (int i = 0; i < totalTreesFrom1toN.size(); i++) 
    	{ 
        	preorder(totalTreesFrom1toN[i]); 
        	cout << "\n";
    	}
	}
    return 0; 
} 
