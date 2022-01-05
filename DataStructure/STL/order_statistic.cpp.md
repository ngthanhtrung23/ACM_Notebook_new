---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/STL/order_statistic.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include <ext/pb_ds/assoc_container.hpp> // Common file\n\
    #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update\n\
    \nusing namespace __gnu_pbds;\n\ntypedef tree<int, null_type, less<int>, rb_tree_tag,\
    \ tree_order_statistics_node_update> ordered_set;\n\nint main() { \n    ordered_set\
    \ X;\n    // X = {1, 2, 4, 8, 16}\n    for(int i = 1; i <= 16; i *= 2)\n     \
    \   X.insert(i);\n    cout << *X.find_by_order(0) << endl; // 1\n    cout << *X.find_by_order(1)\
    \ << endl; // 2\n    cout << *X.find_by_order(2) << endl; // 4\n    cout << *X.find_by_order(4)\
    \ << endl; // 16\n    cout << (X.end()==X.find_by_order(6)) << endl; // true\n\
    \n    cout<<X.order_of_key(-5)<<endl;  // 0\n    cout<<X.order_of_key(1)<<endl;\
    \   // 0\n    cout<<X.order_of_key(3)<<endl;   // 2\n    cout<<X.order_of_key(4)<<endl;\
    \   // 2\n    cout<<X.order_of_key(400)<<endl; // 5\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#include <ext/pb_ds/assoc_container.hpp>\
    \ // Common file\n#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update\n\
    \nusing namespace __gnu_pbds;\n\ntypedef tree<int, null_type, less<int>, rb_tree_tag,\
    \ tree_order_statistics_node_update> ordered_set;\n\nint main() { \n    ordered_set\
    \ X;\n    // X = {1, 2, 4, 8, 16}\n    for(int i = 1; i <= 16; i *= 2)\n     \
    \   X.insert(i);\n    cout << *X.find_by_order(0) << endl; // 1\n    cout << *X.find_by_order(1)\
    \ << endl; // 2\n    cout << *X.find_by_order(2) << endl; // 4\n    cout << *X.find_by_order(4)\
    \ << endl; // 16\n    cout << (X.end()==X.find_by_order(6)) << endl; // true\n\
    \n    cout<<X.order_of_key(-5)<<endl;  // 0\n    cout<<X.order_of_key(1)<<endl;\
    \   // 0\n    cout<<X.order_of_key(3)<<endl;   // 2\n    cout<<X.order_of_key(4)<<endl;\
    \   // 2\n    cout<<X.order_of_key(400)<<endl; // 5\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/STL/order_statistic.cpp
  requiredBy: []
  timestamp: '2018-11-24 21:39:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/STL/order_statistic.cpp
layout: document
redirect_from:
- /library/DataStructure/STL/order_statistic.cpp
- /library/DataStructure/STL/order_statistic.cpp.html
title: DataStructure/STL/order_statistic.cpp
---
