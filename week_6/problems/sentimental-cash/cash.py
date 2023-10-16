money = 0
while True:
    try:
        money = int(float(input("Change owed: "))*100)
        if money >0:
            break
    except:
        continue

total_coins = 0

total_coins+= money//25
money = money % 25
total_coins+= money//10
money = money % 10
total_coins+= money//5
money = money % 5
total_coins+= money//2
money = money % 2
total_coins+= money//1
money = money % 1

print(total_coins)