
import sys
import datetime

def read_file(filename):

  with open(filename) as f:
    aux = [str(x) for x in f.readline().split()]
    array = []
    for line in f: # read rest of lines
        s=line.split()
        array2=[s[0]] + [float(x) for x in s[1:]]
        array.append(array2)
        
  return array[::-1]      
        
 
def operar(datos):

  new_datos = []
  for x in datos:
    n=[]
    d=datetime.datetime.strptime(x[0], "%d/%m/%y").date()
    n.append(d.day)
    n.append(d.month)    
    n.append(d.weekday())
    n.append(x[1]-x[5])
    n.append(x[2]-x[5])
    n.append(x[4]-x[5])
    n.append(0 if (x[3]<0) else 1)    
    new_datos.append(n)    
  return new_datos      

def imprimir(fname, datos, num):

  fp = open("datos/"+fname+str(num)+".txt", 'w+')
  i=0
  for x in datos:
    for a in datos[i:i+num]:
      for b in a:
        if(isinstance(b, float)):
          fp.write(str(round(b, 3)))
        else:  
          fp.write(str(b))
        fp.write(' ')
    fp.write('\n')
    i+=1
  fp.close()              
  

fname = sys.argv[2]
comb = int(sys.argv[1])          
datos = read_file(fname)        
print len(datos), 'datos'
datos=operar(datos)
for i in list(range(1, comb+1)):
  imprimir(fname, datos, i)


        
        
        
        
      





