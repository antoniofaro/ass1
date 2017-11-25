/*
* =========================================================================================
* Name        : processData.cpp
* Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
* =========================================================================================
*/
#include "eventLib.h"
#include "dbLib.h"
#include "listLib.h"

template <class T>
struct L1Process {
	T data;
	L1Process<T> *pNext;
};

template <class T>
class L1List {
	L1Process<T>   *_pHead;// The head pointer of linked list
public:
	int event00();
	int event01();
	int event02();
	int event03();
	int event04();

//Mã yêu cầu 00: Danh sách mã yêu cầu trong tập tin events.txt
template <class T>
int L1List<T>::event00(){
	int count = 0;
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
	for (pRun = _pHead; pRun->pNext == NULL; pRun = pRun->pNext){
		count++;
	}
	return count;
}

//Mã yêu cầu 01: Số hiệu ninja được lưu trữ đầu tiên
template <class T>
int L1List<T>::event01(){
	return _pHead->data.id;
}

//Mã yêu cầu 02: Số hiệu ninja được lưu trữ cuối cùng
template <class T>
int L1List<T>::event02(){
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
	for (pRun = _pHead; pRun->pNext == NULL; pRun = pRun->pNext){
		if (pRun->pNext == NULL) return pRun->data.id;
	}
}

 //Mã yêu cầu 03: Số phần tử tham gia cuộc thi
template <class T>
int L1List<T>::event03(){
	int count = 0;
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
	for (pRun = _pHead; pRun->pNext == NULL; pRun = pRun->pNext){
		if (pRun->data.id != pRun->pNext->data.id)
			count++;
	}
	return count;
}

 //Mã yêu cầu 04: Số hiệu lớn nhất của ninja tham gia cuộc thi
template <class T>
int L1List<T>::event04(){
	int max = _pHead->data.id;
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
	for (pRun = _pHead; pRun->pNext == NULL; pRun = pRun->pNext){
		if (pRun->data.id == max)
			max = pRun->data.id;
	}
	return max;
}

template <class T>
bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList) {	
	pRun = _pHead;
	while (pRun->pNext != NULL){
		if (pRun->data == 0){
			event00();
			pRun = pRun->pNext;
		}
		else if (pRun->data == 1){
			event01();
			pRun = pRun->pNext;
		}
		else if (pRun->data == 2){
			event02();
			pRun = pRun->pNext;
		}
		else if (pRun->data == 3){
			event01();
			pRun = pRun->pNext;
		}
		else if (pRun->data == 4){
			event04();
			pRun = pRun->pNext;
		}
		//else if ((pRun->data) % 10000 == 5){
		//	event05();
		//	pRun = pRun->pNext;
		//}
	}

	// TODO: Your code comes here

	/// NOTE: The output of the event will be printed on one line
	/// end by the endline character.
	return true;
}

/* Class1: Time (Ngày, tháng, năm, giờ, phút, giây)
*/