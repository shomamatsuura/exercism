#include "twelve_days.h"
#include <vector>

namespace twelve_days {
static const std::vector<std::string> days = {
    "first", "second", "third", "fourth", "fifth", "sixth",
    "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
};

static const std::vector<std::string> gifts = {
    "a Partridge in a Pear Tree.",
    "two Turtle Doves, ",
    "three French Hens, ",
    "four Calling Birds, ",
    "five Gold Rings, ",
    "six Geese-a-Laying, ",
    "seven Swans-a-Swimming, ",
    "eight Maids-a-Milking, ",
    "nine Ladies Dancing, ",
    "ten Lords-a-Leaping, ",
    "eleven Pipers Piping, ",
    "twelve Drummers Drumming, "  
};
std::string get_verse(unsigned int n){
    std::string verse = "On the " + days[n -1] + " day of Christmas my true love gave to me: ";

    for(unsigned int i{n - 1}; i > 0; --i){
        verse += gifts[i];
    }
    if(n > 1) verse += "and ";
    verse += gifts[0] + "\n";
    return verse;
}

std::string recite(unsigned int from, unsigned int to){
    std::string result = "";
    for(unsigned int i{from}; i <= to; ++i){
        result += get_verse(i);
        if(i < to) result += "\n";
    }
    return result;
}

}  // namespace twelve_days