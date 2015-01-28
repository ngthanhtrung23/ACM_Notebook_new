#include "template.h"
#include "Graph/Misc/EulerPath.h"

int main() {
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 1);
    add_edge(1, 3);

    find_path(1);
    PR0(path, path.size());
}
