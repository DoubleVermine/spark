#include <spark/image.hpp>
#include <spark/core.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

Image::Image() : IElement()
{
	m_bg_color = vec4<unsigned int>(0, 0, 0, 0);
}

Image::~Image()
{
	//delete the image
}

void Image::OnInitialize()
{

}

void Image::SetVisible(const bool visible)
{
	m_visible = visible;
}

void Image::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		if (m_image == -1)
		{
			m_image = nvgCreateImage(vg, m_file.c_str(), 0); 
			/*int width, height;*/
			//if (m_width == 0)
			//{
			//	nvgImageSize(vg, m_image, &width, &height);
			//	m_width = width;
			//}
			//if (m_height == 0)
			//{
			//	nvgImageSize(vg, m_image, &width, &height);
			//	m_height = height;
			//}
		}

		CalcPosition(box);

		nvgBeginPath(vg);
		nvgRect(vg, m_box.x, m_box.y, m_box.width, m_box.height);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		float alpha = 1.0f;
		NVGpaint imgPaint = nvgImagePattern(vg, m_box.x, m_box.y, m_box.width, m_box.height, 0.0f, m_image, alpha);
		nvgFillPaint(vg, imgPaint);
		nvgFill(vg);
	}
}

void Image::Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view)
{
	if (m_visible)
	{
		Core::GetCore()->ExecuteFunction(shared_from_this(), m_update);
	}
}

void Image::SetImage(const std::string& imgFile)
{
	m_file = imgFile;
}

