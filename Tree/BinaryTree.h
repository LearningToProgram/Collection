#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T> class BinaryTree {
public:
	BinaryTree( )		{ root = ( Node< T >* )0; }
	BinaryTree( T item )	{ root = new Node< T >( item ); }
	~BinaryTree( )		{ if ( root ) delete root; }

	void preorder ( );
	void inorder  ( );
	void postorder( );
	void DisplayTree();

	template <class U> class Node {
	public:
		Node( )			{ mLeft = mRight = ( Node* )0; }
		Node( T item )	{ mLeft = mRight = ( Node* )0; mData = item; }
		~Node( )		{ if ( mLeft ) delete mLeft; if ( mRight ) delete mRight; }

		void preorder( );
		void inorder( );
		void postorder( );

		Node *mLeft;
		Node *mRight;
		U mData;
	};
	Node< T > *root;
};

template< class T > void BinaryTree< T >::preorder( )
{
	if (root)	root->preorder();
}

template< class T > void BinaryTree< T >::inorder()
{
	if (root)	root->inorder();
}

template< class T > void BinaryTree< T >::postorder()
{
	if (root)	root->postorder();
}

template< class T >
template< class U >
void BinaryTree< T >::Node< U >::preorder()
{
	std::cout << mData << ", ";
	if ( mLeft )	mLeft->preorder( );
	if ( mRight ) mRight->preorder( );
}

template< class T >
template< class U >
void BinaryTree< T >::Node< U >::inorder( )
{
	if ( mLeft )	mLeft->inorder( );
	std::cout << mData << ", ";
	if ( mRight ) mRight->inorder( );
}

template< class T >
template< class U >
void BinaryTree< T >::Node< U >::postorder( )
{
	if ( mLeft )	mLeft->postorder( );
	if ( mRight )	mRight->postorder( );
	std::cout << mData << ", ";
}

template< class T >
void BinaryTree< T >::DisplayTree()
{
	BinaryTree< T > tree( 'K' );
	tree.root->mLeft = new BinaryTree< T >::Node< T >( 'I' );
	tree.root->mRight = new BinaryTree< T >::Node< T >( 'M' );

	std::cout << "Preorder: ";
	tree.preorder();

	std::cout << std::endl;
	std::cout << "Inorder: ";
	tree.inorder();
	std::cout << std::endl;
	std::cout << "Postorder: ";
	tree.postorder();
	std::cout << std::endl;
}

#endif
