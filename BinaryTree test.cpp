#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
using namespace std;
int main() {
	cout << "Binary Tree :" <<endl;
	BinaryTree<int> a, x, y, z;
	y.MakeTree(5, a, a);
	z.MakeTree(3, a, a);
	x.MakeTree(1, y, z);
	y.MakeTree(2, x, a);
	// second max method
	cout << " Second Max: " << y.maxSecond() << endl;
	system("pause");
	return 0;
}
