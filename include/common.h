/**
 * \brief ���������ļ������õ��Ĺ�ͬ����
 */


#pragma once

#ifndef GENERAL_H //���� #pragma once����һ�����ʡȥ���ڴ󹤳�������� #pragma once �Ϻ�ʱ
#define GENERAL_H


#include "../include/public.hpp"


/**
 * \brief �ؼ�֡
 * \note  there is vector in FRAME, if you transfer a longer vector to small, there will be truncated (err)
 */
struct FRAME {
    int frameID;
    Mat rgb, depth;
    Mat descriptors;
    vector<KeyPoint> keypoints;
};

/**
 * \brief �� YML �ж�ȡ�Ĳ���
 */
struct PARAMETER {

};

/**
 * \brief ��ȡ rgb��depth ͼ��
 * \param imagePath ����ͼƬ����·��
 * \param idxFrame 
 * \param idx ͼƬ���������
 * \param flag false��û�����ͼ
 * \return 
 */
bool readImage(const string& imagePath, FRAME& idxFrame, const int& idx, const bool& flag = false);

/**
 * \brief ���� YML �ļ������� YML �﷨���ӣ�����ʹ�ó������ɵķ�ʽ��
 * \param parameterYML �ļ�·��
 */
void writeYML(string& parameterYML);

/**
 * \brief ��ȡ YML �ļ��еĲ���
 * \param parameterYML �ļ�·��
 */
void readYML(string& parameterYML);


#endif // !GENERAL_H

