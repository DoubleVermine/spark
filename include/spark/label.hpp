#pragma once
#include <string>
#include "element.hpp"


namespace spark
{	
	class Label : public IElement
	{
	public:
		Label();
	
        void OnPaint(const PaintEvent& ev,const Dimension& box);
        void OnInitialize();
		void Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view);

		void SetVisible(const bool visible);
        
		void SetText(const std::string& text) { m_text = text; }
		std::string& GetText() { return m_text; }
		
		void SetFontSize(float size) { m_size = size; }
		float GetFontSize() { return m_size; }

		unsigned long long GetLength() { return m_text.length(); }
		
		void SetFont(const std::string& font_name) { m_font = font_name; }
		const std::string& GetFont() { return m_font;}
		
		void SetFontColor(vec4<unsigned int> color) { m_font_color = color; }
		vec4<unsigned int> GetFontColor() { return m_font_color; }
		
	private:
		std::string m_text;
		std::string m_font;
		
		float m_size;
		
		vec4<unsigned int> m_font_color;
	};
}
