#include "../template.h"
#include "basic.h"
#include "circle.h"

int main() {
    // Example: Check point inside circle
    Circle C1(2, 2, 7);
    assert(cmp((C1 - Point(8, 2)).norm(), C1.r * C1.r) < 0);
    assert(cmp((C1 - Point(9, 2)).norm(), C1.r * C1.r) == 0);
    assert(cmp((C1 - Point(10, 2)).norm(), C1.r * C1.r) > 0);
}
