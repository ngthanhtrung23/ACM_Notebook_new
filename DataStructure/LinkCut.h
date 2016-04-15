// - Index from 0
// - Usage: linkcut<int> lc(n);
template<class T> struct splnode {
  typedef splnode<T> node_t;

  splnode() : P(NULL), flip(0), pp(NULL) {
    C[0] = C[1] = NULL;
    fix();
  }

  node_t* P;
  node_t* C[2];

  int flip;
  node_t* pp;

  /* Fix the parent pointers of our children.  Additionally if we have any
   * extra data we're tracking (e.g. sum of subtree elements) now is the time to
   * update them (all of the children will already be up to date). */
  void fix() {
    if(C[0]) C[0]->P = this;
    if(C[1]) C[1]->P = this;
  }

  /* Push the flip bit down the tree. */
  void push_flip() {
    if(!flip) return;
    flip = 0;
    swap(C[0], C[1]);
    if(C[0]) C[0]->flip ^= 1;
    if(C[1]) C[1]->flip ^= 1;
  }

  /* Return the direction of this relative its parent. */
  int up() {
    return !P ? -1 : (P->C[0] == this ? 0 : 1);
  }

  /* Simple zig step in the 'c' direction when we've reached the root. */
  void zig(int c) {
    node_t* X = C[c];
    if(X->P = P) P->C[up()] = X;
    C[c] = X->C[1 - c];
    X->C[1 - c] = this;
    fix(); X->fix();
    if(P) P->fix();
    swap(pp, X->pp);
  }

  /* Zig zig in the 'c' direction both times. */
  void zigzig(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = X->C[1 - c];
    X->C[c] = Y->C[1 - c];
    Y->C[1 - c] = X;
    X->C[1 - c] = this;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }

  /* Zig zag first in the 'c' direction then in the '1-c' direciton. */
  void zigzag(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[1 - c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = Y->C[1 - c];
    X->C[1 - c] = Y->C[c];
    Y->C[1 - c] = this;
    Y->C[c] = X;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }

  /* Splay this up to the root.  Always finishes without flip set. */
  node_t* splay() {
    for(push_flip(); P; ) {
      /* Reorganize flip bits so we can rotate as normal. */
      if(P->P) P->P->push_flip();
      P->push_flip();
      push_flip();

      int c1 = up();
      int c2 = P->up();
      if(c2 == -1) {
        P->zig(c1);
      } else if(c1 == c2) {
        P->P->zigzig(c1);
      } else {
        P->P->zigzag(c2);
      }
    }
    return this;
  }

  /* Return the max element of the subtree rooted at this. */
  node_t* last() {
    push_flip();
    return C[1] ? C[1]->last()  : splay();
  }

  /* Return the min element of the subtree rooted at this. */
  node_t* first() {
    push_flip();
    return C[0] ? C[0]->first() : splay();
  }
};


template<class T>
struct linkcut {
typedef splnode<T> node_t;

linkcut(int N) : node(N) {
}

void link(int u, int v) {
  make_root(v);
  node[v].pp = &node[u];
}

void cut(int u, int v) {
  make_root(u);
  node[v].splay();
  if(node[v].pp) {
    node[v].pp = NULL;
  } else {
    node[v].C[0]->P = NULL;
    node[v].C[0] = NULL;
    node[v].fix();
  }
}

bool connected(int u, int v) {
  node_t* nu = access(u)->first();
  node_t* nv = access(v)->first();
  return nu == nv;
}

/* Move u to root of represented tree. */
void make_root(int u) {
  access(u);
  node[u].splay();
  if(node[u].C[0]) {
    node[u].C[0]->P = NULL;
    node[u].C[0]->flip ^= 1;
    node[u].C[0]->pp = &node[u];

    node[u].C[0] = NULL;
    node[u].fix();
  }
}

/* Move u to root aux tree.  Return the root of the root aux tree. */
splnode<T>* access(int u) {
  node_t* x,* pp;
  for(x = node[u].splay(); x->pp; x = pp) {
    pp = x->pp->splay();
    x->pp = NULL;
    if(pp->C[1]) {
      pp->C[1]->P = NULL;
      pp->C[1]->pp = pp;
    }
    pp->C[1] = x;
    pp->fix();
  }
  return x;
}

vector<node_t> node;
};

