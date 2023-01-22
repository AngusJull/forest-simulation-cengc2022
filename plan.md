Getting this done
  1. Come up with a consistent schedule
  2. Divide work up into weeks
  3. Define goals and components
  4. Define internal structure before starting

Components
1. Plants (Third)
   - Individual plant objects
   - Way of translating input into new plant objects
   - Base plant class for inheritance
   
2. Simulation Area (Second)
   - Way of arranging all plants
   - Way of efficiently storing all plants that allows for easy access to neighbors
   - Way of scaling the allowed area
   
3. Properties (First)
   - Rules for how trees grow
   - Simple checks with neighbors
   - Equations for how trees change on each iteration using these rules
   - Define how long of a time period an interation is

4. Output (Fourth)
   - Debug output using either text files or the console
   - Find a way to go from C++ to visual rep of the forest

Properties
- Plant Type
   - Inherit from a base plant type, have modifiers in derived class for the second keyword
   - One class for all trees but modifiers to change how the tree behaves as a single variable

- Growth Rate
   - Come up with one equation that relates previous height to new height, dH/dt = aH^bt + C, keep the same but diff plants can have diff equations for a and b
   - Trees could be more exponential while small plants more linear in growth rates?
   - Check equations in desmos or something

- Max Growth
   - Either just stop calculating growth after the max height, or add a factor to the growth rate that decreases growth rate to 0 over time

- Percipitation/Temperature for Plants
  - Just multiply into the exponent

- Shade tolerance
  - Have a map of shade values at every plant, and only update them when a change happens?
  - Would also need a way to calculate shade from scratch when a new plant is created
  - Or make an array the same size as the simulation field that has the shade values
  - Could decrease shade percentage based on height? might favour tall trees too much, but could also allow them to rise above shade
  - Could have seperate zones for shade, low/high?

- Seeds produced
  - Have a formula for calculating # of seeds made
  - Seeds could run the growth rate to check for the probability they live
  - Seeds would check how close neighbors are to see if they can grow in a spot
  - Seed production starts around when max growth rate reached
  - Growth rate and seeds produced could just be multiplied together and rounded

- Seed distribution radius
  - Use random libraries and check for a spot within a distance

- Lifespan
  - Either kill the plant after this length of time or add another factor to growth rate? Or just use growth rate + random to decide when to kill a plant

Enviroment Properties
- When calling plant properties just pass in the current temp/percip as enviroment properties

Simulation Area
- Do a linked list implementation
   - Could use built in list structure
   - Good with inserting plants into the structure, dynamic size
   - Harder to find neighboring plants above and below
   - Would need to use algorithms that work through rows
   - Could have plants off grid
      - Would make calculating shade more difficult
- Do an array
   - Max number of plants and possible distribution decided beforehand
   - Could have a lot of cells if allowing for complete coverage with tiny plants
   - Would work well with shade
   - Size of the data structure would be pretty large by default
-  Array rows + linked list (kinda like dict)
   - Set spacing in one dimension, not the other
   - Would make shade calculations slightly easier

Make diagrams for the overall structure
- Start with getting a plant and showing its growth over time
- Then work on multiple



