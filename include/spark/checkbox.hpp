#pragma once
#include "element.hpp"

namespace spark
{
	class Checkbox : public IElement
	{
	public:
		Checkbox();
		~Checkbox();

		void OnPaint(const PaintEvent& ev, const Dimension& box);
		void OnInitialize();
		void Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view);

		void SetVisible(const bool visible);

		bool Toggle();
		void SetState(bool state) { m_checked = state; }
	private:
		bool m_checked;

		vec4<unsigned int> m_checked_border_color;
		vec4<unsigned int> m_checked_bg_color;
	};
}