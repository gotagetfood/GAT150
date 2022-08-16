#pragma once 
#include "Text.h"
#include "Resource/Resource.h"
#include <string>
// !! add necessary includes 

// !! forward declare the _TTF_Font struct 
	struct _TTF_Font {};
namespace towr
{
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		//bool Create(const std::string& filename, void* data = nullptr) override;
		bool Create(std::string filename, ...) override;
		bool Load(const std::string& filename, int fontSize);

		_TTF_Font* m_ttfFont = nullptr;
	protected:
	};
}
