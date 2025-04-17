def findPartitionCost(cost, k):
    n = len(cost)
    
    if k == 1:
        total = cost[0] + cost[-1]
        return [total, total]

    # Step 1: Create all pair contributions between partitions
    pair_contributions = [cost[i] + cost[i+1] for i in range(n - 1)]
    
    # Step 2: Sort pair contributions
    pair_contributions.sort()
    
    # Step 3: Base cost is always cost[0] + cost[-1]
    base = cost[0] + cost[-1]
    
    # Step 4: Add k-1 smallest and largest pairs
    min_cost = base + sum(pair_contributions[:k - 1])
    max_cost = base + sum(pair_contributions[-(k - 1):])
    
    return [min_cost, max_cost]


cost = [1, 2, 3, 2,5]
k = 3

result = findPartitionCost(cost, k)
print("Minimum and Maximum Partition Costs:", result)

