

#include "../include/core.h"


using namespace sre;


SortParcle::SortParcle(): width_(0),
							img_left_(nullptr),
							is_initialized_(false)
{
	/*构造函数处要初始化成员变量，布尔型变量置位false
	 *指针未被初始化,所以指针所指向的也是随机的,他是个野指针,如果你引用指针,
	 *并修改这个指针所指向的内容,而如果这个指针所指向的内容恰好是另外一个程序的数据的话,
	 *你将其进行修改了,就会导致另外一个程序可能不能正常运行了.所以使用前一定要进行初始化，
	 * 针变量置空,初始化为NULL,使它不指向任何内容，
	 */
}

SortParcle::~SortParcle()
{
    // 对类成员所有new出的内存释放
    SortParcle::FreeMemory();
    
    is_initialized_ = false; // 重置初始化标记
}

void SortParcle::FreeMemory()
{
    SAFE_DELETE(img_left_);
	//...
	
}

bool SortParcle::Initialize(const uint32& width, const uint32& height)
{
    if (width == 0 || height == 0) {
        return false;
    }

    //赋值
    width_ = width;
    //...

	//开辟内存空间
    census_left_ = new uint32[width * height](); //开辟长度为width * height的数组，()
    disp_left_ = new uint32[width * height]();
	//...
	
    is_initialized_ = census_left_ && disp_left_; //确保内存成功开辟：指针非空

    return is_initialized_;
}

bool SortParcle::Core(const uint8* img_left, const uint8* img_right, float32* disp_left)
{
    if (!is_initialized_) {
        return false;
    }
    if (img_left == nullptr || img_right == nullptr) {
        return false;
    }

    img_left_ = img_left;

    // 调用各个功能模块（一般都放在私有部分）
    CensusTransform();
    //...

    //内存拷贝函数：将disp_left_拷贝到disp_left(全局变量)：void *memcpy(void *destin, void *source, unsigned n)
    // 输出视差图
	if (disp_left == nullptr) { //为空的话肯定不能拷贝内存空间
		return false;
	}
    memcpy(disp_left, disp_left_, width_ * height_ * sizeof(float32));

    return true;
}

bool SortParcle::Reset(const uint32& width, const uint32& height, const sortOption& option)
{
    // 对类成员所有new出的内存释放，避免内存泄漏
    SortParcle::FreeMemory();

    // 重置初始化标记
    is_initialized_ = false;

    // 修改图像尺寸
    return Initialize(width, height);
}

void SortParcle::CensusTransform() const
{
	//所有的函数开头都要加 if() 做初始判断
}