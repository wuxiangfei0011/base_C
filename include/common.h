/**
 * \brief 包含其他文件都会用到的共同函数
 */


#pragma once

#ifndef GENERAL_H //有了 #pragma once，这一句可以省去；在大工程中相对于 #pragma once 较耗时
#define GENERAL_H


#include "../include/public.hpp"


/**
 * \brief 关键帧
 * \note  there is vector in FRAME, if you transfer a longer vector to small, there will be truncated (err)
 */
struct FRAME {
    int frameID;
    Mat rgb, depth;
    Mat descriptors;
    vector<KeyPoint> keypoints;
};

/**
 * \brief 从 YML 中读取的参数
 */
struct PARAMETER {

};

/**
 * \brief 读取 rgb、depth 图像
 * \param imagePath 所有图片的总路径
 * \param idxFrame 
 * \param idx 图片的名称序号
 * \param flag false：没有深度图
 * \return 
 */
bool readImage(const string& imagePath, FRAME& idxFrame, const int& idx, const bool& flag = false);

/**
 * \brief 生成 YML 文件（由于 YML 语法复杂，所以使用程序生成的方式）
 * \param parameterYML 文件路径
 */
void writeYML(string& parameterYML);

/**
 * \brief 提取 YML 文件中的参数
 * \param parameterYML 文件路径
 */
void readYML(string& parameterYML);


#endif // !GENERAL_H

