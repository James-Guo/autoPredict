#pragma once

#include <queue>
#include "AVL_ADT.h"

using namespace std;
struct DATA
{
	string key;
	int data;
};

struct dataComparision
{
	bool operator()(const DATA& a, const DATA& b) {
		return a.data<b.data;
	}
};

template <class TYPE, class KTYPE>
class AvlTreeExt: public AvlTree< TYPE, KTYPE>
{
public:

	void _traversal(NODE<TYPE>* root, string input);
	void search(string input);

	void _traversalSearch(NODE<TYPE>* root, string input, priority_queue<TYPE, vector<TYPE>, dataComparision> *pq);
	void search(string input, priority_queue<TYPE, vector<TYPE>, dataComparision> *pq);

	bool AVL_RetrieveInsert(KTYPE   key, TYPE& dataOut);
	
};

template <class TYPE, class KTYPE>
bool   AvlTreeExt<TYPE, KTYPE>
::AVL_RetrieveInsert(KTYPE   key, TYPE& dataOut)
{
	//	Local Definitions
	NODE<TYPE> *node;

	//	Statements 
	if (!tree)
		return false;

	node = _retrieve(key, tree);
	if (node)
	{
		node->data = dataOut;
		return true;
	} // if found
	else
		return false;
}	//  AVL_Retrieve 



template <class TYPE, class KTYPE>
void  AvlTreeExt<TYPE, KTYPE>
::search(string input)
{
	_traversal(tree, input);
}



template <class TYPE, class KTYPE>
void  AvlTreeExt<TYPE, KTYPE>
::_traversal(NODE<TYPE> *root, string input)
{
	//	Statements
	if (root)
	{

		_traversal(root->left, input);

		if (root->data.key.substr(0, input.length()) == input)
		{
			cout << root->data.key << endl;
		}

		_traversal(root->right, input);
	} //  if
	return;
}	//  _traversal


template<class TYPE, class KTYPE>
void AvlTreeExt<TYPE, KTYPE>::_traversalSearch(NODE<TYPE> *root, string input, priority_queue<TYPE, vector<TYPE>, dataComparision>* pq)
{
	//	Statements
	if(root)
	{
	
		_traversalSearch(root->left, input, pq);
	
		if (root->data.key.substr(0, input.length()) == input)
		{
			DATA data;
			data.key = root->data.key;
			data.data = root->data.data;
			pq->push(data);

		}
	
		_traversalSearch(root->right, input, pq);
	} //  if
	return;
}

template<class TYPE, class KTYPE>
void AvlTreeExt<TYPE, KTYPE>::search(string input, priority_queue<TYPE, vector<TYPE>, dataComparision>* pq)
{
	_traversalSearch(tree, input, pq);
}


