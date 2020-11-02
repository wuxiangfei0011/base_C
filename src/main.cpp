

#include "../include/public.hpp"
#include "../include/common.h"
#include "../include/core.h"


/** \brief YML 参数文件路径，writeYML() 可自动创建 */
string parameter = ".\\parameter.yml";

/** \brief 各个图片具体路径需到 readImage() 中指定 */
string imagePath = ".\\data\\";

FRAME frame;

int main(int argv, char** argc)
{

	/*readImage(imagePath, frame, 1, true);

	imshow("b", frame.rgb);
	imshow("a", frame.depth);*/
	
	//system("pause");
	waitKey(0);

	//此处要对 main() 中用new开辟的所有内存释放掉，防止内存泄露：delete[] disparity; disparity = nullptr;
	return 0;
}
