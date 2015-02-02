// V is the number of vertices
// Tree is the tree with adjacency list representation
// HL[v] is the number of v from which we can decide
//      a segment is heavy or light
// in_segment_id[v] is the position of node v in its corresponding
//      segment
// segment_id[v] is the segment in which there is node v
// oldest[s] is the oldest node (the nearest node to the root) in segment s
// segment is the list of the segments and every nodes inside each of them
int V;
vector <int> Tree[MAXV + 2];
int HL[MAXV + 2];
int in_segment_id[MAXV + 2];
int segment_id[MAXV + 2];
int oldest[MAXV + 2];
vector <int> segment[MAXV + 2];
inline void rec (int v, int parent) {
    int idx = -1;    
    REP (i, SIZE (Tree[v])) {
        int w = Tree[v][i];
        if (w == parent)
            continue;
        rec (w, v);
        if (idx == -1 || HL[w] > HL[idx])
            idx = w;
    }    
    if (idx != -1) {
        HL[v] = HL[idx];        
        REP (i, SIZE (Tree[v])) {
            int w = Tree[v][i];
            if (w == parent || w == idx)
                continue;
            HL[v] = MAX (HL[v], HL[w] + 1);
        }        
        segment_id[v] = segment_id[idx];
        in_segment_id[v] = SIZE (segment[segment_id[v]]);
        segment[segment_id[v]].PB (v);
        oldest[segment_id[v]] = parent;
    } else {
        HL[v] = 1;
        segment_id[v] = v;
        in_segment_id[v] = 0;
        segment[v].PB (v);
        oldest[v] = parent;
    }
}
inline void decompose () {
    RESET (oldest, -1);
    RESET (segment_id, -1);
    RESET (in_segment_id, -1);
    rec (0, -1);
}