/**
 * \brief �����ļ����õ�����������
 */


#pragma once //�ϱ�������֧��#pragma once���磺GCC 3.4֮ǰ�汾

#ifndef HEAD_H //������ͷ�ļ��໥�������������޵ݹ���������ظ�����
#define HEAD_H


#define _CRT_SECURE_NO_WARNINGS //ʹ�������cָ��


/**
* \brief �� new �������ڴ�ͳһ���ͷŽӿ�
* \equal to:  if (P != nullptr) {
				delete[] P;
				P = nullptr; } //�ͷ��ڴ�����Ҫ�ÿ�
*/
#ifndef SAFE_DELETE //#ifndef ���ͷ�ļ��໥���õ����ض��������
#define SAFE_DELETE(P) {if(P) delete[](P);(P)=nullptr;}
#endif


#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>


using namespace std;
using namespace cv;


/** \brief ��ͬ��������ƽ̨�Ļ�������λ����ͬ����෽�㣻һ�۾��ܱ��� */
typedef int8_t			int8;		// �з���8λ����
typedef uint8_t			uint8;		// �޷���8λ����
typedef int16_t			int16;		// �з���16λ����
typedef uint16_t		uint16;		// �޷���16λ����
typedef int32_t			int32;		// �з���32λ����
typedef uint32_t		uint32;		// �޷���32λ����
typedef int64_t			int64;		// �з���64λ����
typedef uint64_t		uint64;		// �޷���64λ����
typedef float			float32;	// �����ȸ���
typedef double			float64;	// ˫���ȸ���


/**
 * \brief 'cout' information's color in terminal
 * \usage   cout << RED"informationNeededToBePrinted" << endl;
 *          cout << RESET; //���Ҫ�ǵ�������и�ʽ   
 */
#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m" /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m" /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m" /* Cyan */
#define WHITE "\033[37m" /* White */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define BOLDRED "\033[1m\033[31m" /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m" /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m" /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m" /* Bold White */
 

#endif // !HEAD_H

