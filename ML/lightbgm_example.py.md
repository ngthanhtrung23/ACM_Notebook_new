---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\ninput = sys.stdin.readline\n\n\nimport pandas as pd\nimport numpy\
    \ as np\n\nfrom sklearn.model_selection import train_test_split\nimport lightgbm\
    \ as lgb\n\ndef main():\n    # K = dimension of input vectors\n    # T = specific\
    \ to this problem\n    # N = number of training data\n    # M = number of test\
    \ data\n    # U = number of dimensions\n    # Note that in this problem, input\
    \ vectors are sparse, so K < U\n    K, T, N, M, U = map(int, input().split())\n\
    \    feat_cols = [f'user_{i}' for i in range(U)]\n    \n    # Read training data\n\
    \    train_df = np.full((N, U+1), -1)\n    for i in range(N):\n        tups =\
    \ input().split()\n        for tup in tups:\n            x, a = map(int, tup.split(':'))\n\
    \            train_df[i][x] = a\n    # Read training labels\n    for i in range(N):\n\
    \        train_df[i][U] = int(input())\n\n    # Setup training DF\n    train_df\
    \ = pd.DataFrame(train_df, columns = feat_cols + ['label'])\n        \n    # Read\
    \ test data\n    test_df = np.full((M, U), -1)\n    for i in range(M):\n     \
    \   tups = input().split()\n        for tup in tups:\n            x, a = map(int,\
    \ tup.split(':'))\n            test_df[i][x] = a\n\n    # Setup test DF\n    test_df\
    \ = pd.DataFrame(test_df, columns = feat_cols)\n\n    # train\n    train_df, val_df\
    \ = train_test_split(train_df, test_size=0.2)\n    train_X, train_y = train_df[feat_cols],\
    \ train_df[['label']]\n    val_X, val_y = val_df[feat_cols], val_df[['label']]\n\
    \    test_X = test_df\n    del train_df, val_df, test_df\n\n    params = {\n \
    \     'boosting_type': 'gbdt',\n      'objective': 'regression',\n      'metric':\
    \ 'l2',\n      'learning_rate': 0.005,\n      'subsample': 1,\n      'colsample_bytree':\
    \ 0.2,\n      'reg_alpha': 3,\n      'reg_lambda': 1,\n      'n_estimators': 2000,\n\
    \      'verbose': 1,\n      'max_depth': -1,\n      'seed':100, \n      'force_col_wise':\
    \ True,\n      'verbose': -1,\n    }\n\n    clf = lgb.train(params, \n       \
    \ train_set = lgb.Dataset(train_X, train_y),\n        valid_sets = [lgb.Dataset(val_X,\
    \ val_y)],\n        verbose_eval = False,\n    )\n\n    # predict\n    y_test\
    \ = clf.predict(test_X, num_iteration=clf.best_iteration)\n    for y in y_test:\
    \ print(max(min(round(y), T), 0))\n\n\n\nif __name__ == '__main__':\n    main()\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: ML/lightbgm_example.py
  requiredBy: []
  timestamp: '2022-02-06 02:34:43+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ML/lightbgm_example.py
layout: document
redirect_from:
- /library/ML/lightbgm_example.py
- /library/ML/lightbgm_example.py.html
title: ML/lightbgm_example.py
---
