/*
* =========================================================================================
* Name        : listLib.h
* Author      : Duc Dung Nguyen
* Email       : nddung@hcmut.edu.vn
* Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
* Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
* =========================================================================================
*/

#ifndef A01_LISTLIB_H
#define A01_LISTLIB_H

#include <string>
using namespace std;

class DSAException {
	int     _error;
	string  _text;
public:

	DSAException() : _error(0), _text("Success") {}
	DSAException(int err) : _error(err), _text("Unknown Error") {}
	DSAException(int err, const char* text) : _error(err), _text(text) {}

	int getError() { return _error; }
	string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
	T data;
	L1Item<T> *pNext;
	L1Item() : pNext(NULL) {}
	L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
	L1Item<T>   *_pHead;// The head pointer of linked list
	size_t      _size;// number of elements in this list
public:
	L1List() : _pHead(NULL), _size(0) {}
	~L1List();

	void    clean();
	bool    isEmpty() {
		return _pHead == NULL;
	}
	size_t  getSize() {
		return _size;
	}
	int count();
	T&      at(int i);
	T&      operator[](int i);

	bool    find(T& a, int& idx);
	int     insert(int i, T& a);
	int     remove(int i);

	int     push_back(T& a);
	int     insertHead(T& a);

	int     removeHead();
	int     removeLast();

	void    reverse(){
		struct node *p = _pHead, *q = NULL, *r;
		while (p != NULL)
		{
			r = q;
			q = p;
			p = p -> pNext;
			q->pNext = r;
		}
    q = _pHead;
	}
	void    traverse(void(*op)(T&)) {
		L1Item<T>   *p = _pHead;
		while (p) {
			op(p->data);
			p = p->pNext;
		}
	}
	void    traverse(void(*op)(T&, void*), void* pParam) {
		L1Item<T>   *p = _pHead;
		while (p) {
			op(p->data, pParam);
			p = p->pNext;
		}
	}
};

/// Insert item to the end of the list
/// Return 0 if success
template <class T>
int L1List<T>::push_back(T &a) {
	if (_pHead == NULL) {
		_pHead = new L1Item<T>(a);
	}
	else {
		L1Item<T>   *p = _pHead;
		while (p->pNext) p = p->pNext;
		p->pNext = new L1Item<T>(a);
	}

	_size++;
	return 0;
}

/// Insert item to the front of the list
/// Return 0 if success
template <class T>
int L1List<T>::insertHead(T &a) {
	L1Item<T>   *p = new L1Item<T>(a);
	p->pNext = _pHead;
	_pHead = p;
	_size++;
	return 0;
}

/// Remove the first item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeHead() {
	if (_pHead) {
		L1Item<T>* p = _pHead;
		_pHead = p->pNext;
		delete p;
		_size--;
		return 0;
	}
	return -1;
}

/// Remove the last item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeLast() {
	if (_pHead) {
		if (_pHead->pNext) {
			L1Item<T>* prev = _pHead;
			L1Item<T>* pcur = prev->pNext;
			while (pcur->pNext) {
				prev = pcur;
				pcur = pcur->pNext;
			}
			delete pcur;
			prev->pNext = NULL;
		}
		else {
			delete _pHead;
			_pHead = NULL;
		}
		_size--;
		return 0;
	}
	return -1;
}

template <class T>
bool L1List<T>::find(T& a, int& idx){
	while (idx != NULL){
		if (a == idx) {
			return true;
			break;
		}
		else return false;
	}
}

template <class T>
int L1List<T>::insert(int i, T& a){
	int k = 1;
	L1Item<T> c = new L1Item<T>;
	L1Item<T> *b = a;
	if (k == 1) insertHead(a);
	else{
		while (b != NULL && k != i - 1)
		{
			k++;
			b = b->pNext;
		}
		c->pNext = b->pNext;
		b->pNext = c;
	}
}

template <class T>
int L1List<T>::count(){
	int c = 0;
	L1List<T> *pRun;
	for (pRun = _pHead; pRun->pNext != NULL; pRun = pRun->pNext){
		c++
	}
	return c;
}

template <class T>
int L1List<T>::remove(int i){

}
#endif //A01_LISTLIB_H
