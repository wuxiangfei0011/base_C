

#include "../include/common.h"


bool readImage(const string& imagePath, FRAME& idxFrame, const int& idx, const bool& flag)
{
	//��ȡ rgb ͼ��
    string rgbPath = imagePath + to_string(idx) + ".png";
    idxFrame.rgb = imread(rgbPath, IMREAD_UNCHANGED);

    if (idxFrame.rgb.data == nullptr) {
        cerr << " don't exit " << idx << "th rgb image." << endl; //number of image start from 1.png
        return false;
    }

	//��ȡ depth ͼ��
    if (flag == true)
    {
        string depthPath = imagePath + to_string(idx) + ".png";
        idxFrame.depth = imread(depthPath, IMREAD_UNCHANGED);
    	
        if (idxFrame.depth.empty()) {
            cerr << "don't exit " << idx << "th depth image." << endl;
            return false;
        }
        if (idxFrame.rgb.rows != idxFrame.depth.rows || idxFrame.rgb.cols != idxFrame.depth.cols) {
            std::cout << "size of rgb and depth is not same" << std::endl;
            return false;
        }
    }
    //cout << " rgb.type(): " << idxFrame.rgb.type() << endl; //ensure rgb's type for compyting cloud: 8U3C=16,
    //cout << " depth.type(): " << idxFrame.depth.type() << endl; //ensure depth's type for compyting cloud: uchar=2,

	idxFrame.frameID = idx;

    return true;
}

void writeYML(string& parameterYML) {
    FileStorage fs(parameterYML, FileStorage::WRITE);

    if (fs.isOpened()) {
        //...��Ҫ���� YML �Ĳ���
    	
        fs.release();
    }
    else cout << "can't create YML file" << endl;
}

void readYML(string& parameterYML) {
    FileStorage fs(parameterYML, FileStorage::READ);

    if (fs.isOpened()) {
        //..�� YML �ļ�����ȡ�Ĳ���
    	
        fs.release();
    }
    else cout << "can't open YML file" << endl;
}

