Mo's algorithm:
- Sort by (l / SQRTN, r)
--> Extend the segment in O(|l - l'| + |r - r'|)
On tree:
- Standard method of linearizing does not work, because nodes can be O(N) apart
- Slightly modify the standard dfs traversal, by adding nodes at even depth to our traversal as we go down, and nodes at odd depth to our traversal as we go up, kind of "hopping" down and up the tree. This ensures that nodes right next to each other in the traversal are at most 3 nodes apart in the actual tree
