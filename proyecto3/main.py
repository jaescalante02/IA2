from pyevolve import GSimpleGA
from pyevolve import G1DBinaryString
from pyevolve import Selectors
from pyevolve import Initializators, Mutators
import operaciones

# Genome instance
genome = G1DBinaryString.G1DBinaryString(65)

genome.evaluator.set(operaciones.FitnessDividido)
genome.mutator.set(operaciones.MutacionDeGabil)
genome.crossover.set(operaciones.CrossoverDeGabil)

# Genetic Algorithm Instance
ga = GSimpleGA.GSimpleGA(genome)
ga.selector.set(Selectors.GRouletteWheel)
ga.nGenerations = 300

# Do the evolution
ga.evolve(10)


#Parametros del algoritmo
#ga.setCrossoverRate(1.0)
#ga.setMutationRate(0.03)
#ga.setPopulationSize(80)

# Best individual
print ga.bestIndividual()
