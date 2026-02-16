#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    int startIdx = line.find(" ") + 1;
    return line.substr(startIdx);
}

std::string log_level(std::string line) {
    // return the log level
    int startIdx = line.find("[") + 1;
    int endIdx = line.find("]");
    return line.substr(startIdx, endIdx - startIdx);
}

std::string reformat(std::string line) {
    // return the reformatted message
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
