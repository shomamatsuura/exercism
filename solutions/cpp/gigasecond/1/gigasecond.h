#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond {

    // Use boost::posix_time::ptime as the input and output type
    boost::posix_time::ptime advance(const boost::posix_time::ptime& start_time);

}  // namespace gigasecond