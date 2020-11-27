#include<iostream>
#include<string>
using namespace std;

template<class Comparable>
class BinarySearchTree;

template<class Comparable>
class BinaryNode {
	Comparable element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const Comparable & theElement,
		BinaryNode *lt, BinaryNode *rt) :
		element(theElement), left(lt), right(rt){}

	friend class BinarySearchTree<Comparable>;
};

template<class Comparable>
class BinarySearchTree {
public:
	explicit BinarySearchTree(const Comparable & notFound);
	~BinarySearchTree();

	const Comparable & findMin() const;
	const Comparable & findMax() const;
	const Comparable & find(const Comparable & x) const;

	bool isEmpty() const;
	void printTree() const;
	void printPost() const;
	void printPre() const;
	void makeEmpty();

	void insert(const Comparable & x);
	void remove(const Comparable & x);
	const BinarySearchTree & operator=(const BinarySearchTree & rhs);

private:
	BinaryNode <Comparable> *root;
	Comparable ITEM_NOT_FOUND;
	const Comparable & elementAt(BinaryNode<Comparable> *t) const;

	void insert(const Comparable & x, BinaryNode<Comparable> * & t) const;
	void remove(const Comparable & x, BinaryNode<Comparable> * & t) const;

	BinaryNode<Comparable> * findMin(BinaryNode<Comparable> *t) const;
	BinaryNode<Comparable> * findMax(BinaryNode<Comparable> *t) const;
	BinaryNode<Comparable> * find(const Comparable & x, BinaryNode<Comparable> *t) const;

	void makeEmpty(BinaryNode<Comparable> * & t) const;
	void printTree(BinaryNode<Comparable> *t) const;
	void printPost(BinaryNode<Comparable> *t) const;
	void printPre(BinaryNode<Comparable> *t) const;

	BinaryNode<Comparable> * clone(BinaryNode<Comparable> *t) const;
};

template<class Comparable>
BinarySearchTree<Comparable> ::
BinarySearchTree(const Comparable & notFound)
{
	root = NULL;
	ITEM_NOT_FOUND = notFound;
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
insert(const Comparable & x)
{
	insert(x, root);
}

template<class Comparable> void BinarySearchTree<Comparable> ::
insert(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	if (t == NULL)
		t = new BinaryNode<Comparable>(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else ;
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
printPost() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printPost(root);
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
printPre() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printPre(root);
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
printTree(BinaryNode<Comparable> *t) const
{
	if (t != NULL)
	{
		printTree(t->left);
		cout << t->element << " ";
		printTree(t->right);
	}
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
printPost(BinaryNode<Comparable> *t) const
{
	if (t != NULL)
	{
		printPost(t->left);
		printPost(t->right);
		cout << t->element << " ";
	}
}

template<class Comparable>
void BinarySearchTree<Comparable> ::
printPre(BinaryNode<Comparable> *t) const
{
	if (t != NULL)
	{
		cout << t->element << " ";
		printPre(t->left);
		printPre(t->right);
	}
}

template<class Comparable>
const Comparable & BinarySearchTree<Comparable> ::
elementAt(BinaryNode<Comparable> *t) const
{
	if (t == NULL) return ITEM_NOT_FOUND;
	else return t->element;
}

template<class Comparable>
const Comparable & BinarySearchTree<Comparable> ::
find(const Comparable & x) const
{
	return elementAt(find(x, root));
}

template<class Comparable>
BinaryNode<Comparable> *BinarySearchTree<Comparable>::
find(const Comparable & x, BinaryNode<Comparable> *t) const
{
	if (t == NULL) return NULL;
	else if (x < t->element)
		return find(x, t->left);
	else if (t->element < x)
		return find(x, t->right);
	else
		return t;
}

template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::
findMin() const
{
	return elementAt(findMin(root));
}

template<class Comparable>
BinaryNode<Comparable> *BinarySearchTree<Comparable>::
findMin(BinaryNode<Comparable> *t) const
{
	if (t == NULL) return NULL;
	if (t->left == NULL) return t;
	return findMin(t->left);
}

template<class Comparable>
const Comparable & BinarySearchTree<Comparable>::
findMax() const
{
	return elementAt(findMax(root));
}

template<class Comparable>
BinaryNode<Comparable> *BinarySearchTree<Comparable>::
findMax(BinaryNode<Comparable> *t) const
{
	if (t != NULL)
	while (t->right != NULL)
		t = t->right;
	return t;
}

template<class Comparable>
void BinarySearchTree<Comparable>::
remove(const Comparable & x)
{
	remove(x, root);
}

template<class Comparable>
void BinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	if (t == NULL) return;
	if (x < t->element) remove(x, t->left);
	else if (t->element < x) remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) {
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else {
		BinaryNode <Comparable> *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
}

template<class Comparable>
BinarySearchTree<Comparable>::
~BinarySearchTree()
{
	makeEmpty();
}

template<class Comparable>
void BinarySearchTree<Comparable>::
makeEmpty()
{
	makeEmpty(root);
}

template<class Comparable>
void BinarySearchTree<Comparable>::
makeEmpty(BinaryNode<Comparable> * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

template<class Comparable>
bool BinarySearchTree<Comparable> ::
isEmpty() const
{
	return root == NULL;
}