// Buffered reader {{{
namespace IO {
    const int BUFSIZE = 1<<14;
    char buf[BUFSIZE + 1], *inp = buf;

    bool reacheof;
    char get_char() {
        if (!*inp && !reacheof) {
            memset(buf, 0, sizeof buf);
            int tmp = fread(buf, 1, BUFSIZE, stdin);
            if (tmp != BUFSIZE) reacheof = true;
            inp = buf;
        }
        return *inp++;
    }
    template<typename T>
    T get() {
        int neg = 0;
        T res = 0;
        char c = get_char();
        while (!std::isdigit(c) && c != '-' && c != '+') c = get_char();
        if (c == '+') { neg = 0; }
        else if (c == '-') { neg = 1; }
        else res = c - '0';

        c = get_char();
        while (std::isdigit(c)) {
            res = res * 10 + (c - '0');
            c = get_char();
        }
        return neg ? -res : res;
    }
};
// }}}
