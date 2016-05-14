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
private:
	void _traversal(NODE<TYPE>* root, string input);
	void _traversalSearch(NODE<TYPE>* root, string input, priority_queue<TYPE, vector<TYPE>, dataComparision> *pq);
	void _deleteLowFrequency(NODE<TYPE>* root, int frequency);
	void _breadthFirstTraverse(void(*process)(TYPE dataProc), NODE<TYPE>* root);
public:

	
	void search(string input);

	
	void search(string input, priority_queue<TYPE, vector<TYPE>, dataComparision> *pq);

	void breadthFirstTraverse(void(*process)(TYPE dataProc));

	bool AVL_RetrieveInsert(KTYPE   key, TYPE& dataOut);
	

	
	void deleteLowFrequency(int frequency);
	void _traversal(NODE<TYPE>* root, int frequency, vector<DATA>& v);
	

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

template<class TYPE, class KTYPE>
void AvlTreeExt<TYPE, KTYPE>::deleteLowFrequency(int frequency)
{
	vector<DATA> deletionVector;
	_traversal(tree, frequency, deletionVector);
	for (int i = 0; i < deletionVector.size(); i++)
	{
		AVL_Delete(deletionVector[i].key);
	}
		


}



template <class TYPE, class KTYPE>
void  AvlTreeExt<TYPE, KTYPE>
::_traversal(NODE<TYPE> *root, int frequency, vector<DATA> &v)
{
	//	Statements
	if (root)
	{
		_traversal(root->left, frequency, v);

		if (root->data.data <= frequency)
		{
			DATA newItem;
			newItem.key = root->data.key;
			newItem.data = root->data.data;
			v.push_back(newItem);		
		}

		_traversal(root->right, frequency, v);
	} //  if
	return;
}	//  _traversal




template <class TYPE, class KTYPE>
void  AvlTreeExt<TYPE, KTYPE>
::search(string input)
{
	_traversal(tree, input);
}


// for finding words
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

template<class TYPE, class KTYPE>
void AvlTreeExt<TYPE, KTYPE>::breadthFirstTraverse(void(*process)(TYPE dataProc))
{
	_breadthFirstTraverse(process, tree);
}




template<class TYPE, class KTYPE>
void AvlTreeExt<TYPE, KTYPE>::_breadthFirstTraverse(void(*process)(TYPE dataProc), NODE<TYPE> *root)
{
	queue<NODE<DATA>*> q;

	if (root)
	{
		q.push(root);
		process(root->data);
	}
	else
		cout << "Tree is empty" << endl;

	while (!q.empty())
	{
		const NODE<TYPE>* const temp_node = q.front();
		q.pop();

		if (temp_node->left)
		{
			q.push(temp_node->left);
			process(temp_node->left->data);
	

		}


		if (temp_node->right)
		{
			q.push(temp_node->right);
			process(temp_node->right->data);

		}
	

	}




}