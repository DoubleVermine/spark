#include <spark/container.hpp>

using namespace spark;

IContainer::IContainer() : IElement()
{
	m_horizontalAlignment = STRETCH;
	m_verticalAlignment = STRETCH;
	m_bg_color = vec4<unsigned int>(0, 0, 0, 0);
}

void IContainer::SetImage(std::shared_ptr<Image> image)
{
	m_image = image;
	m_image->SetHorizontalAlignment(STRETCH);
	m_image->SetVerticalAlignment(STRETCH);
}