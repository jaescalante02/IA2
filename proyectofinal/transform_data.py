
import sys
import datetime

training = False if (sys.argv[1]=='0') else True

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
    n.append(x[1]-x[2])
    n.append(x[4]-x[2])
    n.append(x[5]-x[2])
    n.append(0 if (x[3]<0) else 1)    
    new_datos.append(n)    
  return new_datos      

def imprimir(fname, outname, datos, num):

  fp = open('datos/'+outname+str(num-1), 'w+')
  i=num-1
  for x in datos[num-1:]:
    for a in datos[i-num+1:i]:
      for b in a[3:]:
        if(isinstance(b, float)):
          fp.write(str(round(b, 3)))
        else:  
          fp.write(str(b))
        fp.write(' ')  
    for c in datos[i][:3]: 
        if(isinstance(c, float)):
          fp.write(str(round(c, 3)))
        else:  
          fp.write(str(c))
        fp.write(' ')
    if(training):
      fp.write(str(datos[i][6]))
    fp.write('\n')
    i+=1
  fp.close()               
  

fname = sys.argv[3]
comb = int(sys.argv[2])          
datos = read_file(fname)        
print len(datos), 'datos'
datos=operar(datos)
for i in list(range(2, comb+1)):
  imprimir(fname, sys.argv[4], datos, i)


        
        
        
        
      





