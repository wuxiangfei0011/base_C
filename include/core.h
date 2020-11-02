/**
 * \brief ������ SortParcle �����г�Ա
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
		/** \brief ��ʼ�����г�Ա��������������new������SorParcle���飬��һ��Ҫд�޲ι��� */
		SortParcle();
		
		/** \brief ��ʹ�� Reset() �ͷ��ڴ棬������������ҲҪ���ڴ��ͷ� */
		~SortParcle();

		/** \brief �����ṹ�壺��ͬ����ֵ���㷨�в�ͬ��ִ��Ч������Ҫ����Ӧ�ó���ȷ������ֵ�� */
		struct sortOption {
			// P1,P2 
			// P2 = P2_int / (Ip-Iq)
			int32  p1;				// �ͷ������P1
			int32  p2_int;			// �ͷ������P2

			sortOption() : p1(10), p2_int(150) {}
		};

		//Ϊ�������еı���Ԥ�趨����ֵ������Ա���������ֲ�����ֵ������Ԥ����ɸ��õ��ڴ�飨�����鿪���ڴ�ռ䲢��ʼ����
		bool Initialize(const uint32& width, const uint32& height);

		//�㷨���ĺ�����ʹ��ǰ��ҪԤ�ȿ�����Ӧ�ڴ棩
		bool Core(const uint8* img_left, const uint8* img_right, float32* disp_left);

		//��ͼ��ߴ硢ĳЩ�������̶�����Ŀ�У���Ҫ�ṩ�ӿ����޸�ͼ��ߴ���������һЩԤ������
		//��������֮ǰ����Ҫ��֮ǰ������ڴ�ռ䶼���������Ȼ������ڴ�й©������ �������ڴ� + ��ʼ���� ����
		bool Reset(const uint32& width, const uint32& height, const sortOption& option);

		/** \brief �ͷ����� new ��Ա�����ڴ� */
		void FreeMemory();
		
	private:
		//�㷨��һЩ�ӵ��ú�����ȫ������const���ڱ�������ֻ�ܶ�ȡ��Ա�������������޸�
		/** \brief Census�任 */
		void CensusTransform() const;

		//��Ա����ȫ��˽�л��������Ҫ��ȡ/����ĳ����Ա��ֵ������ͨ�����ӹ��еĳ�Ա����get/set����ȡ��������

		/** \brief Ӱ���	 */
		int32 width_;

		/** \brief ��Ӱ������	 */
		const uint8* img_left_;//const: �ڵ���ʱ�� = ָ�볣������������Ҫconst;����ָ�루�������α������ͣ�����ַ�е�ֵ���ܸģ���ַ�ɸ�

		/** \brief ��Ӱ��censusֵ	*/
		void* census_left_; //void* ���Խ����κ�����

		void* disp_left_;
		
		/** \brief ��ʼƥ�����	*/
		uint8* cost_init_;
		bool is_initialized_;

		/** \brief ��ƥ�������ؼ�	*/
		std::vector<std::pair<int, int>> mismatches_;

	};

}


#endif // !SORTE_H


