namespace std {
    template<>
    struct hash< pair<int,long long> > {
        public:
            size_t operator() (pair<int,long long> x) const {
                return x.first * 1000000009 + x.second;
            }
    };
}
