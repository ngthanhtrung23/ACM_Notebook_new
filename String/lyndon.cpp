#include "../template.h"
#include "lyndon.h"

int main() {
    lyndon("abcdef"); // abcdef
    lyndon("fedcba"); // f e d c b a
    lyndon("aaaaaa"); // a a a a a a
    lyndon("ababab"); // ab ab ab
}
