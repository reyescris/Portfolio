def displaynames (lastn, salary):
  for i in lastn, salary:
    print(i)
  for y in salary:
    print(y)
def displayr (lastn, salary):
  l = len(lastn)
  print("Number of array elements:  ", l)
  print("Arrays in order:  ")
  for y in range (0, l, 1):
    print(lastn[y], salary[y])
  print("Arrays in reverse order:  ")
  for y in range (l-1, -1, -1):
    print(lastn[y], salary[y])

def hilow (lastn, salary):
  l = len(lastn)
  hisalary = -1.0
  lowsalary = 99999999.99
for y in range (0, l, 1):
  s = s + salary[y]
  print("Total all salaries ", s)

def seqsearch (lastn, sname):
  l = len(lastn)
  i = -1
  for y in range (0,l,1):
    if lastn[y] == sname:
      i = y

  return i
  
  if float(salary[y]) > float(hisalary):
    hiindex = y
    hisalary = salary[y]

  if float(salary[y]) < float(lowsalary):
    loindex = y
    lowsalary = salary[y]

print("highest salary" , lastn[hiindex] , salary[hiindex])
print("lowest salary" , lastn[loindex] , salary[loindex])

f = open("lnames.txt" , "r")


print("here")

lastname = f.readline()
lastn = []
salary = []
while lastname != "":
  c = c + 1
  lastn.append(str(lastname).rstrip("\n"))
  s = float(f.readline())
  salary.append(s)
  lastname = f.readline()

f.close()
displaynames (lastn, salary)
displayr (lastn, salary)
hilow(lastn, salary)
sumsalaries (salary)
response = input("Do you want to do this program? (Yes or No)")

while response == "Yes":
  sname = input("Enter last name to search for")


  i = seqsearch (lastn, sname)
  if i == -1:
    print(sname, "not in the array")
  else:
    print (lastn[i], "salary of", salary[i])

  response = input("Do you want to do the program again? (Yes or No)")