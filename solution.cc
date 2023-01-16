#include "solution.hh"
#include <stdio.h>
#include <iostream> 

bool Solution::isRobotBounded(std::string& instructions) {
    int compassArr[] = {0, 0, 0, 0};
    int currDirection = 0;

    std::string cycle = instructions;
    for (int i=0; i < 3; i++) {
        cycle.append(instructions);
    }

    for (int i=0; i < cycle.length(); i++) {
        if (cycle[i] == 'G') {
            compassArr[currDirection] += 1;
        } else if (cycle[i] == 'R') {
            currDirection = (currDirection + 1) % 4;
        } else {
            currDirection -= 1;
            if (currDirection == -1) {
                currDirection = 3;
            }
        }
    }

if (compassArr[0] == compassArr[2] && compassArr[1] == compassArr[3]) {
    return true;
} else {
    return false;
}
}
