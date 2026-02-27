#include "gigasecond.h"

namespace gigasecond {

    boost::posix_time::ptime advance(const boost::posix_time::ptime& start_time) {
        // A gigasecond is 1,000,000,000 seconds.
        // We use boost::posix_time::seconds to define the duration.
        const boost::posix_time::seconds giga(1000000000);

        // In Boost, adding a duration to a ptime is as simple as using the + operator.
        return start_time + giga;
    }

}  // namespace gigasecond