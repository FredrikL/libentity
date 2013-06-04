#pragma once

#include "entity/entity.h"

namespace ent
{
	class json
	{
		public:
			static std::string to(entity &item, bool pretty, int depth = 0);
			static entity from(std::string &text);
			
		private:
			static std::string property(value &item, bool pretty, int depth);

			static void validate(std::string &text);
			static entity parse(std::string &text, int &i);
			static std::string parse_key(std::string &text, int &i);
			static std::string parse_string(std::string &text, int &i);
			static std::string parse_item(std::string &text, int &i);
			static value parse_array(std::string &text, int &i);
			static void error(std::string message, std::string json, int i);
	};
}
