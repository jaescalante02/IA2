
import sys
import datetime

def read_file(filename):

  with open(filename) as f:
    aux = [str(x) for x in f.readline().split()]
    dic = {}
    for line in f: # read rest of lines
        s=line.split()
        dic[datetime.datetime.strptime(s[0], "%d/%m/%y").date().strftime("%d/%m/%y")] = [float(x) for x in s[1:]]
    first = datetime.datetime.strptime(s[0], "%d/%m/%y").date().strftime("%d/%m/%y")

        
  return dic, first      
        
def completar(fday, datos):

  i=0
  tam = len(datos)
  day=datetime.datetime.strptime(fday, "%d/%m/%y").date()
  new_datos=[]
  while(i<tam):
    str_date = day.strftime("%d/%m/%y")
    if(str_date in datos):
      new_datos.append([str_date] + datos[str_date]) 
      i+=1   
      day += datetime.timedelta(days=1)      
    else:
      while(str_date not in datos):
        new_datos.append([str_date] + [0.0, 0.0, 0.0, 0.0, 0])        
        day += datetime.timedelta(days=1) 
        str_date = day.strftime("%d/%m/%y") 
      
        
  return new_datos
  
 
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

  fp = open("datos_completos/"+fname+str(num)+".txt", 'w+')
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
datos, first_day = read_file(fname)        
datos = completar(first_day, datos)
print len(datos), 'datos'
datos=operar(datos)
for i in list(range(1, comb+1)):
  imprimir(fname, datos, i)


        
