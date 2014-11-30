
import sys

def read_file(filename):

  with open(filename) as f:
    array = []
    for line in f: # read rest of lines
        array2=[int(x) for x in line.split()]
        array.append(array2)
        
  return array
  
a=read_file(sys.argv[2])     

b=[]
for i in a:
   b.append(sum(i))

for i in b:
  if(i>=int(sys.argv[1])):
    print 1
  else:
    print 0   
