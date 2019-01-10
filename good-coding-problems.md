#Good Coding Problems
####Back-Tracking
1. Rat in a maze.
	- Maze is (N,N) matrix, rat have to reach from 	         source(0,0) to destination(N-1,N-1), some cells are     blocked. **Rat can move in all 4 directions.**
	- Our Thought: keep marking the cells that we visit 	in the path and if encounter some visited cells than 	 backtrack.
	- **TRICK**: This can be done with `int 		   previous_dirction` variable only but we have to follow the specific order of directions when we move. ```order : down, left, up, right```
	- Link: [https://algorithms.tutorialhorizon.com/backtracking-rat-in-a-maze-puzzle/](http://)

2. Next

####NextCategory
