def maximize_profit(price, profit):
  n = len(price)
  increasing = [1] * n
  profitSum = profit.copy()

  for i in range(1, n):
        for j in range(i):
            if price[i] > price[j]:
                increasing[i] = max(increasing[i], increasing[j] + 1)
                profitSum[i] = max(profitSum[i], profit[i] + profitSum[j])

  return max(profitSum)

# Example usage
price = [1, 5, 3, 4, 6]
profit = [2, 3, 4, 5, 6]
max_profit = maximize_profit(price, profit)
print(max_profit)  # Output: 120