print("C     F")
print("------------")

C = 5

while C <= 38:
    F = (C*1.8) + 32
    print("{:2d}   {:3.1f}".format(C, F))
    C = C + 3