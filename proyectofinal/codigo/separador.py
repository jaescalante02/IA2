import sys

entrada = open(sys.argv[1],'r')

for data in entrada:
  data = data.split()
  print data[-1]


