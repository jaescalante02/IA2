#Modulo para procesar la informacion de las iris y dividirlas por clases
#Creado por:
#     Juan Escalante
#     Wilmer Bandres

#Se define en que rango cayo el valor del primer campo de las iris
#Los rangos son:
#   1 si el valor pertenece a (-inf, 5.6)
#   2 si el valor pertenece a [5.6, 6.6)
#   3 si el valor pertenece a [6.6, inf)

import sys

def campo1(valor):
  if(valor<5.6):
    return 1
  if(valor<6.6):
    return 2
  return 3

#Se define en que rango cayo el valor del segundo campo de las iris
#Los rangos son:
#   1 si el valor pertenece a (-inf, 3.0)
#   2 si el valor pertenece a [3.0, inf)
def campo2(valor):
  if (valor < 3.0):
    return 1
  return 2


#Se define en que rango cayo el valor del tercer campo de las iris
#Los rangos son:
#   1 si el valor pertenece a (-inf, 2.5)
#   2 si el valor pertenece a [2.5, 5.0)
#   3 si el valor pertenece a [5.0, inf)
def campo3(valor):
  if(valor<2.5):
    return 1
  if(valor<5.0):
    return 2
  return 3
  
#Se define en que rango cayo el valor del cuarto campo de las iris
#Los rangos son:
#   1 si el valor pertenece a (-inf, 1.0)
#   2 si el valor pertenece a [1.0, 2.0)
#   3 si el valor pertenece a [2.0, inf)
def campo4(valor):
  if(valor<1,.0):
    return 1
  if(valor<2.0):
    return 2
  return 3

  
def campo5(nombre):
  if(nombre=="Iris-setosa\n"):
    return 1
  if(nombre=="Iris-versicolor\n"):
    return 2
  return 3
  
  
def procesar():
  if(len(sys.argv) != 2):
    print "Uso:"
    print "./procesador.py <archivo_de_datos_de_iris>"
    exit(0)

  entrada = open(sys.argv[1],'r')
  
  datos = []
  for data in entrada:
      data = data.split(',')
      #print data
      datos.append([campo1(float(data[0])),campo2(float(data[1])),\
      campo3(float(data[2])),campo4(float(data[3])),\
      campo5(data[4])])

  return datos
  
# print procesar()
