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
public:

	
	void search(string input);

	
	void search(string input, priority_queue<TYPE, vector<TYPE>, dataComparision> *pq);

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

//template<class TYPE, class KTYPE>
//void AvlTreeExt<TYPE, KTYPE>::_deleteLowFrequency(NODE<TYPE>* root, int frequency)
//{
//	if (root != NULL)
//	{
//		cout << "Currently at: " << root->data.key << endl;
//		bool shorter;
//		bool success;
//
//		NODE<TYPE>  *newRoot;
//
//		_deleteLowFrequency(root->left, frequency);
//
//		if (root->data.data <= frequency)
//		{
//			
//			cout << "Attemping to delete: " << root->data.key << endl;
//			newRoot = _delete(root, root->data.key, shorter, success);	
//
//			if (success)
//			{
//				cout << "Delete successful" << endl;
//				cout << root->data.key << " has been deleted" << endl;
//				tree = newRoot;
//				count--;
//				_deleteLowFrequency(tree, frequency);
//				return;
//			}
//		}
//
//		_deleteLowFrequency(root->right, frequency);
//	} //  if
//	return;
//}


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


