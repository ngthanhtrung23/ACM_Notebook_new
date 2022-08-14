// RangeSet - for maintaining set of segments {{{
//
// merge_adjacent_segment = true -> merge 2 consecutive segments,
// e.g. [1, 10] and [11, 20] --> [1, 20]
//
// Based on https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp
template<typename T, bool merge_adjacent_segment = true>
struct RangeSet {
    T n_elements() const { return sz; }
    T n_ranges() const { return ranges.size(); }

    bool contains(T x) const {
        auto it = ranges.upper_bound(x);
        return it != ranges.begin() && x <= std::prev(it)->second;
    }

    // Find range containing x, i.e. l <= x <= r
    std::optional<std::pair<T, T>> find_range(T x) const {
        auto it = ranges.upper_bound(x);
        if (it == ranges.begin()) return std::nullopt;
        --it;
        return (x <= it->second) ? std::optional<std::pair<T, T>>{*it} : std::nullopt;
    }

    // Insert [l, r]
    // Returns number of new integers added.
    // AMORTIZED O(logN)
    T insert(T l, T r) {
        assert(l <= r);
        auto it = ranges.upper_bound(l);
        if (it != ranges.begin() && is_mergeable(std::prev(it)->second, l)) {
            it = std::prev(it);
            l = std::min(l, it->first);
        }
        T inserted = 0;
        for (; it != ranges.end() && is_mergeable(r, it->first); it = ranges.erase(it)) {
            auto [cl, cr] = *it;
            r = std::max(r, cr);
            inserted -= cr - cl + 1;
        }

        inserted += r - l + 1;
        ranges[l] = r;
        sz += inserted;
        return inserted;
    }

    // Erase [l, r]
    // Returns number of integers removed
    // AMORTIZED O(logN)
    T erase(T l, T r) {
        assert(l <= r);
        T tl = l, tr = r;
        auto it = ranges.upper_bound(l);
        if (it != ranges.begin() && l <= std::prev(it)->second) {
            it = std::prev(it);
            tl = it->first;
        }

        T erased = 0;
        for (; it != ranges.end() && it->first <= r; it = ranges.erase(it)) {
            auto [cl, cr] = *it;
            tr = cr;
            erased += cr - cl + 1;
        }
        if (tl < l) {
            ranges[tl] = l-1;
            erased -= l - tl;
        }
        if (r < tr) {
            ranges[r + 1] = tr;
            erased -= tr - r;
        }
        sz -= erased;
        return erased;
    }

    // Find min x: x >= lower && x NOT in this set
    T minimum_excluded(T lower) const {
        static_assert(merge_adjacent_segment);
        auto it = find_range(lower);
        return it == ranges.end() ? lower : it->second + 1;
    }

    // Find max x: x <= upper && x NOT in this set
    T maximum_excluded(T upper) const {
        static_assert(merge_adjacent_segment);
        auto it = find_range(upper);
        return it == ranges.end() ? upper : it->first - 1;
    }

    T sz = 0;
    std::map<T, T> ranges;

    bool is_mergeable(T cur_r, T next_l) {
        return next_l <= cur_r + merge_adjacent_segment;
    }
};
// }}}
