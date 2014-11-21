#Modulo de operaciones de Gabil basado en pyevolve
#Creado por:
#     Juan Escalante
#     Wilmer Bandres

from random import randint as rand_randint, gauss as rand_gauss, uniform as rand_uniform
import pyevolve.Consts
import pyevolve.Util
import MiConstantes
import procesador

#Funcion encargada de realizar el swap de alguno de los bits
#De la representacion de un individuo
#Cambia unicamente un bit
def MutacionDeGabil(genome, **args):
  which = rand_randint(1, len(genome)-1)
  mutations = args["pmut"] * (len(genome))
  
  if args["pmut"] <= 0.0: 
    return 0
    
  if mutations < 1.0:
    mutations=0
    if pyevolve.Util.randomFlipCoin(args["pmut"]):
      if (genome[which] == 0): 
        genome[which] = 1
      else: 
        genome[which] = 0
      mutations=1.0
      
  else:
    if (genome[which] == 0): 
      genome[which] = 1
    else: 
      genome[which] = 0

  return mutations


#Funcion que implementa el crossover de Gabil explicado en la seccion 9
#del libro
def CrossoverDeGabil(genome, **args):
  sister = None
  brother = None
  gMom = args["mom"]
  gDad = args["dad"]
  tamReglas = MiConstantes.tamanioReglas
  
  
  cuts = [rand_randint(0, (len(gMom)-1)/ tamReglas) , rand_randint(0, (len(gMom)-1)/tamReglas)]  
  
  if cuts[0] > cuts[1]:
    pyevolve.Util.listSwapElement(cuts, 0, 1)
    
  restos = [rand_randint(0, tamReglas-1), rand_randint(0, tamReglas-1)]
  
  if restos[0] > restos[1]:
    pyevolve.Util.listSwapElement(restos, 0, 1)

  cuts2 = [rand_randint(0, (len(gDad)-1) / tamReglas), rand_randint(0, (len(gDad)-1)/tamReglas)]

  if cuts2[0] > cuts2[1]:
    pyevolve.Util.listSwapElement(cuts2, 0, 1)
  
  

  if args["count"] >= 1:
    sister = gMom.clone()
    sister.resetStats()
    sister[cuts[0]*tamReglas+restos[0]:cuts[1]*tamReglas+restos[1]] = \
      gDad[cuts2[0]*tamReglas+restos[0]:cuts2[1]*tamReglas+restos[1]]
    sister.stringLength = len(sister.genomeString)

  if args["count"] == 2:
    brother = gDad.clone()
    brother.resetStats()
    brother[cuts2[0]*tamReglas+restos[0]:cuts2[1]*tamReglas+restos[1]] = \
      gMom[cuts[0]*tamReglas+restos[0]:cuts[1]*tamReglas+restos[1]]
    brother.stringLength = len(brother.genomeString)
    
  return (sister, brother)


#Variable que tendra los casos procesados de las iris  
casos = procesador.procesar()



#Funcion que calcula el score de gabil dado los casos parseados
#y el individuo
#Ademas se divide el score de Gabil por el tamanio del individuo
#para poder controlar un crecimiento exagerado del mismo
def FitnessGabil(genome):
  score = 0.0
  tam = len(genome)  
  tamRegla = MiConstantes.tamanioReglas
  
  # Itero sobre los bits de la regla
  for caso in casos:
    ya = 0
    for x in range(0,tam/tamRegla):
       regla = x*tamRegla
       if(genome[regla+caso[0]-1]==0):
        continue
       if(genome[regla+3+caso[1]-1]==0):
        continue
       if(genome[regla+5+caso[2]-1]==0):
        continue
       if(genome[regla+8+caso[3]-1]==0):
        continue
       if(genome[regla+11+caso[4]-1]==0):
        continue
       
       if(ya==0):
        score+=1.0
       ya = 1
       

  return (score*score)/float(tam)


