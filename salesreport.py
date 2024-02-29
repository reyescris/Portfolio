def salesreport (sales):
  if sales > 100000.00:
    percent = 0.10
  elif sales <= 100000.00:
    percent = 0.05
    commission = sales * percent
    target = sales * 1.05
    
    return commission, target

salesperson = input("Enter salesperson name:  ")
sales = float(input("Enter sales amount:  "))
commission, target = salesreport (sales)
print("Commission:  $", commission)
print("Next year's target $", target)