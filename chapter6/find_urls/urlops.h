#include <vector>
#include <string>

std::vector<std::string> find_urls(const std::string&);

std::string::const_iterator url_beg(std::string::const_iterator, 
                                    std::string::const_iterator);

std::string::const_iterator url_end(std::string::const_iterator,
                                    std::string::const_iterator);