from pyevolve import GSimpleGA
from pyevolve import G1DBinaryString
from pyevolve import Selectors
from pyevolve import Initializators, Mutators
import operaciones

# Genome instance
genome = G1DBinaryString.G1DBinaryString(65)

genome.evaluator.set(operaciones.FitnessDividido) #Mejor fit
#genome.evaluator.set(operaciones.FitnessGabil) # 2do mejor fit
genome.mutator.set(operaciones.MutacionDeGabil)
genome.crossover.set(operaciones.CrossoverDeGabil)

# Genetic Algorithm Instance
ga = GSimpleGA.GSimpleGA(genome)
#ga.selector.set(Selectors.GRouletteWheel) #<- 3er mejor
#ga.selector.set(Selectors.GRankSelector) # <- gual al de arriba
ga.selector.set(Selectors.GTournamentSelector) #<- mejor
#ga.selector.set(Selectors.GUniformSelector) #<- 2do mejor

ga.nGenerations = 200

#Parametros del algoritmo
ga.setCrossoverRate(0.80)
ga.setMutationRate(0.015)
#ga.setPopulationSize(80)

# Do the evolution
ga.evolve(10)


# Best individual
print ga.bestIndividual()
print operaciones.FitnessDividido(ga.bestIndividual())
