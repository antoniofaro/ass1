/*
* =========================================================================================
* Name        : processData.cpp
* Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
* =========================================================================================
*/
#include "eventLib.h"
#include "dbLib.h"
#include "listLib.h"

//Mã yêu cầu 00: Danh sách mã yêu cầu trong tập tin events.txt
template <class T>
int event00(){
	loadEvents("events.txt", L1List<ninjaEvent_t> &eList);
	int count = 0;
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
	for (pRun = _pHead; pRun->pNext == NULL; pRun = pRun->pNext){
		count++;
	}
	return count;
}

//Mã yêu cầu 01: Số hiệu ninja được lưu trữ đầu tiên
template <class T>
int event01(){
	loadNinjaDB("data.csv", L1List<NinjaInfo_t> &db);
	parseNinjaInfo(char* pBuf, NinjaInfo_t& nInfo);
	return _pHead->data.id;
}

//Mã yêu cầu 02: Số hiệu ninja được lưu trữ cuối cùng
template <class T>
int event02(){
	loadNinjaDB("data.csv", L1List<NinjaInfo_t> &db);
	parseNinjaInfo(char* pBuf, NinjaInfo_t& nInfo);
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
	for (pRun = _pHead; pRun->pNext == NULL; pRun = pRun->pNext){
		if (pRun->pNext == NULL) return pRun->data.id;
	}
}

 //Mã yêu cầu 03: Số phần tử tham gia cuộc thi
template <class T>
int event03(){
	loadNinjaDB("data.csv", L1List<NinjaInfo_t> &db);
	parseNinjaInfo(char* pBuf, NinjaInfo_t& nInfo);
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
int event04(){
	loadNinjaDB("data.csv", L1List<NinjaInfo_t> &db);
	parseNinjaInfo(char* pBuf, NinjaInfo_t& nInfo);
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
	loadEvents("events.txt", L1List<ninjaEvent_t> &eList);
	L1List<NinjaInfo_t> *pRun = new L1List<NinjaInfo_t>;
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