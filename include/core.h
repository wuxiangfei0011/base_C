/**
 * \brief 包含类 SortParcle 的所有成员
 */


#pragma once

#ifndef SORTE_H
#define SORTE_H


#include "../include/public.hpp"


namespace sre //sre: sort
{
	class SortParcle
	{
	public:
		/** \brief 初始化所有成员变量，若工程中new开辟了SorParcle数组，则一定要写无参构造 */
		SortParcle();
		
		/** \brief 即使有 Reset() 释放内存，但是析构函数也要对内存释放 */
		~SortParcle();

		/** \brief 参数结构体：不同参数值对算法有不同的执行效果（需要根据应用场景确定最优值） */
		struct sortOption {
			// P1,P2 
			// P2 = P2_int / (Ip-Iq)
			int32  p1;				// 惩罚项参数P1
			int32  p2_int;			// 惩罚项参数P2

			sortOption() : p1(10), p2_int(150) {}
		};

		//为类中所有的变量预设定参数值（给成员变量、各种参数赋值）；和预分配可复用的内存块（给数组开辟内存空间并初始化）
		bool Initialize(const uint32& width, const uint32& height);

		//算法核心函数（使用前需要预先开辟相应内存）
		bool Core(const uint8* img_left, const uint8* img_right, float32* disp_left);

		//在图像尺寸、某些参数不固定的项目中，需要提供接口来修改图像尺寸来重新做一些预备工作
		//但是在做之前我们要把之前分配的内存空间都清理掉，不然会出现内存泄漏。就是 “清理内存 + 初始化” 两步
		bool Reset(const uint32& width, const uint32& height, const sortOption& option);

		/** \brief 释放所有 new 成员变量内存 */
		void FreeMemory();
		
	private:
		//算法的一些子调用函数；全都用了const：在本函数中只能读取成员变量，而不能修改
		/** \brief Census变换 */
		void CensusTransform() const;

		//成员变量全部私有化，如果需要获取/设置某个成员的值，可以通过增加公有的成员函数get/set来获取或者设置

		/** \brief 影像宽	 */
		int32 width_;

		/** \brief 左影像数据	 */
		const uint8* img_left_;//const: 在调用时候 = 指针常量，所有这里要const;常量指针（常量修饰变量类型）：地址中的值不能改，地址可改

		/** \brief 左影像census值	*/
		void* census_left_; //void* 可以接收任何类型

		void* disp_left_;
		
		/** \brief 初始匹配代价	*/
		uint8* cost_init_;
		bool is_initialized_;

		/** \brief 误匹配区像素集	*/
		std::vector<std::pair<int, int>> mismatches_;

	};

}


#endif // !SORTE_H


