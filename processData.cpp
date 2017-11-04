/*
* =========================================================================================
* Name        : processData.cpp
* Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
* =========================================================================================
*/
#include "eventLib.h"
#include "dbLib.h"
#include "listLib.h"

class REPORT_TIME{
public:
	int day, month, year, sec, min, hour;
};

class NinjaData{
public:
	REPORT_TIME TIME;
	float LONGITUDE;
	float LATITUDE;
	float SPEED;
};

//Mã yêu cầu 1: Dem so phan tu trong events.txt
// Dùng hàm ()atof() chuyển dữ liệu trong file events.txt từ string sang L1List<ninjaEvent_t>
// For (i=_head; i->next=NULL; i = i->next){ count++; return i;}
template <class T>
int traverse_events(){
	L1List<ninjaEvent_t> &pTra;
	int count = 0;
	char *fileName;
	void d = loadEvents(fileName, pTra);
	for (pTra = _pHead; pTra->next = NULL; pTra = pTra->next){
		count++;
	}
	return count;
}


//Mã yêu cầu 2: Xuất ra phần tử đầu tiên trong data.csv
template <class T>
int first_pHead(){
	if (_pHead != NULL && _size == 1)
		return _pHead; 
}


//Mã yêu cầu 3: Tìm ra số hiệu ninja max trong data.csv
bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList) {
	
	// Mở và đọc file events.txt và data.csv
	/*char *fName1 = "events.txt";
	char *fName2 = "data.csv";
	L1List<NinjaInfo_t> &db, &de;
	loadNinjaDB(fName1, db);
	loadEvents(fName1, db);
	loadNinjaDB(fName2, de);
	loadEvents(fName2, de);*/


	//Mã yêu cầu 1: Dem so phan tu trong events.txt

	
	//Mã yêu cầu 3: Tìm ra số hiệu ninja max trong data.csv
	

	// TODO: Your code comes here

	/// NOTE: The output of the event will be printed on one line
	/// end by the endline character.
	return true;
}

/* Class1: Time (Ngày, tháng, năm, giờ, phút, giây)
*/