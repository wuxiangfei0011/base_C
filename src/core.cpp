

#include "../include/core.h"


using namespace sre;


SortParcle::SortParcle(): width_(0),
							img_left_(nullptr),
							is_initialized_(false)
{
	/*���캯����Ҫ��ʼ����Ա�����������ͱ�����λfalse
	 *ָ��δ����ʼ��,����ָ����ָ���Ҳ�������,���Ǹ�Ұָ��,���������ָ��,
	 *���޸����ָ����ָ�������,��������ָ����ָ�������ǡ��������һ����������ݵĻ�,
	 *�㽫������޸���,�ͻᵼ������һ��������ܲ�������������.����ʹ��ǰһ��Ҫ���г�ʼ����
	 * ������ÿ�,��ʼ��ΪNULL,ʹ����ָ���κ����ݣ�
	 */
}

SortParcle::~SortParcle()
{
    // �����Ա����new�����ڴ��ͷ�
    SortParcle::FreeMemory();
    
    is_initialized_ = false; // ���ó�ʼ�����
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

    //��ֵ
    width_ = width;
    //...

	//�����ڴ�ռ�
    census_left_ = new uint32[width * height](); //���ٳ���Ϊwidth * height�����飬()
    disp_left_ = new uint32[width * height]();
	//...
	
    is_initialized_ = census_left_ && disp_left_; //ȷ���ڴ�ɹ����٣�ָ��ǿ�

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

    // ���ø�������ģ�飨һ�㶼����˽�в��֣�
    CensusTransform();
    //...

    //�ڴ濽����������disp_left_������disp_left(ȫ�ֱ���)��void *memcpy(void *destin, void *source, unsigned n)
    // ����Ӳ�ͼ
	if (disp_left == nullptr) { //Ϊ�յĻ��϶����ܿ����ڴ�ռ�
		return false;
	}
    memcpy(disp_left, disp_left_, width_ * height_ * sizeof(float32));

    return true;
}

bool SortParcle::Reset(const uint32& width, const uint32& height, const sortOption& option)
{
    // �����Ա����new�����ڴ��ͷţ������ڴ�й©
    SortParcle::FreeMemory();

    // ���ó�ʼ�����
    is_initialized_ = false;

    // �޸�ͼ��ߴ�
    return Initialize(width, height);
}

void SortParcle::CensusTransform() const
{
	//���еĺ�����ͷ��Ҫ�� if() ����ʼ�ж�
}