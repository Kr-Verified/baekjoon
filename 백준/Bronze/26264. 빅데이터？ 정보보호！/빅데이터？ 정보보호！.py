input()
n = input()
bigdata = n.count("bigdata")
security = n.count("security")
if (bigdata>security):
    print("bigdata?")
elif (bigdata<security):
    print("security!")
else:
    print("bigdata? security!")