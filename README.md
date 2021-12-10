# Conway-Game-of-Life
A recreation of Conway's Game of Life
User inputs the number of rows and columns and the number of iterations to run. 
Next, the user creates a grid using the dimensions specified. Cells must contain a 'x' (dead), 'g' (green/alive), or 'r' (red/alive).
The program will return the number of red and green cells present after the number of given iterations.

Rules:

* If cell has >3 neighbors, cell dies ("becomes 'x')
* If cell has <2 neighbors, cell dies
* If cell has exactly 3 neighbors and is dead ('x'), the cell takes the color of the majority of its neighbors
* If none of the above, cell does not change

Note: the grid has wrapping borders

ex. 

5 4

1

g x x r

r x g g

x x r x

r g x r

x r x x


returns: green: 2, red: 4
