#pragma once
#include <vector>
#include <string>
#include <string_view>


namespace protein_translation {

std::vector<std::string> proteins(std::string_view condons);

}  // namespace protein_translation
