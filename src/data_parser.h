#ifndef DATA_PARSER_H_
#define DATA_PARSER_H_

#include <map>
#include <vector>
#include "event.h"

namespace DataParser
{
   std::vector<Event> ReadData(); 
   std::string CurrentTime();

} // namespace dataParser

#endif /* DATA_PARSER_H_ */