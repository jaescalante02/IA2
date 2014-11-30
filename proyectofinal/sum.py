
def read_file(filename):

  with open(filename) as f:
    array = []
    for line in f: # read rest of lines
        array2=[int(x) for x in line.split()]
        array.append(array2)
        
  return array
  
a=read_file('datos_completos/votacion.txt')     

b=[]
for i in a:
   b.append(sum(i))

for i in b:
  if(i>3):
    print 1
  else:
    print 0   
