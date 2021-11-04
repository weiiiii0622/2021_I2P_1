#PBC_hw2_q3
#B10701204_陳孟夏

#輸入包裝方法數
packing_sum = int(input())

#輸入後馬上處理 並儲存最佳者
#when p = (a+bc)/2b, profit has maximum = (a-bp)(p-c)
max_packing = 0
max_price = 0
max_profit = -1
for i in range(packing_sum): #共輸入 包裝方法數 次
    basic_demand = int(input())
    price_sensitivity = int(input())
    cost = int(input())
    price = (basic_demand + price_sensitivity * cost) / (price_sensitivity * 2)

    if price - int(price) >= 0.5:
        price = int(price) + 1
    else:
        price = int(price)


    demand = basic_demand - price_sensitivity * price
    unit_profit = price - cost
    profit = demand * unit_profit
    if demand <= 0 or unit_profit < 0: #完全沒有獲利的情況
        price = 1000
        profit = 0
    if profit > max_profit: #更新最佳值
        max_packing = i
        max_profit = profit
        max_price = price

#輸出
print(max_packing + 1, max_price, max_profit, sep=",")


#PBC_hw2_q3
#B10701204_陳孟夏

#輸入包裝方法數
#n = int(input())

#輸入後馬上處理 並儲存最佳者
#when p = (a+bc)/2b, profit has maximum = (a-bp)(p-c)
#max_packing = 0
#max_price = 0
#max_profit = -1
#for i in range(n): #共輸入 包裝方法數 次
    # a = int(input())
    # b = int(input())
    # c = int(input())
    # p = (a + b * c) / (b * 2)

    # if p - int(p) >= 0.5:
    #     p = int(p) + 1
    # else:
    #     p = int(p)

    # demand = a - b * p
    # unit_profit = p - c
    # r = demand * unit_profit
    #if demand < 0 or unit_profit < 0: #完全沒有獲利的情況
        #p = 1000
        #r = 0
    #if r > max_profit: #更新最佳值
        #max_packing = i
        #max_profit = r
        #max_price = p

#輸出
#print(max_packing + 1, max_price, max_profit, sep=",")