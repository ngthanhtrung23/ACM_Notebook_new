// Formal Power Series {{{
//
// Notes:
// - T must be ModInt

#include "NTT.h"
template<typename T> struct FormalPowerSeries : std::vector<T> {
    using std::vector<T>::vector;
    using P = FormalPowerSeries;

    // Remove zeroes at the end
    void shrink() {
        while (!this->empty() && this->back() == T(0)) this->pop_back();
    }

    // basic operators with another FPS: + - * / % {{{
    P operator + (const P& r) { return P(*this) += r; }
    P operator - (const P& r) { return P(*this) -= r; }
    P operator * (const P& r) { return P(*this) *= r; }

    P& operator += (const P& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < static_cast<int> (r.size()); ++i)
            (*this)[i] += r[i];
        shrink();
        return *this;
    }
    P& operator -= (const P& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < static_cast<int> (r.size()); ++i)
            (*this)[i] -= r[i];
        shrink();
        return *this;
    }
    P& operator *= (const P& r) {
        if (this->empty() || r.empty()) {
            this->clear();
        } else {
            auto res = multiply(*this, r);
            *this = P(res.begin(), res.end());
        }
        return *this;
    }
    // }}}
};
// }}}
