# Traveling salesman problem
A console application that finds the shortest path through all the points of the route.

To implement the nearest neighbor algorithm, I created two functions. 
The "Exist" function is designed to make sure that each city on the route has only been traveled once. 
This function is called in another function "Nearest_neighbor". The "Nearest_neighbor" function directly 
implements the nearest neighbor algorithm: searching for the shortest distance from the current city.