import sys
input = sys.stdin.readline


import pandas as pd
import numpy as np

from sklearn.model_selection import train_test_split
import lightgbm as lgb

def main():
    # K = dimension of input vectors
    # T = specific to this problem
    # N = number of training data
    # M = number of test data
    # U = number of dimensions
    # Note that in this problem, input vectors are sparse, so K < U
    K, T, N, M, U = map(int, input().split())
    feat_cols = [f'user_{i}' for i in range(U)]
    
    # Read training data
    train_df = np.full((N, U+1), -1)
    for i in range(N):
        tups = input().split()
        for tup in tups:
            x, a = map(int, tup.split(':'))
            train_df[i][x] = a
    # Read training labels
    for i in range(N):
        train_df[i][U] = int(input())

    # Setup training DF
    train_df = pd.DataFrame(train_df, columns = feat_cols + ['label'])
        
    # Read test data
    test_df = np.full((M, U), -1)
    for i in range(M):
        tups = input().split()
        for tup in tups:
            x, a = map(int, tup.split(':'))
            test_df[i][x] = a

    # Setup test DF
    test_df = pd.DataFrame(test_df, columns = feat_cols)

    # train
    train_df, val_df = train_test_split(train_df, test_size=0.2)
    train_X, train_y = train_df[feat_cols], train_df[['label']]
    val_X, val_y = val_df[feat_cols], val_df[['label']]
    test_X = test_df
    del train_df, val_df, test_df

    params = {
      'boosting_type': 'gbdt',
      'objective': 'regression',
      'metric': 'l2',
      'learning_rate': 0.005,
      'subsample': 1,
      'colsample_bytree': 0.2,
      'reg_alpha': 3,
      'reg_lambda': 1,
      'n_estimators': 2000,
      'verbose': 1,
      'max_depth': -1,
      'seed':100, 
      'force_col_wise': True,
      'verbose': -1,
    }

    clf = lgb.train(params, 
        train_set = lgb.Dataset(train_X, train_y),
        valid_sets = [lgb.Dataset(val_X, val_y)],
        verbose_eval = False,
    )

    # predict
    y_test = clf.predict(test_X, num_iteration=clf.best_iteration)
    for y in y_test: print(max(min(round(y), T), 0))



if __name__ == '__main__':
    main()

