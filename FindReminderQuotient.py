# Python program
# To find reminder, quotient and answer of division of any to number.

print("\tFind the answer of two number.\n")
print("Q.) First no. / Second no. = ?")

numerator = input("Enter Numerator: >>  ")
denominator = input("Enter Denominator: >>  ")
numerator = float(numerator)
denominator = float(denominator)
q = numerator//denominator
r = numerator%denominator
ans = numerator/denominator

print("Q.)",numerator,"/",denominator,"=",ans,"\n")
print("     Answer is   >>",ans)
print("     quotient is >>",q)
print("     reminder is >>",r)
