/**
 * \brief 所有文件公用的声明和引用
 */


#pragma once //老编译器不支持#pragma once，如：GCC 3.4之前版本

#ifndef HEAD_H //避免多个头文件相互包含而导致无限递归包含、或重复定义
#define HEAD_H


#define _CRT_SECURE_NO_WARNINGS //使程序兼容c指令


/**
* \brief 对 new 创建的内存统一化释放接口
* \equal to:  if (P != nullptr) {
				delete[] P;
				P = nullptr; } //释放内存后，务必要置空
*/
#ifndef SAFE_DELETE //#ifndef 解决头文件相互调用导致重定义的问题
#define SAFE_DELETE(P) {if(P) delete[](P);(P)=nullptr;}
#endif


#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>


using namespace std;
using namespace cv;


/** \brief 不同编译器或平台的基础类型位数不同；简洁方便；一眼就能辨认 */
typedef int8_t			int8;		// 有符号8位整数
typedef uint8_t			uint8;		// 无符号8位整数
typedef int16_t			int16;		// 有符号16位整数
typedef uint16_t		uint16;		// 无符号16位整数
typedef int32_t			int32;		// 有符号32位整数
typedef uint32_t		uint32;		// 无符号32位整数
typedef int64_t			int64;		// 有符号64位整数
typedef uint64_t		uint64;		// 无符号64位整数
typedef float			float32;	// 单精度浮点
typedef double			float64;	// 双精度浮点


/**
 * \brief 'cout' information's color in terminal
 * \usage   cout << RED"informationNeededToBePrinted" << endl;
 *          cout << RESET; //最后要记得清除所有格式   
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

